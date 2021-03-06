%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>

	#include "src/ast.h"
	#include "src/symtab.h"
	#include "src/nodes/nodes_list.h"

	#define MAX_ROOT_NODES 64
	#define MAX_PRINT_NODES 64

	AbstractSyntaxTree ast;
	SymbolTable sym_tab;
	Node* root_nodes[MAX_ROOT_NODES];
	unsigned int root_node_count = 0;
	Node* print_nodes[MAX_PRINT_NODES];
	unsigned int print_node_count = 0;

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
%type<node>	declaration declaration_specifiers init_declarator_list init_declarator
%type<txt> assignment_operator type_name unary_operator
%%
start	
	: statement_list
	;

primary_expression
	: IDENTIFIER			{	Node* node = makeNode_0_STRING(&ast, createNode_GetSymbol, $1); 
								node->additional_info = &sym_tab; 
								$$ = node;
							}
	| CONSTANT_INT 			{$$ = makeNode_0_INT(&ast, createNode_ValueInt, atoi($1));}
	| CONSTANT_DOUBLE		{$$ = makeNode_0_DOUBLE(&ast, createNode_ValueDouble, atof($1));}
	| '(' expression ')'	{$$ = $2;}
	;

postfix_expression
: primary_expression														{$$ = $1;}
	| postfix_expression '[' expression ']'									{$$ = makeNode_0(&ast, createNode);}
	| IDENTIFIER '(' ')'													{$$ = makeNode_0_STRING(&ast, createNode_Function_0, $1);}
	| IDENTIFIER '(' assignment_expression ')'								{$$ = makeNode_1_STRING(&ast, createNode_Function_1, $3, $1);}
	| IDENTIFIER '(' assignment_expression ',' assignment_expression ')'	{$$ = makeNode_2_STRING(&ast, createNode_Function_2, $3, $5, $1);}
	| postfix_expression INC_OP												{$$ = makeNode_1(&ast, createNode_IncrementPost, $1);}
	| postfix_expression DEC_OP												{$$ = makeNode_1(&ast, createNode_DecrementPost, $1);}
	;

unary_expression
: postfix_expression					{$$ = $1;}
	| INC_OP unary_expression			{$$ = makeNode_1(&ast, createNode_IncrementPre, $2);}
	| DEC_OP unary_expression			{$$ = makeNode_1(&ast, createNode_DecrementPre, $2);}
	| unary_operator cast_expression	{$$ = makeNode_1_STRING(&ast, createNode_UnaryOp, $2, $1);}
	| SIZEOF unary_expression			{$$ = makeNode_1(&ast, createNode_Sizeof_Expression, $2);}
	| SIZEOF '(' type_name ')'			{$$ = makeNode_0_STRING(&ast, createNode_Sizeof_Type, $3);} // ToDo
	;

unary_operator
	: '+'		{strcpy($$, "+");}
	| '-'		{strcpy($$, "-");}
	| '~'		{strcpy($$, "~");}
	| '!'		{strcpy($$, "!");}
	;

cast_expression
	: unary_expression											{$$ = $1;}
	| '(' type_name ')' cast_expression							{$$ = makeNode_1_STRING(&ast, createNode_Cast, $4, $2);}
	;

multiplicative_expression
	: cast_expression											{$$ = $1;}
	| multiplicative_expression '*' cast_expression				{$$ = makeNode_2(&ast, createNode_Mult, $1, $3);}
	| multiplicative_expression '/' cast_expression				{$$ = makeNode_2(&ast, createNode_Divide, $1, $3);}
	| multiplicative_expression '%' cast_expression				{$$ = makeNode_2(&ast, createNode_Modulo, $1, $3);}
	;

additive_expression
	: multiplicative_expression									{$$ = $1;}
	| additive_expression '+' multiplicative_expression			{$$ = makeNode_2(&ast, createNode_Plus, $1, $3);}
	| additive_expression '-' multiplicative_expression			{$$ = makeNode_2(&ast, createNode_Sub, $1, $3);}
	;

shift_expression
	: additive_expression										{$$ = $1;}
	| shift_expression LEFT_OP additive_expression				{$$ = makeNode_2(&ast, createNode_ShiftLeft, $1, $3);}
	| shift_expression RIGHT_OP additive_expression				{$$ = makeNode_2(&ast, createNode_ShiftRight, $1, $3);}
	;

