#include "tree.h"

// Util ===

bool tokenTypeIsOperation(TokenType type) {
    return type >= OPERATION_PLUS;
}

void tokenPrint(Token token) {
    switch (token.type) {
        case INTEGER:
            printf("%d", token.value);
            break;
        case VARIABLE:
            printf("%s", token.name);
            break;
        case OPERATION_PLUS:
            printf("+");
            break;
        case OPERATION_MINUS:
            printf("-");
            break;
        case OPERATION_MULT:
            printf("*");
            break;
        case OPERATION_DIVIDE:
            printf("/");
            break;
        case BRACKETS_OPEN:
            printf("(");
            break;
        case BRACKETS_CLOSE:
            printf(")");
            break;
        case BLANK:
            break;
    }
}

char *tokenGetValue(Token token) {
    char *s = malloc(sizeof(char) * (VARIABLE_MAX_LENGTH + 1));
    switch (token.type) {
        case INTEGER:
            strcpy(s, intToString(token.value, 10));
            break;
        case VARIABLE:
            strcpy(s, token.name);
            return s;
            break;
        case OPERATION_PLUS:
            s[0] = '+'; s[1] = '\0';
            return s;
            break;
        case OPERATION_MINUS:
            s[0] = '-'; s[1] = '\0';
            return s;
            break;
        case OPERATION_MULT:
            s[0] = '*'; s[1] = '\0';
            return s;
            break;
        case OPERATION_DIVIDE:
            s[0] = '/'; s[1] = '\0';
            return s;
            break;
        case BRACKETS_OPEN:
            s[0] = '('; s[1] = '\0';
            return s;
            break;
        case BRACKETS_CLOSE:
            s[0] = ')'; s[1] = '\0';
            return s;
            break;
        case BLANK:
            s[0] = '\0';
            return s;
            break;
    }
    return s;
}

// ========

// AstNodeTree interface ===

TreeNode *treeNodeCreate() {
    TreeNode *result = malloc(sizeof(TreeNode));
    result->left = NULL;
    result->right = NULL;
    result->finished = false;
    return result;
}

void treeNodeDestroy(TreeNode *node) {
    if (node != NULL) {
        free(node);
    }
}

void treeNodeDestroySubtree(TreeNode *node) {
    if (node != NULL) {
        treeNodeDestroySubtree(node->left);
        treeNodeDestroySubtree(node->right);
        treeNodeDestroy(node);
    }
}

void treeNodeSimplePrintSubtree(TreeNode *node, int shift) {
    if (node == NULL) return;
    treeNodeSimplePrintSubtree(node->left, shift + TREE_PRINT_SHIFT);
    for (int i = 0;i < shift;i++) putchar(' ');
    tokenPrint(node->token);
    putchar('\n');
    treeNodeSimplePrintSubtree(node->right, shift + TREE_PRINT_SHIFT);
}

// =========================

// Tree interface ===

