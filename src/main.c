#include <stdio.h>

#include "node_value.h"
#include "node_arithmetic.h"

int main(int argc, char** argv) {
    Node summand_1 = createNode_ValueInt(5);
    Node summand_2 = createNode_ValueDouble(3.4);
    Node plus_node = createNode_Plus(&summand_1, &summand_2);
    processNode_Plus(&plus_node);
    Node mult_1 = createNode_ValueInt(3);
    Node mult_node = createNode_Mult(&plus_node, &mult_1);
    processNode_Mult(&mult_node);

    printNodeValue(&summand_1);
    printf(" + ");
    printNodeValue(&summand_2);
    printf(" = ");
    printNodeValue(&plus_node);
    printf("\n");

    printNodeType(&summand_1);
    printf(" + ");
    printNodeType(&summand_2);
    printf(" = ");
    printNodeType(&plus_node);
    printf("\n");

    printNodeValue(&plus_node);
    printf(" * ");
    printNodeValue(&mult_1);
    printf(" = ");
    printNodeValue(&mult_node);
    printf("\n");

    printNodeType(&plus_node);
    printf(" * ");
    printNodeType(&mult_1);
    printf(" = ");
    printNodeType(&mult_node);
    printf("\n");


    return 0;
}