#include "vector.h"

// Vector interface ===

Vector *vectorCreate() {
    Vector *vector = malloc(sizeof(Vector));
    vector->size = 0;
    vector->capacity = 1;
    vector->data = malloc(vector->capacity * sizeof(int));
    return vector;
}

void vectorDestroy(Vector *vector) {
    assert(vector != NULL);
    free(vector->data);
    free(vector);
}

size_t vectorSize(Vector *vector) {
    assert(vector != NULL);
    return vector->size;
}

void vectorResize(Vector *vector, size_t newSize) {
    assert(vector != NULL);
    vector->size = newSize;
    if (newSize > vector->capacity) {
        vector->capacity = newSize;
        vector->data = realloc(vector->data, vector->capacity * sizeof(int));
    }
}

void vectorSet(Vector *vector, size_t index, int value) {
    assert(vector != NULL);
    assert(index < vector->size);
    vector->data[index] = value;
}

void vectorPushBack(Vector *vector, int value) {
    assert(vector != NULL);
    vectorResize(vector, vector->size + 1);
    vectorSet(vector, vector->size - 1, value);
}

int vectorGet(Vector *vector, size_t index) {
    assert(vector != NULL);
    assert(index < vector->size);
    return vector->data[index];
}

void vectorPrint(Vector *vector) {
    assert(vector != NULL);
    for (size_t i = 0;i < vector->size;i++) {
        int el = vector->data[i];
        printf("%d ", el);
    }
    printf("\n");
}

void vectorClear(Vector *vector) {
    assert(vector != NULL);
    vector->size = 0;
}

void vectorErase(Vector *vector, size_t index) {
    assert(vector != NULL && (index < vector->size));
    for (size_t i = index;i < (vector->size - 1);i++) {
        vector->data[i] = vector->data[i + 1];
    }
    vector->size--;
}

// Element inserts on index "index"
void vectorInsert(Vector *vector, size_t index, int value) {
    assert(vector != NULL && (index <= vector->size));
    vectorResize(vector, vector->size + 1);
    for (size_t i = (vector->size - 1);i > index;i--) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[index] = value;
}

// ====================
