# Отчёт по заданию №9 по курсовому проекту по циклу дисциплин «Информатика»

<b>Студент группы:</b> <ins>М80-108Б-22 Рамалданов Рустамхан Ражудинович, № по списку: 15</ins>

<b>Контакты e-mail:</b> <ins>mrpepelulka@gmail.com</ins>

<b>Работа выполнена:</b> «28» <ins>марта</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «28» <ins>марта</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ___________

## 1. Тема
Сортировка и поиск

## 2. Цель работы
Составить программу на языке Си с использованием процедур и функций для сортировки таблицы заданным методом
и двоичного поиска по ключу в таблице.

## 3. Задание (Вариант 15)
Программа должна вводить значения элементов неупорядоченной таблицы и проверять работу процедуры
сортировки в трех случаях: (1) элементы таблицы с самого начала упорядочены; (2) элементы таблицы расставлены в
обратном порядке; (3) элементы таблицы не упорядочены.

После выполнения сортировки программа должна вводить ключи и для каждого из них выполнять поиск в
упорядоченной таблице с помощью процедуры двоичного поиска и печатать найденные элементы, если они присутствуют в
таблице.

Метод сортировки: Естественное слияние.

Структура таблицы: тип ключа - строковый (5 байт), хранение ключа и данных - раздельно, минимальное число элементов
таблицы - 15.

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

## 6. Идея, метод, алгоритм решения:
Таблица хранится в текстовом файле, разделитель - ":". Таблица хранится в виде вектора пар ключ-значение.
Алгоритм сортировки естественным слиянием работает следующим образом: исходная последовательность разбивается на минимальное количество неубывающих отрезков. Далее каждая четная и
нечетная серии сливаются друг с другом, засчет чего формируется новая последовательность, минимальное количество неубывающих отрезков в которой стало вдвое меньше. Алгоритм
повторяется до тех пор, пока количество отрезков не станет равно единице. Для хранения разбиения последовательности на отрезки я использовал вектор указателей на таблицы.

## 7. Сценарий выполнения работы:

Makefile:
```
CC=gcc
LD=gcc
CCFLAGS=-Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors
LDFLAGS=
SOURCES=$(addprefix src/,main.c table.c textmenu.c)
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
```

table.h:
```src:table.h
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

```

table.c:
```src:table.c
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
    int current = 0; TableVector* heaps[2] = {tv1, tv2}; // For fast switching between two heaps
    for (size_t i = 1;i < table->size;i++) {
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
    if (table->size <= 1) return;
    TableVector *tv1 = tvCreate(), *tv2 = tvCreate();
    tableDivide(table, tv1, tv2);
    size_t value = (tv1->size + tv2->size);
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
        if (strcmp(table->data[mid].key, key) <= 0) l = mid;
        else r = mid;
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

```

textmenu.h:
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

textmenu.c:
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
t1.txt
```
app:░░░░░░░░░░░░░░░░░░░░░▄▀░░▌
bet:░░░░░░░░░░░░░░░░░░░▄▀▐░░░▌
can:░░░░░░░░░░░░░░░░▄▀▀▒▐▒░░░▌
did:░░░░░▄▀▀▄░░░▄▄▀▀▒▒▒▒▌▒▒░░▌
ear:░░░░▐▒░░░▀▄▀▒▒▒▒▒▒▒▒▒▒▒▒▒█
fat:░░░░▌▒░░░░▒▀▄▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄
gee:░░░░▐▒░░░░░▒▒▒▒▒▒▒▒▒▌▒▐▒▒▒▒▒▀▄
hit:░░░░▌▀▄░░▒▒▒▒▒▒▒▒▐▒▒▒▌▒▌▒▄▄▒▒▐
ice:░░░▌▌▒▒▀▒▒▒▒▒▒▒▒▒▒▐▒▒▒▒▒█▄█▌▒▒▌
joe:░▄▀▒▐▒▒▒▒▒▒▒▒▒▒▒▄▀█▌▒▒▒▒▒▀▀▒▒▐░░░
kor:▀▒▒▒▒▌▒▒▒▒▒▒▒▄▒▐███▌▄▒▒▒▒▒▒▒▄▀▀▀▀
lol:▒▒▒▒▒▐▒▒▒▒▒▄▀▒▒▒▀▀▀▒▒▒▒▄█▀░░▒▌▀▀▄
mom:▒▒▒▒▒▒█▒▄▄▀▒▒▒▒▒▒▒▒▒▒▒░░▐▒▀▄▀▄░░░░
non:▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▄▒▒▒▒▄▀▒▒▒▌░░▀▄
pea:▒▒▒▒▒▒▒▒▀▄▒▒▒▒▒▒▒▒▀▀▀▀▒▒▒▄▀
```

