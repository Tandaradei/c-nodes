#include <stdio.h>

#include "nodes/node_value.h"
#include "nodes/node_arithmetic.h"

int main(int argc, char** argv) {
    Node summand_1 = createNode_ValueInt(5);
    Node summand_2 = createNode_ValueDouble(3.4);
    Node plus_node = createNode_Plus(&summand_1, &summand_2);
    Node mult_1 = createNode_ValueInt(3);
    Node mult_node = createNode_Mult(&plus_node, &mult_1);

    processNode(&mult_node);

    printNodeValue(summand_1.out);
    printf(" + ");
    printNodeValue(summand_2.out);
    printf(" = ");
    printNodeValue(plus_node.out);
    printf("\n");

    printNodeType(summand_1.out);
    printf(" + ");
    printNodeType(summand_2.out);
    printf(" = ");
    printNodeType(plus_node.out);
    printf("\n");

    printNodeValue(plus_node.out);
    printf(" * ");
    printNodeValue(mult_1.out);
    printf(" = ");
    printNodeValue(mult_node.out);
    printf("\n");

    printNodeType(plus_node.out);
    printf(" * ");
    printNodeType(mult_1.out);
    printf(" = ");
    printNodeType(mult_node.out);
    printf("\n");


    return 0;
}