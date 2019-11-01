#ifndef NODE_H
#define NODE_H

#include <stdbool.h>

typedef enum ValueType {
    ERROR = 0,
    INT = 1,
    DOUBLE = 2,
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
} Node;

bool checkNode(const NodeIn node_in);

ValueType getHighestValueType(const NodeIn node_in);

bool processNode(Node* node);

int getAsInt(const NodeOut node_out);
double getAsDouble(const NodeOut node_out);

void printNodeValue(const NodeOut node_out);
void printNodeType(const NodeOut node_out);

#endif // NODE_H