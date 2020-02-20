#ifndef NODE_SIZEOF_H
#define NODE_SIZEOF_H

#include "node.h"

bool processNode_Sizeof_Type(Node* node, const ProcessMode process_mode);
Node createNode_Sizeof_Type(const char* typename);

bool processNode_Sizeof_Expression(Node* node, const ProcessMode process_mode);
Node createNode_Sizeof_Expression(Node* node_0);

#endif // NODE_SIZEOF_H