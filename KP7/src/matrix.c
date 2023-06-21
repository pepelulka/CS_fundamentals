#include "matrix.h"

// Matrix interface (prefix - matrix) ===

Matrix *matrixCreate() {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->CIP = vectorCreate();
    matrix->PI = vectorCreate();
    matrix->YE = vectorCreate();
    matrix->n = 0;
    matrix->m = 0;
    return matrix;
}

void matrixClear(Matrix *matrix) {
    assert(matrix != NULL);
    matrix->n = 0;
    matrix->m = 0;
    vectorClear(matrix->CIP); vectorClear(matrix->PI); vectorClear(matrix->YE);
}

void matrixDestroy(Matrix *matrix) {
    if (matrix == NULL) return;
    vectorDestroy(matrix->CIP); vectorDestroy(matrix->PI); vectorDestroy(matrix->YE);
    free(matrix);
}

// Statusable
bool matrixFromFile(Matrix *matrix, char *filename) {
    FILE *input;
    if ((input = fopen(filename, "r")) == NULL) {
        return false;
    }
    int n, m;
    fscanf(input, "%d %d", &n, &m);
    Vector *cip = matrix->CIP, *pi = matrix->PI, *ye = matrix->YE;
    matrixClear(matrix);
    matrix->n = n;
    matrix->m = m;
    for (int i = 0;i < n;i++) {
        vectorPushBack(cip, (int)vectorSize(pi));
        for (int j = 1;j <= m;j++) {
            int cur;
            fscanf(input, "%d", &cur);
            if (cur != 0) {
                vectorPushBack(pi, j);
                vectorPushBack(ye, cur);
            }
        }
    }
    vectorPushBack(pi, 0);
    fclose(input);
    return true;
}

void matrixPrintNormal(Matrix *matrix) {
    assert(matrix != NULL);
    int n = matrix->n, m = matrix->m;
    // Print all rows except last
    for (int i = 0;i < n;i++) {
        int ptr = 1;
        int curRowPiInd = matrix->CIP->data[i];
        int nextRowPiInd;
        if (i == (n - 1)) {
            nextRowPiInd = (vectorSize(matrix->PI) - 1);
        } else {
            nextRowPiInd = matrix->CIP->data[i + 1];
        }
        while (curRowPiInd != nextRowPiInd) {
            int curColumn = matrix->PI->data[curRowPiInd];
            int curValue = matrix->YE->data[curRowPiInd];
            while (ptr != curColumn) {
                printf("0\t");
                ptr++;
            }
            ptr++;
            printf("%d\t", curValue);
            curRowPiInd++;
        }
        while (ptr != (m + 1)) {
            printf("0\t");
            ptr++;
        }
        putchar('\n');
    }
}

void matrixPrintRaw(Matrix *matrix) {
    assert(matrix != NULL);
    printf("Matrix %lux%lu\n", matrix->n, matrix->m);
    printf("CIP: "); vectorPrint(matrix->CIP);
    printf("PI: "); vectorPrint(matrix->PI);
    printf("YE: "); vectorPrint(matrix->YE);
}

void matrixSet(Matrix *matrix, size_t i, size_t j, int value) {
    assert(matrix != NULL && i < matrix->n && j < matrix->m);
    size_t n = matrix->n;
    int curRowPiInd = matrix->CIP->data[i];
    int nextRowPiInd;
    if (i == (n - 1)) {
        nextRowPiInd = (vectorSize(matrix->PI) - 1);
    } else {
        nextRowPiInd = matrix->CIP->data[i + 1];
    }
    // Row is zero
    if (curRowPiInd == nextRowPiInd) {
        j++;
        vectorInsert(matrix->PI, curRowPiInd, j);
        vectorInsert(matrix->YE, curRowPiInd, value);
        for (size_t k = i + 1;k < n;k++) matrix->CIP->data[k]++;
    } else {
        j++;
        while (j > (size_t)matrix->PI->data[curRowPiInd] && curRowPiInd != nextRowPiInd) {
            curRowPiInd++;
        }
        if (j == (size_t)matrix->PI->data[curRowPiInd] && curRowPiInd != nextRowPiInd) {
            if (value == 0) {
                matrix->PI->size--;
                matrix->YE->size--;
                for (size_t k = curRowPiInd;k < matrix->PI->size;k++) {
                    matrix->PI->data[k] = matrix->PI->data[k + 1];
                    matrix->YE->data[k] = matrix->YE->data[k + 1];
                }
                for (size_t k = i + 1;k < matrix->n;k++) matrix->CIP->data[k]--;
            } else {
                matrix->YE->data[curRowPiInd] = value;
            }
        }
        else {
            vectorInsert(matrix->PI, curRowPiInd, j);
            vectorInsert(matrix->YE, curRowPiInd, value);
            for (size_t k = i + 1;k < n;k++) matrix->CIP->data[k]++;
        }
    }
}

int matrixGet(Matrix *matrix, size_t i, size_t j) {
    assert(matrix != NULL && i < matrix->n && j < matrix->m);
    int result = 0;
    int curRowPiInd = matrix->CIP->data[i];
    int nextRowPiInd;
    if (i == (matrix->n - 1)) {
        nextRowPiInd = (vectorSize(matrix->PI) - 1);
    } else {
        nextRowPiInd = matrix->CIP->data[i + 1];
    }
    j++;
    for (;curRowPiInd != nextRowPiInd;curRowPiInd++) {
        if ((size_t)matrix->PI->data[curRowPiInd] == j)
            result = matrix->YE->data[curRowPiInd];
    }
    return result;
}

int matrixMultVector(Matrix *matrix, Vector *vector, Vector *result) {
    assert(matrix != NULL && vector != NULL && result != NULL && vectorSize(vector) == matrix->m);
    vectorClear(result);
    int nonZeroCount = 0;
    int n = matrix->n;
    for (int i = 0;i < n;i++) {
        int curResult = 0;

        int curRowPiInd = matrix->CIP->data[i];
        int nextRowPiInd;
        if (i == (n - 1)) {
            nextRowPiInd = (vectorSize(matrix->PI) - 1);
        } else {
            nextRowPiInd = matrix->CIP->data[i + 1];
        }

        while (curRowPiInd != nextRowPiInd) {
            curResult += matrix->YE->data[curRowPiInd] * (vector->data[matrix->PI->data[curRowPiInd] - 1]);
            curRowPiInd++;
        }
        vectorPushBack(result, curResult);
        if (curResult != 0) nonZeroCount++;
    }
    return nonZeroCount;
}

// =============================================
