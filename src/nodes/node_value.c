#include "node_value.h"

#include <stdio.h>
#include <string.h>

bool processNode_Value(Node* node, const PROCESS_MODE process_mode) {
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
            .value.i_value = value,
            .is_lvalue = false,
            .is_processed = false,
        },
        .processNode = processNode_Value,
        .error = "",
        .additional_info = NULL,
    };
    strcpy(node.text, converted_value);
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
            .value.d_value = value,
            .is_lvalue = false,
            .is_processed = false,
        },
        .processNode = processNode_Value,
        .error = "",
        .additional_info = NULL,
    };
    strcpy(node.text, converted_value);
    return node;
}