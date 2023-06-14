# Отчёт по лабораторным работам №25-26 по курсу “Языки и методы программирования”

<b>Студент группы:</b> <ins>М80-108Б-22 Рамалданов Рустамхан Ражудинович, № по списку: 15</ins>

<b>Контакты e-mail:</b> <ins>mrpepelulka@gmail.com</ins>

<b>Работа выполнена:</b> «28» <ins>марта</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «28» <ins>марта</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ___________


## 1. Тема
Автоматизация сборки программ модульной структуры на языке Си с использованием утилиты make. Абстрактные типы данных. Рекурсия. Модульное программирование на языке Си.
## 2. Цель работы
Составить и отладить модуль определений и модуль реализации по заданной схее модуля определений для абстрактного (пользовательского) типа данных (стека, очереди, списка или дека, в зависимости от варианта задания). Составить программный модуль, сортирующий экземляр указанного абстрактного типа данных заданным методом, используя только операции, импортированные из модуля UUDT. Использовать утилиту make.
## 3. Задание (вариант № 15)
Тип данных: стек

Процедура: слияние двух стеков, отсортированных по возрастанию, с сохранением порядка.

Метод: сортировка слиянием.

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

Сначала был реализована структура данных стек, описан базовый интерфейс взаимодействия со структурой. Стек был реализован над динамическим массивом.
Далее были написаны вспомогательные функции, например, для разворота стека.
Далее в отдельном файле были реализованы особая процедура, которая была дана в условии, и сортировка данным в условии методом.

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию].

Makefile
```
CC=gcc
LD=gcc
CCFLAGS=-Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors
LDFLAGS=
SOURCES=$(addprefix src/,main.c stack.c stack_algo.c textmenu.c)
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

main.c
```src:main.c
#include "stack.h"
#include "stack_algo.h"
#include "textmenu.h"

// C & D
void *creator_Stack() {
    Stack *stack = stackCreate();
    return (void*)stack;
}

void destroyer_Stack(void *obj) {
    Stack *stack = (Stack*)obj;
    stackDestroy(stack);
}

// Handlers
void handler_print(void *obj) {
    Stack *stack = (Stack*)obj;
    //
    stackPrint(stack);
}

void handler_push(void *obj) {
    Stack *stack = (Stack*)obj;
    //
    int value;
    scanf("%d", &value);
    stackPush(stack, value);
}

void handler_top(void *obj) {
    Stack *stack = (Stack*)obj;
    //
    printf("%d\n", stackTop(stack));
}

void handler_pop(void *obj) {
    Stack *stack = (Stack*)obj;
    //
    printf("%d\n", stackPop(stack));
}


void handler_clear(void *obj) {
    Stack *stack = (Stack*)obj;
    //
    stackClear(stack);
}

void handler_size(void *obj) {
    Stack *stack = (Stack*)obj;
    //
    printf("%d\n", stackSize(stack));
}

void handler_sort(void *obj) {
    Stack *stack = (Stack*)obj;
    //
    stackMergeSort(stack);
}

int main() {
    textMenuFastInitialize(7,
                           "print", "print - prints stack", handler_print,
                           "size", "size - prints size of stack", handler_size,
                           "clear", "clear - clears stack", handler_clear,
                           "top", "top - prints top element", handler_top,
                           "pop", "pop - pops top element", handler_pop,
                           "push", "push - pushes element on the top", handler_push,
                           "sort", "sort - sorts stack", handler_sort);
    textMenuFastStart(creator_Stack, destroyer_Stack);
    textMenuFastClose();
}
```

stack.h
```src:stack.h
#ifndef __STACK__
#define __STACK__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

typedef struct {
    int size, capacity;
    int *data;
} Stack;

// Stack interface ====

Stack *stackCreate();
void stackDestroy(Stack *stack);
int stackTop(Stack *stack);
int stackPop(Stack *stack);
void stackPush(Stack *stack, int value);
void stackClear(Stack *stack);
int stackSize(Stack *stack);
bool stackEmpty(Stack *stack);
void stackPrint(Stack *stack);
void stackMove(Stack *destination, Stack *stack);

// \Stack interface ===

#endif

```

stack.c
```src:stack.c
#include "stack.h"

// Stack interface ====

// Private

void stackDoubleCapacity(Stack *stack) {
    stack->capacity *= 2;
    stack->data = realloc(stack->data, sizeof(int) * stack->capacity);
}

void stackExpand(Stack *stack) {
    stack->size++;
    if (stack->size > stack->capacity) stackDoubleCapacity(stack);
}

//

