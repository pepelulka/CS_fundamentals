# Отчёт по лабораторной работе №23 по курсу “Языки и методы программирования”

<b>Студент группы:</b> <ins>М80-108Б-22 Рамалданов Рустамхан Ражудинович, № по списку: 15</ins>

<b>Контакты e-mail:</b> <ins>mrpepelulka@gmail.com</ins>

<b>Работа выполнена:</b> «28» <ins>марта</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «28» <ins>марта</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ___________

## 1. Тема
Динамические структуры данных. Обработка деревьев
## 2. Цель работы
Составить программу на Си для интерактивного взаимодействия с двоичным деревом поиска.
## 3. Задание (вариант № 15)
Проверить, находятся ли все листья двоичного дерева но одном уровне.

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

Двоичное дерево поиска было реализовано с помощью динамических структур. Каждая вершина представляла собой структуру, содержащую значение узла и указатели на родителя, левого и
правого детей.

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию].

main.c:
```src:main.c
#include "textmenu.h"
#include "tree.h"

// C & D
void *creator_Tree() {
    Tree *tree = treeCreate();
    return (void*)tree;
}

void destroyer_Tree(void *obj) {
    Tree *tree = (Tree*)obj;
    treeDestroy(tree);
}

// Handlers
void handler_print(void *obj) {
    Tree *tree = (Tree*)obj;
    //
    treePrint(tree);
}

void handler_insert(void *obj) {
    Tree *tree = (Tree*)obj;
    //
    float value;
    scanf("%f", &value);
    treeInsert(tree, value);
}

void handler_erase(void *obj) {
    Tree *tree = (Tree*)obj;
    //
    float value;
    scanf("%f", &value);
    treeErase(tree, value);
}

void handler_func(void *obj) {
    Tree *tree = (Tree*)obj;
    //
    if (treeFunc(tree)) printf("True\n");
    else printf("False\n");
}

void handler_simple_print(void *obj) {
    Tree *tree = (Tree*)obj;
    //
    treeSimplePrint(tree);
}

int main() {
    textMenuFastInitialize(5,
                           "print", "print - prints tree", handler_print,
                           "simple_print", "simple_print - prints tree (simplier)", handler_simple_print,
                           "insert", "insert <value> - inserts value in tree", handler_insert,
                           "erase", "erase <value> - erases value in tree", handler_erase,
                           "func", "func - compute special function", handler_func);
    textMenuFastStart(creator_Tree, destroyer_Tree);
    textMenuFastClose();
}
```


tree.h:
```src:tree.h
#ifndef __TREE__
#define __TREE__

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct _TreeNode {
    float value;
    struct _TreeNode *left, *right, *parent;
} TreeNode;

typedef struct {
    TreeNode *root;
} Tree;

// TreeNode interface ====

TreeNode *treeNodeCreate(float value);
void treeNodeDestroy(TreeNode *node);
void treeNodeDestroySubtree(TreeNode *node);
void treeNodeInsert(TreeNode *node, TreeNode *parent, TreeNode *newNode);

// Returns -1 if has various depths.
int treeNodeDepth(TreeNode *node);

// \TreeNode interface ===

// Tree interface ====

Tree *treeCreate();
void treeDestroy(Tree *tree);
void treeInsert(Tree *tree, float value);
void treeErase(Tree *tree, float value);
bool treeFunc(Tree *tree);

// \Tree interface ===

// Tree Print

#define TREE_PRINT_SHIFT 4

void treePrint(Tree *tree);
void treeSimplePrint(Tree *tree);

//

#endif

```

