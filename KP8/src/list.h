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
