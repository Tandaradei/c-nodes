#include "node_bool_ops.h"

bool processNode_BoolAnd(Node* node, const ProcessMode process_mode) {
    if(process_mode == PM_TYPE_ONLY) {
        return processAllNodeInSlots(node, process_mode);
    }
    node->out.value.i_value = 1;
    for(uint32_t i = 0; i < node->in.slot_count; i++) {
        Node* child_node = node->in.slot[i].node;
        if(processNode(child_node)) {
            switch (child_node->out.type) {
            case VT_INT:
                if(child_node->out.value.i_value == 0) {
                    node->out.value.i_value = 0;
                    return true;
                }
                break;
            case VT_DOUBLE:
                if(child_node->out.value.d_value == 0.0) {
                    node->out.value.i_value = 0;
                    return true;
                }
                break;
            
            default:
                return false;
                break;
            }
        }
        else {
            node->out.value.i_value = 0;
            return false;
        }
    }
    return true;
}

Node createNode_BoolAnd(Node* node_0, Node* node_1) {
    return (Node) {
        .in = {
            .slot_0 = {
                .node = node_0,
                .allowed_value_types = VT_INT & VT_DOUBLE,
                .allow_rvalues = true,
            },
            .slot_1 = {
                .node = node_1,
                .allowed_value_types = VT_INT & VT_DOUBLE,
                .allow_rvalues = true,
            },
            .slot_count = 2,
        },
        .out = {
            .type = VT_INT,
            .value.i_value = 0,
            .is_lvalue = false,
            .is_processed = false,
        },
        .processNode = processNode_BoolAnd,
        .text = "&&",
        .error = "",
        .additional_info = NULL,
    };
}

bool processNode_BoolOr(Node* node, const ProcessMode process_mode) {
    if(process_mode == PM_TYPE_ONLY) {
        return processAllNodeInSlots(node, process_mode);
    }
    node->out.value.i_value = 0;
    for(uint32_t i = 0; i < node->in.slot_count; i++) {
        Node* child_node = node->in.slot[i].node;
        if(processNode(child_node)) {
            switch (child_node->out.type) {
            case VT_INT:
                if(child_node->out.value.i_value != 0) {
                    node->out.value.i_value = 1;
                    return true;
                }
                break;
            case VT_DOUBLE:
                if(child_node->out.value.d_value != 0.0) {
                    node->out.value.i_value = 1;
                    return true;
                }
                break;
            
            default:
                return false;
                break;
            }
        }
        else {
            node->out.value.i_value = 0;
            return false;
        }
    }
    return true;
}
Node createNode_BoolOr(Node* node_0, Node* node_1) {
    return (Node) {
        .in = {
            .slot_0 = {
                .node = node_0,
                .allowed_value_types = VT_INT & VT_DOUBLE,
                .allow_rvalues = true,
            },
            .slot_1 = {
                .node = node_1,
                .allowed_value_types = VT_INT & VT_DOUBLE,
                .allow_rvalues = true,
            },
            .slot_count = 2,
        },
        .out = {
            .type = VT_INT,
            .value.i_value = 0,
            .is_lvalue = false,
            .is_processed = false,
        },
        .processNode = processNode_BoolOr,
        .text = "||",
        .error = "",
        .additional_info = NULL,
    };
}