tree.c:
```src:tree.c
#include "tree.h"
#include "tree_print.h"

// TreeNode interface ====

TreeNode *treeNodeCreate(float value) {
    TreeNode *result = malloc(sizeof(TreeNode));
    result->left = NULL;
    result->right = NULL;
    result->parent = NULL;
    result->value = value;
    return result;
}

void treeNodeDestroy(TreeNode *node) {
    if (node == NULL) return;
    free(node);
}

void treeNodeDestroySubtree(TreeNode *node) {
    if (node != NULL) {
        treeNodeDestroySubtree(node->left);
        treeNodeDestroySubtree(node->right);
    }
    treeNodeDestroy(node);
}

void treeNodeInsert(TreeNode *node, TreeNode *parent, TreeNode *newNode) {
    if (newNode == NULL) return ;
    if (node == NULL) {
        if (newNode->value > parent->value) parent->right = newNode;
        else parent->left = newNode;
        newNode->parent = parent;
    } else {
        if (newNode->value > node->value) treeNodeInsert(node->right, node, newNode);
        else treeNodeInsert(node->left, node, newNode);
    }
}

int treeNodeDepth(TreeNode *node) {
    if (node == NULL) return 0;
    int left = treeNodeDepth(node->left), right = treeNodeDepth(node->right);
    if (left != right || left == -1 || right == -1) return -1;
    return left + 1;
}

// \TreeNode interface ===

// Tree interface ====

Tree *treeCreate() {
    Tree *result = malloc(sizeof(Tree));
    result->root = NULL;
    return result;
}

void treeDestroy(Tree *tree) {
    if (tree != NULL) {
        treeNodeDestroySubtree(tree->root);
        free(tree);
    }
}

void treeInsert(Tree *tree, float value) {
    assert(tree != NULL);
    TreeNode *node = treeNodeCreate(value);
    if (tree->root == NULL) tree->root = node;
    else treeNodeInsert(tree->root, NULL, node);
}

void treeErase(Tree *tree, float value) {
    assert(tree != NULL);
    if (tree->root == NULL) return ;
    if (tree->root->value == value) {
        TreeNode *oldRoot = tree->root;
        if (tree->root->right == NULL) tree->root = tree->root->left;
        else if (tree->root->left == NULL) tree->root = tree->root->right;
        else {
            tree->root = tree->root->right;
            treeNodeInsert(tree->root, NULL, oldRoot->left);
        }
        treeNodeDestroy(oldRoot);
    } else {
        TreeNode *current = tree->root;
        while (current != NULL && current->value != value) {
            if (value > current->value) current = current->right;
            else current = current->left;
        }
        if (current == NULL) return;
        TreeNode *oldNode = current;
        if (current->right == NULL) current = current->left;
        else if (current->left == NULL) current = current->right;
        else {
            current = current->right;
            treeNodeInsert(current, NULL, oldNode->left);
            current->parent = oldNode->parent;
        }
        if (oldNode->value > oldNode->parent->value) oldNode->parent->right = current;
        else oldNode->parent->left = current;
        treeNodeDestroy(oldNode);
    }
}

bool treeFunc(Tree *tree) {
    assert(tree != NULL);
    return treeNodeDepth(tree->root) != -1;
}

void treeNodeSimplePrint(TreeNode *node, int shift) {
    if (node == NULL) return;
    treeNodeSimplePrint(node->left, shift + TREE_PRINT_SHIFT);
    for (int i = 0;i < shift;i++) putchar(' ');
    printf("%.3f", node->value);
    putchar('\n');
    treeNodeSimplePrint(node->right, shift + TREE_PRINT_SHIFT);
}


// \Tree interface ===

// Tree Print

char *valueAccessor(void *obj) {
    TreeNode *node = (TreeNode*)obj;
    char *result = malloc(sizeof(char) * 10);
    gcvt (node->value, 3, result);
    return result;
}

void *leftChildAccessor(void *obj) {
    TreeNode *node = (TreeNode*)obj;
    return (void*)(node->left);
}

void *rightChildAccessor(void *obj) {
    TreeNode *node = (TreeNode*)obj;
    return (void*)(node->right);
}

void treePrint(Tree *tree) {
    if (tree == NULL) return;
    if (tree->root == NULL) return;
    treePrintUniversal((void*)tree->root,
                       valueAccessor,
                       leftChildAccessor,
                       rightChildAccessor);
}

void treeSimplePrint(Tree *tree) {
    if (tree != NULL) treeNodeSimplePrint(tree->root, 0);
}

//
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

tree_print.h:
```src:tree_print.h
#pragma once

#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// ================
// Tree print
// ================

#define MAX_STRING_LENGTH 200

typedef struct _TextChunkNode {
    char *str;
    struct _TextChunkNode *next;
} TextChunkNode;

// Представление для прямоугольного куска текста. Хранит в себе односвязный список строк.
typedef struct {
    int rootIndex;
    int rowCount;
    int columnCount;
    TextChunkNode *first, *last;
} TextChunk;

// === String functions ===

char* intToString(int val, int base);

char *stringGenerate(char c, int n);

void stringConcatenate(char *str1, char *str2);

char *stringGenerateCell(char *str);

// ========================\ String functions

