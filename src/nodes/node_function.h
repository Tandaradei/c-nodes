#ifndef NODE_FUNCTION_H
#define NODE_FUNCTION_H

#include "node.h"

bool processNode_FunctionEmpty(Node* node, const PROCESS_MODE process_mode);
Node createNode_FunctionEmpty(const char* name);

bool processNode_Argument(Node* node, const PROCESS_MODE process_mode);
Node createNode_Argument(Node* value);

bool processNode_ArgumentList(Node* node, const PROCESS_MODE process_mode);
Node createNode_ArgumentList(Node* value, Node* rest);

bool processNode_Function(Node* node, const PROCESS_MODE process_mode);
Node createNode_Function(Node* node_0, const char* name);

#endif // NODE_FUNCTION_H