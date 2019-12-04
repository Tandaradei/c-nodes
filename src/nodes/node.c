#include "node.h"

#include <stdbool.h>
#include <stdio.h>

bool processNodeDefault(Node* node) {
    return true;
}

Node createNode(void) {
    return (Node){
        .in = {
            .slot_count = 0,
        },
        .out = {
            .type = VT_ERROR,
            .value.i_value = 0,
        },
        .processNode = processNodeDefault,
        .text = "Default",
        .additional_info = NULL,
    };
}

Node createNode_BasicBinary(Node* node_0, Node* node_1) {
    return (Node){
        .in = {
            .slot_0 = {
                .node = node_0,
                .allowed_value_types = VT_DOUBLE | VT_INT,
                .allow_rvalues = true,
            },
            .slot_1 = {
                .node = node_1,
                .allowed_value_types = VT_DOUBLE | VT_INT,
                .allow_rvalues = true,
            },
            .slot_count = 2,
        },
        .out = {
            .type = VT_ERROR,
            .value.i_value = 0,
        },
        .processNode = processNodeDefault,
        .text = "BasicBinary",
        .additional_info = NULL,
        .symbol_handle = 0,
    };
}

bool checkNode(const NodeIn node_in) {
    for(unsigned int i = 0; i < node_in.slot_count; i++) {
        if(!(
            node_in.slot[i].node 
        && (node_in.slot[i].allowed_value_types & node_in.slot[i].allowed_value_types)
        && (node_in.slot[i].allow_rvalues || node_in.slot[i].node->out.is_lvalue)
        )) {
            return false;
        }
    }
    return true;
}

ValueType getHighestValueType(const NodeIn node_in) {
    ValueType type = VT_INT;
    for(unsigned int i = 0; i < node_in.slot_count; i++) {
        if(node_in.slot[i].node->out.type > type) {
            type = node_in.slot[i].node->out.type;
        }
    }
    return type;
}

bool processNode(Node* node) {
    bool is_successful = false;
    bool all_ins_valid = true;
    for(unsigned int i = 0; i < node->in.slot_count; i++) {
        if(!processNode(node->in.slot[i].node)) {
            all_ins_valid = false;
            break;
        }
    }
    if(all_ins_valid && node->processNode && checkNode(node->in)) {
        is_successful = node->processNode(node);
    }
    if(!is_successful) {
        node->out.type = VT_ERROR;
    }
    return is_successful;
}


int getAsInt(const Node* node) {
    switch(node->out.type) {
        case VT_INT: return node->out.value.i_value;
        case VT_DOUBLE: return (int)node->out.value.d_value;
        default: return 0;
    };
}

double getAsDouble(const Node* node) {
    switch(node->out.type) {
        case VT_INT: return (double)node->out.value.i_value;
        case VT_DOUBLE: return node->out.value.d_value;
        default: return 0.0;
    };
}

void printNodeValue(FILE* file, const NodeOut node_out) {
    switch (node_out.type) {
    case VT_INT:
        PRINT(file, "%d",node_out.value.i_value);
        break;
    case VT_DOUBLE:
        PRINT(file, "%f", node_out.value.d_value);
        break;
    default:
        PRINT(file, "ERROR");
        break;
    }
}

void printNodeType(const NodeOut node_out) {
    switch (node_out.type) {
    case VT_INT:
        printf("<INT>");
        break;
    case VT_DOUBLE:
        printf("<DOUBLE>");
        break;
    default:
        printf("<ERROR>");
        break;
    }
}

void printNodeRecursively_Basic(const Node* node, const uint8_t depth) {
    if(!node) {
        printf("NULL\n");
        return;
    }
    printf("%s%s\n", &"              "[14-depth], node->text);
    for(uint8_t i = 0; i < node->in.slot_count; i++) {
        printNodeRecursively_Basic(node->in.slot[i].node, depth + 1);
    }
}

void printNodeRecursively_Enhanced(const Node* node, const uint8_t depth) {
    if(!node) {
        printf("Reached null node\n");
        return;
    }
    printf("%s[%s] T: ", &"              "[14-depth], node->text);
    printNodeType(node->out);
    printf(" | V: ");
    printNodeValue(NULL, node->out);
    printf(" | # In slots: %d\n", node->in.slot_count);
    for(unsigned int i = 0; i < node->in.slot_count; i++) {
        printNodeRecursively_Enhanced(node->in.slot[i].node, depth + 1);
    }
}

void printNodeRecursively_Tikz(FILE* file, const Node* node, const uint8_t depth) {
    if(!node) {
        return;
    }
    PRINT(file, "node[fill=%s,%s label={", getColorForValueType(node->out.type), node->out.is_lvalue ? " double," : "");
    printNodeValue(file, node->out);
    PRINT(file, "}] { %s }", node->text);
    if(node->in.slot_count > 0) {
        PRINT(file, "\n");
        for(unsigned int i = 0; i < node->in.slot_count; i++) {
            PRINT(file, "%schild { ", &"              "[14-depth]);
            printNodeRecursively_Tikz(file, node->in.slot[i].node, depth + 1);
            PRINT(file, "%s}\n", &"              "[14-depth]);
        }
    }
}

void printNodeRecursively_D3Json(FILE* file, const Node* node, const uint8_t depth) {
    if(!node) {
        return;
    }
    PRINT(file, "%s{ \"name\": \"%s\",\n", &"              "[14-depth], node->text);
    PRINT(file, "%s  \"children\":[\n", &"              "[14-depth]);
    if(node->in.slot_count > 0) {
        for(unsigned int i = 0; i < node->in.slot_count; i++) {
            printNodeRecursively_D3Json(file, node->in.slot[i].node, depth + 1);
            PRINT(file, "%s", i < node->in.slot_count - 1 ? ",\n" : "");
        }
    }
    PRINT(file, "%s]}\n", &"              "[14-depth]);
}