// === TextChunk interface ===

TextChunkNode *TextChunkNodeCreate();

TextChunk *textChunkCreate();

// Result in chunk1
void textChunkAdd(TextChunk *chunk1, TextChunk *chunk2);

// Result in chunk1
void textChunkConcatenate(TextChunk *chunk1, TextChunk *chunk2);

TextChunk *textChunkGenerateBlank(int n, int m);

TextChunkNode *textChunkGet(TextChunk *chunk, int index);

void textChunkPush(TextChunk *chunk, char *str);

void textChunkComplement(TextChunk *chunk, int n);

void textChunkEven(TextChunk *chunk1, TextChunk *chunk2);

void textChunkPrint(TextChunk *chunk);

void textChunkNodeDestroy(TextChunkNode *node);

void textChunkDestroy(TextChunk *chunk);

// ===========================\ TextChunk interface

#define SUBTREE_SPACING 1 // Must be odd
#define CELL_LENGTH 7 // Must be odd

TextChunk *treeGenerateTextChunkForSubtree(void *node,
                                           char *(*valueAccessor)(void*),
                                           void *(*leftChildAccessor)(void*),
                                           void *(*rightChildAccessor)(void*));

// valueAccessor must return unsafe string.
void treePrintUniversal(void *node,
                        char *(*valueAccessor)(void*),
                        void *(*leftChildAccessor)(void*),
                        void *(*rightChildAccessor)(void*));

```

tree_print.c:
```src:tree_print.c
#include "tree_print.h"

// ================
// Tree print
// ================

// === String functions ===

char* intToString(int val, int base) {
	static char buf[32] = {0};
    if (val == 0) {
        buf[0] = '0';
        buf[1] = '\0';
        return buf;
    }
	int i = 30;
	for(; val && i ; --i, val /= base)
		buf[i] = "0123456789abcdef"[val % base];
	return &buf[i+1];
}

// Returns unsafe string
char *stringGenerate(char c, int n) {
    char *result = malloc(sizeof(char) * (n + 1));
    if (n <= 0) {
        result[0] = '\0';
        return result;
    }
    for (int i = 0; i < n; i++) {
        result[i] = c;
    }
    result[n] = '\0';
    return result;
}

void stringConcatenate(char *str1, char *str2) {
    int ptr1 = 0, ptr2 = 0;
    while (str1[ptr1] != '\0') ptr1++;
    while (str2[ptr2] != '\0') {
        str1[ptr1] = str2[ptr2];
        ptr1++; ptr2++;
    }
    str1[ptr1] = '\0';
}

// Returns unsafe string
char *stringGenerateCell(char *str) {
    char *result = malloc(sizeof(char) * (CELL_LENGTH + 1));
    char curResult[20];
    curResult[0] = '\0';
    result[0] = '\0';
    stringConcatenate(curResult, str);
    int numberLength = strlen(curResult);
    int diff = CELL_LENGTH - numberLength;
    assert(diff >= 0);

    // Helping strings
    char *s1 = stringGenerate(' ', diff / 2);
    char *s2 = stringGenerate(' ', diff / 2 + 1);
    //

    if (diff % 2 == 0) {
        stringConcatenate(result, s1);
        stringConcatenate(result, curResult);
        stringConcatenate(result, s1);
    } else {
        stringConcatenate(result, s1);
        stringConcatenate(result, curResult);
        stringConcatenate(result, s2);
    }
    free(s1); free(s2);
    return result;
}

// ========================\ String functions

// === TextChunk interface ===

TextChunkNode *TextChunkNodeCreate() {
    TextChunkNode *node = malloc(sizeof(TextChunkNode));
    node->str = malloc(sizeof(char) * MAX_STRING_LENGTH);
    node->str[0] = '\0';
    node->next = NULL;
}


TextChunk *textChunkCreate() {
    TextChunk *chunk = malloc(sizeof(TextChunk));
    chunk->rowCount = 0;
    chunk->columnCount = 0;
    chunk->first = NULL;
    chunk->last = NULL;
    return chunk;
}

void textChunkAdd(TextChunk *chunk1, TextChunk *chunk2) {
    assert(chunk1 != NULL && chunk2 != NULL);
    assert(chunk1->rowCount == chunk2->rowCount);
    if (chunk1->rowCount == 0) return;
    TextChunkNode *node1 = chunk1->first, *node2 = chunk2->first;
    while (node1 != NULL) {
        stringConcatenate(node1->str, node2->str);

        node1 = node1->next; node2 = node2->next;
    }
    chunk1->columnCount += chunk2->columnCount;
}

