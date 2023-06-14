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
