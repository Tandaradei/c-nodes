#include <iostream>
using namespace std;
#include <iterator>
#include <map>
#include <string>
#include "symtab.hpp"
#include "fastcgi.h"
#include "term-ast.h"

#ifndef ___SYMATB_H
#define ___SYMATB_H

map<string, symtabentry> symtab;

int symtab_insert_i(char * name, int value) {
	symtabentry e = {value,0,type_int};
	string n(name);
	
	bool rc = symtab.insert(pair<string,symtabentry>(n,e)).second;
}

int symtab_insert_d(char * name, double value) {
	symtabentry e = {0, value, type_double};
	string n(name);
	
	bool rc = symtab.insert(pair<string,symtabentry>(n,e)).second;
}

int symtab_lookup(char * name, symtabentry * e) {
	int rc;
	map<string, symtabentry>::iterator it = symtab.find(string(name));
	if (it != symtab.end()) {
		*e = it->second;
		rc = 0;
	}
	else
		rc = -1;
	return rc;
}


#endif
