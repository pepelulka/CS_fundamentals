# Отчёт по курсовой работе №7 по курсу “Языки и методы программирования”

<b>Студент группы:</b> <ins>М80-108Б-22 Рамалданов Рустамхан Ражудинович, № по списку: 15</ins>

<b>Контакты e-mail:</b> <ins>mrpepelulka@gmail.com</ins>

<b>Работа выполнена:</b> «28» <ins>марта</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «28» <ins>марта</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ___________


## 1. Тема
Разреженные матрицы
## 2. Цель работы
Составить и отладить программу на языке Си для обработки разреженных матриц с элементами целого типа.
## 3. Задание (вариант № 19)
- Вариант схемы размещения матрицы: 3 вектора
- Вариант физического представления: отображение на массив
- Вариант преобразования: Умножить разреженную матрицу на вектор-столбец и вычислить количество ненулевых элементов результата.

## 4. Оборудование:
<b>Процессор:</b> 11th Gen intel(R) Core(TM) i5-11400H @ 2.70GHz<br/>
<b>ОП:</b> 16 ГБ<br/>
<b>SSD:</b> 512 ГБ<br/>
<b>Адрес:</b> 192.168.56.1 <br/>
<b>Монитор:</b> 1920x1080<br/>
<b>Графика:</b> Nvidia GeForce RTX 3050 Ti Laptop GPU <br/>

## 5. Программное обеспечение:

<b>Операционная система семейства:</b> linux(ubuntu) версии 5.15.0-47-generic<br/>
<b>Интерпретатор команд:</b> bash версия 5.1.16<br/>
<b>Система программирования:</b> не использовалась версия —<br/>
<b>Редактор текстов:</b> emacs версия 25.2.2<br/>
<b>Утилиты операционной системы:</b> nano, ls, cd, touch, gcc <br/>
<b>Прикладные системы и программы:</b> GNU C compiler <br/>
<b>Местонахождение и имена файлов программ и данных на домашнем компьютере:</b> /home/pepelulka<br/>

## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)

Разреженная матрица была реализована согласно схеме представления. Была реализована структура вектора над динамическим массивом. Далее была реализована структура матрицы, хранящая в себе свои размеры и указатели на три вектора, согласно схеме представления.

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию].

Makefile:
```
CC=gcc
LD=gcc
CCFLAGS=-Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors
LDFLAGS=
SOURCES=$(addprefix src/,main.c matrix.c vector.c textmenu.c)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=src/main

$(EXECUTABLE): $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)
	mkdir build
	mkdir build/bin
	mv $(EXECUTABLE) build/bin
	mv $(OBJECTS) build

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -r build

```

main.c:
```src:main.c
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
```

vector.h
```src:vector.h
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

```

vector.c
```src:vector.c
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

```

matrix.h
```src:matrix.h
#include "vector.h"

#include <stdbool.h>

#ifndef __SPARSE_MATRIX__
#define __SPARSE_MATRIX__

typedef struct {
    Vector *CIP, *PI, *YE;
    int n, m;
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

```

matrix.c
```src:matrix.c
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
    int n = matrix->n;
    // Print all rows except last
    for (int i = 0;i < n;i++) {
        int ptr = 1;
        int curRowPiInd = matrix->CIP->data[i];
        int nextRowPiInd;
        if (i == (n - 1)) {
            nextRowPiInd = (int)(vectorSize(matrix->PI) - 1);
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
        while (ptr != (n + 1)) {
            printf("0\t");
            ptr++;
        }
        putchar('\n');
    }
}

void matrixPrintRaw(Matrix *matrix) {
    assert(matrix != NULL);
    printf("Matrix %dx%d\n", matrix->n, matrix->m);
    printf("CIP: "); vectorPrint(matrix->CIP);
    printf("PI: "); vectorPrint(matrix->PI);
    printf("YE: "); vectorPrint(matrix->YE);
}

void matrixSet(Matrix *matrix, size_t i, size_t j, int value) {
    assert(matrix != NULL && (int)i < matrix->n && (int)j < matrix->m);
    int n = matrix->n;
    int curRowPiInd = matrix->CIP->data[i];
    int nextRowPiInd;
    if ((int)i == (n - 1)) {
        nextRowPiInd = (int)(vectorSize(matrix->PI) - 1);
    } else {
        nextRowPiInd = matrix->CIP->data[i + 1];
    }
    // Row is zero
    if (curRowPiInd == nextRowPiInd) {
        j++;
        vectorInsert(matrix->PI, curRowPiInd, (int)j);
        vectorInsert(matrix->YE, curRowPiInd, value);
        for (size_t k = i + 1;(int)k < n;k++) matrix->CIP->data[k]++;
    } else {
        j++;
        while ((int)j > matrix->PI->data[curRowPiInd] && curRowPiInd != nextRowPiInd) {
            curRowPiInd++;
        }
        if ((int)j == matrix->PI->data[curRowPiInd] && curRowPiInd != nextRowPiInd) matrix->YE->data[curRowPiInd] = value;
        else {
            vectorInsert(matrix->PI, curRowPiInd, j);
            vectorInsert(matrix->YE, curRowPiInd, value);
            for (size_t k = i + 1;(int)k < n;k++) matrix->CIP->data[k]++;
        }
    }
}

int matrixGet(Matrix *matrix, size_t i, size_t j) {
    assert(matrix != NULL && (int)i < matrix->n && (int)j < matrix->m);
    int result = 0;
    int curRowPiInd = matrix->CIP->data[i];
    int nextRowPiInd;
    if ((int)i == (matrix->n - 1)) {
        nextRowPiInd = (int)(vectorSize(matrix->PI) - 1);
    } else {
        nextRowPiInd = matrix->CIP->data[i + 1];
    }
    j++;
    for (;curRowPiInd != nextRowPiInd;curRowPiInd++) {
        if (matrix->PI->data[curRowPiInd] == (int)j) result = matrix->YE->data[curRowPiInd];
    }
    return result;
}

int matrixMultVector(Matrix *matrix, Vector *vector, Vector *result) {
    assert(matrix != NULL && vector != NULL && result != NULL && (int)vectorSize(vector) == matrix->m);
    vectorClear(result);
    int nonZeroCount = 0;
    int n = matrix->n;
    for (int i = 0;i < n;i++) {
        int curResult = 0;

        int curRowPiInd = matrix->CIP->data[i];
        int nextRowPiInd;
        if (i == (n - 1)) {
            nextRowPiInd = (int)(vectorSize(matrix->PI) - 1);
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

```

