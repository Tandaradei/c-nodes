#include "node_plus.h"

Node createNode_Plus_Empty() {
    return (Node) {
        .in_0 = {
            .node = (Node*)0,
            .allowed_value_types = INT | DOUBLE
        },
        .in_1 = {
            .node = (Node*)0,
            .allowed_value_types = INT | DOUBLE
        },
        .in_slot_count = 2,
        .out_type = ERROR,
        .out_value.i_value = 0
    };
}

Node createNode_Plus(Node* node1, Node* node2) {
    Node node = createNode_Plus_Empty();
    node.in_0.node = node1;
    node.in_1.node = node2;
    return node;
}

bool processNode_Plus(Node* node) {
    if(checkNode(node)) {
        ValueType type = getHighestValueType(node);
        node->out_type = type;
        switch (type) {
            case INT:
                node->out_value.i_value = node->in_0.node->out_value.i_value + node->in_1.node->out_value.i_value;
                break;
            case DOUBLE:
                node->out_value.d_value = getAsDouble(node->in_0.node) + getAsDouble(node->in_1.node);
                break;
            default:
                break; 
        }
        return true;
    }
    else {
        node->out_type = ERROR;
        return false;
    }
}