#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#ifndef __VECTOR__
#define __VECTOR__

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} Vector;

// Vector interface ===

Vector *vectorCreate();
void vectorDestroy(Vector *vector);

size_t vectorSize(Vector *vector);
void vectorResize(Vector *vector, size_t newSize);
void vectorSet(Vector *vector, size_t index, int value);
void vectorPushBack(Vector *vector, int value);
int vectorGet(Vector *vector, size_t index);
void vectorPrint(Vector *vector);
void vectorClear(Vector *vector);
void vectorErase(Vector *vector, size_t index);
void vectorInsert(Vector *vector, size_t index, int value);

// ====================

#endif
