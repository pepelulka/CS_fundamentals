#include "vector.h"

#include <stdbool.h>

#ifndef __SPARSE_MATRIX__
#define __SPARSE_MATRIX__

typedef struct {
    Vector *CIP, *PI, *YE;
    size_t n, m;
} Matrix;

// Matrix interface (prefix - matrix) ===

Matrix *matrixCreate();
void matrixDestroy(Matrix *matrix);
void matrixClear(Matrix *matrix);

// Statusable
bool matrixFromFile(Matrix *matrix, char *filename);

void matrixPrintNormal(Matrix *matrix);
void matrixPrintRaw(Matrix *matrix);

void matrixSet(Matrix *matrix, size_t i, size_t j, int value);
int matrixGet(Matrix *matrix, size_t i, size_t j);

int matrixMultVector(Matrix *matrix, Vector *vector, Vector *result);

// =============================================

#endif
