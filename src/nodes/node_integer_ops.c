#include "node_integer_ops.h"

bool processNode_IncrementPre(Node* node) {
    SymbolHandle handle = node->in.slot_0.node->symbol_handle;
    SymbolTable* sym_tab = (SymbolTable*)node->in.slot_0.node->additional_info;
    if(!sym_tab) {
        return false;
    }
    const int new_value = getAsInt(node->in.slot_0.node) + 1;
    updateSymbolValue_Int(sym_tab, handle, new_value);
    node->out.value.i_value = new_value;
    node->out.type = VT_INT;
    node->out.is_lvalue = true;
    node->symbol_handle = handle;
    node->additional_info = node->in.slot_0.node->additional_info;
    return true;
}

Node createNode_IncrementPre(Node* node_0) {
    return (Node) {
        .in = {
            .slot_0 = {
                .node = node_0,
                .allowed_value_types = VT_INT,
                .allow_rvalues = false,
            },
            .slot_count = 1,
        },
        .out = {
            .type = VT_ERROR,
            .value.i_value = 0,
        },
        .processNode = processNode_IncrementPre,
        .text = "++(pre)",
        .additional_info = NULL,
    };
}

bool processNode_IncrementPost(Node* node) {
    SymbolHandle handle = node->in.slot_0.node->symbol_handle;
    SymbolTable* sym_tab = (SymbolTable*)node->in.slot_0.node->additional_info;
    if(!sym_tab) {
        return false;
    }
    const int value = getAsInt(node->in.slot_0.node);
    node->out.value.i_value = value;
    const int new_value = value + 1;
    updateSymbolValue_Int(sym_tab, handle, new_value);
    node->out.type = VT_INT;
    node->out.is_lvalue = true;
    node->symbol_handle = handle;
    node->additional_info = node->in.slot_0.node->additional_info;
    return true;
}

Node createNode_IncrementPost(Node* node_0) {
    return (Node) {
        .in = {
            .slot_0 = {
                .node = node_0,
                .allowed_value_types = VT_INT,
                .allow_rvalues = false,
            },
            .slot_count = 1,
        },
        .out = {
            .type = VT_ERROR,
            .value.i_value = 0,
        },
        .processNode = processNode_IncrementPost,
        .text = "(post)++",
        .additional_info = NULL,
    };
}

bool processNode_DecrementPre(Node* node) {
    SymbolHandle handle = node->in.slot_0.node->symbol_handle;
    SymbolTable* sym_tab = (SymbolTable*)node->in.slot_0.node->additional_info;
    if(!sym_tab) {
        return false;
    }
    const int new_value = getAsInt(node->in.slot_0.node) - 1;
    updateSymbolValue_Int(sym_tab, handle, new_value);
    node->out.value.i_value = new_value;
    node->out.type = VT_INT;
    node->out.is_lvalue = true;
    node->symbol_handle = handle;
    node->additional_info = node->in.slot_0.node->additional_info;
    return true;
}

Node createNode_DecrementPre(Node* node_0) {
    return (Node) {
        .in = {
            .slot_0 = {
                .node = node_0,
                .allowed_value_types = VT_INT,
                .allow_rvalues = false,
            },
            .slot_count = 1,
        },
        .out = {
            .type = VT_ERROR,
            .value.i_value = 0,
        },
        .processNode = processNode_DecrementPre,
        .text = "--(pre)",
        .additional_info = NULL,
    };
}

bool processNode_DecrementPost(Node* node) {
    SymbolHandle handle = node->in.slot_0.node->symbol_handle;
    SymbolTable* sym_tab = (SymbolTable*)node->in.slot_0.node->additional_info;
    if(!sym_tab) {
        return false;
    }
    const int value = getAsInt(node->in.slot_0.node);
    node->out.value.i_value = value;
    const int new_value = value - 1;
    updateSymbolValue_Int(sym_tab, handle, new_value);
    node->out.type = VT_INT;
    node->out.is_lvalue = true;
    node->symbol_handle = handle;
    node->additional_info = node->in.slot_0.node->additional_info;
    return true;
}

Node createNode_DecrementPost(Node* node_0) {
    return (Node) {
        .in = {
            .slot_0 = {
                .node = node_0,
                .allowed_value_types = VT_INT,
                .allow_rvalues = false,
            },
            .slot_count = 1,
        },
        .out = {
            .type = VT_ERROR,
            .value.i_value = 0,
        },
        .processNode = processNode_DecrementPost,
        .text = "(post)--",
        .additional_info = NULL,
    };
}