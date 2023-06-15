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