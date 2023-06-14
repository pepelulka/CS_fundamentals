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