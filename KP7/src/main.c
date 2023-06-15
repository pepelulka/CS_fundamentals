#include "matrix.h"
#include "textmenu.h"

// C & D
void *creator_Matrix() {
    Matrix *matrix = matrixCreate();
    return (void*)matrix;
}

void destroyer_Matrix(void *obj) {
    Matrix *matrix = (Matrix*)obj;
    matrixDestroy(matrix);
}

// Handlers
void handler_load(void *obj) {
    Matrix *matrix = (Matrix*)obj;
    //
    char filename[40];
    scanf("%s", filename);
    if (matrixFromFile(matrix, filename)) {
        printf("Success\n");
    } else printf("Failed to load matrix\n");
}

void handler_print(void *obj) {
    Matrix *matrix = (Matrix*)obj;
    //
    matrixPrintNormal(matrix);
}

void handler_raw_print(void *obj) {
    Matrix *matrix = (Matrix*)obj;
    //
    matrixPrintRaw(matrix);
}

void handler_set(void *obj) {
    Matrix *matrix = (Matrix*)obj;
    //
    size_t i, j;
    int value;
    scanf("%lu %lu %d", &i, &j, &value);
    matrixSet(matrix, i, j, value);
}

void handler_get(void *obj) {
    Matrix *matrix = (Matrix*)obj;
    //
    size_t i, j;
    scanf("%lu %lu", &i, &j);
    printf("%d\n", matrixGet(matrix, i, j));
}

void handler_mult(void *obj) {
    Matrix *matrix = (Matrix*)obj;
    //
    int m = matrix->m;
    Vector *vector = vectorCreate();
    printf("Enter vector:\n");
    for (int i = 0;i < m;i++) {
        int cur;
        scanf("%d", &cur);
        vectorPushBack(vector, cur);
    }
    Vector *resultVector = vectorCreate();
    int result = matrixMultVector(matrix, vector, resultVector);
    printf("Result vector: "); vectorPrint(resultVector);\
    printf("Non-zero count: %d\n", result);
    vectorDestroy(vector);
    vectorDestroy(resultVector);
}

int main() {
    textMenuFastInitialize(6,
                           "load", "load <filename> - loads matrix from file", handler_load,
                           "print", "print - prints matrix", handler_print,
                           "print_raw", "print_raw - prints internal vectors of matrix", handler_raw_print,
                           "set", "set <i> <j> <value> - sets value on index (i, j)", handler_set,
                           "get", "get <i> <j> - gets value on index (i, j)", handler_get,
                           "mult", "mult - multiply matrix by vector and prints number of non-zero elements in the result", handler_mult);
    textMenuFastStart(creator_Matrix, destroyer_Matrix);
    textMenuFastClose();
}