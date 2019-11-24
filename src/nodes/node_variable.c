#include "node_variable.h"

#include <stddef.h>
#include <string.h>

#include "src/symtab.h"

bool processNode_GetSymbol(Node* node) {
    SymbolTable* sym_tab = (SymbolTable*) node->additional_info;
    if(!sym_tab) {
        return false;
    }
    SymbolHandle handle = getSymbolHandle(sym_tab, node->text); // TODO: not perfect, 'text' has to be the exact identifier
    SymbolValue sym_value = getSymbolValue(sym_tab, handle);
    node->out.type = sym_value.type;
    node->out.is_lvalue = !sym_value.is_const; 
    if(node->out.is_lvalue) {
        node->symbol_handle = handle;
    } 
    node->out.value = sym_value.value;
    return true;
}

Node createNode_GetSymbol(const char* identifier) {
    Node node = {
        .in = {
            .slot_count = 0,
        }, 
        .out = {
            .type = VT_INT,
            .value.i_value = 0
        },
        .processNode = processNode_GetSymbol,
        .additional_info = NULL,
        .symbol_handle = 0,
    };
    strcpy(node.text, identifier);
    return node;
}