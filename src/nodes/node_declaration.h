#ifndef NODE_DECLARATION_H
#define NODE_DECLARATION_H

#include "node.h"

bool processNode_Declaration(Node* node, const ProcessMode process_mode);
Node createNode_Declaration(Node* config, Node* symbol_list);

bool processNode_SymbolDeclarationList(Node* node, const ProcessMode process_mode);
Node createNode_SymbolDeclarationList(Node* symbol_list, Node* symbol);

#endif // NODE_DECLARATION_H