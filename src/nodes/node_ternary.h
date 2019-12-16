#ifndef NODE_TERNARY_H
#define NODE_TERNARY_H

#include "node.h"

bool processNode_Ternary(Node* node);
Node createNode_Ternary(Node* cond, Node* true_expr, Node* false_expr);

#endif // NODE_TERNARY_H