# Отчёт по курсовой работе №8 по курсу “Языки и методы программирования”

<b>Студент группы:</b> <ins>М80-108Б-22 Рамалданов Рустамхан Ражудинович, № по списку: 15</ins>

<b>Контакты e-mail:</b> <ins>mrpepelulka@gmail.com</ins>

<b>Работа выполнена:</b> «28» <ins>марта</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «28» <ins>марта</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ___________


## 1. Тема
Линейные списки
## 2. Цель работы
Составить и отладить программу на языке Си для обработки линейного списа заданной организации с отображением списка на динамические структуры, содержащего узлы типа int. Навигацию по списку следует реализовать с применением итераторов.
## 3. Задание (вариант № 15)
- Тип элемента спика: целый
- Вид списка: линейный однонаправленный
- Нестандартное действие: удалить из середины списка k элементов

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

Реализуется однонаправленный линейный список с отображением на динамические структуры. Структура узла списка хранит в себе значение в узле и указатель на следующий узел. В структуре списка хранятся указатель на первую вершину и на "последнюю". Во всех списках последняя вершина не является элементов самого списка, а лишь обозначает конец списка. Сделано это для
удобства реализации итераторов. Итераторы реализованы как структура, хранящая в себе указатель на список и вершину списка.

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию].

Makefile
```
CC=gcc
LD=gcc
CCFLAGS=-Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors
LDFLAGS=
SOURCES=$(addprefix src/,main.c list.c textmenu.c)
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
#include "list.h"
#include "textmenu.h"

// C & D
void *creator_List() {
    List *list = listCreate();
    return (void*)list;
}

void destroyer_List(void *obj) {
    List *list = (List*)obj;
    listDestroy(list);
}

// handlers
void handler_print(void *obj) {
    List *list = (List*)obj;
    //
    listPrint(list);
}

void handler_size(void *obj) {
    List *list = (List*)obj;
    //
    printf("%lu\n", listSize(list));
}

void handler_erase(void *obj) {
    List *list = (List*)obj;
    //
    size_t ind;
    scanf("%lu", &ind);
    ListIterator it = listIteratorBegin(list);
    if (ind >= listSize(list)) printf("There's no such index in list\n");
    else {
        for (size_t i = 0;i < ind;i++) listIteratorNext(&it);
        listErase(&it);
        printf("Success\n");
    }
}

void handler_insert(void *obj) {
    List *list = (List*)obj;
    //
    size_t ind;
    int value;
    scanf("%lu %d", &ind, &value);
    ListIterator it = listIteratorBegin(list);
    if (ind > listSize(list)) printf("There's no such index in list\n");
    else {
        for (size_t i = 0;i < ind;i++) listIteratorNext(&it);
        listInsert(&it, value);
        printf("Success\n");
    }
}

void handler_push(void *obj) {
    List *list = (List*)obj;
    //
    int value;
    scanf("%d", &value);
    listPushBack(list, value);
}

void handler_pop(void *obj) {
    List *list = (List*)obj;
    //
    if (listSize(list) == 0) {
        printf("List is empty");
    } else printf("%d\n", listPopBack(list));
}

void handler_push_front(void *obj) {
    List *list = (List*)obj;
    //
    int value;
    scanf("%d", &value);
    listPushFront(list, value);
}

void handler_pop_front(void *obj) {
    List *list = (List*)obj;
    //
    if (listSize(list) == 0) {
        printf("List is empty");
    } else printf("%d\n", listPopFront(list));
}

void handler_middle_erase(void *obj) {
    List *list = (List*)obj;
    //
    size_t k;
    scanf("%lu", &k);
    listRemoveInTheMiddle(list, k);
}

int main() {
    textMenuFastInitialize(9,
                           "print", "print - prints list", handler_print,
                           "size", "size - prints size of the list", handler_size,
                           "erase", "erase <ind> - erases element on index", handler_erase,
                           "insert", "insert <ind> <value> - inserts value before index", handler_insert,
                           "push", "push <value> - pushes in the back", handler_push,
                           "pop", "pop - pops in the back", handler_pop,
                           "push_front", "push_front <value> - pushes value in the front", handler_push_front,
                           "pop_front", "pop_front - pops value in the front", handler_pop_front,
                           "middle_erase", "middle_erase <k> - erases k elements in the middle", handler_middle_erase);
    textMenuFastStart(creator_List, destroyer_List);
    textMenuFastClose();
}
```

