#ifndef NODE_COMMA_OP_H
#define NODE_COMMA_OP_H

#include "node.h"

bool processNode_CommaOp(Node* node, const ProcessMode process_mode);
Node createNode_CommaOp(Node* node_0, Node* node_1);

#endif // NODE_COMMA_OP_H