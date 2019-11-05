#ifndef AST_H
#define AST_H

#include <stdint.h>
#include "nodes/node.h"

#define AST_MAX_NODES 256

typedef struct AbstractSyntaxTree {
    Node nodes[AST_MAX_NODES];
    uint16_t node_count;
} AbstractSyntaxTree;

Node* makeNode_0(AbstractSyntaxTree* ast, Node (*createNode)(void));
Node* makeNode_1(AbstractSyntaxTree* ast, Node (*createNode)(Node* node_0), Node* node_0);
Node* makeNode_2(AbstractSyntaxTree* ast, Node (*createNode)(Node* node_0, Node* node_1), Node* node_0, Node* node_1);
Node* makeNode_3(AbstractSyntaxTree* ast, Node (*createNode)(Node* node_0, Node* node_1, Node* node_2), Node* node_0, Node* node_1, Node* node_2);

Node* makeNode_0_INT(AbstractSyntaxTree* ast, Node (*createNode)(const int value), const int value);
Node* makeNode_0_DOUBLE(AbstractSyntaxTree* ast, Node (*createNode)(const double value), const double value);

#endif // AST_H