list.h
```src:list.h
#ifndef __LIST__
#define __LIST__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct _ListNode {
    int value;
    struct _ListNode *next;
} ListNode;

// List's last->next is pointing on ListNode of last element in the list. If it's NULL, list is empty
typedef struct {
    ListNode *first, *last;
    size_t size;
} List;

typedef struct {
    List *list;
    ListNode *node;
} ListIterator;

// ListIterator interface ====

ListIterator listIteratorBegin(List *list);
ListIterator listIteratorEnd(List *list);
ListIterator *listIteratorNext(ListIterator *it);
int listIteratorGet(ListIterator *it);
bool listIteratorSet(ListIterator *it, int value);
bool listIteratorEqual(ListIterator *lhs, ListIterator *rhs);
size_t listIteratorDistance(ListIterator it1, ListIterator it2);

// \ListIterator interface ===

// List interface ====

List *listCreate();
void listDestroy(List *list);

size_t listSize(List *list);
void listClear(List *list);
void listPushBack(List *list, int value);
void listPushFront(List *list, int value);
int listBack(List *list);
int listFront(List *list);
int listPopBack(List *list);
int listPopFront(List *list);
void listErase(ListIterator *it);
void listEraseRange(ListIterator *it1, ListIterator *it2);
// Inserts before "it"
void listInsert(ListIterator *it, int value);

void listRemoveInTheMiddle(List *list, size_t k);
void listPrint(List *list);

// \List interface ===

#endif

```

