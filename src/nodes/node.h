#ifndef NODE_H
#define NODE_H

#include <stdbool.h>
#include <stdint.h>

#include "src/values.h"

typedef struct Node Node;

typedef struct InSlot {
    Node* node;
    const unsigned int allowed_value_types;
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
    const unsigned int slot_count;
} NodeIn;

typedef struct NodeOut {
    ValueType type;
    Value     value;
} NodeOut;

typedef struct Node {
    NodeIn in;
    NodeOut out;
    bool (*processNode)(Node* node);
    char text[20];
    void* additional_info;
} Node;


Node createNode(void);

Node createNode_BasicBinary(Node* node_0, Node* node_1);

bool checkNode(const NodeIn node_in);

ValueType getHighestValueType(const NodeIn node_in);

bool processNode(Node* node);

int getAsInt(const NodeOut node_out);
double getAsDouble(const NodeOut node_out);

void printNodeValue(const NodeOut node_out);
void printNodeType(const NodeOut node_out);

void printNodeRecursively_Basic(const Node* node, const uint8_t depth);
void printNodeRecursively_Enhanced(const Node* node, const uint8_t depth);

#endif // NODE_H