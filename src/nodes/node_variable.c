#include "node_variable.h"

#include <stddef.h>
#include <string.h>

#include "src/symtab.h"

bool processNode_GetSymbol(Node* node, const ProcessMode process_mode) {
    SymbolTable* sym_tab = (SymbolTable*) node->additional_info;
    if(!sym_tab) {
        strcpy(node->error, "DEBUG: No reference to symbol table");
        return false;
    }
    SymbolHandle handle = getSymbolHandle(sym_tab, node->text);
    if(handle.value == 0) {
        sprintf(node->error, "There's no variable named '%s'", node->text);
        return false;
    }
    SymbolValue sym_value = getSymbolValue(sym_tab, handle);
    node->out.type = sym_value.type;
    if(process_mode == PM_FULL) {
        node->out.is_lvalue = !sym_value.is_const; 
        node->symbol_handle = handle;
        node->out.value = sym_value.value;
    }
    return true;
}

Node createNode_GetSymbol(const char* identifier) {
    Node node = {
        .in = {
            .slot_count = 0,
        }, 
        .out = {
            .type = VT_ERROR,
            .value.i_value = 0,
            .is_lvalue = false,
            .is_processed = false,
        },
        .processNode = processNode_GetSymbol,
        .additional_info = NULL,
        .error = "",
        .symbol_handle = 0,
    };
    strcpy(node.text, identifier);
    return node;
}

#define NEW_VALUE_INT(OLD_VALUE, VALUE, OP) \
    if(!strcmp(OP, "=")) { \
    } \
    else if(!strcmp(OP, "+=")) { \
        VALUE = OLD_VALUE + VALUE; \
    } \
    else if(!strcmp(OP, "-=")) { \
        VALUE = OLD_VALUE - VALUE; \
    } \
    else if(!strcmp(OP, "*=")) { \
        VALUE = OLD_VALUE * VALUE; \
    } \
    else if(!strcmp(OP, "/=")) { \
        VALUE = OLD_VALUE / VALUE; \
    } \
    else if(!strcmp(OP, "%=")) { \
        VALUE = OLD_VALUE % VALUE; \
    } \
    else if(!strcmp(OP, "&=")) { \
        VALUE = OLD_VALUE & VALUE; \
    } \
    else if(!strcmp(OP, "|=")) { \
        VALUE = OLD_VALUE | VALUE; \
    } \
    else if(!strcmp(OP, "^=")) { \
        VALUE = OLD_VALUE ^ VALUE; \
    } \
    else if(!strcmp(OP, "<<=")) { \
        VALUE = OLD_VALUE << VALUE; \
    } \
    else if(!strcmp(OP, ">>=")) { \
        VALUE = OLD_VALUE >> VALUE; \
    } \
    else { \
        strcpy(node->error, "Unknown assignment operator"); \
        return false; \
    } \

#define NEW_VALUE_DOUBLE(OLD_VALUE, VALUE, OP) \
    if(!strcmp(OP, "=")) { \
    } \
    else if(!strcmp(OP, "+=")) { \
        VALUE = OLD_VALUE + VALUE; \
    } \
    else if(!strcmp(OP, "-=")) { \
        VALUE = OLD_VALUE - VALUE; \
    } \
    else if(!strcmp(OP, "*=")) { \
        VALUE = OLD_VALUE * VALUE; \
    } \
    else if(!strcmp(OP, "/=")) { \
        VALUE = OLD_VALUE / VALUE; \
    } \
    else if(!strcmp(OP, "%=")) { \
        strcpy(node->error, "Can't use % operator on 'double'"); \
        return false; \
    } \
    else if(!strcmp(OP, "&=")) { \
        strcpy(node->error, "Can't use & operator on 'double'"); \
        return false; \
    } \
    else if(!strcmp(OP, "|=")) { \
        strcpy(node->error, "Can't use | operator on 'double'"); \
        return false; \
    } \
    else if(!strcmp(OP, "^=")) { \
        strcpy(node->error, "Can't use ^ operator on 'double'"); \
        return false; \
    } \
    else if(!strcmp(OP, "<<=")) { \
        strcpy(node->error, "Can't use << operator on 'double'"); \
        return false; \
    } \
    else if(!strcmp(OP, ">>=")) { \
        strcpy(node->error, "Can't use >> operator on 'double'"); \
        return false; \
    } \
    else { \
        strcpy(node->error, "Unknown assignment operator"); \
        return false; \
    } \