void textChunkConcatenate(TextChunk *chunk1, TextChunk *chunk2) {
    assert(chunk1 != NULL && chunk2 != NULL);
    if (chunk1->rowCount == 0) {
        chunk1->first = chunk2->first;
        chunk1->last = chunk2->last;
    } else {
        chunk1->last->next = chunk2->first;
        if (chunk2->last != NULL) chunk1->last = chunk2->last;
    }
    chunk1->rowCount += chunk2->rowCount;
}

TextChunk *textChunkGenerateBlank(int n, int m) {
    TextChunk *result = textChunkCreate();
    char *sm = stringGenerate(' ', m);
    for (int i = 0;i < n;i++) {
        textChunkPush(result, sm);
    }
    free(sm);
    return result;
}

TextChunkNode *textChunkGet(TextChunk *chunk, int index) {
    assert(index < chunk->rowCount);
    TextChunkNode *node = chunk->first;
    while (index--) node = node->next;
    return node;
}

void textChunkPush(TextChunk *chunk, char *str) {
    assert(chunk != NULL);
    TextChunkNode *node = TextChunkNodeCreate();
    stringConcatenate(node->str, str);
    if (chunk->rowCount == 0) {
        chunk->first = node;
        chunk->last = node;
        chunk->rowCount = 1;
        chunk->columnCount = strlen(str);
    } else {
        assert(strlen(str) == chunk->columnCount);
        chunk->last->next = node;
        chunk->last = node;
        chunk->rowCount++;
    }
}

void textChunkComplement(TextChunk *chunk, int n) {
    assert(chunk != NULL);
    if (chunk->rowCount < n) {
        TextChunk *blank = textChunkGenerateBlank(n - chunk->rowCount, chunk->columnCount);
        textChunkConcatenate(chunk, blank);
        free(blank);
    }
}

void textChunkEven(TextChunk *chunk1, TextChunk *chunk2) {
    textChunkComplement(chunk1, chunk2->rowCount);
    textChunkComplement(chunk2, chunk1->rowCount);
}

void textChunkPrint(TextChunk *chunk) {
    assert(chunk != NULL);
    TextChunkNode *node = chunk->first;
    while (node != NULL) {
        printf("%s\n", node->str);
        node = node->next;
    }
    printf("\n");
}

void textChunkNodeDestroy(TextChunkNode *node) {
    assert(node != NULL);
    free(node->str);
    free(node);
}

void textChunkDestroy(TextChunk *chunk) {
    assert(chunk != NULL);
    if (chunk->first == NULL) {
        free(chunk);
        return;
    }
    TextChunkNode *node, *next;
    node = chunk->first;
    while (node != NULL) {
        next = node->next;
        textChunkNodeDestroy(node);
        node = next;
    }
    free(chunk);
}

// =========================== \TextChunk interface