t2.txt
```
pea:▒▒▒▒▒▒▒▒▀▄▒▒▒▒▒▒▒▒▀▀▀▀▒▒▒▄▀
non:▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▄▒▒▒▒▄▀▒▒▒▌░░▀▄
mom:▒▒▒▒▒▒█▒▄▄▀▒▒▒▒▒▒▒▒▒▒▒░░▐▒▀▄▀▄░░░░
lol:▒▒▒▒▒▐▒▒▒▒▒▄▀▒▒▒▀▀▀▒▒▒▒▄█▀░░▒▌▀▀▄
kor:▀▒▒▒▒▌▒▒▒▒▒▒▒▄▒▐███▌▄▒▒▒▒▒▒▒▄▀▀▀▀
joe:░▄▀▒▐▒▒▒▒▒▒▒▒▒▒▒▄▀█▌▒▒▒▒▒▀▀▒▒▐░░░
ice:░░░▌▌▒▒▀▒▒▒▒▒▒▒▒▒▒▐▒▒▒▒▒█▄█▌▒▒▌
hit:░░░░▌▀▄░░▒▒▒▒▒▒▒▒▐▒▒▒▌▒▌▒▄▄▒▒▐
gee:░░░░▐▒░░░░░▒▒▒▒▒▒▒▒▒▌▒▐▒▒▒▒▒▀▄
fat:░░░░▌▒░░░░▒▀▄▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄
ear:░░░░▐▒░░░▀▄▀▒▒▒▒▒▒▒▒▒▒▒▒▒█
did:░░░░░▄▀▀▄░░░▄▄▀▀▒▒▒▒▌▒▒░░▌
can:░░░░░░░░░░░░░░░░▄▀▀▒▐▒░░░▌
bet:░░░░░░░░░░░░░░░░░░░▄▀▐░░░▌
app:░░░░░░░░░░░░░░░░░░░░░▄▀░░▌
```

t3.txt
```
fat:░░░░▌▒░░░░▒▀▄▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄
bet:░░░░░░░░░░░░░░░░░░░▄▀▐░░░▌
app:░░░░░░░░░░░░░░░░░░░░░▄▀░░▌
did:░░░░░▄▀▀▄░░░▄▄▀▀▒▒▒▒▌▒▒░░▌
ear:░░░░▐▒░░░▀▄▀▒▒▒▒▒▒▒▒▒▒▒▒▒█
can:░░░░░░░░░░░░░░░░▄▀▀▒▐▒░░░▌
non:▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▄▒▒▒▒▄▀▒▒▒▌░░▀▄
gee:░░░░▐▒░░░░░▒▒▒▒▒▒▒▒▒▌▒▐▒▒▒▒▒▀▄
pea:▒▒▒▒▒▒▒▒▀▄▒▒▒▒▒▒▒▒▀▀▀▀▒▒▒▄▀
ice:░░░▌▌▒▒▀▒▒▒▒▒▒▒▒▒▒▐▒▒▒▒▒█▄█▌▒▒▌
joe:░▄▀▒▐▒▒▒▒▒▒▒▒▒▒▒▄▀█▌▒▒▒▒▒▀▀▒▒▐░░░
lol:▒▒▒▒▒▐▒▒▒▒▒▄▀▒▒▒▀▀▀▒▒▒▒▄█▀░░▒▌▀▀▄
kor:▀▒▒▒▒▌▒▒▒▒▒▒▒▄▒▐███▌▄▒▒▒▒▒▒▒▄▀▀▀▀
hit:░░░░▌▀▄░░▒▒▒▒▒▒▒▒▐▒▒▒▌▒▌▒▄▄▒▒▐
mom:▒▒▒▒▒▒█▒▄▄▀▒▒▒▒▒▒▒▒▒▒▒░░▐▒▀▄▀▄░░░░
```

