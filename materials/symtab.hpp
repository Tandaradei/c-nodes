#ifndef __SYMTAB_HPP
#define __SYMTAB_HPP
#include <map>
using namespace std;

#include "term-ast.h"

typedef struct {
	int i_val;
	double d_val;
	nodetype type;
} symtabentry;

typedef struct {
	char txt[10];
} symtabentryname;

extern map<string, symtabentry> symtab;

int symtab_insert_i(char * name, int value);
int symtab_insert_d(char * name, double value);
int symtab_lookup(char * name, symtabentry * e);
#endif
