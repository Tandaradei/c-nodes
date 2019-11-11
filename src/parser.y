%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>

	#include "src/ast.h"
	#include "src/symtab.h"
	#include "src/nodes/nodes_list.h"

	AbstractSyntaxTree ast;
	SymbolTable sym_tab;
	Node* root_node;

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
%token<txt> CONSTANT_INT CONSTANT_DOUBLE IDENTIFIER STRING_LITERAL
%union {char txt[256]; struct Node* node;}
%type<node> primary_expression expression assignment_expression conditional_expression unary_expression
%type<node> logical_or_expression logical_and_expression inclusive_or_expression exclusive_or_expression
%type<node> and_expression equality_expression relational_expression shift_expression
%type<node> additive_expression multiplicative_expression cast_expression
%type<node> postfix_expression
%type<txt> assignment_operator type_name unary_operator
%%
start	: expression {root_node = $1;}
		;
primary_expression
	: IDENTIFIER			{Node* node = makeNode_0_STRING(&ast, createNode_GetVariableValue, $1); node->additional_info = &sym_tab; $$ = node;}
	| CONSTANT_INT 			{$$ = makeNode_0_INT(&ast, createNode_ValueInt, atoi($1));}
	| CONSTANT_DOUBLE		{$$ = makeNode_0_DOUBLE(&ast, createNode_ValueDouble, atof($1));}
	| STRING_LITERAL		{$$ = makeNode_0(&ast, createNode);}
	| '(' expression ')'	{$$ = $2;}
	;

postfix_expression
: primary_expression										{$$ = $1;}
	| postfix_expression '[' expression ']'					{$$ = makeNode_0(&ast, createNode);}
	| postfix_expression '(' ')'							{$$ = makeNode_0(&ast, createNode);} // ToDo
	| postfix_expression '(' argument_expression_list ')'	{$$ = makeNode_0(&ast, createNode);} // ToDo
	| postfix_expression '.' IDENTIFIER						{$$ = makeNode_0(&ast, createNode);} // ToDo
	| postfix_expression PTR_OP IDENTIFIER					{$$ = makeNode_0(&ast, createNode);}
	| postfix_expression INC_OP								{$$ = makeNode_0(&ast, createNode);}
	| postfix_expression DEC_OP								{$$ = makeNode_0(&ast, createNode);}
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
: postfix_expression					{$$ = $1;}
	| INC_OP unary_expression			{$$ = makeNode_0(&ast, createNode);}
	| DEC_OP unary_expression			{$$ = makeNode_0(&ast, createNode);}
	| unary_operator cast_expression	{$$ = makeNode_0(&ast, createNode);}
	| SIZEOF unary_expression			{$$ = makeNode_0(&ast, createNode);}
	| SIZEOF '(' type_name ')'			{$$ = makeNode_0(&ast, createNode);} // ToDo
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
	| '(' type_name ')' cast_expression							{$$ = makeNode_0(&ast, createNode);} // Todo!
	;

multiplicative_expression
	: cast_expression											{$$ = $1;}
	| multiplicative_expression '*' cast_expression				{$$ = makeNode_2(&ast, createNode_Mult, $1, $3);}
	| multiplicative_expression '/' cast_expression				{$$ = makeNode_2(&ast, createNode_Divide, $1, $3);}
	| multiplicative_expression '%' cast_expression				{$$ = makeNode_0(&ast, createNode);}
	;

additive_expression
	: multiplicative_expression									{$$ = $1;}
	| additive_expression '+' multiplicative_expression			{$$ = makeNode_2(&ast, createNode_Plus, $1, $3);}
	| additive_expression '-' multiplicative_expression			{$$ = makeNode_2(&ast, createNode_Sub, $1, $3);}
	;

shift_expression
	: additive_expression										{$$ = $1;}
	| shift_expression LEFT_OP additive_expression				{$$ = makeNode_0(&ast, createNode);}
	| shift_expression RIGHT_OP additive_expression				{$$ = makeNode_0(&ast, createNode);}
	;

relational_expression
	: shift_expression											{$$ = $1;}
	| relational_expression '<' shift_expression				{$$ = makeNode_0(&ast, createNode);}
	| relational_expression '>' shift_expression				{$$ = makeNode_0(&ast, createNode);}
	| relational_expression LE_OP shift_expression				{$$ = makeNode_0(&ast, createNode);}
	| relational_expression GE_OP shift_expression				{$$ = makeNode_0(&ast, createNode);}
	;

equality_expression
	: relational_expression										{$$ = $1;}
	| equality_expression EQ_OP relational_expression			{$$ = makeNode_0(&ast, createNode);}
	| equality_expression NE_OP relational_expression			{$$ = makeNode_0(&ast, createNode);}
	;

and_expression
	: equality_expression										{$$ = $1;}
	| and_expression '&' equality_expression					{$$ = makeNode_0(&ast, createNode);}
	;

exclusive_or_expression
	: and_expression											{$$ = $1;}
	| exclusive_or_expression '^' and_expression				{$$ = makeNode_0(&ast, createNode);}
	;

inclusive_or_expression
	: exclusive_or_expression									{$$ = $1;}
	| inclusive_or_expression '|' exclusive_or_expression		{$$ = makeNode_0(&ast, createNode);}
	;

logical_and_expression
	: inclusive_or_expression									{$$ = $1;}
	| logical_and_expression AND_OP inclusive_or_expression		{$$ = makeNode_0(&ast, createNode);}
	;

logical_or_expression
	: logical_and_expression									{$$ = $1;}
	| logical_or_expression OR_OP logical_and_expression		{$$ = makeNode_0(&ast, createNode);}
	;

conditional_expression
	: logical_or_expression 											{$$ = $1;}
	| logical_or_expression '?' expression ':' conditional_expression 	{$$ = makeNode_0(&ast, createNode);}
	;

assignment_expression
	: conditional_expression										{$$ = $1;}
	| unary_expression assignment_operator assignment_expression 	{$$ = makeNode_1_STRING(&ast, createNode_UpdateVariableValue, $3, $1);}
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
	| expression ',' assignment_expression 	{$$ = makeNode_0(&ast, createNode);}
	;

type_name
	: INT					{strcpy($$, "int");}
	| DOUBLE				{strcpy($$, "double");}
	;
%%
#include <stdio.h>

#include "src/ast.h"

extern char yytext[];
extern int column;

void yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

int yyparse();
int main(unsigned int argc, char** argv) {
	addSymbol(
		&sym_tab, 
		"a", 
		(SymbolValue) {
			.type = VT_INT,
			.value.i_value = 9,
			.is_const = false,
		}
	);
	addSymbol(
		&sym_tab, 
		"b", 
		(SymbolValue) {
			.type = VT_DOUBLE,
			.value.d_value = 15.023,
			.is_const = true,
		}
	);
	for(unsigned int i = 1; i < argc; i++) {
		yy_scan_string(argv[i]);
		int rc = yyparse();
		if (rc == 0) {
			printf("# nodes: %d\n", ast.node_count);
			processNode(root_node);
			printf("Basic syntax tree:\n");
			printNodeRecursively_Basic(root_node, 0);
			printf("Enhanced syntax tree:\n");
			printNodeRecursively_Enhanced(root_node, 0);
			//tree_output(root, 0);
			//tree_tikz(root, 0);
		}
		else {
			printf("Syntaxfehler\n");
		}
		yylex_destroy();
	}	
	
	return 0;
}
