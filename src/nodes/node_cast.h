#ifndef NODE_CAST_H
#define NODE_CAST_H

#include "node.h"

bool processNode_Cast(Node* node, const ProcessMode process_mode);
Node createNode_Cast(Node* node_0, const char* typename);

#endif // NODE_CAST_H