## 8. Распечатка протокола

```
pepelulka@pepelulka:~/Desktop/labs/repo/KP9/build/bin$ ./main
Starting session
You entered interactive mode. Here's the list of commands:
    print - prints table
    load <filename> - loads table from file
    sort - sorts table
    search <key> - binary search in sorted(!) table
---------------
    exit - exit program.
> load ../../data/t1.txt
Success
> print
app:░░░░░░░░░░░░░░░░░░░░░▄▀░░▌
bet:░░░░░░░░░░░░░░░░░░░▄▀▐░░░▌
can:░░░░░░░░░░░░░░░░▄▀▀▒▐▒░░░▌
did:░░░░░▄▀▀▄░░░▄▄▀▀▒▒▒▒▌▒▒░░▌
ear:░░░░▐▒░░░▀▄▀▒▒▒▒▒▒▒▒▒▒▒▒▒█
fat:░░░░▌▒░░░░▒▀▄▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄
gee:░░░░▐▒░░░░░▒▒▒▒▒▒▒▒▒▌▒▐▒▒▒▒▒▀▄
hit:░░░░▌▀▄░░▒▒▒▒▒▒▒▒▐▒▒▒▌▒▌▒▄▄▒▒▐
ice:░░░▌▌▒▒▀▒▒▒▒▒▒▒▒▒▒▐▒▒▒▒▒█▄█▌▒▒▌
joe:░▄▀▒▐▒▒▒▒▒▒▒▒▒▒▒▄▀█▌▒▒▒▒▒▀▀▒▒▐░░░
kor:▀▒▒▒▒▌▒▒▒▒▒▒▒▄▒▐███▌▄▒▒▒▒▒▒▒▄▀▀▀▀
lol:▒▒▒▒▒▐▒▒▒▒▒▄▀▒▒▒▀▀▀▒▒▒▒▄█▀░░▒▌▀▀▄
mom:▒▒▒▒▒▒█▒▄▄▀▒▒▒▒▒▒▒▒▒▒▒░░▐▒▀▄▀▄░░░░
non:▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▄▒▒▒▒▄▀▒▒▒▌░░▀▄
pea:▒▒▒▒▒▒▒▒▀▄▒▒▒▒▒▒▒▒▀▀▀▀▒▒▒▄▀
> sort
> print
app:░░░░░░░░░░░░░░░░░░░░░▄▀░░▌
bet:░░░░░░░░░░░░░░░░░░░▄▀▐░░░▌
can:░░░░░░░░░░░░░░░░▄▀▀▒▐▒░░░▌
did:░░░░░▄▀▀▄░░░▄▄▀▀▒▒▒▒▌▒▒░░▌
ear:░░░░▐▒░░░▀▄▀▒▒▒▒▒▒▒▒▒▒▒▒▒█
fat:░░░░▌▒░░░░▒▀▄▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄
gee:░░░░▐▒░░░░░▒▒▒▒▒▒▒▒▒▌▒▐▒▒▒▒▒▀▄
hit:░░░░▌▀▄░░▒▒▒▒▒▒▒▒▐▒▒▒▌▒▌▒▄▄▒▒▐
ice:░░░▌▌▒▒▀▒▒▒▒▒▒▒▒▒▒▐▒▒▒▒▒█▄█▌▒▒▌
joe:░▄▀▒▐▒▒▒▒▒▒▒▒▒▒▒▄▀█▌▒▒▒▒▒▀▀▒▒▐░░░
kor:▀▒▒▒▒▌▒▒▒▒▒▒▒▄▒▐███▌▄▒▒▒▒▒▒▒▄▀▀▀▀
lol:▒▒▒▒▒▐▒▒▒▒▒▄▀▒▒▒▀▀▀▒▒▒▒▄█▀░░▒▌▀▀▄
mom:▒▒▒▒▒▒█▒▄▄▀▒▒▒▒▒▒▒▒▒▒▒░░▐▒▀▄▀▄░░░░
non:▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▄▒▒▒▒▄▀▒▒▒▌░░▀▄
pea:▒▒▒▒▒▒▒▒▀▄▒▒▒▒▒▒▒▒▀▀▀▀▒▒▒▄▀
> search lol
lol:▒▒▒▒▒▐▒▒▒▒▒▄▀▒▒▒▀▀▀▒▒▒▒▄█▀░░▒▌▀▀▄
> search pepe
There's no such key in the table
> load ../../data/t2.txt
Success
> print
pea:▒▒▒▒▒▒▒▒▀▄▒▒▒▒▒▒▒▒▀▀▀▀▒▒▒▄▀
non:▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▄▒▒▒▒▄▀▒▒▒▌░░▀▄
mom:▒▒▒▒▒▒█▒▄▄▀▒▒▒▒▒▒▒▒▒▒▒░░▐▒▀▄▀▄░░░░
lol:▒▒▒▒▒▐▒▒▒▒▒▄▀▒▒▒▀▀▀▒▒▒▒▄█▀░░▒▌▀▀▄
kor:▀▒▒▒▒▌▒▒▒▒▒▒▒▄▒▐███▌▄▒▒▒▒▒▒▒▄▀▀▀▀
joe:░▄▀▒▐▒▒▒▒▒▒▒▒▒▒▒▄▀█▌▒▒▒▒▒▀▀▒▒▐░░░
ice:░░░▌▌▒▒▀▒▒▒▒▒▒▒▒▒▒▐▒▒▒▒▒█▄█▌▒▒▌
hit:░░░░▌▀▄░░▒▒▒▒▒▒▒▒▐▒▒▒▌▒▌▒▄▄▒▒▐
gee:░░░░▐▒░░░░░▒▒▒▒▒▒▒▒▒▌▒▐▒▒▒▒▒▀▄
fat:░░░░▌▒░░░░▒▀▄▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄
ear:░░░░▐▒░░░▀▄▀▒▒▒▒▒▒▒▒▒▒▒▒▒█
did:░░░░░▄▀▀▄░░░▄▄▀▀▒▒▒▒▌▒▒░░▌
can:░░░░░░░░░░░░░░░░▄▀▀▒▐▒░░░▌
bet:░░░░░░░░░░░░░░░░░░░▄▀▐░░░▌
app:░░░░░░░░░░░░░░░░░░░░░▄▀░░▌
> sort
> print
app:░░░░░░░░░░░░░░░░░░░░░▄▀░░▌
bet:░░░░░░░░░░░░░░░░░░░▄▀▐░░░▌
can:░░░░░░░░░░░░░░░░▄▀▀▒▐▒░░░▌
did:░░░░░▄▀▀▄░░░▄▄▀▀▒▒▒▒▌▒▒░░▌
ear:░░░░▐▒░░░▀▄▀▒▒▒▒▒▒▒▒▒▒▒▒▒█
fat:░░░░▌▒░░░░▒▀▄▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄
gee:░░░░▐▒░░░░░▒▒▒▒▒▒▒▒▒▌▒▐▒▒▒▒▒▀▄
hit:░░░░▌▀▄░░▒▒▒▒▒▒▒▒▐▒▒▒▌▒▌▒▄▄▒▒▐
ice:░░░▌▌▒▒▀▒▒▒▒▒▒▒▒▒▒▐▒▒▒▒▒█▄█▌▒▒▌
joe:░▄▀▒▐▒▒▒▒▒▒▒▒▒▒▒▄▀█▌▒▒▒▒▒▀▀▒▒▐░░░
kor:▀▒▒▒▒▌▒▒▒▒▒▒▒▄▒▐███▌▄▒▒▒▒▒▒▒▄▀▀▀▀
lol:▒▒▒▒▒▐▒▒▒▒▒▄▀▒▒▒▀▀▀▒▒▒▒▄█▀░░▒▌▀▀▄
mom:▒▒▒▒▒▒█▒▄▄▀▒▒▒▒▒▒▒▒▒▒▒░░▐▒▀▄▀▄░░░░
non:▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▄▒▒▒▒▄▀▒▒▒▌░░▀▄
pea:▒▒▒▒▒▒▒▒▀▄▒▒▒▒▒▒▒▒▀▀▀▀▒▒▒▄▀
> search pea
pea:▒▒▒▒▒▒▒▒▀▄▒▒▒▒▒▒▒▒▀▀▀▀▒▒▒▄▀
> search polo
There's no such key in the table
> load ../../data/t3.txt
Success
> print
fat:░░░░▌▒░░░░▒▀▄▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄
bet:░░░░░░░░░░░░░░░░░░░▄▀▐░░░▌
app:░░░░░░░░░░░░░░░░░░░░░▄▀░░▌
did:░░░░░▄▀▀▄░░░▄▄▀▀▒▒▒▒▌▒▒░░▌
ear:░░░░▐▒░░░▀▄▀▒▒▒▒▒▒▒▒▒▒▒▒▒█
can:░░░░░░░░░░░░░░░░▄▀▀▒▐▒░░░▌
non:▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▄▒▒▒▒▄▀▒▒▒▌░░▀▄
gee:░░░░▐▒░░░░░▒▒▒▒▒▒▒▒▒▌▒▐▒▒▒▒▒▀▄
pea:▒▒▒▒▒▒▒▒▀▄▒▒▒▒▒▒▒▒▀▀▀▀▒▒▒▄▀
ice:░░░▌▌▒▒▀▒▒▒▒▒▒▒▒▒▒▐▒▒▒▒▒█▄█▌▒▒▌
joe:░▄▀▒▐▒▒▒▒▒▒▒▒▒▒▒▄▀█▌▒▒▒▒▒▀▀▒▒▐░░░
lol:▒▒▒▒▒▐▒▒▒▒▒▄▀▒▒▒▀▀▀▒▒▒▒▄█▀░░▒▌▀▀▄
kor:▀▒▒▒▒▌▒▒▒▒▒▒▒▄▒▐███▌▄▒▒▒▒▒▒▒▄▀▀▀▀
hit:░░░░▌▀▄░░▒▒▒▒▒▒▒▒▐▒▒▒▌▒▌▒▄▄▒▒▐
mom:▒▒▒▒▒▒█▒▄▄▀▒▒▒▒▒▒▒▒▒▒▒░░▐▒▀▄▀▄░░░░
> sort
> print
app:░░░░░░░░░░░░░░░░░░░░░▄▀░░▌
bet:░░░░░░░░░░░░░░░░░░░▄▀▐░░░▌
can:░░░░░░░░░░░░░░░░▄▀▀▒▐▒░░░▌
did:░░░░░▄▀▀▄░░░▄▄▀▀▒▒▒▒▌▒▒░░▌
ear:░░░░▐▒░░░▀▄▀▒▒▒▒▒▒▒▒▒▒▒▒▒█
fat:░░░░▌▒░░░░▒▀▄▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄
gee:░░░░▐▒░░░░░▒▒▒▒▒▒▒▒▒▌▒▐▒▒▒▒▒▀▄
hit:░░░░▌▀▄░░▒▒▒▒▒▒▒▒▐▒▒▒▌▒▌▒▄▄▒▒▐
ice:░░░▌▌▒▒▀▒▒▒▒▒▒▒▒▒▒▐▒▒▒▒▒█▄█▌▒▒▌
joe:░▄▀▒▐▒▒▒▒▒▒▒▒▒▒▒▄▀█▌▒▒▒▒▒▀▀▒▒▐░░░
kor:▀▒▒▒▒▌▒▒▒▒▒▒▒▄▒▐███▌▄▒▒▒▒▒▒▒▄▀▀▀▀
lol:▒▒▒▒▒▐▒▒▒▒▒▄▀▒▒▒▀▀▀▒▒▒▒▄█▀░░▒▌▀▀▄
mom:▒▒▒▒▒▒█▒▄▄▀▒▒▒▒▒▒▒▒▒▒▒░░▐▒▀▄▀▄░░░░
non:▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▄▒▒▒▒▄▀▒▒▒▌░░▀▄
pea:▒▒▒▒▒▒▒▒▀▄▒▒▒▒▒▒▒▒▀▀▀▀▒▒▒▄▀
> search hit
hit:░░░░▌▀▄░░▒▒▒▒▒▒▒▒▐▒▒▒▌▒▌▒▄▄▒▒▐
> exit
Goodbye!
```

## 9. Замечания автора по существу работы

Замечаний нет.

## 10.Вывод работы:
Были получены базовые представления о внутренней работе баз данных и таблиц с информацией. Были изучены новый метод сортировки, алгоритм бинарного поиска. Получено более глубокое понимание механизмов выделения памяти в C.

<b>Подпись студента:</b> ________________
