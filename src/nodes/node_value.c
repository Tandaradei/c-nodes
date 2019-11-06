#include "node_value.h"

#include <stdio.h>
#include <string.h>

bool processNode_Value(Node* node) {
    return true;
}

Node createNode_ValueInt(const int value) {
    char converted_value[20];
    snprintf(converted_value, 20, "%d", value);
    Node node = {
        .in = {
            .slot_count = 0,
        }, 
        .out = {
            .type = VT_INT,
            .value.i_value = value
        },
        .processNode = processNode_Value,
        .additional_info = NULL,
    };
    strcpy_s(node.text, 20, converted_value);
    return node;
}

Node createNode_ValueDouble(const double value) {
    char converted_value[20];
    snprintf(converted_value, 20, "%f", value);
    Node node = {
        .in = {
            .slot_count = 0,
        }, 
        .out = {
            .type = VT_DOUBLE,
            .value.d_value = value
        },
        .processNode = processNode_Value,
        .additional_info = NULL,
    };
    strcpy_s(node.text, 20, converted_value);
    return node;
}