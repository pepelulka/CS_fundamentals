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
