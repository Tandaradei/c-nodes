#include "ast.h"

#include <stdio.h>

#define DEBUG 0
#define PRINT_DEBUG(...) if(DEBUG) { printf(__VA_ARGS__); }

Node* makeNode_0(AbstractSyntaxTree* ast, Node (*createNode)(void)) {
    if(ast->node_count < AST_MAX_NODES) {
        ast->nodes[ast->node_count++] = createNode();
        PRINT_DEBUG("Inserted node from makeNode_0 on #%d\n", ast->node_count-1);
        return &(ast->nodes[ast->node_count-1]);
    }
    PRINT_DEBUG("Failed to insert node from makeNode_0");
    return NULL;
}

Node* makeNode_1(AbstractSyntaxTree* ast, Node (*createNode)(Node* node_0), Node* node_0) {
    if(ast->node_count < AST_MAX_NODES) {
        ast->nodes[ast->node_count++] = createNode(node_0);
        PRINT_DEBUG("Inserted node from makeNode_1 on #%d\n", ast->node_count-1);
        return &(ast->nodes[ast->node_count-1]);
    }
    PRINT_DEBUG("Failed to insert node from makeNode_1");
    return NULL;
}

Node* makeNode_2(AbstractSyntaxTree* ast, Node (*createNode)(Node* node_0, Node* node_1), Node* node_0, Node* node_1) {
    if(ast->node_count < AST_MAX_NODES) {
        ast->nodes[ast->node_count++] = createNode(node_0, node_1);
        PRINT_DEBUG("Inserted node from makeNode_2 on #%d\n", ast->node_count-1);
        return &(ast->nodes[ast->node_count-1]);
    }
    PRINT_DEBUG("Failed to insert node from makeNode_2");
    return NULL;
}

Node* makeNode_3(AbstractSyntaxTree* ast, Node (*createNode)(Node* node_0, Node* node_1, Node* node_2), Node* node_0, Node* node_1, Node* node_2) {
    if(ast->node_count < AST_MAX_NODES) {
        ast->nodes[ast->node_count++] = createNode(node_0, node_1, node_2);
        PRINT_DEBUG("Inserted node from makeNode_3 on #%d\n", ast->node_count-1);
        return &(ast->nodes[ast->node_count-1]);
    }
    PRINT_DEBUG("Failed to insert node from makeNode_3");
    return NULL;
}

Node* makeNode_0_INT(AbstractSyntaxTree* ast, Node (*createNode)(const int value), const int value) {
    if(ast->node_count < AST_MAX_NODES) {
        ast->nodes[ast->node_count++] = createNode(value);
        PRINT_DEBUG("Inserted node from makeNode_0_INT on #%d\n", ast->node_count-1);
        return &(ast->nodes[ast->node_count-1]);
    }
    PRINT_DEBUG("Failed to insert node from makeNode_0_INT");
    return NULL;
}

Node* makeNode_0_DOUBLE(AbstractSyntaxTree* ast, Node (*createNode)(const double value), const double value) {
    if(ast->node_count < AST_MAX_NODES) {
        ast->nodes[ast->node_count++] = createNode(value);
        PRINT_DEBUG("Inserted node from makeNode_0_DOUBLE on #%d\n", ast->node_count-1);
        return &(ast->nodes[ast->node_count-1]);
    }
    PRINT_DEBUG("Failed to insert node from makeNode_0_DOUBLE");
    return NULL;
}

Node* makeNode_0_STRING(AbstractSyntaxTree* ast, Node (*createNode)(const char* value), const char* value) {
    if(ast->node_count < AST_MAX_NODES) {
        ast->nodes[ast->node_count++] = createNode(value);
        PRINT_DEBUG("Inserted node from makeNode_0_STRING (%s) on #%d\n", value, ast->node_count-1);
        return &(ast->nodes[ast->node_count-1]);
    }
    printf("Failed to insert node from makeNode_0_STRING");
    return NULL;
}

Node* makeNode_1_STRING(AbstractSyntaxTree* ast, Node (*createNode)(Node* node_0, const char* value), Node* node_0, const char* value) {
    if(ast->node_count < AST_MAX_NODES) {
        ast->nodes[ast->node_count++] = createNode(node_0, value);
        printf("Inserted node from makeNode_1_STRING on #%d\n", ast->node_count-1);
        return &(ast->nodes[ast->node_count-1]);
    }
    PRINT_DEBUG("Failed to insert node from makeNode_1_STRING");
    return NULL;
}