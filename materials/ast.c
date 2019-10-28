/**********************************************************
Syntaxbaum - Bibliothek
**********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

void tree_output(ast * p, int n) {
// Baum-Traversierung First-Order
	if (n == 0)
		printf("Explorer-View:\n");
  if (p != NULL) {
    printf("%s", "              "+14-2*n);
    printf("%s\n", p->text);
	  tree_output(p->c, n+1);
    tree_output(p->l, n+1);
    tree_output(p->r, n+1);
  }
}

void tree_tikz(ast * p, int n) {
	// Baum-Traversierung First-Order
	if (p != NULL) {
		if (!n) {
			printf("tikz-View:\n");
			printf("\\Tree");
		}
		printf("%s", "              "+14-2*n);
		if (p->l != NULL)
		printf("[.");
		printf("%s\n", p->text);
		tree_tikz(p->c, n+1);
		tree_tikz(p->l, n+1);
		tree_tikz(p->r, n+1);
		if (p->l != NULL)
		printf("%s]\n", "              "+14-2*n);
	}
}

void tree_d3json(ast * p, int n) {
	// Baum-Traversierung First-Order
	if (p != NULL) {
		printf("%s", "              "+14-2*n);
		printf("{\"name\": \"%s\",\n", p->text);
		printf("%s", "              "+14-2*n);
		printf("\"children\":[");
		if (p->c != NULL)
			tree_d3json(p->c, n+1), printf(",");
		if (p->l != NULL)
			tree_d3json(p->l, n+1);
		if (p->r != NULL)
			printf(","),tree_d3json(p->r, n+1);
		printf("%s]}\n", "              "+14-2*n);
	}
}


ast * new_node(char *t, ast * l, ast * r, ast * c) {
    ast * p = (ast*) malloc(sizeof(ast));
    if (p != NULL) {
        p->l = l, p->r = r, p->c = c;
        strcpy(p->text, t);
    }
    return p;
}

void tree_free(ast * p) { // Baum löschen
    if (p != NULL) {
        tree_free(p->l);
        tree_free(p->r);
        free(p);
    }
}