TextChunk *treeGenerateTextChunkForSubtree(void *node,
                                           char *(*valueAccessor)(void*),
                                           void *(*leftChildAccessor)(void*),
                                           void *(*rightChildAccessor)(void*)) {
    assert(node != NULL);
    char *value = valueAccessor(node);
    if (leftChildAccessor(node) == NULL && rightChildAccessor(node) == NULL) {
        TextChunk *chunk = textChunkCreate();
        char *cellStr = stringGenerateCell(value);
        chunk->rootIndex = strlen(cellStr) / 2;
        textChunkPush(chunk, cellStr);
        free(cellStr); free(value);
        return chunk;
    } else if (rightChildAccessor(node) == NULL) {
        TextChunk *lChunk = treeGenerateTextChunkForSubtree(leftChildAccessor(node),
                                                            valueAccessor,
                                                            leftChildAccessor,
                                                            rightChildAccessor);
        TextChunk *spaceChunk = textChunkGenerateBlank(lChunk->rowCount, SUBTREE_SPACING);
        TextChunk *rChunk = textChunkGenerateBlank(lChunk->rowCount, lChunk->columnCount);

        int subtreeWidth = lChunk->columnCount;
        int spaceWidth = SUBTREE_SPACING;
        int allWidth = 2 * subtreeWidth + spaceWidth;

        textChunkAdd(lChunk, spaceChunk);
        textChunkAdd(lChunk, rChunk);

        textChunkDestroy(spaceChunk);
        textChunkDestroy(rChunk);

        char *str1 = malloc(sizeof(char) * (allWidth + 1));
        char *str2 = malloc(sizeof(char) * (allWidth + 1));
        str1[0] = '\0'; str2[0] = '\0';
        // stringConcatenate(str2, s5);
        // stringConcatenate(str2, "|");
        // stringConcatenate(str2, s6);

        // Helping
        char *s1 = stringGenerate(' ', (allWidth - CELL_LENGTH) / 2);
        char *s2 = stringGenerateCell(value);
        char *s3 = stringGenerate(' ', subtreeWidth / 2);
        char *s4 = stringGenerate('-', subtreeWidth / 2);
        char *s5 = stringGenerate(' ', spaceWidth / 2);
        char *s6 = stringGenerate(' ', subtreeWidth + (spaceWidth / 2));
        //

        // str1
        stringConcatenate(str1, s1);
        stringConcatenate(str1, s2);
        stringConcatenate(str1, s1);

        // str2
        stringConcatenate(str2, s3);
        stringConcatenate(str2, "|");
        stringConcatenate(str2, s4);
        stringConcatenate(str2, s5);
        stringConcatenate(str2, "+");
        stringConcatenate(str2, s6);

        int rootIndex = strlen(s3) + 1 + strlen(s4) + strlen(s5);

        free(s1); free(s2); free(s3); free(s4); free(s5); free(s6);

        TextChunk *header = textChunkCreate();
        textChunkPush(header, str1);
        textChunkPush(header, str2);

        textChunkConcatenate(header, lChunk); // lChunk is alive !!!

        header->rootIndex = rootIndex;
        free(lChunk);
        free(str1); free(str2); free(value);
        return header;
    } else if (leftChildAccessor(node) == NULL) {
        TextChunk *rChunk = treeGenerateTextChunkForSubtree(rightChildAccessor(node),
                                                            valueAccessor,
                                                            leftChildAccessor,
                                                            rightChildAccessor);
        TextChunk *lChunk = textChunkGenerateBlank(rChunk->rowCount, rChunk->columnCount);
        TextChunk *spaceChunk = textChunkGenerateBlank(rChunk->rowCount, SUBTREE_SPACING);

        int subtreeWidth = rChunk->columnCount;
        int spaceWidth = SUBTREE_SPACING;
        int allWidth = 2 * subtreeWidth + spaceWidth;

        textChunkAdd(lChunk, spaceChunk);
        textChunkAdd(lChunk, rChunk);

        textChunkDestroy(spaceChunk);
        textChunkDestroy(rChunk);

        char *str1 = malloc(sizeof(char) * (allWidth + 1));
        char *str2 = malloc(sizeof(char) * (allWidth + 1));
        str1[0] = '\0'; str2[0] = '\0';

        // Helping
        char *s1 = stringGenerate(' ', (allWidth - CELL_LENGTH) / 2);
        char *s2 = stringGenerateCell(value);
        char *s3 = stringGenerate(' ', subtreeWidth / 2);
        char *s5 = stringGenerate('-', spaceWidth / 2 + subtreeWidth / 2);
        char *s6 = stringGenerate(' ', subtreeWidth + (spaceWidth / 2));
        //

        // str1
        stringConcatenate(str1, s1);
        stringConcatenate(str1, s2);
        stringConcatenate(str1, s1);

        // str2
        stringConcatenate(str2, s6);
        stringConcatenate(str2, "+");
        stringConcatenate(str2, s5);
        stringConcatenate(str2, "|");
        stringConcatenate(str2, s3);

        int rootIndex = strlen(s6);

        free(s1); free(s2); free(s3); free(s5); free(s6);

        TextChunk *header = textChunkCreate();
        textChunkPush(header, str1);
        textChunkPush(header, str2);

        textChunkConcatenate(header, lChunk); // lChunk is alive!!!
        header->rootIndex = rootIndex;

        free(lChunk);
        free(str1); free(str2); free(value);
        return header;
    } else {
        TextChunk *rChunk = treeGenerateTextChunkForSubtree(rightChildAccessor(node),
                                                            valueAccessor,
                                                            leftChildAccessor,
                                                            rightChildAccessor);
        TextChunk *lChunk = treeGenerateTextChunkForSubtree(leftChildAccessor(node),
                                                            valueAccessor,
                                                            leftChildAccessor,
                                                            rightChildAccessor);

        textChunkEven(lChunk, rChunk);

        TextChunk *spaceChunk = textChunkGenerateBlank(lChunk->rowCount, SUBTREE_SPACING);

        int leftWidth = lChunk->columnCount;
        int spaceWidth = SUBTREE_SPACING;
        int rightWidth = rChunk->columnCount;
        int allWidth = leftWidth + spaceWidth + rightWidth;
        int lRootIndex = lChunk->rootIndex;
        int rRootIndex = rChunk->rootIndex;


        textChunkAdd(lChunk, spaceChunk);
        textChunkAdd(lChunk, rChunk);

        textChunkDestroy(spaceChunk);
        textChunkDestroy(rChunk);

        char *str1 = malloc(sizeof(char) * (allWidth + 1));
        char *str2 = malloc(sizeof(char) * (allWidth + 1));
        str1[0] = '\0'; str2[0] = '\0';

        // Helping
        char *s1 = stringGenerate(' ', (leftWidth + spaceWidth / 2 - CELL_LENGTH / 2));
        char *s2 = stringGenerate(' ', (rightWidth + spaceWidth / 2 - CELL_LENGTH / 2));
        char *s3 = stringGenerate(' ', lRootIndex);
        char *s4 = stringGenerate('-', leftWidth + spaceWidth / 2 - lRootIndex - 1);
        char *s5 = stringGenerate('-', leftWidth + spaceWidth + rRootIndex - (leftWidth + spaceWidth / 2 + 1));
        char *s6 = stringGenerate(' ', rightWidth - rRootIndex - 1);
        char *s7 = stringGenerateCell(value);
        //

        // str1
        stringConcatenate(str1, s1);
        stringConcatenate(str1, s7);
        stringConcatenate(str1, s2);

        // str2
        stringConcatenate(str2, s3);
        stringConcatenate(str2, "|");
        stringConcatenate(str2, s4);
        stringConcatenate(str2, "+");
        stringConcatenate(str2, s5);
        stringConcatenate(str2, "|");
        stringConcatenate(str2, s6);

        int rootIndex = strlen(s3) + 1 + strlen(s4);

        free(s1); free(s2); free(s3); free(s4); free(s5); free(s6); free(s7);

        TextChunk *header = textChunkCreate();
        textChunkPush(header, str1);
        textChunkPush(header, str2);

        textChunkConcatenate(header, lChunk); // lChunk is alive!!!
        header->rootIndex = rootIndex;

        free(lChunk);
        free(str1); free(str2); free(value);
        return header;
    }
}

