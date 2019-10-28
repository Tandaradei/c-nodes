#ifndef NODE_PLUS_H
#define NODE_PLUS_H

#include <stdbool.h>
#include "node.h"

Node createNode_Plus_Empty();
Node createNode_Plus(Node* node1, Node* node2);

bool processNode_Plus(Node* node);

#endif // NODE_PLUS_H