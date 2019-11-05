#ifndef NODE_H
#define NODE_H

#include <stdbool.h>
#include <stdint.h>

typedef enum ValueType {
    VT_ERROR = 0,
    VT_INT = 1,
    VT_DOUBLE = 2,
} ValueType;

typedef struct Node Node;

typedef struct InSlot {
    Node* node;
    const unsigned int allowed_value_types;
} InSlot;

typedef union Value {
    int i_value;
    double d_value;
} Value;

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
    bool (*processNode)(const NodeIn node_in, NodeOut* node_out);
    char text[20];
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