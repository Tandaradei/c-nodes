#ifndef NODE_ARITHMETIC_H
#define NODE_ARITHMETIC_H

#include <stdbool.h>
#include "node.h"

#define NODE_ARITHMETIC(OPERATOR, NAME) \
bool processNode_##NAME(Node* node) {\
    if(checkNode(node->in)) {\
        ValueType type = getHighestValueType(node->in);\
        node->out.type = type;\
        switch (type) {\
            case VT_INT:\
                node->out.value.i_value = node->in.slot[0].node->out.value.i_value OPERATOR node->in.slot[1].node->out.value.i_value;\
                break;\
            case VT_DOUBLE:\
                 node->out.value.d_value = getAsDouble(node->in.slot[0].node->out) OPERATOR getAsDouble(node->in.slot[1].node->out);\
                break;\
            default:\
                break; \
        }\
        return true;\
    }\
    else {\
        node->out.type = VT_ERROR;\
        return false;\
    }\
}\
\
Node createNode_##NAME##_Empty() { \
    return (Node) { \
        .in = { \
            .slot_0 = { .node = (Node*)0, .allowed_value_types = VT_INT | VT_DOUBLE }, \
            .slot_1 = { .node = (Node*)0, .allowed_value_types = VT_INT | VT_DOUBLE }, \
            .slot_count = 2, \
        }, \
        .out = { \
            .type = VT_ERROR, \
            .value.i_value = 0 \
        }, \
        .processNode = processNode_##NAME, \
        .text = #OPERATOR, \
        .additional_info = NULL,\
    }; \
} \
\
Node createNode_##NAME(Node* node_0, Node* node_1) { \
    Node node = createNode_##NAME##_Empty(); \
    node.in.slot[0].node = node_0;\
    node.in.slot[1].node = node_1;\
    return node;\
}\

NODE_ARITHMETIC(+, Plus)
NODE_ARITHMETIC(-, Sub)
NODE_ARITHMETIC(*, Mult)
NODE_ARITHMETIC(/, Divide)


#endif // NODE_ARITHMETIC_H