Tree *treeCreate() {
    Tree *tree = malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

void treeDestroy(Tree *tree) {
    if (tree != NULL) {
        treeNodeDestroySubtree(tree->root);
        free(tree);
    }
}

void treeSimplePrint(Tree *tree) {
    assert(tree != NULL);
    treeNodeSimplePrintSubtree(tree->root, 0);
}

// Tree Print

char *valueAccessor(void *obj) {
    TreeNode *node = (TreeNode*)obj;
    //
    return tokenGetValue(node->token);
}

void *leftChildAccessor(void *obj) {
    TreeNode *node = (TreeNode*)obj;
    //
    return (void*)node->left;
}

void *rightChildAccessor(void *obj) {
    TreeNode *node = (TreeNode*)obj;
    //
    return (void*)node->right;
}

void treePrint(Tree *tree) {
    assert(tree != NULL);
    if (tree->root == NULL) return;
    treePrintUniversal((void*)tree->root, valueAccessor, leftChildAccessor, rightChildAccessor);
}

//

// =====================

// Stack interface ===

TNStackNode *tnStackNodeCreate() {
    TNStackNode *node = malloc(sizeof(TNStackNode));
    node->previous = NULL;
    return node;
}

void tnStackNodeDestroy(TNStackNode *node) {
    if (node != NULL) free(node);
}

TNStack *tnStackCreate() {
    TNStack *stack = malloc(sizeof(TNStack));
    stack->size = 0;
    stack->last = NULL;
    return stack;
}

void tnStackDestroy(TNStack *stack) {
    if (stack != NULL) {
        if (stack->last != NULL) {
            TNStackNode *nextNode = stack->last;
            TNStackNode *currentNode = nextNode->previous;
            while (currentNode != NULL) {
                free(nextNode);
                nextNode = currentNode;
                currentNode = nextNode->previous;
            }
            free(nextNode);
        }
        free(stack);
    }
}

void tnStackPush(TNStack *stack, TreeNode *value) {
    assert(stack != NULL);
    if (stack->last == NULL) {
        TNStackNode *node = tnStackNodeCreate();
        node->value = value;
        stack->last = node;
    } else {
        TNStackNode *node = tnStackNodeCreate();
        node->previous = stack->last;
        node->value = value;
        stack->last = node;
    }
    stack->size++;
}

size_t tnStackSize(TNStack *stack) {
    assert(stack != NULL);
    return stack->size;
}

bool tnStackEmpty(TNStack *stack) {
    assert(stack != NULL);
    return tnStackSize(stack) == 0;
}

TreeNode *tnStackTop(TNStack *stack) {
    assert(stack != NULL);
    assert(!tnStackEmpty(stack));
    return stack->last->value;
}

void tnStackSetTop(TNStack *stack, TreeNode *node) {
    assert(stack != NULL);
    stack->last->value = node;
}

TreeNode *tnStackPop(TNStack *stack) {
    assert(stack != NULL);
    assert(!tnStackEmpty(stack));
    TreeNode *result = stack->last->value;
    if (tnStackSize(stack) == 1) {
        tnStackNodeDestroy(stack->last);
        stack->last = NULL;
    } else {
        TNStackNode *previous = stack->last->previous;
        tnStackNodeDestroy(stack->last);
        stack->last = previous;
    }
    stack->size--;
    return result;
}

// ===================

// Parser ===

int parseUnit(char *unit, Token *resultToken) {
    if (unit[0] == '\0') {
        Token token;
        token.type = BLANK;
        *resultToken = token;
    }
    Token token;
    // May be operation
    // One character token
    if (unit[1] == '\0') {
        switch (unit[0]) {
            case '+':
                token.type = OPERATION_PLUS;
                break;
            case '-':
                token.type = OPERATION_MINUS;
                break;
            case '*':
                token.type = OPERATION_MULT;
                break;
            case '/':
                token.type = OPERATION_DIVIDE;
                break;
            case '(':
                token.type = BRACKETS_OPEN;
                break;
            case ')':
                token.type = BRACKETS_CLOSE;
                break;
            default:
                if (isdigit(unit[0])) {
                    token.type = INTEGER;
                    token.value = atoi(unit);
                    break;
                }
                token.type = VARIABLE;
                strcpy(token.name, unit);
                break;
        }
        *resultToken = token;
        return STATUS_OK;
    }

    // Not one character token
    size_t size = strlen(unit);
    if (size > VARIABLE_MAX_LENGTH) return STATUS_ERROR;

    // May be an integer
    if (isdigit(unit[0]) || unit[0] == '-') {
        for (int i = 1;i < (int)size;i++) {
            if (!isdigit(unit[i])) return STATUS_ERROR;
        }
        token.type = INTEGER;
        token.value = atoi(unit);
        *resultToken = token;
        return STATUS_OK;
    }

    // Then it's a variable
    token.type = VARIABLE;
    strcpy(token.name, unit);
    *resultToken = token;
    return STATUS_OK;
}

// Util
void parseUtilPlaceMostRightNull(TNStackNode *stackNode, TreeNode *placingNode) {
    TreeNode *node = stackNode->value;
    if (node == NULL) {
        stackNode->value = placingNode;
        return ;
    }
    while (node->right != NULL) node = node->right;
    node->right = placingNode;
    placingNode->finished = true;
}

void parseUtilPriorityEmplacement(TNStackNode *stackNode, TreeNode *operationNode) {
    TreeNode *node = stackNode->value;
    if (node->finished) {
        operationNode->left = node;
        operationNode->finished = true;
        stackNode->value = operationNode;
    } else {
        while (!node->right->finished) node = node->right;
        TreeNode *rChild = node->right;
        node->right = operationNode;
        operationNode->left = rChild;
        operationNode->finished = true;
    }
}

void parseUtilUnpriorityEmplacement(TNStackNode *stackNode, TreeNode *operationNode) {
    TreeNode *node = stackNode->value;
    operationNode->left = node;
    stackNode->value = operationNode;
}

int parseFromStdin(Tree **resultTree) {
    assert(resultTree != NULL);
    Tree *tree = treeCreate();
    char str[100];
    Token token;
    TNStack *stack = tnStackCreate();

    tnStackPush(stack, NULL);

    do {
        scanf("%[^ \n]", str);
        //
        if (parseUnit(str, &token) == STATUS_ERROR) return STATUS_ERROR;

        if (token.type == BRACKETS_OPEN) {
            tnStackPush(stack, NULL);
        } else if (token.type == INTEGER || token.type == VARIABLE) {
            TreeNode *node = tnStackTop(stack);
            if (node == NULL) {
                node = treeNodeCreate();
                node->token = token;
                node->finished = true;
                tnStackPop(stack);
                tnStackPush(stack, node);
            } else {
                TreeNode *newNode = treeNodeCreate();
                newNode->token = token;
                parseUtilPlaceMostRightNull(stack->last, newNode);
            }
        } else if (token.type == OPERATION_PLUS || token.type == OPERATION_MINUS) {
            TreeNode *operationNode = treeNodeCreate();
            operationNode->token = token;
            parseUtilUnpriorityEmplacement(stack->last, operationNode);
        } else if (token.type == OPERATION_MULT || token.type == OPERATION_DIVIDE) {
            TreeNode *operationNode = treeNodeCreate();
            operationNode->token = token;
            parseUtilPriorityEmplacement(stack->last, operationNode);
        } else if (token.type == BRACKETS_CLOSE) {
            TNStackNode *prev = stack->last->previous;
            parseUtilPlaceMostRightNull(prev, tnStackPop(stack));
            tnStackTop(stack)->finished = true;
        }

    } while (getchar() != '\n');

    tree->root = tnStackPop(stack);
    tnStackDestroy(stack);
    *resultTree = tree;

    return STATUS_OK;
}

// ==========

// Tree to string expression ===

void tokenConvertToStdout(Token token) {
    if (token.type == OPERATION_PLUS) printf("+");
    else if (token.type == OPERATION_MINUS) printf("-");
    else if (token.type == OPERATION_MULT) printf("*");
    else if (token.type == OPERATION_DIVIDE) printf("/");
    else if (token.type == INTEGER) printf("%d", token.value);
    else if (token.type == VARIABLE) printf("%s", token.name);
}

void treeNodeSubtreeConvertToStdout(TreeNode *node, bool isRoot) {
    if (node->finished && !isRoot && (node->token.type == OPERATION_PLUS || node->token.type == OPERATION_MINUS)) {
        printf("( ");
        treeNodeSubtreeConvertToStdout(node->left, false);
        printf(" "); tokenConvertToStdout(node->token); printf(" ");
        treeNodeSubtreeConvertToStdout(node->right, false);
        printf(" )");
    } else if (tokenTypeIsOperation(node->token.type)) {
        treeNodeSubtreeConvertToStdout(node->left, false);
        printf(" "); tokenConvertToStdout(node->token); printf(" ");
        treeNodeSubtreeConvertToStdout(node->right, false);
    } else {
        tokenConvertToStdout(node->token);
    }
}

void treeConvertToStdout(Tree *tree) {
    treeNodeSubtreeConvertToStdout(tree->root, true);
}

// =============================

// ||======||
// ||      ||
// ||      ||
// ||======||

// Special function:

void treeUtilDestroyMultOne(Tree *tree, TreeNode *node, TreeNode *parent, bool isOneLeft) {
    if (parent == NULL) {
        if (isOneLeft) {
            tree->root = node->right;
            free(node->left);
            free(node);
        }
        else {
            tree->root = node->left;
            free(node->right);
            free(node);
        }
        return ;
    }
    if (isOneLeft) {
        treeNodeDestroy(node->left);
        if (parent->left == node) parent->left = node->right;
        else parent->right = node->right;
        treeNodeDestroy(node);
    } else {
        treeNodeDestroy(node->right);
        if (parent->left == node) parent->left = node->left;
        else parent->right = node->left;
        treeNodeDestroy(node);
    }
}

void treeNodeRemoveMultOne(Tree *tree, TreeNode *node, TreeNode *parent) {
    if (node == NULL) return;
    treeNodeRemoveMultOne(tree, node->left, node);
    treeNodeRemoveMultOne(tree, node->right, node);
    if (node->token.type == OPERATION_MULT) {
        if (node->left != NULL && node->left->token.type == INTEGER && node->left->token.value == 1)
            treeUtilDestroyMultOne(tree, node, parent, true);
        else if (node->right != NULL && node->right->token.type == INTEGER && node->right->token.value == 1)
            treeUtilDestroyMultOne(tree, node, parent, false);
    }
}

void treeRemoveMultOne(Tree *tree) {
    assert(tree != NULL);
    treeNodeRemoveMultOne(tree, tree->root, NULL);
}
