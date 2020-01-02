#include "node_ternary.h"

#include <string.h>

bool processNode_Ternary(Node* node, const PROCESS_MODE process_mode) {
    if(process_mode == PM_TYPE_ONLY) {
        bool all_ins_valid = processAllNodeInSlots(node, process_mode);
        if(all_ins_valid) {
            if(node->in.slot_1.node->out.type == node->in.slot_2.node->out.type) {
                node->out.type = node->in.slot_1.node->out.type;
                return true;
            }
            else {
                strcpy(node->error, "Type mismatch of return values");
            }
        }
        return false;
    }
    Node* cond_node = node->in.slot_0.node;
    if(!processNode(cond_node)) {
        strcpy(node->error, "Runtime error in condition");
        return false;
    }
    bool cond_value = false;
    switch(cond_node->out.type) {
        case VT_INT:
            cond_value = getAsInt(cond_node);
            break;
        case VT_DOUBLE:
            cond_value = getAsDouble(cond_node) != 0.0;
            break;
        default:
            break;
    }
    Node* expr_to_use = node->in.slot[cond_value ? 1 : 2].node;
    if(!processNode(expr_to_use)) {
        strcpy(node->error, "Runtime error in selected return value");
        return false;
    }
    node->out.value = expr_to_use->out.value;
    return true;

}

Node createNode_Ternary(Node* cond, Node* true_expr, Node* false_expr) {
    return (Node) {
        .in = {
            .slot_0 = {
                .node = cond,
                .allowed_value_types = VT_INT | VT_DOUBLE,
                .allow_rvalues = true,
            },
            .slot_1 = {
                .node = true_expr,
                .allowed_value_types = VT_INT | VT_DOUBLE,
                .allow_rvalues = true,
            },
            .slot_2 = {
                .node = false_expr,
                .allowed_value_types = VT_INT | VT_DOUBLE,
                .allow_rvalues = true,
            },
            .slot_count = 3,
        }, 
        .out = {
            .type = VT_ERROR,
            .value.i_value = 0,
            .is_lvalue = false,
            .is_processed = false,
        },
        .processNode = processNode_Ternary,
        .text = "?:",
        .error = "",
        .additional_info = NULL,
        .symbol_handle = 0,
    };
}