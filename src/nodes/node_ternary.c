#include "node_ternary.h"

bool processNode_Ternary(Node* node) {
    bool valid_until_now = true;
    if(!processNode(node->in.slot_0.node)) {
        valid_until_now = false;
    }
    if(valid_until_now) {
        Node* expr_to_use = node->in.slot[getAsInt(node->in.slot_0.node) ? 1 : 2].node;
        if(!processNode(expr_to_use)) {
            valid_until_now = false;
        }
        node->out.type = expr_to_use->out.type;
        node->out.value = expr_to_use->out.value;
    }
    return valid_until_now;

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
            .type = VT_UNPROCESSED,
            .value.i_value = 0,
            .is_lvalue = false,
        },
        .processNode = processNode_Ternary,
        .text = "?:",
        .additional_info = NULL,
        .symbol_handle = 0,
    };
}