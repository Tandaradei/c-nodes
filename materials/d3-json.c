#include <stdio.h>
#include "ast.h"
extern         ast * root;
int yyparse();
int main(int argc, char * argv[]) {
	root = NULL;
	if (argc == 2 && argv[1] != NULL)
	yy_scan_string(argv[1]);

	int rc = yyparse();
	if (rc == 0) {
		tree_d3json(root, 0);
	}
	else
	printf("Syntaxfehler\n");
	return 0;
}
