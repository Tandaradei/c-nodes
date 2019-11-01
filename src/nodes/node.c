#include "node.h"

#include <stdbool.h>
#include <stdio.h>

bool checkNode(const NodeIn node_in) {
    for(unsigned int i = 0; i < node_in.slot_count; i++) {
        if(!(node_in.slot[i].node && node_in.slot[i].allowed_value_types & node_in.slot[i].allowed_value_types)) {
            return false;
        }
    }
    return true;
}

ValueType getHighestValueType(const NodeIn node_in) {
    ValueType type = INT;
    for(unsigned int i = 0; i < node_in.slot_count; i++) {
        if(node_in.slot[i].node->out.type > type) {
            type = node_in.slot[i].node->out.type;
        }
    }
    return type;
}

bool processNode(Node* node) {
    if(checkNode(node->in)) {
        bool all_ins_valid = true;
        for(unsigned int i = 0; i < node->in.slot_count; i++) {
            if(!processNode(node->in.slot[i].node)) {
                all_ins_valid = false;
                break;
            }
        }
        if(all_ins_valid && node->processNode) {
            return node->processNode(node->in, &node->out);
        }
    }
    return false;
}

int getAsInt(const NodeOut node_out) {
    switch(node_out.type) {
        case INT: return node_out.value.i_value;
        case DOUBLE: return (int)node_out.value.d_value;
        default: return 0;
    };
}

double getAsDouble(const NodeOut node_out) {
    switch(node_out.type) {
        case INT: return (double)node_out.value.i_value;
        case DOUBLE: return node_out.value.d_value;
        default: return 0.0;
    };
}

void printNodeValue(const NodeOut node_out) {
    switch (node_out.type) {
    case INT:
        printf("%d", node_out.value.i_value);
        break;
    case DOUBLE:
        printf("%f", node_out.value.d_value);
        break;
    default:
        printf("<ERROR>");
        break;
    }
}

void printNodeType(const NodeOut node_out) {
    switch (node_out.type) {
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