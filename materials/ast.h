/**********************************************************
Header-Datei zum Syntaxbaum
**********************************************************/
#ifndef __TERM_TREE_H__
#define __TERM_TREE_H__ 1
typedef struct s_ast_node ast;
struct s_ast_node {
    char text[256];
    ast * l;
    ast * r;
	ast * c;
};
// Prototypen
void tree_output(ast * , int);
void tree_d3json(ast * p, int n);
void tree_tikz(ast * , int);
ast * new_node(char *, ast*, ast*, ast*);

#endif