void treePrintUniversal(void *node,
                        char *(*valueAccessor)(void*),
                        void *(*leftChildAccessor)(void*),
                        void *(*rightChildAccessor)(void*)) {
    TextChunk *chunk = treeGenerateTextChunkForSubtree(node, valueAccessor, leftChildAccessor, rightChildAccessor);
    textChunkPrint(chunk);
    textChunkDestroy(chunk);
}

```

Makefile:
```
CC=gcc
LD=gcc
CCFLAGS=-Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors
LDFLAGS=
SOURCES=$(addprefix src/,main.c textmenu.c tree_print.c tree.c)
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

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.
<b>Подпись преподавателя:</b> _____________________

## 8. Распечатка протокола
```
pepelulka@pepelulka:~/Desktop/labs/repo/Lab23-tree$ build/bin/main
Starting session
You entered interactive mode. Here's the list of commands:
    print - prints tree
    simple_print - prints tree (simplier)
    insert <value> - inserts value in tree
    erase <value> - erases value in tree
    func - compute special function
---------------
    exit - exit program.
> insert 3
> insert 2
> insert 4.5
> print
       3
   |---+---|
   2      4.5

> simple_print
    2.000
3.000
    4.500
> func
True
> insert 10
> print
       3
   |---+-------|
   2          4.5
               +---|
                  10

> func
False
> erase 4.5
> print
       3
   |---+---|
   2      10

> simple_print
    2.000
3.000
    10.000
> func
True
> exit
Goodbye!
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 12.06.23 | 18:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы

Замечаний нет.

## 11. Выводы
Были изучены динамические структуры данных. Была составлена программа на языке Си для обработки двоичного дерева. Были приобретены навыки, которые будут полезны для выполнения других лабораторных работ и курсовых проектов.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> _________________

