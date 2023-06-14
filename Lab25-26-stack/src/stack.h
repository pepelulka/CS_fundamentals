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
