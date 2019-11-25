#ifndef NODE_VARIABLE_H
#define NODE_VARIABLE_H

#include "node.h"

bool processNode_GetSymbol(Node* node);
Node createNode_GetSymbol(const char* identifier);

bool processNode_Assign(Node* node);
Node createNode_Assign(Node* node_target, Node* node_value);

#endif // NODE_VARIABLE_H