#ifndef NODE_UNARY_OPS_H
#define NODE_UNARY_OPS_H

#include "node.h"

bool processNode_UnaryOp(Node* node, const ProcessMode process_mode);
Node createNode_UnaryOp(Node* node, const char* operator);

#endif // NODE_UNARY_OPS_H