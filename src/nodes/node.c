#include "node.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool processNodeDefault(Node* node, const ProcessMode process_mode) {
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
            .is_lvalue = false,
            .is_processed = false,
        },
        .processNode = processNodeDefault,
        .text = "Default",
        .error = "DEBUG: This node wasn't properly initialized",
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
            .is_lvalue = false,
            .is_processed = false,
        },
        .processNode = processNodeDefault,
        .text = "BasicBinary",
        .additional_info = NULL,
        .symbol_handle = 0,
    };
}

bool checkNodeIn(const NodeIn node_in) {
    for(uint8_t i = 0; i < node_in.slot_count; i++) {
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
    for(uint8_t i = 0; i < node_in.slot_count; i++) {
        if(node_in.slot[i].node->out.type > type) {
            type = node_in.slot[i].node->out.type;
        }
    }
    return type;
}

bool findNodeValueType(Node* node) {
    if(node->processNode) {
        if( node->processNode(node, PM_TYPE_ONLY)) {
            return true;
        }
    }
    else {
        strcpy(node->error, "DEBUG: Can't find processing function for this node");
    }
    node->out.type = VT_ERROR;
    if(node->error[0] == '\0') {
        strcpy(node->error, "Compile error in children (can't get type for this node)");
    }
    return false;
}

bool processAllNodeInSlots(Node* node, const ProcessMode process_mode) {
    bool type_deduction_result = true;
    switch (process_mode)
    {
    case PM_TYPE_ONLY:
        for(uint8_t i = 0; i < node->in.slot_count; i++) {
            if(!findNodeValueType(node->in.slot[i].node)) {
                type_deduction_result = false;
            }
        }
        return type_deduction_result;
        break;
    
    case PM_FULL:
        for(uint8_t i = 0; i < node->in.slot_count; i++) {
            if(!processNode(node->in.slot[i].node)) {
                return false;
            }
        }
        return true;
        break;
    }
    
}

bool processNode(Node* node) {
    assert(!node->out.is_processed);
    node->out.is_processed = true;
    if(node->processNode) {
        if( node->processNode(node, PM_FULL)) {
            return true;
        }
    }
    else {
        strcpy(node->error, "DEBUG: Can't find processing function for this node");
    }
    node->out.type = VT_ERROR;
    if(node->error[0] == '\0') {
        strcpy(node->error, "Runtime error in children (can't get value for this node)");
    }
    return false;
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
    case VT_ERROR:
        PRINT(file, " ");
        break;
    case VT_INT:
        PRINT(file, "%d", node_out.value.i_value);
        break;
    case VT_DOUBLE:
        PRINT(file, "%f", node_out.value.d_value);
        break;
    }
}

void printNodeType(FILE* file, const NodeOut node_out) {
    PRINT(file, "%s", getStringForValueType(node_out.type));
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
    printNodeType(NULL, node->out);
    printf(" | V: ");
    printNodeValue(NULL, node->out);
    printf(" | # In slots: %d\n", node->in.slot_count);
    for(uint8_t i = 0; i < node->in.slot_count; i++) {
        printNodeRecursively_Enhanced(node->in.slot[i].node, depth + 1);
    }
}

void printNodeRecursively_Tex(FILE* file, const Node* node, const uint8_t depth) {
    if(!node) {
        return;
    }
    PRINT(file, "node[fill=%s,%s label={", getColorForValueType(node->out.type), node->out.is_lvalue ? " double," : "");
    printNodeValue(file, node->out);
    PRINT(file, "}] { %s }", node->text);
    if(node->in.slot_count > 0) {
        PRINT(file, "\n");
        for(uint8_t i = 0; i < node->in.slot_count; i++) {
            PRINT(file, "%schild { ", &"              "[14-depth]);
            printNodeRecursively_Tex(file, node->in.slot[i].node, depth + 1);
            PRINT(file, "%s}\n", &"              "[14-depth]);
        }
    }
}

void printNodeRecursively_Json(FILE* file, const Node* node, const uint8_t depth) {
    if(!node) {
        return;
    }
    PRINT(file, "%s{ \"name\": \"%s\",\n", &"              "[14-depth], node->text);
    PRINT(file, "%s  \"result\": \"", &"              "[14-depth]);
    printNodeValue(file, node->out);
    PRINT(file, "\",\n");
    PRINT(file, "%s  \"error\": \"%s\",\n", &"              "[14-depth], node->error)
    PRINT(file, "%s  \"type\": \"", &"              "[14-depth]);
    printNodeType(file, node->out);
    PRINT(file, "\",\n");
    PRINT(file, "%s  \"processed\": %s,\n", &"              "[14-depth], node->out.is_processed ? "true" : "false");
    PRINT(file, "%s  \"children\":[", &"              "[14-depth]);
    if(node->in.slot_count > 0) {
        PRINT(file, "\n");
        for(uint8_t i = 0; i < node->in.slot_count; i++) {
            printNodeRecursively_Json(file, node->in.slot[i].node, depth + 1);
            PRINT(file, "%s", i < node->in.slot_count - 1 ? ",\n" : "");
        }
        PRINT(file, "\n%s]}\n", &"              "[14-depth]);
    }
    else {
        PRINT(file, "]\n%s}", &"              "[14-depth]);
    }
    
}