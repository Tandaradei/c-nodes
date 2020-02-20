#include "node_unary_ops.h"

#define APPLY_UNARY_OP_INT(OLD_VALUE, VALUE, OP) \
    if(!strcmp(OP, "+")) { \
        VALUE = +OLD_VALUE; \
    } \
    else if(!strcmp(OP, "-")) { \
        VALUE = -OLD_VALUE; \
    } \
    else if(!strcmp(OP, "~")) { \
        VALUE = ~OLD_VALUE; \
    } \
    else if(!strcmp(OP, "!")) { \
        VALUE = !OLD_VALUE; \
    } \
    else { \
        strcpy(node->error, "Unknown unary operator"); \
        return false; \
    }

#define APPLY_UNARY_OP_DOUBLE(OLD_VALUE, VALUE, OP) \
    if(!strcmp(OP, "+")) { \
        VALUE = +OLD_VALUE; \
    } \
    else if(!strcmp(OP, "-")) { \
        VALUE = -OLD_VALUE; \
    } \
    else if(!strcmp(OP, "~")) { \
        strcpy(node->error, "Can't use ~ on double"); \
        return false; \
    } \
    else if(!strcmp(OP, "!")) { \
        VALUE = !OLD_VALUE; \
    } \
    else { \
        strcpy(node->error, "Unknown unary operator"); \
        return false; \
    }

bool processNode_UnaryOp(Node* node, const ProcessMode process_mode) {
    bool all_ins_valid = processAllNodeInSlots(node, process_mode);
    if(!all_ins_valid) {
        return false;
    }
    NodeOut child_out = node->in.slot_0.node->out;
    node->out.type = child_out.type;
    if(process_mode == PM_TYPE_ONLY) {
        return true;
    }
    switch (node->out.type) {
        case VT_INT:
            APPLY_UNARY_OP_INT(child_out.value.i_value, node->out.value.i_value, node->text)
            break;
        case VT_DOUBLE:
            APPLY_UNARY_OP_DOUBLE(child_out.value.d_value, node->out.value.d_value, node->text)
            break;
        default:
            return false;
            break;
    }
    return true;
}

Node createNode_UnaryOp(Node* node_0, const char* operator) {
    Node node = {
        .in = {
            .slot_0 = {
                .node = node_0,
                .allowed_value_types = VT_INT | VT_DOUBLE,
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
        .processNode = processNode_UnaryOp,
        .error = "",
        .additional_info = NULL,
        .symbol_handle = 0,
    };
    strcpy(node.text, operator);
    return node;
}