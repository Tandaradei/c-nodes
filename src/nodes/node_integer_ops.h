#ifndef NODE_INTEGER_OPS_H
#define NODE_INTEGER_OPS_H

#include "node.h"

bool processNode_IncrementPre(Node* node, const PROCESS_MODE process_mode);
Node createNode_IncrementPre(Node* node_0);

bool processNode_IncrementPost(Node* node, const PROCESS_MODE process_mode);
Node createNode_IncrementPost(Node* node_0);


bool processNode_DecrementPre(Node* node, const PROCESS_MODE process_mode);
Node createNode_DecrementPre(Node* node_0);

bool processNode_DecrementPost(Node* node, const PROCESS_MODE process_mode);
Node createNode_DecrementPost(Node* node_0);

#endif // NODE_INTEGER_OPS_H