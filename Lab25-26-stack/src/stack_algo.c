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