Stack *stackCreate() {
    Stack *stack = malloc(sizeof(Stack));
    stack->size = 0;
    stack->capacity = 1;
    stack->data = malloc(sizeof(int));
    return stack;
}

void stackDestroy(Stack *stack) {
    if (stack == NULL) return;
    free(stack->data);
    free(stack);
}

int stackTop(Stack *stack) {
    assert(stack != NULL && stack->size > 0);
    return stack->data[stack->size - 1];
}

int stackPop(Stack *stack) {
    assert(stack != NULL && stack->size > 0);
    int result = stackTop(stack);
    stack->size--;
    return result;
}

void stackPush(Stack *stack, int value) {
    assert(stack != NULL);
    stackExpand(stack);
    stack->data[stack->size - 1] = value;
}

void stackClear(Stack *stack) {
    assert(stack != NULL);
    stack->size = 0;
}

int stackSize(Stack *stack) {
    assert(stack != NULL);
    return stack->size;
}

bool stackEmpty(Stack *stack) {
    assert(stack != NULL);
    return (stackSize(stack) == 0);
}

void stackPrint(Stack *stack) {
    assert(stack != NULL);
    for (int i = 0;i < stack->size;i++) {
        printf("%d ", stack->data[i]);
    }
    putchar('\n');
}

void stackMove(Stack *destination, Stack *stack) {
    free(destination->data);
    *destination = *stack;
    free(stack);
}

// \Stack interface ===
```

stack_algo.h
```src:stack_algo.h
#include "stack.h"

// Memory safe.
void stackReverse(Stack *stack);

// stack1 & stack2 should be sorted !
// Destroys stack1 & stack2 !
// Creates new stack
Stack *stackMerge(Stack *stack1, Stack *stack2);

// Memory safe
void stackMergeSort(Stack *stack);

```

stack_algo.c
```src:stack_algo.c
#include "stack_algo.h"

void stackReverse(Stack *stack) {
    Stack *result = stackCreate();
    while (!stackEmpty(stack)) stackPush(result, stackPop(stack));
    stackMove(stack, result);
}

Stack *stackMerge(Stack *stack1, Stack *stack2) {
    Stack *result = stackCreate();
    while (!stackEmpty(stack1) || !stackEmpty(stack2)) {
        if (stackEmpty(stack1)) stackPush(result, stackPop(stack2));
        else if (stackEmpty(stack2)) stackPush(result, stackPop(stack1));
        else {
            if (stackTop(stack1) > stackTop(stack2)) {
                stackPush(result, stackPop(stack1));
            } else {
                stackPush(result, stackPop(stack2));
            }
        }
    }
    stackDestroy(stack1); stackDestroy(stack2);
    stackReverse(result);
    return result;
}

void stackMergeSort(Stack *stack) {
    assert(stack != NULL);
    int n = stackSize(stack);
    if (n == 1 || n == 0) return ;
    Stack *left = stackCreate(), *right = stackCreate();
    for (int i = 0;i < (n / 2);i++) {
        stackPush(left, stackPop(stack));
    }
    while (!stackEmpty(stack)) stackPush(right, stackPop(stack));

    stackMergeSort(left);
    stackMergeSort(right);

    stackMove(stack, stackMerge(left, right));
}

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

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.
<b>Подпись преподавателя:</b> _____________________

## 8. Распечатка протокола

```
pepelulka@pepelulka:~/Desktop/labs/repo/Lab25-26-stack$ build/bin/main
Starting session
You entered interactive mode. Here's the list of commands:
    print - prints stack
    size - prints size of stack
    clear - clears stack
    top - prints top element
    pop - pops top element
    push - pushes element on the top
    sort - sorts stack
---------------
    exit - exit program.
> push 3
> push 5
> push -1
> push 20
> print
3 5 -1 20
> sort
> print
-1 3 5 20
> push 11
> push 12
> push -9
> print
-1 3 5 20 11 12 -9
> sort
> print
-9 -1 3 5 11 12 20
> size
7
> top
20
> pop
20
> print
-9 -1 3 5 11 12
> exit
Goodbye!
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 15.06.23 | 18:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы

<b>Div 2</b>

[1841A](https://codeforces.com/contest/1841/submission/209416384)
[1841B](https://codeforces.com/contest/1841/submission/209426102)

## 11. Выводы
Были изучены различные абстрактные типы данных. Был составлен программный модуль, сортирующий экземпляр указанного типа данных заданным методом на языке Си. Также была изучена утилита make. В результате выполнения работы, были приобретены навыки, которые будут полезны для выполнения других лабораторных работ и курсовых проектов.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> _________________

