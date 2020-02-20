#ifndef NODE_COMPARE_H
#define NODE_COMPARE_H

#include "node.h"

#define NODE_COMPARE(OPERATOR, NAME) \
bool processNode_##NAME(Node* node, const ProcessMode process_mode) { \
    bool all_ins_valid = processAllNodeInSlots(node, process_mode); \
    if(!all_ins_valid) { \
        return false; \
    } \
    if(process_mode == PM_TYPE_ONLY) { \
        return true; \
    } \
    Node* node_left = node->in.slot_0.node; \
    Node* node_right = node->in.slot_1.node; \
    if(node_left->out.type == VT_INT && node_right->out.type == VT_INT) { \
        node->out.value.i_value = node_left->out.value.i_value OPERATOR  node_right->out.value.i_value; \
    }  \
    else if(node_left->out.type == VT_INT && node_right->out.type == VT_DOUBLE) { \
        node->out.value.i_value = node_left->out.value.i_value OPERATOR  node_right->out.value.d_value; \
    } \
    else if(node_left->out.type == VT_DOUBLE && node_right->out.type == VT_INT) { \
        node->out.value.i_value = node_left->out.value.d_value OPERATOR  node_right->out.value.i_value; \
    } \
    else if(node_left->out.type == VT_DOUBLE && node_right->out.type == VT_DOUBLE) { \
        node->out.value.i_value = node_left->out.value.d_value OPERATOR  node_right->out.value.d_value; \
    }  \
    return true; \
} \
\
Node createNode_##NAME(Node* node_0, Node* node_1) { \
    return (Node) { \
        .in = { \
            .slot_0 = { .node = node_0, .allowed_value_types = VT_INT | VT_DOUBLE, .allow_rvalues = true, }, \
            .slot_1 = { .node = node_1, .allowed_value_types = VT_INT | VT_DOUBLE, .allow_rvalues = true, }, \
            .slot_count = 2, \
        }, \
        .out = { \
            .type = VT_INT, \
            .value.i_value = 0, \
            .is_lvalue = false, \
            .is_processed = false, \
        }, \
        .processNode = processNode_##NAME, \
        .text = #OPERATOR, \
        .error = "", \
        .additional_info = NULL,\
    }; \
} \

NODE_COMPARE(==, Equal)
NODE_COMPARE(!=, NotEqual)
NODE_COMPARE(<, Less)
NODE_COMPARE(<=, LessEqual)
NODE_COMPARE(>, Greater)
NODE_COMPARE(>=, GreaterEqual)

#endif // NODE_COMPARE_H