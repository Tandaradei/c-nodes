%option nounistd
%option never-interactive
%{
void count();
void comment();
int yywrap();
#include <stdio.h>
#include <string.h>

#include "parser.h"
#include "src/ast.h"
%}
D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*


%%
"double"		{ count(); return(DOUBLE); }
"int"			{ count(); return(INT); }

"sizeof"		{ count(); return(SIZEOF); }

{L}({L}|{D})*		{ count(); strncpy(yylval.txt, yytext, 256); return(IDENTIFIER); }


0[xX]{H}+{IS}?		{ count(); return(CONSTANT_INT); }
0{D}+{IS}?		{ count(); return(CONSTANT_INT); }
{D}+{IS}?		{ count(); strncpy(yylval.txt, yytext, 256); return(CONSTANT_INT); }
L?'(\\.|[^\\'])+'	{ count(); return(CONSTANT_INT); }

{D}+{E}{FS}?		{ count(); return(CONSTANT_DOUBLE); }
{D}*"."{D}+({E})?{FS}?	{ count(); strncpy(yylval.txt, yytext, 256); return(CONSTANT_DOUBLE); }
{D}+"."{D}*({E})?{FS}?	{ count(); strncpy(yylval.txt, yytext, 256); return(CONSTANT_DOUBLE); }

L?\"(\\.|[^\\"])*\"	{ count(); strncpy(yylval.txt, yytext, 256); return(STRING_LITERAL); }

"..."			{ count(); return(ELLIPSIS); }
">>="			{ count(); return(RIGHT_ASSIGN); }
"<<="			{ count(); return(LEFT_ASSIGN); }
"+="			{ count(); return(ADD_ASSIGN); }
"-="			{ count(); return(SUB_ASSIGN); }
"*="			{ count(); return(MUL_ASSIGN); }
"/="			{ count(); return(DIV_ASSIGN); }
"%="			{ count(); return(MOD_ASSIGN); }
"&="			{ count(); return(AND_ASSIGN); }
"^="			{ count(); return(XOR_ASSIGN); }
"|="			{ count(); return(OR_ASSIGN); }
">>"			{ count(); return(RIGHT_OP); }
"<<"			{ count(); return(LEFT_OP); }
"++"			{ count(); return(INC_OP); }
"--"			{ count(); return(DEC_OP); }
"->"			{ count(); return(PTR_OP); }
"&&"			{ count(); return(AND_OP); }
"||"			{ count(); return(OR_OP); }
"<="			{ count(); return(LE_OP); }
">="			{ count(); return(GE_OP); }
"=="			{ count(); return(EQ_OP); }
"!="			{ count(); return(NE_OP); }
";"			{ count(); return(';'); }
("{"|"<%")		{ count(); return('{'); }
("}"|"%>")		{ count(); return('}'); }
","			{ count(); return(','); }
":"			{ count(); return(':'); }
"="			{ count(); return('='); }
"("			{ count(); return('('); }
")"			{ count(); return(')'); }
("["|"<:")		{ count(); return('['); }
("]"|":>")		{ count(); return(']'); }
"."			{ count(); return('.'); }
"&"			{ count(); return('&'); }
"!"			{ count(); return('!'); }
"~"			{ count(); return('~'); }
"-"			{ count(); return('-'); }
"+"			{ count(); return('+'); }
"*"			{ count(); return('*'); }
"/"			{ count(); return('/'); }
"%"			{ count(); return('%'); }
"<"			{ count(); return('<'); }
">"			{ count(); return('>'); }
"^"			{ count(); return('^'); }
"|"			{ count(); return('|'); }
"?"			{ count(); return('?'); }

[ \t\v\n\f]		{ count(); }
.			{ /* ignore bad characters */ }

%%


int yywrap()
{
	return 1;
}





int column = 0;

void count() {
	for (int i = 0; yytext[i] != '\0'; i++) {
		if (yytext[i] == '\n') {
			column = 0;
		}
		else if (yytext[i] == '\t') {
			column += 8 - (column % 8);
		}
		else {
			column++;
		}
	}

	//ECHO;
}