bool processNode_Assign(Node* node, const ProcessMode process_mode) {
    bool all_ins_valid = processAllNodeInSlots(node, process_mode);
    if(!all_ins_valid) {
        return false;
    }
    SymbolTable* sym_tab = (SymbolTable*) node->in.slot_0.node->additional_info;
    if(!sym_tab) {
        strcpy(node->error, "DEBUG: No reference to symbol table");
        return false;
    }
    const SymbolHandle handle = node->in.slot_0.node->symbol_handle;
    ValueType type = node->in.slot_0.node->out.type;
    node->out.type = type;
    if(process_mode == PM_TYPE_ONLY) {
        return type != VT_ERROR;
    }
    UpdateSymbolValue_Result result = USVR_SUCCESS;
    int i_value = getAsInt(node->in.slot_1.node);
    double d_value = getAsDouble(node->in.slot_1.node);
    Value old_value = node->in.slot_0.node->out.value;
    switch(type) {
        case VT_INT:
            NEW_VALUE_INT(old_value.i_value, i_value, node->text)
            result = updateSymbolValue_Int(sym_tab, handle, i_value);
            node->out.value.i_value = i_value;
            break;
        case VT_DOUBLE:
            NEW_VALUE_DOUBLE(old_value.d_value, d_value, node->text)
            result = updateSymbolValue_Double(sym_tab, handle, d_value);
            node->out.value.d_value = d_value;
            break;
        default:
            result = USVR_TYPE_MISMATCH;
    }
    switch(result) {
        case USVR_SUCCESS:
            return true;
            break;
        case USVR_IS_CONST:
            strcpy(node->error, "Cannot assign a value to a constant");
            return false;
            break;
        default: // Other errors should've already been checked at 'compile time'
            return false;
            break;
    }
}

Node createNode_Assign(Node* node_target, Node* node_value, const char* operator) {
    Node node = {
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
            .type = VT_ERROR,
            .value.i_value = 0,
            .is_lvalue = false,
            .is_processed = false,
        },
        .processNode = processNode_Assign,
        .error = "",
        .additional_info = NULL,
        .symbol_handle = 0,
    };
    strcpy(node.text, operator);
    return node;
}

bool processNode_SetSymbolConfig(Node* node, const ProcessMode process_mode) {
    if(process_mode == PM_FULL) {
        return true;
    }
    SymbolTable* sym_tab = (SymbolTable*) node->additional_info;
    if(!sym_tab) {
        strcpy(node->error, "DEBUG: No reference to symbol table");
        return false;
    }
    sym_tab->currentConfig = (SymbolValue) {
        .type = node->out.type,
        .value.i_value = 0,
        .is_const = node->out.value.i_value
    };
    return true;
}

Node createNode_SetSymbolConfig(SymbolValue value) {
    return (Node) {
        .in = {
            .slot_count = 0,
        }, 
        .out = {
            .type = value.type,
            .value.i_value = value.is_const,
            .is_lvalue = false,
            .is_processed = false,
        },
        .processNode = processNode_SetSymbolConfig,
        .text = "Symbol config",
        .error = "",
        .additional_info = NULL,
        .symbol_handle = 0,
    };
}

bool processNode_AddSymbol_Uninitialized(Node* node, const ProcessMode process_mode) {
    if(process_mode == PM_FULL) {
        return true;
    }
    SymbolTable* sym_tab = (SymbolTable*) node->additional_info;
    if(!sym_tab) {
        strcpy(node->error, "DEBUG: No reference to symbol table");
        return false;
    }
    addSymbolWithCurrentConfig(sym_tab, node->text);
    node->out.type = sym_tab->currentConfig.type;
    return true;
}

Node createNode_AddSymbol_Uninitialized(const char* identifier) {
    Node node = {
        .in = {
            .slot_count = 0,
        }, 
        .out = {
            .type = VT_ERROR,
            .value.i_value = 0,
            .is_lvalue = false,
            .is_processed = false,
        },
        .processNode = processNode_AddSymbol_Uninitialized,
        .error = "",
        .additional_info = NULL,
        .symbol_handle = 0,
    };
    strcpy(node.text, identifier);
    return node;
}

bool processNode_AddSymbol_Initialized(Node* node, const ProcessMode process_mode) {
    bool all_ins_valid = processAllNodeInSlots(node, process_mode);
    if(!all_ins_valid) {
        return false;
    }
    SymbolTable* sym_tab = (SymbolTable*) node->additional_info;
    if(!sym_tab) {
        strcpy(node->error, "DEBUG: No reference to symbol table");
        return false;
    }
    if(process_mode == PM_TYPE_ONLY) {
        addSymbolWithCurrentConfig(sym_tab, node->text);
        node->out.type = sym_tab->currentConfig.type;
        node->symbol_handle = getSymbolHandle(sym_tab, node->text);
    }
    else if(process_mode == PM_FULL) {
        return initializeSymbol(sym_tab, node->symbol_handle, node->in.slot_0.node->out.value, node->in.slot_0.node->out.type);
    }
    return true;
}

Node createNode_AddSymbol_Initialized(Node* value, const char* identifier) {
    Node node = {
        .in = {
            .slot_0 = {
                .node = value,
                .allowed_value_types = VT_INT | VT_DOUBLE,
                .allow_rvalues = true,
            },
            .slot_count = 1,
        }, 
        .out = {
            .type = VT_ERROR,
            .value.i_value = 0,
            .is_lvalue = false,
            .is_processed = false,
        },
        .processNode = processNode_AddSymbol_Initialized,
        .error = "",
        .additional_info = NULL,
        .symbol_handle = 0,
    };
    strcpy(node.text, identifier);
    return node;
}