#include "node.h"

#include <stdbool.h>
#include <stdio.h>

bool checkNode(const Node* node) {
    for(unsigned int slot = 0; slot < node->in_slot_count; slot++) {
        if(!(node->in[slot].node && node->in[slot].allowed_value_types & node->in[slot].allowed_value_types)) {
            return false;
        }
    }
    return true;
}

ValueType getHighestValueType(const Node* node) {
    ValueType type = INT;
    for(unsigned int slot = 0; slot < node->in_slot_count; slot++) {
        if(node->in[slot].node->out_type > type) {
            type = node->in[slot].node->out_type;
        }
    }
    return type;
}

int getAsInt(const Node* node) {
    switch(node->out_type) {
        case INT: return node->out_value.i_value;
        case DOUBLE: return (int)node->out_value.d_value;
        default: return 0;
    };
}

double getAsDouble(const Node* node) {
    switch(node->out_type) {
        case INT: return (double)node->out_value.i_value;
        case DOUBLE: return node->out_value.d_value;
        default: return 0.0;
    };
}

void printNodeValue(const Node* node) {
    switch (node->out_type) {
    case INT:
        printf("%d", node->out_value.i_value);
        break;
    case DOUBLE:
        printf("%f", node->out_value.d_value);
        break;
    default:
        printf("<ERROR>");
        break;
    }
}

void printNodeType(const Node* node) {
    switch (node->out_type) {
    case INT:
        printf("<INT>");
        break;
    case DOUBLE:
        printf("<DOUBLE>");
        break;
    default:
        printf("<ERROR>");
        break;
    }
}