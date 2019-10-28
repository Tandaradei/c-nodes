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

typedef struct Node {
    // in
    union {
        struct {
            InSlot in_0;
            InSlot in_1;
            InSlot in_2;
        };
        InSlot in[3];
    };
    const unsigned int in_slot_count; 
    // out
    ValueType out_type;
    Value     out_value;
} Node;

bool checkNode(const Node* node);

ValueType getHighestValueType(const Node* node);

int getAsInt(const Node* node);
double getAsDouble(const Node* node);

void printNodeValue(const Node* node);
void printNodeType(const Node* node);

#endif // NODE_H