#include "tree_print.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

// Constants ===

#define VARIABLE_MAX_LENGTH 50
#define TREE_PRINT_SHIFT 4

// Statuses for expression validation
#define STATUS_OK 0
#define STATUS_ERROR -1

// =============

typedef enum {
    BLANK,
    INTEGER,
    VARIABLE,
    BRACKETS_OPEN,
    BRACKETS_CLOSE,
    OPERATION_PLUS,
    OPERATION_MINUS,
    OPERATION_MULT,
    OPERATION_DIVIDE
} TokenType;

// "abc + ( meow + c )"
// "abc", "+", "meow", "+", "c" - токены
// Переменная, число, операции, скобки
//

typedef struct {
    TokenType type;
    int value; // If type == INTEGER
    char name[VARIABLE_MAX_LENGTH]; // If type == VARIABLE
} Token;

// Node of AST Tree
typedef struct _TreeNode {
    Token token;
    struct _TreeNode *left, *right;
    bool finished; // Used for tree build
} TreeNode;

// AST Tree
typedef struct {
    TreeNode *root;
} Tree;

// Node of stack of AstTreeNodes
typedef struct _TNStackNode {
    struct _TNStackNode *previous;
    TreeNode *value;
} TNStackNode;

// Stack of AstTreeNodes
typedef struct {
    size_t size;
    TNStackNode *last;
} TNStack;

// ================================================================================
// ================================================= Declaration part over ========
// ================================================================================

// Util ===

bool tokenTypeIsOperation(TokenType type);
void tokenPrint(Token token);
char *tokenGetValue(Token token);

// ========

// TreeNode interface ===

TreeNode *treeNodeCreate();
void treeNodeDestroy(TreeNode *node);
void treeNodeDestroySubtree(TreeNode *node);
void treeNodeSimplePrintSubtree(TreeNode *node, int shift);

// =========================

// Tree interface ===

Tree *treeCreate();
void treeDestroy(Tree *tree);
void treeSimplePrint(Tree *tree);
void treePrint(Tree *tree);

// =====================

// Stack interface ===

TNStackNode *tnStackNodeCreate();
void tnStackNodeDestroy(TNStackNode *node);

TNStack *tnStackCreate();
void tnStackDestroy(TNStack *stack);

void tnStackPush(TNStack *stack, TreeNode *value);
size_t tnStackSize(TNStack *stack);
bool tnStackEmpty(TNStack *stack);
TreeNode *tnStackTop(TNStack *stack);
void tnStackSetTop(TNStack *stack, TreeNode *node);
TreeNode *tnStackPop(TNStack *stack);

// ===================

// Parser ===

// ! Status
int parseUnit(char *unit, Token *resultToken);
void parseUtilPlaceMostRightNull(TNStackNode *stackNode, TreeNode *placingNode);
void parseUtilPriorityEmplacement(TNStackNode *stackNode, TreeNode *operationNode);
void parseUtilUnpriorityEmplacement(TNStackNode *stackNode, TreeNode *operationNode);

int parseFromStdin(Tree **resultTree);

// ==========

// Tree to string expression ===

void tokenConvertToStdout(Token token);
void treeNodeSubtreeConvertToStdout(TreeNode *node, bool isRoot);
void treeConvertToStdout(Tree *tree);

// =============================

// ||======||
// ||      ||
// ||      ||
// ||======||

// Special function:

void treeRemoveMultOne(Tree *tree);