relational_expression
	: shift_expression											{$$ = $1;}
	| relational_expression '<' shift_expression				{$$ = makeNode_2(&ast, createNode_Less, $1, $3);}
	| relational_expression '>' shift_expression				{$$ = makeNode_2(&ast, createNode_Greater, $1, $3);}
	| relational_expression LE_OP shift_expression				{$$ = makeNode_2(&ast, createNode_LessEqual, $1, $3);}
	| relational_expression GE_OP shift_expression				{$$ = makeNode_2(&ast, createNode_GreaterEqual, $1, $3);}
	;

equality_expression
	: relational_expression										{$$ = $1;}
	| equality_expression EQ_OP relational_expression			{$$ = makeNode_2(&ast, createNode_Equal, $1, $3);}
	| equality_expression NE_OP relational_expression			{$$ = makeNode_2(&ast, createNode_NotEqual, $1, $3);}
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
	| logical_and_expression AND_OP inclusive_or_expression		{$$ = makeNode_2(&ast, createNode_BoolAnd, $1, $3);}
	;

logical_or_expression
	: logical_and_expression									{$$ = $1;}
	| logical_or_expression OR_OP logical_and_expression		{$$ = makeNode_2(&ast, createNode_BoolOr, $1, $3);}
	;

conditional_expression
	: logical_or_expression 											{$$ = $1;}
	| logical_or_expression '?' expression ':' conditional_expression 	{$$ = makeNode_3(&ast, createNode_Ternary, $1, $3, $5);}
	;

assignment_expression
	: conditional_expression										{$$ = $1;}
	| unary_expression assignment_operator assignment_expression 	{$$ = makeNode_2_STRING(&ast, createNode_Assign, $1, $3, $2);}
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
	| expression ',' assignment_expression 	{$$ = makeNode_2(&ast, createNode_CommaOp, $1, $3);}
	;

type_name
	: INT					{strcpy($$, "int");}
	| DOUBLE				{strcpy($$, "double");}
	;

declaration
	: declaration_specifiers init_declarator_list 	{ $$ = makeNode_2(&ast, createNode_Declaration, $1, $2); }
	;

declaration_specifiers
	: type_name										{	Node* node = makeNode_0_SymbolValue(&ast, createNode_SetSymbolConfig, (SymbolValue){ getValueTypeForString($1), 0, false});
														node->additional_info = &sym_tab;
														$$ = node;
													}
	| CONST type_name								{	Node* node = makeNode_0_SymbolValue(&ast, createNode_SetSymbolConfig, (SymbolValue){ getValueTypeForString($2), 0, true});
														node->additional_info = &sym_tab;
														$$ = node;
													}
	;

init_declarator_list
	: init_declarator								{ $$ = $1; }
	| init_declarator_list ',' init_declarator		{ $$ = makeNode_2(&ast, createNode_SymbolDeclarationList, $1, $3); }
	;

init_declarator
	: IDENTIFIER									{	Node* node = makeNode_0_STRING(&ast, createNode_AddSymbol_Uninitialized, $1);
														node->additional_info = &sym_tab;
														$$ = node;
													}
	| IDENTIFIER '=' assignment_expression 			{ 	Node* expr = $3; 
													  	print_nodes[print_node_count++] = expr; 
													  	Node* node = makeNode_1_STRING(&ast, createNode_AddSymbol_Initialized, expr, $1);
													  	node->additional_info = &sym_tab;
														$$ = node;
													}
	;

statement
	: expression ';'	{ 	Node* expr = $1;
							root_nodes[root_node_count++] = expr;
							print_nodes[print_node_count++] = expr; }
	| declaration ';'	{ root_nodes[root_node_count++] = $1; }
	;

statement_list
	: statement
	| statement_list statement
	;
%%
#include <stdio.h>

#include "src/ast.h"
#include "src/args.h"
#include "src/debug.h"

extern char yytext[];
extern int column;

char yyerror_value[200] = "";

void yyerror(s)
char *s;
{
	strcpy(yyerror_value, s);
}

int yyparse();

void printTex(FILE* file, Node* root_node) {
	PRINT(file, "\\documentclass[border=10pt]{standalone}\n\\usepackage{tikz}\n\\begin{document}\n");
	PRINT(file, "\\begin{tikzpicture}[sibling distance=10em, every node/.style = {shape=rectangle, rounded corners, draw, align=center}]]\n\\");
	printNodeRecursively_Tex(file, root_node, 0);
	PRINT(file, ";\n\\end{tikzpicture}\n");
	PRINT(file, "\\end{document}\n");
}

