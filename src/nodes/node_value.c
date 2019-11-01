#include "node_value.h"

bool processNode_Value(const NodeIn node_in, NodeOut* node_out) {
    return true;
}

Node createNode_ValueInt(const int value) {
    return (Node) {
        .in = {
            .slot_count = 0,
        }, 
        .out = {
            .type = INT,
            .value.i_value = value
        },
        .processNode = processNode_Value
    };
}

Node createNode_ValueDouble(const double value) {
    return (Node) {
        .in = {
            .slot_count = 0,
        }, 
        .out = {
            .type = DOUBLE,
            .value.d_value = value
        },
        .processNode = processNode_Value
    };
}