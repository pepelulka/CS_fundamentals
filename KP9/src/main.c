#include "table.h"
#include "textmenu.h"

// C & D
void *creator_Table() {
    Table *table = tableCreate();
    return (void*)table;
}

void destroyer_Table(void *obj) {
    Table *table = (Table*)obj;
    tableDestroy(table);
}

// Handlers
void handler_print(void *obj) {
    Table *table = (Table*)obj;
    //
    tablePrint(table);
}

void handler_load(void *obj) {
    Table *table = (Table*)obj;
    //
    char filename[40];
    scanf("%s", filename);
    if (tableLoadFromFile(table, filename)) printf("Success\n");
    else printf("Failed to load from file\n");
}

void handler_sort(void *obj) {
    Table *table = (Table*)obj;
    //
    tableNaturalMergeSort(table);
}

void handler_search(void *obj) {
    Table *table = (Table*)obj;
    //
    char key[KEY_LENGTH];
    scanf("%s", key);
    Pair result;
    if (tableBinarySearch(table, key, &result)) {
        printf("%s:%s\n", key, result.value);
    } else printf("There's no such key in the table\n");
}

int main() {
    textMenuFastInitialize(4,
                           "print", "print - prints table", handler_print,
                           "load", "load <filename> - loads table from file", handler_load,
                           "sort", "sort - sorts table", handler_sort,
                           "search", "search <key> - binary search in sorted(!) table", handler_search);
    textMenuFastStart(creator_Table, destroyer_Table);
    textMenuFastClose();
}