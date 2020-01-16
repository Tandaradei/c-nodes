#include "node_shift_ops.h"

bool processNode_ShiftLeft(Node* node, const PROCESS_MODE process_mode) {
    bool all_ins_valid = processAllNodeInSlots(node, process_mode);
    if(!all_ins_valid) {
        return false;
    }
    node->out.type = node->in.slot_0.node->out.type;
    if(process_mode == PM_TYPE_ONLY) {
        return node->out.type != VT_ERROR;
    }
    node->out.value.i_value = node->in.slot_0.node->out.value.i_value << node->in.slot_1.node->out.value.i_value;
    return true;
}

Node createNode_ShiftLeft(Node* node_0, Node* node_1) {
    return (Node) {
        .in = {
            .slot_0 = {
                .node = node_0,
                .allowed_value_types = VT_INT,
                .allow_rvalues = true,
            },
            .slot_1 = {
                .node = node_1,
                .allowed_value_types = VT_INT,
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
        .processNode = processNode_ShiftLeft,
        .text = "<<",
        .error = "",
        .additional_info = NULL,
    };
}

bool processNode_ShiftRight(Node* node, const PROCESS_MODE process_mode) {
    bool all_ins_valid = processAllNodeInSlots(node, process_mode);
    if(!all_ins_valid) {
        return false;
    }
    node->out.type = node->in.slot_0.node->out.type;
    if(process_mode == PM_TYPE_ONLY) {
        return node->out.type != VT_ERROR;
    }
    node->out.value.i_value = node->in.slot_0.node->out.value.i_value >> node->in.slot_1.node->out.value.i_value;
    return true;
}

Node createNode_ShiftRight(Node* node_0, Node* node_1) {
    return (Node) {
        .in = {
            .slot_0 = {
                .node = node_0,
                .allowed_value_types = VT_INT,
                .allow_rvalues = true,
            },
            .slot_1 = {
                .node = node_1,
                .allowed_value_types = VT_INT,
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
        .processNode = processNode_ShiftRight,
        .text = ">>",
        .error = "",
        .additional_info = NULL,
    };
}