#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define KEY_LENGTH 5
#define MAX_STRING_LENGTH 200

typedef struct {
    char key[KEY_LENGTH], value[MAX_STRING_LENGTH];
} Pair;

typedef struct {
    Pair *data;
    size_t size, capacity;
} Table;

// Table interface ====

Table *tableCreate();
void tableDestroy(Table *table);
void tableResize(Table *table, size_t newSize);
void tablePush(Table *table, Pair pair);
size_t tableSize(Table *table);
void tableClear(Table *table);
bool tableEmpty(Table *table);
void tablePrint(Table *table);
// Statusable
bool tableLoadFromFile(Table *table, char *filename);
void tableNaturalMergeSort(Table *table);
bool tableBinarySearch(Table *table, char *key, Pair *result);

// \Table interface ===
