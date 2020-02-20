#include "node_function.h"

#include <stdlib.h>
#include <math.h>

#define FUNCTION(NAME, VALUE_TYPE, VALUE, ...) \
    else if(!strcmp(node->text, #NAME)) {  \
        node->out.type = VALUE_TYPE; \
        if(process_mode == PM_TYPE_ONLY) { return true; } \
        node->out.value.VALUE = NAME(__VA_ARGS__); \
        return true; \
    }

bool processNode_Function_0(Node* node, const ProcessMode process_mode) {
    if(node->text[0] == '\0') {
        strcpy(node->error, "Function name is empty");
        return false;
    }
    FUNCTION(rand, VT_INT, i_value)
    else {
        sprintf(node->error, "There's no function named '%s'", node->text);
        return false;
    }
}

Node createNode_Function_0(const char* name) {
    Node node = {
        .in = {
            .slot_count = 0,
        }, 
        .out = {
            .type = VT_INT,
            .value.i_value = 0,
            .is_lvalue = false,
            .is_processed = false,
        },
        .processNode = processNode_Function_0,
        .error = "",
        .additional_info = NULL,
    };
    strcpy(node.text, name);
    return node;
}

bool processNode_Function_1(Node* node, const ProcessMode process_mode) {
    bool all_ins_valid = processAllNodeInSlots(node, process_mode);
    if(!all_ins_valid) {
        return false;
    }

    if(node->text[0] == '\0') {
        strcpy(node->error, "Function name is empty");
        return false;
    }
    FUNCTION(sin, VT_DOUBLE, d_value, getAsDouble(node->in.slot_0.node))
    FUNCTION(cos, VT_DOUBLE, d_value, getAsDouble(node->in.slot_0.node))
    FUNCTION(tan, VT_DOUBLE, d_value, getAsDouble(node->in.slot_0.node))
    FUNCTION(asin, VT_DOUBLE, d_value, getAsDouble(node->in.slot_0.node))
    FUNCTION(acos, VT_DOUBLE, d_value, getAsDouble(node->in.slot_0.node))
    FUNCTION(atan, VT_DOUBLE, d_value, getAsDouble(node->in.slot_0.node))
    FUNCTION(sinh, VT_DOUBLE, d_value, getAsDouble(node->in.slot_0.node))
    FUNCTION(cosh, VT_DOUBLE, d_value, getAsDouble(node->in.slot_0.node))
    FUNCTION(tanh, VT_DOUBLE, d_value, getAsDouble(node->in.slot_0.node))
    FUNCTION(exp, VT_DOUBLE, d_value, getAsDouble(node->in.slot_0.node))
    FUNCTION(log, VT_DOUBLE, d_value, getAsDouble(node->in.slot_0.node))
    FUNCTION(log10, VT_DOUBLE, d_value, getAsDouble(node->in.slot_0.node))
    FUNCTION(sqrt, VT_DOUBLE, d_value, getAsDouble(node->in.slot_0.node))
    FUNCTION(ceil, VT_DOUBLE, d_value, getAsDouble(node->in.slot_0.node))
    FUNCTION(floor, VT_DOUBLE, d_value, getAsDouble(node->in.slot_0.node))
    FUNCTION(fabs, VT_DOUBLE, d_value, getAsDouble(node->in.slot_0.node))
    else {
        sprintf(node->error, "There's no function named '%s'", node->text);
        return false;
    }
}

Node createNode_Function_1(Node* arg_list, const char* name) {
    Node node = {
        .in = {
            .slot_0 = {
                .node = arg_list,
                .allowed_value_types = VT_INT | VT_DOUBLE,
                .allow_rvalues = true,
            },
            .slot_count = 1,
        }, 
        .out = {
            .type = VT_INT,
            .value.i_value = 0,
            .is_lvalue = false,
            .is_processed = false,
        },
        .processNode = processNode_Function_1,
        .error = "",
        .additional_info = NULL,
    };
    strcpy(node.text, name);
    return node;
}

bool processNode_Function_2(Node* node, const ProcessMode process_mode) {
    bool all_ins_valid = processAllNodeInSlots(node, process_mode);
    if(!all_ins_valid) {
        return false;
    }

    if(node->text[0] == '\0') {
        strcpy(node->error, "Function name is empty");
        return false;
    }
    FUNCTION(pow, VT_DOUBLE, d_value, getAsDouble(node->in.slot_0.node), getAsDouble(node->in.slot_1.node))
    FUNCTION(atan2, VT_DOUBLE, d_value, getAsDouble(node->in.slot_0.node), getAsDouble(node->in.slot_1.node))
    FUNCTION(ldexp, VT_DOUBLE, d_value, getAsDouble(node->in.slot_0.node), getAsDouble(node->in.slot_1.node))
    // frexp and modf don't work with this implementation, because they need a ptr as 2nd argument
    FUNCTION(fmod, VT_DOUBLE, d_value, getAsDouble(node->in.slot_0.node), getAsDouble(node->in.slot_1.node))
    else {
        sprintf(node->error, "There's no function named '%s'", node->text);
        return false;
    }
}

Node createNode_Function_2(Node* arg_0, Node* arg_1, const char* name) {
    Node node = {
        .in = {
            .slot_0 = {
                .node = arg_0,
                .allowed_value_types = VT_INT | VT_DOUBLE,
                .allow_rvalues = true,
            },
            .slot_1 = {
                .node = arg_1,
                .allowed_value_types = VT_INT | VT_DOUBLE,
                .allow_rvalues = true,
            },
            .slot_count = 2,
        }, 
        .out = {
            .type = VT_INT,
            .value.i_value = 0,
            .is_lvalue = false,
            .is_processed = false,
        },
        .processNode = processNode_Function_2,
        .error = "",
        .additional_info = NULL,
    };
    strcpy(node.text, name);
    return node;
}