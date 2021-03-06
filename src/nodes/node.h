#ifndef NODE_H
#define NODE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "src/values.h"
#include "src/symtab.h"

typedef struct Node Node;

typedef struct InSlot {
    Node* node;
    uint32_t allowed_value_types;
    bool allow_rvalues;
} InSlot;

typedef struct NodeIn {
    union {
        struct {
            InSlot slot_0;
            InSlot slot_1;
            InSlot slot_2;
        };
        InSlot slot[3];
    };
    uint8_t slot_count;
} NodeIn;

typedef struct NodeOut {
    ValueType   type;
    Value       value;
    bool        is_lvalue;
    bool        is_processed;
} NodeOut;

typedef enum ProcessMode {
    PM_TYPE_ONLY,
    PM_FULL
} ProcessMode;

typedef struct Node {
    NodeIn in;
    NodeOut out;
    bool (*processNode)(Node* node, const ProcessMode process_mode);
    char text[20];
    char error[200];
    void* additional_info;
    SymbolHandle symbol_handle;
} Node;


Node createNode(void);

Node createNode_BasicBinary(Node* node_0, Node* node_1);

bool checkNodeIn(const NodeIn node_in);

ValueType getHighestValueType(const NodeIn node_in);

bool findNodeValueType(Node* node);

bool processAllNodeInSlots(Node* node, const ProcessMode process_mode);
bool processNode(Node* node);

int getAsInt(const Node* node);
double getAsDouble(const Node* node);

void printNodeValue(FILE* file, const NodeOut node_out);
void printNodeType(FILE* file, const NodeOut node_out);

#define PRINT(file, ...) \
if(file) { \
    fprintf(file, __VA_ARGS__); \
} \
else { \
    printf(__VA_ARGS__); \
} 

void printNodeRecursively_Basic(const Node* node, const uint8_t depth);
void printNodeRecursively_Enhanced(const Node* node, const uint8_t depth);

void printNodeRecursively_Tex(FILE* file, const Node* node, const uint8_t depth);
void printNodeRecursively_Json(FILE* file, const Node* node, const uint8_t depth);

#endif // NODE_H