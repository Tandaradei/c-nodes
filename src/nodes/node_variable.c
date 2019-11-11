#include "node_variable.h"

#include <stddef.h>
#include <string.h>

#include "src/symtab.h"

bool processNode_GetVariableValue(Node* node) {
    SymbolTable* sym_tab = (SymbolTable*) node->additional_info;
    if(!sym_tab) {
        return false;
    }
    SymbolValue sym_value = getSymbolValue(sym_tab, node->text); // TODO: not perfect, 'text' has to be the exact identifier
    node->out.type = sym_value.type;
    node->out.value = sym_value.value;
    return true;
}

Node createNode_GetVariableValue(const char* identifier) {
    Node node = {
        .in = {
            .slot_count = 0,
        }, 
        .out = {
            .type = VT_INT,
            .value.i_value = 0
        },
        .processNode = processNode_GetVariableValue,
        .additional_info = NULL,
    };
    strcpy(node.text, identifier);
    return node;
}

bool processNode_UpdateVariableValue(Node* node) {
    SymbolTable* sym_tab = (SymbolTable*) node->additional_info;
    if(!sym_tab) {
        return false;
    }
    ValueType type = node->in.slot_0.node->out.type;
    UpdateSymbolValue_Result result = USVR_TYPE_MISMATCH;
    switch (type) {
        case VT_INT:
            result = updateSymbolValue_Int(sym_tab, node->text, node->in.slot_0.node->out.value.i_value);
            break;
        case VT_DOUBLE:
            result = updateSymbolValue_Double(sym_tab, node->text, node->in.slot_0.node->out.value.d_value);
            break;
        default:
            break;
    }
    if(result != USVR_SUCCESS) {
        node->out.type = VT_ERROR;
        return false;
    }
    node->out.type = type;
    node->out.value = node->in.slot_0.node->out.value;
    return true;
}


Node createNode_UpdateVariableValue(Node* node_0, const char* identifier) {
    Node node = {
        .in = {
            .slot_count = 1,
            .slot_0 = {
                .node = node_0,
                .allowed_value_types = VT_INT | VT_DOUBLE,
            }
        },
        .out = {
            .type = VT_INT,
            .value.i_value = 0
        },
        .processNode = processNode_UpdateVariableValue,
        .additional_info = NULL,
    };
    strcpy(node.text, identifier);
    return node;
}