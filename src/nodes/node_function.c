#include "node_function.h"

#include <stdlib.h>
#include <math.h>

#define FUNCTION_EMPTY(NAME, VALUE_TYPE, VALUE) \
    else if(!strcmp(node->text, #NAME)) {  \
        node->out.type = VALUE_TYPE; \
        if(process_mode == PM_TYPE_ONLY) { return true; } \
        node->out.value.VALUE = NAME(); \
        return true; \
    }

bool processNode_FunctionEmpty(Node* node, const PROCESS_MODE process_mode) {
    if(node->text[0] == '\0') {
        strcpy(node->error, "Function name is empty");
        return false;
    }
    FUNCTION_EMPTY(rand, VT_INT, i_value)
}

Node createNode_FunctionEmpty(const char* name) {
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
        .processNode = processNode_FunctionEmpty,
        .error = "",
        .additional_info = NULL,
    };
    strcpy(node.text, name);
    return node;
}

bool processNode_Argument(Node* node, const PROCESS_MODE process_mode) {
    bool all_ins_valid = processAllNodeInSlots(node, process_mode);
    if(!all_ins_valid) {
        return false;
    }
    node->out.type = node->in.slot_0.node->out.type;
    if(process_mode == PM_TYPE_ONLY) {
        return true;
    }
    node->out.value = node->in.slot_0.node->out.value;
    writeValue(node->text, node->out.type, node->out.value);
    return true;
}

Node createNode_Argument(Node* value) {
    return (Node) {
        .in = {
            .slot_0 = {
                .node = value,
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
        .processNode = processNode_Argument,
        .error = "",
        .text = "",
        .additional_info = NULL,
    };
}


bool processNode_ArgumentList(Node* node, const PROCESS_MODE process_mode) {
    bool all_ins_valid = processAllNodeInSlots(node, process_mode);
    if(!all_ins_valid) {
        return false;
    }
    node->out.type = node->in.slot_0.node->out.type;
    if(process_mode == PM_TYPE_ONLY) {
        return true;
    }
    node->out.value = node->in.slot_0.node->out.value;
    writeValue(node->text, node->out.type, node->out.value);
    return true;
}

Node createNode_ArgumentList(Node* value, Node* rest) {
    return (Node) {
        .in = {
            .slot_0 = {
                .node = value,
                .allowed_value_types = VT_INT | VT_DOUBLE,
                .allow_rvalues = true,
            },
            .slot_1 = {
                .node = rest,
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
        .processNode = processNode_ArgumentList,
        .error = "",
        .text = "",
        .additional_info = NULL,
    };
}

#define FUNCTION_1_ARG(NAME, VALUE_TYPE, VALUE) \
    else if(!strcmp(node->text, #NAME)) {  \
        if(arg_count != 1) { \
            strcpy(node->error, "Argument count doesn't match"); \
            return false; \
        } \
        node->out.type = VALUE_TYPE; \
        if(process_mode == PM_TYPE_ONLY) { return true; } \
        node->out.value.VALUE = NAME(arg_types[0] == VT_INT ? arg_values[0].i_value : arg_values[0].d_value); \
        return true; \
    }

#define FUNCTION_2_ARG(NAME, VALUE_TYPE, VALUE) \
    else if(!strcmp(node->text, #NAME)) {  \
        if(arg_count != 2) { \
            strcpy(node->error, "Argument count doesn't match"); \
            return false; \
        } \
        node->out.type = VALUE_TYPE; \
        if(process_mode == PM_TYPE_ONLY) { return true; } \
        node->out.value.VALUE = NAME( \
            arg_types[0] == VT_INT ? arg_values[0].i_value : arg_values[0].d_value, \
            arg_types[1] == VT_INT ? arg_values[1].i_value : arg_values[1].d_value \
        ); \
        return true; \
    }

#define FUNCTION_3_ARG(NAME, VALUE_TYPE, VALUE) \
    else if(!strcmp(node->text, #NAME)) {  \
        if(arg_count != 3) { \
            strcpy(node->error, "Argument count doesn't match"); \
            return false; \
        } \
        node->out.type = VALUE_TYPE; \
        if(process_mode == PM_TYPE_ONLY) { return true; } \
        node->out.value.VALUE = NAME( \
            arg_types[0] == VT_INT ? arg_values[0].i_value : arg_values[0].d_value, \
            arg_types[1] == VT_INT ? arg_values[1].i_value : arg_values[1].d_value, \
            arg_types[2] == VT_INT ? arg_values[2].i_value : arg_values[2].d_value \
        ); \
        return true; \
    }

#define MAX_ARGS 16

bool processNode_Function(Node* node, const PROCESS_MODE process_mode) {
    bool all_ins_valid = processAllNodeInSlots(node, process_mode);
    if(!all_ins_valid) {
        return false;
    }
    ValueType arg_types[MAX_ARGS];
    Value arg_values[MAX_ARGS];
    unsigned int arg_count = 0;
    Node* cur_arg = node->in.slot_0.node;
    while(cur_arg && arg_count < MAX_ARGS) {
        arg_types[arg_count] = cur_arg->out.type;
        arg_values[arg_count] = cur_arg->out.value;
        cur_arg = cur_arg->in.slot_count > 1 ? cur_arg->in.slot_1.node : NULL;
        arg_count++;
    }

    if(node->text[0] == '\0') {
        strcpy(node->error, "Function name is empty");
        return false;
    }
    FUNCTION_1_ARG(sin, VT_DOUBLE, d_value)
    FUNCTION_1_ARG(cos, VT_DOUBLE, d_value)
    FUNCTION_1_ARG(tan, VT_DOUBLE, d_value)
    FUNCTION_1_ARG(asin, VT_DOUBLE, d_value)
    FUNCTION_1_ARG(acos, VT_DOUBLE, d_value)
    FUNCTION_1_ARG(atan, VT_DOUBLE, d_value)
    FUNCTION_2_ARG(atan2, VT_DOUBLE, d_value)
    FUNCTION_1_ARG(sinh, VT_DOUBLE, d_value)
    FUNCTION_1_ARG(cosh, VT_DOUBLE, d_value)
    FUNCTION_1_ARG(tanh, VT_DOUBLE, d_value)
    FUNCTION_1_ARG(exp, VT_DOUBLE, d_value)
    FUNCTION_1_ARG(log, VT_DOUBLE, d_value)
    FUNCTION_1_ARG(log10, VT_DOUBLE, d_value)
    FUNCTION_2_ARG(pow, VT_DOUBLE, d_value)
    FUNCTION_1_ARG(sqrt, VT_DOUBLE, d_value)
    FUNCTION_1_ARG(ceil, VT_DOUBLE, d_value)
    FUNCTION_1_ARG(floor, VT_DOUBLE, d_value)
    FUNCTION_1_ARG(fabs, VT_DOUBLE, d_value)
    FUNCTION_2_ARG(ldexp, VT_DOUBLE, d_value)
    // frexp and modf don't work with this implementation, because they need a ptr as 2nd argument
    FUNCTION_2_ARG(fmod, VT_DOUBLE, d_value)
}

Node createNode_Function(Node* arg_list, const char* name) {
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
        .processNode = processNode_Function,
        .error = "",
        .additional_info = NULL,
    };
    strcpy(node.text, name);
    return node;
}