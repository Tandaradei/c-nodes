#ifndef NODE_ARITHMETIC_H
#define NODE_ARITHMETIC_H

#include <stdbool.h>
#include "node.h"

#define NODE_ARITHMETIC(OPERATOR, NAME) \
Node createNode_##NAME##_Empty() { \
    return (Node) { \
        .in_0 = { .node = (Node*)0, .allowed_value_types = INT | DOUBLE }, \
        .in_1 = { .node = (Node*)0, .allowed_value_types = INT | DOUBLE }, \
        .in_slot_count = 2, \
        .out_type = ERROR, \
        .out_value.i_value = 0 \
    }; \
} \
\
Node createNode_##NAME(Node* node1, Node* node2) { \
    Node node = createNode_##NAME##_Empty(); \
    node.in_0.node = node1;\
    node.in_1.node = node2;\
    return node;\
}\
\
bool processNode_##NAME(Node* node) {\
    if(checkNode(node)) {\
        ValueType type = getHighestValueType(node);\
        node->out_type = type;\
        switch (type) {\
            case INT:\
                node->out_value.i_value = node->in_0.node->out_value.i_value OPERATOR node->in_1.node->out_value.i_value;\
                break;\
            case DOUBLE:\
                node->out_value.d_value = getAsDouble(node->in_0.node) OPERATOR getAsDouble(node->in_1.node);\
                break;\
            default:\
                break; \
        }\
        return true;\
    }\
    else {\
        node->out_type = ERROR;\
        return false;\
    }\
}

NODE_ARITHMETIC(+, Plus)
NODE_ARITHMETIC(-, Sub)
NODE_ARITHMETIC(*, Mult)
NODE_ARITHMETIC(/, Divide)


#endif // NODE_ARITHMETIC_H