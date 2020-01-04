#include "node_cast.h"

bool processNode_Cast(Node* node, const PROCESS_MODE process_mode) {
    bool all_ins_valid = processAllNodeInSlots(node, process_mode);
    if(!all_ins_valid) {
        return false;
    }
    node->out.type = getValueTypeForString(node->text);
    if(node->out.type == VT_ERROR) {
        strcpy(node->error, "No valid typename");
        return false;
    }
    if(process_mode == PM_TYPE_ONLY) {
        return true;
    }
    if(node->out.type == node->in.slot_0.node->out.type) {
        node->out.value = node->in.slot_0.node->out.value;
    }
    else {
        switch(node->out.type) {
            case VT_INT:
                switch(node->in.slot_0.node->out.type) {
                    case VT_DOUBLE:
                        node->out.value.i_value = (int)node->in.slot_0.node->out.value.d_value;
                        break;
                    default:
                        strcpy(node->error, "Can't cast to int");
                        return false;
                        break;
                }
                break;
            case VT_DOUBLE: 
                switch(node->in.slot_0.node->out.type) {
                    case VT_INT:
                        node->out.value.d_value = (double)node->in.slot_0.node->out.value.i_value;
                        break;
                    default:
                        strcpy(node->error, "Can't cast to double");
                        return false;
                        break;
                }
                break;
            default:
                break;
        }
    }
    return true;
}

Node createNode_Cast(Node* node_0, const char* typename) {
    Node node = {
        .in = {
            .slot_0 = {
                .node = node_0,
                .allowed_value_types = VT_INT & VT_DOUBLE,
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
        .processNode = processNode_Cast,
        .text = "",
        .error = "",
        .additional_info = NULL,
    };
    strcpy(node.text, typename);
    return node;
}