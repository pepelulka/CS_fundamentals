#include "table.h"

// Table interface ====

Table *tableCreate() {
    Table *table = malloc(sizeof(Table));
    table->size = 0;
    table->capacity = 1;
    table->data = malloc(sizeof(Pair));
    return table;
}

void tableDestroy(Table *table) {
    if (table == NULL) return;
    free(table->data);
    free(table);
}

void tableResize(Table *table, size_t newSize) {
    assert(table != NULL);
    while (newSize > table->capacity) {
        table->capacity *= 2;
    }
    table->data = realloc(table->data, sizeof(Pair) * table->capacity);
    table->size = newSize;
}

void tablePush(Table *table, Pair pair) {
    assert(table != NULL);
    tableResize(table, table->size + 1);
    table->data[table->size - 1] = pair;
}

size_t tableSize(Table *table) {
    assert(table != NULL);
    return table->size;
}

void tableClear(Table *table) {
    assert(table != NULL);
    table->size = 0;
}

bool tableEmpty(Table *table) {
    assert(table != NULL);
    return (tableSize(table) == 0);
}

void tablePrint(Table *table) {
    assert(table != NULL);
    for (size_t i = 0;i < table->size;i++) {
        printf("%s:%s\n", table->data[i].key, table->data[i].value);
    }
}

bool tableLoadFromFile(Table *table, char *filename) {
    FILE *input;
    if ((input = fopen(filename, "r")) == NULL) {
        return false;
    }
    tableClear(table);
    char cur;
    int state = 1; // 0 - start, 1 - writing key, 2 - writing value
    Pair curPair; size_t curKeyLen = 0, curValueLen = 0;
    while (true) {
        cur = getc(input);
        if ((state == 0 || state == 1) && cur == EOF) break;
        if (state == 1 || state == 0) {
            if (cur == ':') {
                state = 2;
                curPair.key[curKeyLen] = '\0';
                continue;
            }
            state = 1;
            curPair.key[curKeyLen] = cur;
            curKeyLen++;
        } else {
            if (cur == '\n' || cur == EOF) {
                state = 1;
                curPair.value[curValueLen] = '\0';
                if (curKeyLen != 0 && curValueLen != 0 ) tablePush(table, curPair);
                curPair.key[0] = '\0';
                curPair.value[0] = '\0';
                curKeyLen = 0;
                curValueLen = 0;
                continue;
                if (cur == EOF) break;
            }
            state = 2;
            curPair.value[curValueLen] = cur;
            curValueLen++;
        }
    }
    fclose(input);
    return true;
}

// Sorting:
// %%%
// t1 and t2 must be sorted
typedef struct {
    Table **data;
    size_t size, capacity;
} TableVector;

// (Private) TableVector interface %%%% (prefix - tv)

TableVector *tvCreate() {
    TableVector *tv = malloc(sizeof(TableVector));
    tv->size = 0;
    tv->capacity = 1;
    tv->data = malloc(sizeof(Table*));
    return tv;
}

void tvDestroy(TableVector *tv) {
    for (size_t i = 0;i < tv->size;i++) tableDestroy(tv->data[i]);
    free(tv->data);
    free(tv);
}

void tvResize(TableVector *tv, size_t newSize) {
    bool flag = false;
    while (newSize > tv->capacity) {
        tv->capacity *= 2;
        flag = true;
    }
    if (flag) tv->data = realloc(tv->data, sizeof(Table*) * tv->capacity);
    tv->size = newSize;
}

void tvPush(TableVector *tv, Table *t) {
    tvResize(tv, tv->size + 1);
    tv->data[tv->size - 1] = t;
}

// \TableVector interface %%%%%%%%%%%%%

// don't clear result
void tableMerge(Table *table1, Table *table2, Table *result) {
    assert(table1 != NULL && table2 != NULL && result != NULL);
    size_t i = 0, j = 0;
    size_t n1 = table1->size, n2 = table2->size;
    while (i != n1 || j != n2) {
        if (j == n2) {
            tablePush(result, table1->data[i]);
            i++;
        } else if (i == n1) {
            tablePush(result, table2->data[j]);
            j++;
        } else {
            if (strcmp(table1->data[i].key, table2->data[j].key) <= 0) {
                tablePush(result, table1->data[i]);
                i++;
            } else {
                tablePush(result, table2->data[j]);
                j++;
            }
        }
    }
}

void tableVectorMerge(TableVector *tv1, TableVector *tv2, Table *result) {
    assert(tv1 != NULL && tv2 != NULL && result != NULL);
    tableClear(result);
    size_t global_i = 0;
    while (global_i < tv1->size && global_i < tv2->size) {
        tableMerge(tv1->data[global_i], tv2->data[global_i], result);
        // printf("PROTO: \n");
        // tablePrint(result);
        // printf("PROTO END\n");
        global_i++;
    }
    while (global_i < tv1->size) {
        for (size_t i = 0;i < tv1->data[global_i]->size;i++) {
            tablePush(result, tv1->data[global_i]->data[i]);
        }
        global_i++;
    }
    while (global_i < tv2->size) {
        for (size_t i = 0;i < tv2->data[global_i]->size;i++) {
            tablePush(result, tv2->data[global_i]->data[i]);
        }
        global_i++;
    }
    // printf("PROTO: \n");
    // tablePrint(result);
    // printf("PROTO END\n");
}

void tableDivide(Table *table, TableVector *tv1, TableVector *tv2) {
    assert(table != NULL && tv1 != NULL && tv2 != NULL);
    tvPush(tv1, tableCreate());
    tablePush(tv1->data[0], table->data[0]);
    int current = 0;
    TableVector* heaps[2] = {tv1, tv2}; // For fast switching between two heaps
    for (size_t i = 1; i < table->size; i++) {
        if (strcmp(table->data[i].key, table->data[i - 1].key) >= 0) {
            tablePush(heaps[current]->data[heaps[current]->size - 1], table->data[i]);
        } else {
            current = 1 - current;
            tvPush(heaps[current], tableCreate());
            tablePush(heaps[current]->data[heaps[current]->size - 1], table->data[i]);
        }
    }
}

void tableNaturalMergeSort(Table *table) {
    assert(table != NULL);
    if (table->size <= 1)
        return;
    TableVector *tv1 = tvCreate(), *tv2 = tvCreate();
    tableDivide(table, tv1, tv2);
    size_t value = tv1->size + tv2->size;
    while (value >= 2) {
        tableVectorMerge(tv1, tv2, table);
        tvDestroy(tv1); tvDestroy(tv2);
        tv1 = tvCreate(), tv2 = tvCreate();
        tableDivide(table, tv1, tv2);
        value = (tv1->size + tv2->size);
    }
    tvDestroy(tv1); tvDestroy(tv2);
}

// Sorting \end

bool tableBinarySearch(Table *table, char *key, Pair *result) {
    size_t l = 0, r = table->size - 1;
    while (r - l > 1) {
        size_t mid = (l + r) / 2;
        if (strcmp(table->data[mid].key, key) <= 0)
            l = mid;
        else
            r = mid;
    }
    if (strcmp(table->data[l].key, key) == 0) {
        *result = table->data[l];
        return true;
    }
    if (strcmp(table->data[r].key, key) == 0) {
        *result = table->data[r];
        return true;
    }
    return false;
}

// \Table interface ===
