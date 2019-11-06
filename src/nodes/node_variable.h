#ifndef NODE_VARIABLE_H
#define NODE_VARIABLE_H

#include "node.h"

bool processNode_GetVariableValue(Node* node);
Node createNode_GetVariableValue(const char* identifier);

bool processNode_UpdateVariableValue(Node* node);
Node createNode_UpdateVariableValue(const char* identifier, Node* node_0);

#endif // NODE_VARIABLE_H