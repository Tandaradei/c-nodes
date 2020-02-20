#ifndef NODE_SHIFT_OPS_H
#define NODE_SHIFT_OPS_H

#include "node.h"

bool processNode_ShiftLeft(Node* node, const ProcessMode process_mode);
Node createNode_ShiftLeft(Node* node_0, Node* node_1);

bool processNode_ShiftRight(Node* node, const ProcessMode process_mode);
Node createNode_ShiftRight(Node* node_0, Node* node_1);

#endif // NODE_SHIFT_OPS_H