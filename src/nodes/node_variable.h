#ifndef NODE_VARIABLE_H
#define NODE_VARIABLE_H

#include "node.h"

bool processNode_GetSymbol(Node* node, const PROCESS_MODE process_mode);
Node createNode_GetSymbol(const char* identifier);

bool processNode_Assign(Node* node, const PROCESS_MODE process_mode);
Node createNode_Assign(Node* node_target, Node* node_value, const char* operator);

bool processNode_SetSymbolConfig(Node* node, const PROCESS_MODE process_mode);
Node createNode_SetSymbolConfig(SymbolValue value);

bool processNode_AddSymbol_Uninitialized(Node* node, const PROCESS_MODE process_mode);
Node createNode_AddSymbol_Uninitialized(const char* identifier);

bool processNode_AddSymbol_Initialized(Node* node, const PROCESS_MODE process_mode);
Node createNode_AddSymbol_Initialized(Node* value, const char* identifier);

#endif // NODE_VARIABLE_H