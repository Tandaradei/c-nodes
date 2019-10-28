%{
	#include "ast.h"
	#include <stdio.h>
	#include <string.h>

	ast * root;
int yylex();
void yyerror(char *);
%}
%token SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
%token<txt> CONSTANT IDENTIFIER STRING_LITERAL

%union {char txt[256];  struct s_ast_node  * tree;}
%type<tree> primary_expression expression assignment_expression conditional_expression unary_expression
%type<tree> logical_or_expression logical_and_expression inclusive_or_expression exclusive_or_expression
%type<tree> and_expression equality_expression relational_expression shift_expression
%type<tree> additive_expression multiplicative_expression cast_expression
%type<tree> postfix_expression
%type<txt> assignment_operator type_name unary_operator
%%
start	: expression {root = $1;}
		;
primary_expression
	: IDENTIFIER			{$$ = new_node($1, NULL, NULL, NULL);}
	| CONSTANT 				{$$ = new_node($1, NULL, NULL, NULL);}
	| STRING_LITERAL		{$$ = new_node($1, NULL, NULL, NULL);}
	| '(' expression ')'	{$$ = $2;}
	;

postfix_expression
: primary_expression							{$$ = $1;}
	| postfix_expression '[' expression ']'		{$$ = new_node("[]", $1, $3, NULL);}
	| postfix_expression '(' ')'				{$$ = new_node("pf??", $1, NULL, NULL);} // ToDo
	| postfix_expression '(' argument_expression_list ')'	{$$ = new_node("pf??", NULL, NULL, NULL);} // ToDo
	| postfix_expression '.' IDENTIFIER			{$$ = new_node(".id", $1, NULL, NULL);} // ToDo
	| postfix_expression PTR_OP IDENTIFIER		{$$ = new_node("->id", $1, NULL, NULL);}
	| postfix_expression INC_OP					{$$ = new_node("++ (post)", $1, NULL, NULL);}
	| postfix_expression DEC_OP					{$$ = new_node("-- (post)", $1, NULL, NULL);}
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
: postfix_expression					{$$ = $1;}
	| INC_OP unary_expression			{$$ = new_node("++ (prae)", $2, NULL, NULL);}
	| DEC_OP unary_expression			{$$ = new_node("-- (prae)", $2, NULL, NULL);}
	| unary_operator cast_expression	{$$ = new_node($1, $2, NULL, NULL);}
	| SIZEOF unary_expression			{$$ = new_node("sizeof", $2, NULL, NULL);}
	| SIZEOF '(' type_name ')'			{$$ = new_node("sizeof", NULL, NULL, NULL);} // ToDo
	;

unary_operator
	: '&'		{strcpy($$, "&");}
	| '*'		{strcpy($$, "*");}
	| '+'		{strcpy($$, "+");}
	| '-'		{strcpy($$, "-");}
	| '~'		{strcpy($$, "~");}
	| '!'		{strcpy($$, "!");}
	;

cast_expression
	: unary_expression											{$$ = $1;}
	| '(' type_name ')' cast_expression							{$$ = new_node("typecast", NULL, NULL, NULL);} // Todo!
	;

multiplicative_expression
	: cast_expression											{$$ = $1;}
	| multiplicative_expression '*' cast_expression				{$$ = new_node("*", $1, $3, NULL);}
	| multiplicative_expression '/' cast_expression				{$$ = new_node("/", $1, $3, NULL);}
	| multiplicative_expression '%' cast_expression				{$$ = new_node("%", $1, $3, NULL);}
	;

additive_expression
	: multiplicative_expression									{$$ = $1;}
	| additive_expression '+' multiplicative_expression			{$$ = new_node("+", $1, $3, NULL);}
	| additive_expression '-' multiplicative_expression			{$$ = new_node("-", $1, $3, NULL);}
	;

shift_expression
	: additive_expression										{$$ = $1;}
	| shift_expression LEFT_OP additive_expression				{$$ = new_node("<<", $1, $3, NULL);}
	| shift_expression RIGHT_OP additive_expression				{$$ = new_node(">>", $1, $3, NULL);}
	;

relational_expression
	: shift_expression											{$$ = $1;}
	| relational_expression '<' shift_expression				{$$ = new_node("<", $1, $3, NULL);}
	| relational_expression '>' shift_expression				{$$ = new_node(">", $1, $3, NULL);}
	| relational_expression LE_OP shift_expression				{$$ = new_node("<=", $1, $3, NULL);}
	| relational_expression GE_OP shift_expression				{$$ = new_node(">=", $1, $3, NULL);}
	;

equality_expression
	: relational_expression										{$$ = $1;}
	| equality_expression EQ_OP relational_expression			{$$ = new_node("==", $1, $3, NULL);}
	| equality_expression NE_OP relational_expression			{$$ = new_node("!0", $1, $3, NULL);}
	;

and_expression
	: equality_expression										{$$ = $1;}
	| and_expression '&' equality_expression					{$$ = new_node("&", $1, $3, NULL);}
	;

exclusive_or_expression
	: and_expression											{$$ = $1;}
	| exclusive_or_expression '^' and_expression				{$$ = new_node("^", $1, $3, NULL);}
	;

inclusive_or_expression
	: exclusive_or_expression									{$$ = $1;}
	| inclusive_or_expression '|' exclusive_or_expression		{$$ = new_node("|", $1, $3, NULL);}
	;

logical_and_expression
	: inclusive_or_expression									{$$ = $1;}
	| logical_and_expression AND_OP inclusive_or_expression		{$$ = new_node("&&", $1, $3, NULL);}
	;

logical_or_expression
	: logical_and_expression									{$$ = $1;}
	| logical_or_expression OR_OP logical_and_expression		{$$ = new_node("||", $1, $3, NULL);}
	;

conditional_expression
	: logical_or_expression 											{$$ = $1;}
	| logical_or_expression '?' expression ':' conditional_expression 	{$$ = new_node("?:", $3, $5, $1);}
	;

assignment_expression
	: conditional_expression										{$$ = $1;}
	| unary_expression assignment_operator assignment_expression 	{$$ = new_node($2, $1, $3, NULL);}
	;

assignment_operator
	: '='					{strcpy($$, "=");}
	| MUL_ASSIGN			{strcpy($$, "*=");}
	| DIV_ASSIGN			{strcpy($$, "/=");}
	| MOD_ASSIGN			{strcpy($$, "%=");}
	| ADD_ASSIGN			{strcpy($$, "+=");}
	| SUB_ASSIGN			{strcpy($$, "-=");}
	| LEFT_ASSIGN			{strcpy($$, "<<=");}
	| RIGHT_ASSIGN			{strcpy($$, ">>=");}
	| AND_ASSIGN			{strcpy($$, "&=");}
	| XOR_ASSIGN			{strcpy($$, "|=");}
	| OR_ASSIGN				{strcpy($$, "^=");}
	;

expression
	: assignment_expression 				{$$ = $1;}
	| expression ',' assignment_expression 	{$$ = new_node(",", $1, $3, NULL);}
	;

type_name
	: INT					{strcpy($$, "int");}
	| DOUBLE				{strcpy($$, "double");}
	;
%%
#include <stdio.h>

extern char yytext[];
extern int column;

void yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

int yyparse();
int main() {
	root = NULL;
	int rc = yyparse();
	if (rc == 0) {
		tree_output(root, 0);
		tree_tikz(root, 0);
	}
	else
	printf("Syntaxfehler\n");
	return 0;
}
