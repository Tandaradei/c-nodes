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
            .type = VT_UNPROCESSED,
            .value.i_value = 0
        },
        .processNode = processNode_GetSymbol,
        .additional_info = NULL,
        .symbol_handle = 0,
    };
    strcpy(node.text, identifier);
    return node;
}

bool processNode_Assign(Node* node) {
    bool all_ins_valid = processAllNodeInSlots(node);
    if(!all_ins_valid) {
        return false;
    }
    SymbolTable* sym_tab = (SymbolTable*) node->in.slot_0.node->additional_info;
    if(!sym_tab) {
        return false;
    }
    const SymbolHandle handle = node->in.slot_0.node->symbol_handle;
    ValueType type = node->in.slot_0.node->out.type;
    UpdateSymbolValue_Result result = USVR_SUCCESS;
    int i_value = getAsInt(node->in.slot_1.node);
    double d_value = getAsDouble(node->in.slot_1.node);
    switch(type) {
        case VT_INT:
            result = updateSymbolValue_Int(sym_tab, handle, i_value);
            node->out.value.i_value = i_value;
            node->out.type = VT_INT;
            break;
        case VT_DOUBLE:
            result = updateSymbolValue_Double(sym_tab, handle, d_value);
            node->out.value.d_value = d_value;
            node->out.type = VT_DOUBLE;
            break;
        default:
            result = USVR_TYPE_MISMATCH;
    }
    return result == USVR_SUCCESS;
}

Node createNode_Assign(Node* node_target, Node* node_value) {
    return (Node) {
        .in = {
            .slot_0 = {
                .node = node_target,
                .allowed_value_types = VT_INT | VT_DOUBLE,
                .allow_rvalues = false,
            },
            .slot_1 = {
                .node = node_value,
                .allowed_value_types = VT_INT | VT_DOUBLE,
                .allow_rvalues = true,
            },
            .slot_count = 2,
        }, 
        .out = {
            .type = VT_UNPROCESSED,
            .value.i_value = 0,
            .is_lvalue = false,
        },
        .processNode = processNode_Assign,
        .text = "=",
        .additional_info = NULL,
        .symbol_handle = 0,
    };
}