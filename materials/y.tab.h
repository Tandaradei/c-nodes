/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
/* Tokens.  */
#define SIZEOF 258
#define PTR_OP 259
#define INC_OP 260
#define DEC_OP 261
#define LEFT_OP 262
#define RIGHT_OP 263
#define LE_OP 264
#define GE_OP 265
#define EQ_OP 266
#define NE_OP 267
#define AND_OP 268
#define OR_OP 269
#define MUL_ASSIGN 270
#define DIV_ASSIGN 271
#define MOD_ASSIGN 272
#define ADD_ASSIGN 273
#define SUB_ASSIGN 274
#define LEFT_ASSIGN 275
#define RIGHT_ASSIGN 276
#define AND_ASSIGN 277
#define XOR_ASSIGN 278
#define OR_ASSIGN 279
#define TYPE_NAME 280
#define TYPEDEF 281
#define EXTERN 282
#define STATIC 283
#define AUTO 284
#define REGISTER 285
#define CHAR 286
#define SHORT 287
#define INT 288
#define LONG 289
#define SIGNED 290
#define UNSIGNED 291
#define FLOAT 292
#define DOUBLE 293
#define CONST 294
#define VOLATILE 295
#define VOID 296
#define STRUCT 297
#define UNION 298
#define ENUM 299
#define ELLIPSIS 300
#define CASE 301
#define DEFAULT 302
#define IF 303
#define ELSE 304
#define SWITCH 305
#define WHILE 306
#define DO 307
#define FOR 308
#define GOTO 309
#define CONTINUE 310
#define BREAK 311
#define RETURN 312
#define CONSTANT 313
#define IDENTIFIER 314
#define STRING_LITERAL 315

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "expressionviewer-parser.y" /* yacc.c:1909  */
char txt[256];  struct s_ast_node  * tree;

#line 177 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
