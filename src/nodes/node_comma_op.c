#include "node_comma_op.h"

bool processNode_CommaOp(Node* node, const PROCESS_MODE process_mode) {
    bool all_ins_valid = processAllNodeInSlots(node, process_mode);
    if(!all_ins_valid) {
        return false;
    }
    node->out.type = node->in.slot_1.node->out.type;
    if(process_mode == PM_TYPE_ONLY) {
        return true;
    }
    node->out.value = node->in.slot_1.node->out.value;
    return true;
}

Node createNode_CommaOp(Node* node_0, Node* node_1) {
   return (Node) {
        .in = {
            .slot_0 = {
                .node = node_0,
                .allowed_value_types = VT_INT | VT_DOUBLE,
                .allow_rvalues = true,
            },
            .slot_1 = {
                .node = node_1,
                .allowed_value_types = VT_INT | VT_DOUBLE,
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
        .processNode = processNode_CommaOp,
        .error = "",
        .text = ",",
        .additional_info = NULL,
    };
}