/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"

	#include "src/ast.h"
	#include <stdio.h>
	#include <string.h>

	ast * root;
int yylex();
void yyerror(char *);

/* Line 371 of yacc.c  */
#line 78 "C:/Users/Laurin/source/repos/c-nodes/src/__generated__/parser.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
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
/* Line 387 of yacc.c  */
#line 23 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
char txt[256];  struct s_ast_node  * tree;

/* Line 387 of yacc.c  */
#line 184 "C:/Users/Laurin/source/repos/c-nodes/src/__generated__/parser.c"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 212 "C:/Users/Laurin/source/repos/c-nodes/src/__generated__/parser.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   204

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  121

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,     2,     2,     2,    74,    67,     2,
      61,    62,    68,    69,    66,    70,    65,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    80,     2,
      75,    81,    76,    79,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,    77,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    78,     2,    71,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    15,    17,    22,
      26,    31,    35,    39,    42,    45,    47,    51,    53,    56,
      59,    62,    65,    70,    72,    74,    76,    78,    80,    82,
      84,    89,    91,    95,    99,   103,   105,   109,   113,   115,
     119,   123,   125,   129,   133,   137,   141,   143,   147,   151,
     153,   157,   159,   163,   165,   169,   171,   175,   177,   181,
     183,   189,   191,   195,   197,   199,   201,   203,   205,   207,
     209,   211,   213,   215,   217,   219,   223,   225
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      83,     0,    -1,   103,    -1,    59,    -1,    58,    -1,    60,
      -1,    61,   103,    62,    -1,    84,    -1,    85,    63,   103,
      64,    -1,    85,    61,    62,    -1,    85,    61,    86,    62,
      -1,    85,    65,    59,    -1,    85,     4,    59,    -1,    85,
       5,    -1,    85,     6,    -1,   101,    -1,    86,    66,   101,
      -1,    85,    -1,     5,    87,    -1,     6,    87,    -1,    88,
      89,    -1,     3,    87,    -1,     3,    61,   104,    62,    -1,
      67,    -1,    68,    -1,    69,    -1,    70,    -1,    71,    -1,
      72,    -1,    87,    -1,    61,   104,    62,    89,    -1,    89,
      -1,    90,    68,    89,    -1,    90,    73,    89,    -1,    90,
      74,    89,    -1,    90,    -1,    91,    69,    90,    -1,    91,
      70,    90,    -1,    91,    -1,    92,     7,    91,    -1,    92,
       8,    91,    -1,    92,    -1,    93,    75,    92,    -1,    93,
      76,    92,    -1,    93,     9,    92,    -1,    93,    10,    92,
      -1,    93,    -1,    94,    11,    93,    -1,    94,    12,    93,
      -1,    94,    -1,    95,    67,    94,    -1,    95,    -1,    96,
      77,    95,    -1,    96,    -1,    97,    78,    96,    -1,    97,
      -1,    98,    13,    97,    -1,    98,    -1,    99,    14,    98,
      -1,    99,    -1,    99,    79,   103,    80,   100,    -1,   100,
      -1,    87,   102,   101,    -1,    81,    -1,    15,    -1,    16,
      -1,    17,    -1,    18,    -1,    19,    -1,    20,    -1,    21,
      -1,    22,    -1,    23,    -1,    24,    -1,   101,    -1,   103,
      66,   101,    -1,    33,    -1,    38,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    31,    31,    34,    35,    36,    37,    41,    42,    43,
      44,    45,    46,    47,    48,    52,    53,    57,    58,    59,
      60,    61,    62,    66,    67,    68,    69,    70,    71,    75,
      76,    80,    81,    82,    83,    87,    88,    89,    93,    94,
      95,    99,   100,   101,   102,   103,   107,   108,   109,   113,
     114,   118,   119,   123,   124,   128,   129,   133,   134,   138,
     139,   143,   144,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   162,   163,   167,   168
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP",
  "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "STRUCT", "UNION",
  "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "CONSTANT",
  "IDENTIFIER", "STRING_LITERAL", "'('", "')'", "'['", "']'", "'.'", "','",
  "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "':'", "'='", "$accept", "start",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "type_name", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    40,    41,    91,    93,    46,    44,    38,    42,    43,
      45,   126,    33,    47,    37,    60,    62,    94,   124,    63,
      58,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    84,    84,    84,    84,    85,    85,    85,
      85,    85,    85,    85,    85,    86,    86,    87,    87,    87,
      87,    87,    87,    88,    88,    88,    88,    88,    88,    89,
      89,    90,    90,    90,    90,    91,    91,    91,    92,    92,
      92,    93,    93,    93,    93,    93,    94,    94,    94,    95,
      95,    96,    96,    97,    97,    98,    98,    99,    99,   100,
     100,   101,   101,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   103,   103,   104,   104
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     4,     3,
       4,     3,     3,     2,     2,     1,     3,     1,     2,     2,
       2,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     4,     3,     5,     0,    23,    24,
      25,    26,    27,    28,     0,     7,    17,    29,     0,    31,
      35,    38,    41,    46,    49,    51,    53,    55,    57,    59,
      61,    74,     2,     0,    21,     0,    18,    19,    76,    77,
       0,     0,     1,     0,    13,    14,     0,     0,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    63,
       0,    29,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,    12,     9,     0,    15,
       0,    11,    62,    32,    33,    34,    36,    37,    39,    40,
      44,    45,    42,    43,    47,    48,    50,    52,    54,    56,
      58,     0,    75,    22,    30,    10,     0,     8,     0,    16,
      60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    14,    15,    16,    88,    61,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      60,    40,    41
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -61
static const yytype_int8 yypact[] =
{
      50,    65,    94,    94,   -61,   -61,   -61,    19,   -61,   -61,
     -61,   -61,   -61,   -61,    11,   -61,   124,   123,    50,   -61,
     -59,   -27,    37,    39,    47,   -46,   -51,   -44,     5,    -6,
     -61,   -61,   -34,    19,   -61,    50,   -61,   -61,   -61,   -61,
     -49,   -26,   -61,   -21,   -61,   -61,    34,    50,    -9,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
      50,   -61,   -61,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    -8,   -61,    50,   -61,   -61,   -39,   -61,
     -54,   -61,   -61,   -61,   -61,   -61,   -59,   -59,   -27,   -27,
      37,    37,    37,    37,    39,    39,    47,   -46,   -51,   -44,
       5,   -60,   -61,   -61,   -61,   -61,    50,   -61,    50,   -61,
     -61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -61,   -61,   -61,   -61,   -61,     0,   -61,    -2,    -1,    44,
     -42,    74,   -12,   -10,    -4,    -7,   -11,   -61,   -20,   -41,
     -61,     4,    43
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      17,    34,    36,    37,    32,    89,    82,    17,    80,    63,
     117,    42,    82,    84,    64,    65,    62,    82,    79,    92,
     118,    76,     1,   115,     2,     3,    77,   116,   100,   101,
     102,   103,    82,    17,    78,    17,    85,     1,    86,     2,
       3,   112,    66,    67,    68,    69,    17,    17,    70,    71,
      91,    90,    38,     1,   113,     2,     3,    39,    74,    75,
      17,    93,    94,    95,   106,    96,    97,   107,     1,   110,
       2,     3,   109,    81,   108,   119,    83,     4,     5,     6,
       7,    17,    17,   114,     0,   111,     8,     9,    10,    11,
      12,    13,     4,     5,     6,     7,    87,     1,   120,     2,
       3,     8,     9,    10,    11,    12,    13,     0,     4,     5,
       6,     7,    98,    99,    72,    73,    17,     8,     9,    10,
      11,    12,    13,     4,     5,     6,    33,     0,    43,    44,
      45,     0,     8,     9,    10,    11,    12,    13,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,   104,   105,
       0,     0,     4,     5,     6,    35,     0,     0,     0,     0,
       0,     8,     9,    10,    11,    12,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,     0,    47,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    59
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-61)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
       0,     1,     2,     3,     0,    46,    66,     7,    14,    68,
      64,     0,    66,    62,    73,    74,    18,    66,    13,    60,
      80,    67,     3,    62,     5,     6,    77,    66,    70,    71,
      72,    73,    66,    33,    78,    35,    62,     3,    59,     5,
       6,    82,    69,    70,     7,     8,    46,    47,     9,    10,
      59,    47,    33,     3,    62,     5,     6,    38,    11,    12,
      60,    63,    64,    65,    76,    66,    67,    77,     3,    80,
       5,     6,    79,    79,    78,   116,    33,    58,    59,    60,
      61,    81,    82,    85,    -1,    81,    67,    68,    69,    70,
      71,    72,    58,    59,    60,    61,    62,     3,   118,     5,
       6,    67,    68,    69,    70,    71,    72,    -1,    58,    59,
      60,    61,    68,    69,    75,    76,   116,    67,    68,    69,
      70,    71,    72,    58,    59,    60,    61,    -1,     4,     5,
       6,    -1,    67,    68,    69,    70,    71,    72,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    74,    75,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    63,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,    58,    59,    60,    61,    67,    68,
      69,    70,    71,    72,    83,    84,    85,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   103,    61,    87,    61,    87,    87,    33,    38,
     103,   104,     0,     4,     5,     6,    61,    63,    65,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    81,
     102,    87,    89,    68,    73,    74,    69,    70,     7,     8,
       9,    10,    75,    76,    11,    12,    67,    77,    78,    13,
      14,    79,    66,   104,    62,    62,    59,    62,    86,   101,
     103,    59,   101,    89,    89,    89,    90,    90,    91,    91,
      92,    92,    92,    92,    93,    93,    94,    95,    96,    97,
      98,   103,   101,    62,    89,    62,    66,    64,    80,   101,
     100
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 31 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {root = (yyvsp[(1) - (1)].tree);}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 34 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node((yyvsp[(1) - (1)].txt), NULL, NULL, NULL);}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 35 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node((yyvsp[(1) - (1)].txt), NULL, NULL, NULL);}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 36 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node((yyvsp[(1) - (1)].txt), NULL, NULL, NULL);}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 37 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = (yyvsp[(2) - (3)].tree);}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 41 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 42 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("[]", (yyvsp[(1) - (4)].tree), (yyvsp[(3) - (4)].tree), NULL);}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 43 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("pf??", (yyvsp[(1) - (3)].tree), NULL, NULL);}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 44 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("pf??", NULL, NULL, NULL);}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 45 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node(".id", (yyvsp[(1) - (3)].tree), NULL, NULL);}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 46 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("->id", (yyvsp[(1) - (3)].tree), NULL, NULL);}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 47 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("++ (post)", (yyvsp[(1) - (2)].tree), NULL, NULL);}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 48 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("-- (post)", (yyvsp[(1) - (2)].tree), NULL, NULL);}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 57 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 58 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("++ (prae)", (yyvsp[(2) - (2)].tree), NULL, NULL);}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 59 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("-- (prae)", (yyvsp[(2) - (2)].tree), NULL, NULL);}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 60 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node((yyvsp[(1) - (2)].txt), (yyvsp[(2) - (2)].tree), NULL, NULL);}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 61 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("sizeof", (yyvsp[(2) - (2)].tree), NULL, NULL);}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 62 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("sizeof", NULL, NULL, NULL);}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 66 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {strcpy_s((yyval.txt), sizeof (yyval.txt), "&");}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 67 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {strcpy_s((yyval.txt), sizeof (yyval.txt), "*");}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 68 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {strcpy_s((yyval.txt), sizeof (yyval.txt), "+");}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 69 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {strcpy_s((yyval.txt), sizeof (yyval.txt), "-");}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 70 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {strcpy_s((yyval.txt), sizeof (yyval.txt), "~");}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 71 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {strcpy_s((yyval.txt), sizeof (yyval.txt), "!");}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 75 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 76 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("typecast", NULL, NULL, NULL);}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 80 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 81 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("*", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree), NULL);}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 82 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("/", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree), NULL);}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 83 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("%", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree), NULL);}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 87 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 88 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("+", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree), NULL);}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 89 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("-", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree), NULL);}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 93 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 94 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("<<", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree), NULL);}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 95 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node(">>", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree), NULL);}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 99 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 100 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("<", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree), NULL);}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 101 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node(">", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree), NULL);}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 102 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("<=", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree), NULL);}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 103 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node(">=", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree), NULL);}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 107 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 108 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("==", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree), NULL);}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 109 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("!0", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree), NULL);}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 113 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 114 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("&", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree), NULL);}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 118 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 119 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("^", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree), NULL);}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 123 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 124 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("|", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree), NULL);}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 128 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 129 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("&&", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree), NULL);}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 133 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 134 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("||", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree), NULL);}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 138 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 139 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node("?:", (yyvsp[(3) - (5)].tree), (yyvsp[(5) - (5)].tree), (yyvsp[(1) - (5)].tree));}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 143 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 144 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node((yyvsp[(2) - (3)].txt), (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree), NULL);}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 148 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {strcpy_s((yyval.txt), sizeof (yyval.txt), "=");}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 149 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {strcpy_s((yyval.txt), sizeof (yyval.txt), "*=");}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 150 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {strcpy_s((yyval.txt), sizeof (yyval.txt), "/=");}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 151 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {strcpy_s((yyval.txt), sizeof (yyval.txt), "%=");}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 152 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {strcpy_s((yyval.txt), sizeof (yyval.txt), "+=");}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 153 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {strcpy_s((yyval.txt), sizeof (yyval.txt), "-=");}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 154 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {strcpy_s((yyval.txt), sizeof (yyval.txt), "<<=");}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 155 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {strcpy_s((yyval.txt), sizeof (yyval.txt), ">>=");}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 156 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {strcpy_s((yyval.txt), sizeof (yyval.txt), "&=");}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 157 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {strcpy_s((yyval.txt), sizeof (yyval.txt), "|=");}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 158 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {strcpy_s((yyval.txt), sizeof (yyval.txt), "^=");}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 162 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 163 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {(yyval.tree) = new_node(",", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree), NULL);}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 167 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {strcpy_s((yyval.txt), sizeof (yyval.txt), "int");}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 168 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"
    {strcpy_s((yyval.txt), sizeof (yyval.txt), "double");}
    break;


/* Line 1792 of yacc.c  */
#line 1993 "C:/Users/Laurin/source/repos/c-nodes/src/__generated__/parser.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 170 "C:/Users/Laurin/source/repos/c-nodes/src/parser.y"

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
int main(unsigned int argc, char** argv) {
	root = NULL;
	for(unsigned int i = 1; i < argc; i++) {
		yy_scan_string(argv[i]);
		int rc = yyparse();
		if (rc == 0) {
			tree_output(root, 0);
			tree_tikz(root, 0);
		}
		else {
			printf("Syntaxfehler\n");
		}
		yylex_destroy();
	}	
	
	return 0;
}