textmenu.h
```src:textmenu.h
#ifndef __TEXTMENU__
#define __TEXTMENU__

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#define COMMAND_LENGTH 40
#define DESCRIPTION_LENGTH 200

typedef void (*CommandHandler)(void*);
// Codestyle for handler names: handler_<handler-name-in-snake-case>
// Example: handler_print, handler_set_list
// Codestyle for creator/destroyer names: <creator/destroyer>_<name-of-data-structure>
// Default handlers
void handler_undefined();

typedef struct {
    char name[COMMAND_LENGTH];
    char description[DESCRIPTION_LENGTH];
    CommandHandler handler;
} Command;

typedef struct {
    Command *commands;
    int size, capacity;
} CommandStorage;

// CommandStorage interface ====

Command commandCreate(char *name, char *description, void (*handler)(void*));
CommandStorage *commandStorageCreate();
void commandStorageDestroy(CommandStorage *commandStorage);
void commandStoragePush(CommandStorage *commandStorage, Command binding);
void commandStorageClear(CommandStorage *commandStorage);

// \CommandStorage interface ===

// TextMenu interface ====

void textMenuDescript(CommandStorage *storage);
void textMenuMatch(CommandStorage *storage, void *obj, char *name);
void textMenuStart(CommandStorage *storage, void *obj);

// \TextMenu interface ===

// ===================== ||
// Wrapper               ||
// ===================== ||
// ! Use only if you have only one textMenu in your program.
// You also need initialize creator and destroyer functions.

// Order: name, description, handler
void textMenuFastInitialize(int commandCount, ...);
void textMenuFastStart(void *(*creator)(void), void (*destroyer)(void*));
void textMenuFastClose();

#endif

```

