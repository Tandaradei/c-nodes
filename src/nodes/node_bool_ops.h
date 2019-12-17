#ifndef NODE_BOOL_OPS_H
#define NODE_BOOL_OPS_H

#include "node.h"

bool processNode_BoolAnd(Node* node, const PROCESS_MODE process_mode);
Node createNode_BoolAnd(Node* node_0, Node* node_1);

bool processNode_BoolOr(Node* node, const PROCESS_MODE process_mode);
Node createNode_BoolOr(Node* node_0, Node* node_1);

#endif // NODE_BOOL_OPS_H