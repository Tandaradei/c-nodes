%{
#include <stdio.h>
#include <string.h>
#include "term-ast.h"
#include "y.tab.h"
%}
%%
","                 return t_komma;
";"                 return t_semik;
"="                 return t_assign;
"+"                 return t_plus;
"-"                 return t_minus;
"*"                 return t_mal;
"/"                 return t_div;
"%"                 return t_mod;
"("                 return t_kla_auf;
")"                 return t_kla_zu;
"int"				return t_int;
"double"			return t_double;
sin					return t_sin;
pow					return t_pow;
[A-Za-z_]+  				strncpy(yylval.tt, yytext, 20); return t_id;
[0-9]*"."[0-9]+|[0-9]+"."  	strncpy(yylval.tt, yytext, 20); return t_dconst;
[0-9]+  					strncpy(yylval.tt, yytext, 20); return t_iconst;
[ \t\n]               /* do nothing */;
.                   return t_fehler;
%%
int yywrap() { return 1; }
