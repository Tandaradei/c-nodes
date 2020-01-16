#include "node_sizeof.h"

bool processNode_Sizeof_Type(Node* node, const PROCESS_MODE process_mode) {
    node->out.type = VT_INT;
    if(!strcmp(node->text, "sizeof(int)")) {
        node->out.value.i_value = sizeof(int);
    }
    else if(!strcmp(node->text, "sizeof(double)")) {
        node->out.value.i_value = sizeof(double);
    }
    else {
        strcpy(node->error, "Unknown type");
        return false;
    }
    return true;
}

Node createNode_Sizeof_Type(const char* typename) {
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
        .processNode = processNode_Sizeof_Type,
        .error = "",
        .additional_info = NULL,
        .symbol_handle = 0,
    };
    sprintf(node.text, "sizeof(%s)", typename);
    return node;
}

bool processNode_Sizeof_Expression(Node* node, const PROCESS_MODE process_mode) {
    bool all_ins_valid = processAllNodeInSlots(node, PM_TYPE_ONLY); // 'sizeof expr' never evaluates the expression, just the type
    if(!all_ins_valid) {
        return false;
    }
    switch(node->in.slot_0.node->out.type) {
        case VT_INT:
            node->out.value.i_value = sizeof(int);
            break;
        case VT_DOUBLE:
            node->out.value.i_value = sizeof(double);
            break;
        default:
            strcpy(node->error, "Unknown type");
            return false;
            break;
    }
    return true;
}

Node createNode_Sizeof_Expression(Node* node_0) {
    return (Node) {
        .in = {
            .slot_0 = {
                .node = node_0,
                .allowed_value_types = VT_INT | VT_DOUBLE,
                .allow_rvalues = false,
            },
            .slot_count = 1,
        }, 
        .out = {
            .type = VT_INT,
            .value.i_value = 0,
            .is_lvalue = false,
            .is_processed = false,
        },
        .processNode = processNode_Sizeof_Expression,
        .error = "",
        .text = "sizeof",
        .additional_info = NULL,
        .symbol_handle = 0,
    };
}