list.c
```src:list.c
#include "list.h"

// Private ( %%%%%%%%%%%%%%%%%% )


// ListNode interface
ListNode *listNodeCreate(int value) {
    ListNode *node = malloc(sizeof(ListNode));
    node->next = NULL;
    node->value = value;
    return node;
}

void listNodeDestroy(ListNode *node) {
    if (node == NULL) return;
    free(node);
}

void listNodeDestroyForward(List *list, ListNode *node) {
    if (node != NULL && list != NULL && node != list->last) listNodeDestroyForward(list, node->next);
    listNodeDestroy(node);
}

void listNodeDestroyStop(ListNode *node, ListNode *stop) {
    if (node == stop) return;
    listNodeDestroyStop(node->next, stop);
    listNodeDestroy(node);
}

void listEraseRangeIndex(List *list, size_t i1, size_t i2) {
    assert(list != NULL);
    assert(i1 < list->size && i2 <= list->size);
    ListIterator it1 = listIteratorBegin(list), it2 = listIteratorBegin(list);
    for (size_t k = 0;k < i1;k++) listIteratorNext(&it1);
    for (size_t k = 0;k < i2;k++) listIteratorNext(&it2);
    listEraseRange(&it1, &it2);
}

// ( %%%%%%%%%%%%%%%%%%%%%%%%%% )

// ListIterator interface ====

ListIterator listIteratorBegin(List *list) {
    return (ListIterator) { .node = list->first, .list = list };
}

ListIterator listIteratorEnd(List *list) {
    return (ListIterator) { .node = list->last, .list = list };
}

ListIterator *listIteratorNext(ListIterator *it) {
    assert (it->node != it->list->last);
    it->node = it->node->next;
    return it;
}

int listIteratorGet(ListIterator *it) {
    assert (it->node != it->list->last);
    return it->node->value;
}

// Statusable
bool listIteratorSet(ListIterator *it, int value) {
    if (it->node == it->list->last) return false;
    it->node->value = value;
    return true;
}

bool listIteratorEqual(ListIterator *lhs, ListIterator *rhs) {
    return (lhs->list == rhs->list) && (lhs->node == rhs->node);
}

size_t listIteratorDistance(ListIterator it1, ListIterator it2) {
    assert(it1.list == it2.list);
    size_t result = 0;
    while (!listIteratorEqual(&it1, &it2)) {
        listIteratorNext(&it1);
        result++;
    }
    return result;
}

// \ListIterator interface ===

// List interface ====

List *listCreate() {
    List *list = malloc(sizeof(List));
    list->first = listNodeCreate(0);
    list->last = list->first;
    list->size = 0;
    return list;
}

void listDestroy(List *list) {
    if (list == NULL) return;
    listNodeDestroyForward(list, list->first);
    free(list);
}

size_t listSize(List *list) {
    assert(list != NULL);
    return list->size;
}

void listClear(List *list) {
    assert(list != NULL);
    list->size = 0;
    listNodeDestroyForward(list, list->first);
    list->first = listNodeCreate(0);
    list->last = list->first;
}

void listPushBack(List *list, int value) {
    assert(list != NULL);
    ListNode *node = listNodeCreate(value);
    if (list->size == 0) {
        list->first = node;
        list->first->next = list->last;
        list->last->next = node;
    } else {
        node->next = list->last;
        list->last->next->next = node;
        list->last->next = node;
    }
    list->size++;
}

void listPushFront(List *list, int value) {
    assert(list != NULL);
    ListNode *node = listNodeCreate(value);
    if (list->size == 0) {
        list->first = node;
        list->first->next = list->last;
        list->last->next = node;
    } else {
        node->next = list->first;
        list->first = node;
    }
    list->size++;
}

int listBack(List *list) {
    assert(list != NULL && list->size != 0);
    return list->last->next->value;
}

int listFront(List *list) {
    assert(list != NULL && list->size != 0);
    return list->first->value;
}

int listPopBack(List *list) {
    assert(list != NULL && list->size != 0);
    int result = listBack(list);
    if (list->size == 1) {
        ListNode *temp = list->first;
        list->first = list->last;
        list->last->next = NULL;
        listNodeDestroy(temp);
    } else {
        ListNode *temp;
        ListNode *pre_last = list->first;
        while (pre_last->next->next != list->last) pre_last = pre_last->next;
        temp = list->last->next;
        pre_last->next = list->last;
        list->last->next = pre_last;
        listNodeDestroy(temp);
    }
    list->size--;
    return result;
}

int listPopFront(List *list) {
    assert(list != NULL && list->size != 0);
    int result = listFront(list);
    if (list->size == 1) {
        ListNode *temp = list->first;
        list->first = list->last;
        list->last->next = NULL;
        listNodeDestroy(temp);
    } else {
        ListNode *temp = list->first;
        list->first = list->first->next;
        listNodeDestroy(temp);
    }
    list->size--;
    return result;
}

void listErase(ListIterator *it) {
    assert(it != NULL);
    assert(it->node != it->list->last);
    if (it->node == it->list->first) {
        listPopFront(it->list);
    } else {
        ListIterator pre_it = listIteratorBegin(it->list), to_it = listIteratorBegin(it->list);
        while (!listIteratorEqual(&to_it, it)) {
            pre_it = to_it;
            listIteratorNext(&to_it);
        }
        pre_it.node->next = it->node->next;
        listNodeDestroy(it->node);
        it->list->size--;
    }
}

void listEraseRange(ListIterator *it1, ListIterator *it2) {
    assert(it1 != NULL && it2 != NULL);
    assert(it1->node != it1->list->last);
    assert(it1->list == it2->list);
    List *list = it1->list;
    if (it1->node == it1->list->first) {
        if (it2->node == it2->list->last) listClear(list);
        else {
            ListNode *temp1 = list->first, *temp2 = it2->node;
            list->first = it2->node;
            list->size -= listIteratorDistance(*it1, *it2);
            listNodeDestroyStop(temp1, temp2);
        }
    } else {
        if (it2->node == it2->list->last) {
            ListIterator pre_it = listIteratorBegin(it1->list), to_it = listIteratorBegin(it1->list);
            while (!listIteratorEqual(&to_it, it1)) {
                pre_it = to_it;
                listIteratorNext(&to_it);
            }
            it1->list->last->next = pre_it.node;
            ListNode *temp1 = it1->node, *temp2 = list->last;
            pre_it.node->next = it1->list->last;
            list->size -= listIteratorDistance(*it1, *it2);
            listNodeDestroyStop(temp1, temp2);
        } else {
            // When there're no border
            ListIterator pre_it = listIteratorBegin(it1->list), to_it = listIteratorBegin(it1->list);
            while (!listIteratorEqual(&to_it, it1)) {
                pre_it = to_it;
                listIteratorNext(&to_it);
            }
            ListNode *temp1 = it1->node, *temp2 = it2->node;
            list->size -= listIteratorDistance(*it1, *it2);
            pre_it.node->next = it2->node;
            listNodeDestroyStop(temp1, temp2);
        }
    }
}


void listInsert(ListIterator *it, int value) {
    assert(it != NULL);
    if (it->node == it->list->first) listPushFront(it->list, value);
    else if (it->node == it->list->last) listPushBack(it->list, value);
    else {
        ListIterator pre_it = listIteratorBegin(it->list), to_it = listIteratorBegin(it->list);
        while (!listIteratorEqual(&to_it, it)) {
            pre_it = to_it;
            listIteratorNext(&to_it);
        }
        ListNode *newNode = listNodeCreate(value);
        pre_it.node->next = newNode;
        newNode->next = it->node;
        it->list->size++;
    }
}

void listPrint(List *list) {
    assert(list != NULL);
    for (ListIterator it = listIteratorBegin(list), end = listIteratorEnd(list);!listIteratorEqual(&it, &end);listIteratorNext(&it)) {
        printf("%d ", listIteratorGet(&it));
    }
    printf("\n");
}

void listRemoveInTheMiddle(List *list, size_t k) {
    if (k >= list->size) listClear(list);
    else {
        size_t i1, i2;
        if (list->size % 2 == 0 && k % 2 == 0) {
            i1 = (list->size - k) / 2;
            i2 = list->size - i1;
        } else if (list->size % 2 == 0 && k % 2 != 0) {
            i1 = (list->size - k) / 2;
            i2 = list->size - i1;
            i1++;
        } else if (list->size % 2 != 0 && k % 2 == 0) {
            i1 = (list->size - k) / 2;
            i2 = list->size - i1;
            i1++;
        } else {
            i1 = (list->size - k) / 2;
            i2 = list->size - i1;
        }
        listEraseRangeIndex(list, i1, i2);
    }
}

// \List interface ===


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
Starting session
You entered interactive mode. Here's the list of commands:
    print - prints list
    size - prints size of the list
    erase <ind> - erases element on index
    insert <ind> <value> - inserts value before index
    push <value> - pushes in the back
    pop - pops in the back
    push_front <value> - pushes value in the front
    pop_front - pops value in the front
    middle_erase <k> - erases k elements in the middle
---------------
    exit - exit program.
> push 1
> push 2
> push 3
> push 4
> push 5
> push 6
> print
1 2 3 4 5 6
> pop_front
1
> pop
6
> print
2 3 4 5
> push_front 1
> push_back 6
Undefined command
> Undefined command
> push 6
> print
1 2 3 4 5 6
> middle_erase 4
> print
1 6
> insert 1 2
Success
> print
1 2 6
> middle_erase 1
> print
1 6
> exit
Goodbye!
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 16.05.23 | 1:30 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы

## 11. Выводы
Была составлена программа на языке Си для обработки линейного списка заданной организации с отображением на динамические структуры и написана процедура для выполнения нестандартного действия по номеру варианта. Были получены навыки написания итераторов для структур данных, изучен принцип их работы. Были приобретены навыки, которые будут полезны для выполнения других лабораторных работ и курсовых проектов.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> _________________

