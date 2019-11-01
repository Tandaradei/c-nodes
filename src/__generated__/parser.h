/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_C_USERS_LAURIN_SOURCE_REPOS_C_NODES_SRC_GENERATED_PARSER_H_INCLUDED
# define YY_YY_C_USERS_LAURIN_SOURCE_REPOS_C_NODES_SRC_GENERATED_PARSER_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SIZEOF = 258,
     PTR_OP = 259,
     INC_OP = 260,
     DEC_OP = 261,
     LEFT_OP = 262,
     RIGHT_OP = 263,
     LE_OP = 264,
     GE_OP = 265,
     EQ_OP = 266,
     NE_OP = 267,
     AND_OP = 268,
     OR_OP = 269,
     MUL_ASSIGN = 270,
     DIV_ASSIGN = 271,
     MOD_ASSIGN = 272,
     ADD_ASSIGN = 273,
     SUB_ASSIGN = 274,
     LEFT_ASSIGN = 275,
     RIGHT_ASSIGN = 276,
     AND_ASSIGN = 277,
     XOR_ASSIGN = 278,
     OR_ASSIGN = 279,
     TYPE_NAME = 280,
     TYPEDEF = 281,
     EXTERN = 282,
     STATIC = 283,
     AUTO = 284,
     REGISTER = 285,
     CHAR = 286,
     SHORT = 287,
     INT = 288,
     LONG = 289,
     SIGNED = 290,
     UNSIGNED = 291,
     FLOAT = 292,
     DOUBLE = 293,
     CONST = 294,
     VOLATILE = 295,
     VOID = 296,
     STRUCT = 297,
     UNION = 298,
     ENUM = 299,
     ELLIPSIS = 300,
     CASE = 301,
     DEFAULT = 302,
     IF = 303,
     ELSE = 304,
     SWITCH = 305,
     WHILE = 306,
     DO = 307,
     FOR = 308,
     GOTO = 309,
     CONTINUE = 310,
     BREAK = 311,
     RETURN = 312,
     CONSTANT = 313,
     IDENTIFIER = 314,
     STRING_LITERAL = 315
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 23 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
char txt[256];  struct s_ast_node  * tree;

/* Line 2058 of yacc.c  */
#line 120 "C:/Users/Laurin/source/repos/c-nodes/src/__generated__/parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_C_USERS_LAURIN_SOURCE_REPOS_C_NODES_SRC_GENERATED_PARSER_H_INCLUDED  */
