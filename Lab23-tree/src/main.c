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