textmenu.c
```src:textmenu.c
#include "textmenu.h"

void handler_undefined() {
    printf("Undefined command\n");
}

// CommandStorage interface ====

Command commandCreate(char *name, char *description, void (*handler)(void*)) {
    Command result;
    strcpy(result.name, name);
    strcpy(result.description, description);
    result.handler = handler;
    return result;
}

CommandStorage *commandStorageCreate() {
    CommandStorage *result = malloc(sizeof(CommandStorage));
    result->size = 0;
    result->capacity = 1;
    result->commands = malloc(sizeof(Command));
    return result;
}

void commandStorageDestroy(CommandStorage *commandStorage) {
    assert(commandStorage != NULL);
    free(commandStorage->commands);
    free(commandStorage);
}

void commandStoragePush(CommandStorage *commandStorage, Command command) {
    assert(commandStorage != NULL);
    commandStorage->size++;
    if (commandStorage->size > commandStorage->capacity) {
        commandStorage->capacity *= 2;
        commandStorage->commands = realloc(commandStorage->commands, sizeof(Command) * commandStorage->capacity);
    }
    commandStorage->commands[commandStorage->size - 1] = command;
}

void commandStorageClear(CommandStorage *commandStorage) {
    assert(commandStorage != NULL);
    commandStorage->size = 0;
}

// \CommandStorage interface ===

// TextMenu interface ====

void textMenuDescript(CommandStorage *storage) {
    assert(storage != NULL);
    printf("You entered interactive mode. Here's the list of commands:\n");
    for (int i = 0;i < storage->size;i++) {
        printf("    %s\n", storage->commands[i].description);
    }
    printf("---------------\n    exit - exit program.\n");
}

void textMenuMatch(CommandStorage *storage, void *obj, char *name) {
    assert(storage != NULL && obj != NULL);
    for (int i = 0;i < storage->size;i++) {
        if (strcmp(name, storage->commands[i].name) == 0) {
            (*storage->commands[i].handler)(obj);
            return;
        }
    }
    handler_undefined();
}

void textMenuStart(CommandStorage *storage, void *obj) {
    assert(storage != NULL && obj != NULL);
    printf("Starting session\n");
    textMenuDescript(storage);
    char command[COMMAND_LENGTH];

    bool terminated = false;
    while (!terminated) {
        printf("> ");
        scanf("%s", command);
        // Exit checking
        if (strcmp("exit", command) == 0) {
            printf("Goodbye!\n");
            break;
        }
        textMenuMatch(storage, obj, command);
    }
}

// \TextMenu interface ===

// ===================== ||
// Macro Wrapper         ||
// ===================== ||

CommandStorage *__TEXTMENU_GLOBAL_STORAGE;

void textMenuFastInitialize(int commandCount, ...) {
    __TEXTMENU_GLOBAL_STORAGE = commandStorageCreate();

    va_list args;
    va_start(args, commandCount);

    for (int i = 0; i < commandCount; i++) {
        char *name = va_arg(args, char*);
        char *description = va_arg(args, char*);
        CommandHandler handler = va_arg(args, CommandHandler);
        Command command = commandCreate(name,
                                        description,
                                        handler);
        commandStoragePush(__TEXTMENU_GLOBAL_STORAGE, command);
    }

    va_end(args);
}

void textMenuFastStart(void *(*creator)(void), void (*destroyer)(void*)) {
    assert(__TEXTMENU_GLOBAL_STORAGE != NULL && (creator != NULL) && (destroyer != NULL));
    void *obj = (*creator)();
    textMenuStart(__TEXTMENU_GLOBAL_STORAGE, obj);
    (*destroyer)(obj);
}

void textMenuFastClose() {
    commandStorageDestroy(__TEXTMENU_GLOBAL_STORAGE);
    __TEXTMENU_GLOBAL_STORAGE = NULL;
}

```

Тестовые файлы:
t0.txt:
```
3 3
1 0 0
0 1 0
0 0 1
```

t1.txt:
```
6 6
1 2 0 0 0 0
0 0 500 0 0 0
1 0 1 0 1 0
0 0 0 0 0 0
0 0 0 0 0 -9
1 2 3 4 5 6
```

t2.txt:
```
3 5
1 1 0 0 0
0 0 -1 -1 0
56 0 0 0 100000
```

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.
<b>Подпись преподавателя:</b> _____________________

## 8. Распечатка протокола

```
pepelulka@pepelulka:~/Desktop/labs/repo/KP7/build/bin$ ./main
Starting session
You entered interactive mode. Here's the list of commands:
    load <filename> - loads matrix from file
    print - prints matrix
    print_raw - prints internal vectors of matrix
    set <i> <j> <value> - sets value on index (i, j)
    get <i> <j> - gets value on index (i, j)
    mult - multiply matrix by vector and prints number of non-zero elements in the result
---------------
    exit - exit program.
> load ../../data/t2.txt
Success
> print
1       1       0       0       0
0       0       -1      -1      0
56      0       0       0       100000
> mult
Enter vector:
1 1 1 0 1
Result vector: 2 -1 100056
Non-zero count: 3
> mult
Enter vector:
0 0 0 0 0
Result vector: 0 0 0
Non-zero count: 0
> set 2 1 15
> print
1       1       0       0       0
0       0       -1      -1      0
56      15      0       0       100000
> get 0 2
0
> get 2 0
56
> load ../../data/t1.txt
Success
> print
1       2       0       0       0       0
0       0       500     0       0       0
1       0       1       0       1       0
0       0       0       0       0       0
0       0       0       0       0       -9
1       2       3       4       5       6
> mult
Enter vector:
1 1 1 0 1 1
Result vector: 3 500 3 0 -9 17
Non-zero count: 5
> print_raw
Matrix 6x6
CIP: 0 2 3 6 6 7
PI: 1 2 3 1 3 5 6 1 2 3 4 5 6 0
YE: 1 2 500 1 1 1 -9 1 2 3 4 5 6
> load ../../data/t0.txt
Success
> print
1       0       0
0       1       0
0       0       1
> set 0 2 1
> print
1       0       1
0       1       0
0       0       1
> print_raw
Matrix 3x3
CIP: 0 2 3
PI: 1 3 2 3 0
YE: 1 1 1 1
> mult
Enter vector:
1 1 1
Result vector: 2 1 1
Non-zero count: 3
> exit
Goodbye!
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 15.06.23 | 13:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы

## 11. Выводы
Были получены навыки написания эффективных программ для обработки разреженных матриц. Были отработаны навыки работы с файлами, динамическими структурами и указателями в Си. Были получены навыки устранения утечек памяти с помощью Valgrind.

<b>Подпись студента:</b> _________________
