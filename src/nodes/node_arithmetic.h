#ifndef NODE_ARITHMETIC_H
#define NODE_ARITHMETIC_H

#include <stdbool.h>
#include "node.h"

#define NODE_ARITHMETIC(OPERATOR, NAME) \
bool processNode_##NAME(Node* node, const ProcessMode process_mode) { \
    bool all_ins_valid = processAllNodeInSlots(node, process_mode); \
    if(!all_ins_valid) { \
        return false; \
    } \
    ValueType type = getHighestValueType(node->in); \
    node->out.type = type;\
    if(process_mode == PM_TYPE_ONLY) { \
        return node->out.type != VT_ERROR; \
    } \
    switch (type) {\
        case VT_INT:\
            node->out.value.i_value = getAsInt(node->in.slot[0].node) OPERATOR getAsInt(node->in.slot[1].node);\
            break;\
        case VT_DOUBLE:\
            node->out.value.d_value = getAsDouble(node->in.slot[0].node) OPERATOR getAsDouble(node->in.slot[1].node);\
            break;\
        default:\
            break; \
    }\
    return true;\
}\
\
Node createNode_##NAME(Node* node_0, Node* node_1) { \
    return (Node) { \
        .in = { \
            .slot_0 = { .node = node_0, .allowed_value_types = VT_INT | VT_DOUBLE, .allow_rvalues = true, }, \
            .slot_1 = { .node = node_1, .allowed_value_types = VT_INT | VT_DOUBLE, .allow_rvalues = true, }, \
            .slot_count = 2, \
        }, \
        .out = { \
            .type = VT_ERROR, \
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

NODE_ARITHMETIC(+, Plus)
NODE_ARITHMETIC(-, Sub)
NODE_ARITHMETIC(*, Mult)
NODE_ARITHMETIC(/, Divide)

bool processNode_Modulo(Node* node, const ProcessMode process_mode) { 
    bool all_ins_valid = processAllNodeInSlots(node, process_mode); 
    if(!all_ins_valid) { 
        return false; 
    }
    ValueType type = getHighestValueType(node->in); 
    node->out.type = type;
    if(type != VT_INT) {
        strcpy(node->error, "Both children must be of type 'int'");
        return false;
    }
    if(process_mode == PM_TYPE_ONLY) {
        return true; 
    } 
    // Value deduction
    node->out.value.i_value = getAsInt(node->in.slot[0].node) % getAsInt(node->in.slot[1].node);
    return true;
}

Node createNode_Modulo(Node* node_0, Node* node_1) { 
    return (Node) { 
        .in = { 
            .slot_0 = { .node = node_0, .allowed_value_types = VT_INT, .allow_rvalues = true, }, 
            .slot_1 = { .node = node_1, .allowed_value_types = VT_INT, .allow_rvalues = true, }, 
            .slot_count = 2, 
        }, 
        .out = { 
            .type = VT_ERROR, 
            .value.i_value = 0, 
            .is_lvalue = false, 
            .is_processed = false, 
        }, 
        .processNode = processNode_Modulo, 
        .text = "%", 
        .error = "",
        .additional_info = NULL,
    }; 
} 


#endif // NODE_ARITHMETIC_H