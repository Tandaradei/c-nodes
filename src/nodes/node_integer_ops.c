#include "node_integer_ops.h"

bool processNode_IncrementPre(Node* node, const PROCESS_MODE process_mode) {
    bool all_ins_valid = processAllNodeInSlots(node, process_mode);
    if(!all_ins_valid) {
        return false;
    }
    node->out.type = node->in.slot_0.node->out.type;
    if(process_mode == PM_TYPE_ONLY) {
        return node->out.type != VT_ERROR;
    }
    SymbolHandle handle = node->in.slot_0.node->symbol_handle;
    SymbolTable* sym_tab = (SymbolTable*)node->in.slot_0.node->additional_info;
    if(!sym_tab) {
        strcpy(node->error, "DEBUG: No reference to symbol table");
        return false;
    }
    Value new_value;
    switch(node->in.slot_0.node->out.type) {
        case VT_INT: 
            new_value.i_value = getAsInt(node->in.slot_0.node) + 1;
            updateSymbolValue_Int(sym_tab, handle, new_value.i_value);
            node->out.value = new_value;
            break;
        case VT_DOUBLE: 
            new_value.d_value = getAsDouble(node->in.slot_0.node) + 1.0 ;
            updateSymbolValue_Double(sym_tab, handle, new_value.d_value);
            node->out.value = new_value;
            break;
        default:
            break;
    }
    node->symbol_handle = handle;
    node->additional_info = node->in.slot_0.node->additional_info;
    return true;
}

Node createNode_IncrementPre(Node* node_0) {
    return (Node) {
        .in = {
            .slot_0 = {
                .node = node_0,
                .allowed_value_types = VT_INT & VT_DOUBLE,
                .allow_rvalues = false,
            },
            .slot_count = 1,
        },
        .out = {
            .type = VT_ERROR,
            .value.i_value = 0,
            .is_lvalue = true,
            .is_processed = false,
        },
        .processNode = processNode_IncrementPre,
        .text = "++(pre)",
        .error = "",
        .additional_info = NULL,
    };
}

bool processNode_IncrementPost(Node* node, const PROCESS_MODE process_mode) {
    bool all_ins_valid = processAllNodeInSlots(node, process_mode);
    if(!all_ins_valid) {
        return false;
    }
    node->out.type = node->in.slot_0.node->out.type;
    if(process_mode == PM_TYPE_ONLY) {
        return node->out.type != VT_ERROR;
    }
    SymbolHandle handle = node->in.slot_0.node->symbol_handle;
    SymbolTable* sym_tab = (SymbolTable*)node->in.slot_0.node->additional_info;
    if(!sym_tab) {
        strcpy(node->error, "DEBUG: No reference to symbol table");
        return false;
    }
    Value value;
    switch(node->in.slot_0.node->out.type) {
        case VT_INT: 
            value.i_value = getAsInt(node->in.slot_0.node);
            node->out.value = value;
            updateSymbolValue_Int(sym_tab, handle, value.i_value + 1);
            break;
        case VT_DOUBLE: 
            value.d_value = getAsDouble(node->in.slot_0.node);
            node->out.value = value;
            updateSymbolValue_Double(sym_tab, handle, value.d_value + 1.0);
            break;
        default:
            break;
    }
    node->symbol_handle = handle;
    node->additional_info = node->in.slot_0.node->additional_info;
    return true;
}

Node createNode_IncrementPost(Node* node_0) {
    return (Node) {
        .in = {
            .slot_0 = {
                .node = node_0,
                .allowed_value_types = VT_INT & VT_DOUBLE,
                .allow_rvalues = false,
            },
            .slot_count = 1,
        },
        .out = {
            .type = VT_ERROR,
            .value.i_value = 0,
            .is_lvalue = true,
            .is_processed = false,
        },
        .processNode = processNode_IncrementPost,
        .text = "(post)++",
        .error = "",
        .additional_info = NULL,
    };
}

bool processNode_DecrementPre(Node* node, const PROCESS_MODE process_mode) {
    bool all_ins_valid = processAllNodeInSlots(node, process_mode);
    if(!all_ins_valid) {
        return false;
    }
    node->out.type = node->in.slot_0.node->out.type;
    if(process_mode == PM_TYPE_ONLY) {
        return node->out.type != VT_ERROR;
    }
    SymbolHandle handle = node->in.slot_0.node->symbol_handle;
    SymbolTable* sym_tab = (SymbolTable*)node->in.slot_0.node->additional_info;
    if(!sym_tab) {
        strcpy(node->error, "DEBUG: No reference to symbol table");
        return false;
    }
    Value new_value;
    switch(node->in.slot_0.node->out.type) {
        case VT_INT: 
            new_value.i_value = getAsInt(node->in.slot_0.node) - 1;
            updateSymbolValue_Int(sym_tab, handle, new_value.i_value);
            node->out.value = new_value;
            break;
        case VT_DOUBLE: 
            new_value.d_value = getAsDouble(node->in.slot_0.node) - 1.0;
            updateSymbolValue_Double(sym_tab, handle, new_value.d_value);
            node->out.value = new_value;
            break;
        default:
            break;
    }
    node->symbol_handle = handle;
    node->additional_info = node->in.slot_0.node->additional_info;
    return true;
}

Node createNode_DecrementPre(Node* node_0) {
    return (Node) {
        .in = {
            .slot_0 = {
                .node = node_0,
                .allowed_value_types = VT_INT & VT_DOUBLE,
                .allow_rvalues = false,
            },
            .slot_count = 1,
        },
        .out = {
            .type = VT_ERROR,
            .value.i_value = 0,
            .is_lvalue = true,
            .is_processed = false,
        },
        .processNode = processNode_DecrementPre,
        .text = "--(pre)",
        .error = "",
        .additional_info = NULL,
    };
}

bool processNode_DecrementPost(Node* node, const PROCESS_MODE process_mode) {
    bool all_ins_valid = processAllNodeInSlots(node, process_mode);
    if(!all_ins_valid) {
        return false;
    }
    node->out.type = node->in.slot_0.node->out.type;
    if(process_mode == PM_TYPE_ONLY) {
        return node->out.type != VT_ERROR;
    }
    SymbolHandle handle = node->in.slot_0.node->symbol_handle;
    SymbolTable* sym_tab = (SymbolTable*)node->in.slot_0.node->additional_info;
    if(!sym_tab) {
        strcpy(node->error, "DEBUG: No reference to symbol table");
        return false;
    }
    Value value;
    switch(node->in.slot_0.node->out.type) {
        case VT_INT: 
            value.i_value = getAsInt(node->in.slot_0.node);
            node->out.value = value;
            updateSymbolValue_Int(sym_tab, handle, value.i_value - 1);
            break;
        case VT_DOUBLE: 
            value.d_value = getAsDouble(node->in.slot_0.node);
            node->out.value = value;
            updateSymbolValue_Double(sym_tab, handle, value.d_value - 1.0);
            break;
        default:
            break;
    }
    node->symbol_handle = handle;
    node->additional_info = node->in.slot_0.node->additional_info;
    return true;
}

Node createNode_DecrementPost(Node* node_0) {
    return (Node) {
        .in = {
            .slot_0 = {
                .node = node_0,
                .allowed_value_types = VT_INT & VT_DOUBLE,
                .allow_rvalues = false,
            },
            .slot_count = 1,
        },
        .out = {
            .type = VT_ERROR,
            .value.i_value = 0,
            .is_lvalue = false,
            .is_processed = false,
        },
        .processNode = processNode_DecrementPost,
        .text = "(post)--",
        .error = "",
        .additional_info = NULL,
    };
}