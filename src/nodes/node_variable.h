#ifndef NODE_VARIABLE_H
#define NODE_VARIABLE_H

#include "node.h"

bool processNode_GetVariableValue(Node* node);
Node createNode_GetVariableValue(const char* identifier);

bool processNode_UpdateVariableValue(Node* node);
Node createNode_UpdateVariableValue(Node* node_0, const char* identifier);

#endif // NODE_VARIABLE_H