char* splitFirst(const char* string, char delimiter, const unsigned int OFFSET, char* dest) {
	unsigned int i = 0;
	while(string[i + OFFSET] && string[i + OFFSET] != delimiter) {
		PRINT_DEBUG("i: %2d | o: %2d | r: %2d | c: %c\n", i, OFFSET, i + OFFSET, string[i + OFFSET]);
		dest[i] = string[i + OFFSET];
		i++;
	}
	PRINT_DEBUG("-\n");
	dest[i] = 0;
}

int main(unsigned int argc, char** argv) {
	MyArgs args = parseArgs(argc, argv);

	if(args.symbols.is_set) {
		char* symbol = strtok(args.symbols.value.as_string, ";");
		while(symbol != NULL) {
			PRINT_DEBUG("symbol: %s\n", symbol);
			char name[80];
			char type[10];
			char value[20];
			char is_const[2];
			char delimiter = ',';
			unsigned int offset = 0;
			splitFirst(symbol, delimiter, offset, name);
			offset += strlen(name) + 1;
			splitFirst(symbol, delimiter, offset, type);
			offset += strlen(type) + 1;
			splitFirst(symbol, delimiter, offset, value);
			offset += strlen(value) + 1;
			splitFirst(symbol, delimiter, offset, is_const);
			PRINT_DEBUG("n: %s | t: %s | v: %s | c: %s\n", name, type, value, is_const);
			ValueType vt = VT_ERROR;
			Value v;
			char* endptr;
			if(!strcmp(type, "int")) {
				vt = VT_INT;
				v.i_value = strtol(value, &endptr, 10);
			}
			else if(!strcmp(type, "double")) {
				vt = VT_DOUBLE;
				v.d_value = strtod(value, &endptr);
			}
			addSymbol(
				&sym_tab, 
				name, 
				(SymbolValue) {
					vt,
					v,
					is_const[0] == '1'
				}
			);

			symbol = strtok(NULL, ";");
		}
	}
	yy_scan_string(args.expr.value.as_string);
	int rc = yyparse();
	if (rc == 0) {
		for(unsigned int i = 0; i < root_node_count; i++) {
			if(findNodeValueType(root_nodes[i])) {
				processNode(root_nodes[i]);
			}
		}
		if(args.tex.is_set) {
			for(unsigned int i = 0; i < print_node_count; i++) {
				printTex(NULL, print_nodes[i]);
			}
		}
		
		if(args.json.is_set) {
			printf("{ \"trees\": [\n");
			if(print_node_count > 0) {
				for(unsigned int i = 0; i < print_node_count; i++) {
					if(i > 0) {
						printf(",\n");
					}
					printNodeRecursively_Json(NULL, print_nodes[i], 1);
				}
			}
			else {
				printf("{\"name\": \"No expression found\", \"type\": \"ERROR\", \"error\": \"\"}\n");
			}
			printf("]}\n");
		}
		FILE* file = NULL;
		if(args.tex_file.is_set) {
			for(unsigned int i = 0; i < print_node_count; i++) {	
				file = fopen(args.tex_file.value.as_string, "w");
				printTex(file, print_nodes[i]);
				fclose(file);
				file = NULL;
			}
		}
		
		if(args.json_file.is_set) {
			for(unsigned int i = 0; i < print_node_count; i++) {
				file = fopen(args.json_file.value.as_string, "w");
				printNodeRecursively_Json(file, print_nodes[i], 0);
				fclose(file);
				file = NULL;
			}
		}
	}
	else {
		if(args.json.is_set) {
			char* expr = args.expr.value.as_string;
			int col = column - 1;
			const int window_size = 5;
			printf("{ \"trees\" : [\n{\"name\": \"parse error on column %d\", \"type\": \"ERROR\", \"error\": \"%s%.*s    %c    %.*s%s\"}\n]\n}\n", 
				col + 1, 
				col > window_size ? "..." : "",
				col > window_size ? window_size : col, col > window_size ? expr + (col - window_size) : expr,
				strlen(expr) > 0 ? expr[col] : ' ',
				window_size, expr + (col + 1),
				col + window_size < strlen(expr) ? "..." : ""
			);
		}
	}
	yylex_destroy();
	
	return 0;
}
