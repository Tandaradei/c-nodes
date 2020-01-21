#include "node_declaration.h"

bool processNode_Declaration(Node* node, const PROCESS_MODE process_mode) {
    return processAllNodeInSlots(node, process_mode);
}

Node createNode_Declaration(Node* config, Node* symbol_list) {
    return (Node) {
         .in = {
            .slot_0 = {
                .node = config,
                .allowed_value_types = VT_INT | VT_DOUBLE,
                .allow_rvalues = true,
            },
            .slot_1 = {
                .node = symbol_list,
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
        .processNode = processNode_Declaration,
        .error = "",
        .text = "<Declaration>",
        .additional_info = NULL,
    };
}

bool processNode_SymbolDeclarationList(Node* node, const PROCESS_MODE process_mode) {
    return processAllNodeInSlots(node, process_mode);
}

Node createNode_SymbolDeclarationList(Node* symbol_list, Node* symbol) {
    return (Node) {
         .in = {
            .slot_0 = {
                .node = symbol_list,
                .allowed_value_types = VT_INT | VT_DOUBLE,
                .allow_rvalues = true,
            },
            .slot_1 = {
                .node = symbol,
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
        .processNode = processNode_SymbolDeclarationList,
        .error = "",
        .text = "<DeclList>",
        .additional_info = NULL,
    };
}