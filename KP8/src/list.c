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
