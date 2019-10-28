#include "node_value.h"

Node createNode_ValueInt(const int value) {
    return (Node) {
        .in_slot_count = 0,
        .out_type = INT,
        .out_value.i_value = value
    };
}

Node createNode_ValueDouble(const double value) {
    return (Node) {
        .in_slot_count = 0,
        .out_type = DOUBLE,
        .out_value.d_value = value
    };
}