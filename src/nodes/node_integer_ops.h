#ifndef NODE_INTEGER_OPS_H
#define NODE_INTEGER_OPS_H

#include <stdbool.h>
#include "node.h"

bool processNode_IncrementPre(Node* node);
Node createNode_IncrementPre(Node* node_0);

bool processNode_IncrementPost(Node* node);
Node createNode_IncrementPost(Node* node_0);


bool processNode_DecrementPre(Node* node);
Node createNode_DecrementPre(Node* node_0);

bool processNode_DecrementPost(Node* node);
Node createNode_DecrementPost(Node* node_0);

#endif // NODE_INTEGER_OPS_H