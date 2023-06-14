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