%{
#include "fastcgi.h"
#include <stdio.h>
#include "term-ast.h"
#include "symtab.hpp"
#include <string.h>
#include <stdlib.h>

int yyerror(const char *s);
int yylex();
void logge(char * t);
int l, error;
void out(char *);
ast_node * root;
char txt[100];

%}
%union {ast_node * p;  char tt[20]; int i; double d;}
%token t_komma
%token t_plus t_minus t_mal t_div  t_mod  t_kla_auf t_kla_zu t_fehler
%token t_sin t_pow t_int t_double t_semik t_assign
%token<tt> t_iconst t_dconst t_id

%right t_assign
%left t_plus t_minus
%left t_mal t_div t_mod
%type<p> expression factor
%type<tt> decl_vz
%%
start       : {root = NULL; error = 0;} declarations expression t_semik {root = $3;}
          ;
declarations: declarations t_int i_decl t_semik
			| declarations t_double d_decl t_semik
			| /* eps */
			;
i_decl		: i_decl2 | i_decl2 t_komma i_decl
			;
i_decl2		:  t_id t_assign decl_vz t_iconst {symtab_insert_i((char *) $1, atoi($4));}
			;
d_decl		: d_decl2 | d_decl2 t_komma d_decl
			;
d_decl2		:  t_id t_assign decl_vz t_dconst {symtab_insert_d((char *) $1, atof($4));}
			;
decl_vz	: t_plus {strcpy($$, "+");} | t_minus {strcpy($$, "-");} | /* eps */  {strcpy($$, "");}
			;

expression: factor					{$$ = $1;}
| expression t_plus expression   {$$ = new_node((char *) "+", $1, $3);}
| expression t_minus expression   {$$ = new_node((char *) "-", $1, $3);}
| expression t_mal expression   {$$ = new_node((char *) "*", $1, $3);}
| expression t_div expression   {$$ = new_node((char *) "/", $1, $3);}
| expression t_mod expression   {$$ = new_node((char *) "%", $1, $3);}
| t_id t_assign expression   {
	symtabentry r;
	$$ = new_node((char *) "=", new_node($1, NULL, NULL), $3);
	if (symtab_lookup($1, &r) == 0 )
		$$->l->type=r.type;
	else
	$$->l->type=type_error;
}
    ;
factor:     t_iconst 							{$$ = new_node((char *) "C", NULL, NULL);$$->type=type_int;$$->i_val = atoi($1);}
			| t_dconst 							{$$ = new_node((char *) "C", NULL, NULL);$$->type=type_double;$$->d_val = atof($1);}
			| t_id 								{
				symtabentry r;
				$$ = new_node((char *) "V", NULL, NULL);
				if (symtab_lookup($1, &r) == 0 )
					$$->type=r.type, $$->i_val = r.i_val, $$->d_val = r.d_val;
				else
					$$->type=type_error;
			}
			| t_kla_auf expression t_kla_zu		{$$ = $2;}
			| t_plus factor						{$$ = new_node((char *) "+", $2, NULL);}
          	| t_minus factor					{$$ = new_node((char *) "-", $2, NULL);}
			| t_sin t_kla_auf expression t_kla_zu	{$$ = new_node((char *) "sin", $3, NULL);}
			| t_pow t_kla_auf expression t_komma expression t_kla_zu	{$$ = new_node((char *) "pow", $3, $5);}
          ;
%%

int yyerror(const char *s) {
	error = 1;
    return 0;
}
