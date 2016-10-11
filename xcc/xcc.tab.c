/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CHAR = 258,
     ELSE = 259,
     GOTO = 260,
     IF = 261,
     INT = 262,
     RETURN = 263,
     VOID = 264,
     WHILE = 265,
     EQ = 266,
     AND = 267,
     OR = 268,
     IDENTIFIER = 269,
     STRING = 270,
     INTEGER_CONSTANT = 271,
     CHARACTER_CONSTANT = 272,
     UNARY_OP = 273
   };
#endif
/* Tokens.  */
#define CHAR 258
#define ELSE 259
#define GOTO 260
#define IF 261
#define INT 262
#define RETURN 263
#define VOID 264
#define WHILE 265
#define EQ 266
#define AND 267
#define OR 268
#define IDENTIFIER 269
#define STRING 270
#define INTEGER_CONSTANT 271
#define CHARACTER_CONSTANT 272
#define UNARY_OP 273




/* Copy the first part of user declarations.  */
#line 4 "xcc.y"

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "xcc.h"
#include "misc.h"
#include "AST.h"
#include "type.h"
#include "symbol.h"
#include "codegen.h"
#ifdef XCC_VIS
#include "vis/vis.h"
#endif
#define YYERROR_VERBOSE

struct AST *ast_root;
char       *filename;
FILE       *xcc_out;
int AST_is_local = 0;

static void init (int argc, char *argv []);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 1
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 167 "xcc.tab.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   209

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNRULES -- Number of states.  */
#define YYNSTATES  103

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   273

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,     2,     2,     2,    32,     2,
      25,    27,    22,    20,    28,    21,     2,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    29,    26,
      19,    18,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
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
      15,    16,    17,    24
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    13,    18,    19,
      22,    26,    28,    30,    32,    34,    37,    42,    46,    48,
      52,    55,    57,    60,    63,    65,    71,    79,    85,    89,
      93,    97,    98,    99,   106,   107,   109,   111,   113,   115,
     117,   121,   125,   129,   133,   137,   141,   145,   149,   153,
     156,   161,   165,   169,   171,   173,   175,   177,   179,   181,
     185
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      35,     0,    -1,    36,    -1,    35,    36,    -1,    37,    -1,
      40,    -1,    -1,    41,    42,    38,    47,    -1,    -1,    39,
      40,    -1,    41,    42,    26,    -1,     9,    -1,     3,    -1,
       7,    -1,    54,    -1,    22,    42,    -1,    42,    25,    43,
      27,    -1,    42,    25,    27,    -1,    44,    -1,    43,    28,
      44,    -1,    41,    42,    -1,    46,    -1,    45,    46,    -1,
      50,    26,    -1,    47,    -1,     6,    25,    51,    27,    46,
      -1,     6,    25,    51,    27,    46,     4,    46,    -1,    10,
      25,    51,    27,    46,    -1,     5,    54,    26,    -1,    54,
      29,    46,    -1,     8,    50,    26,    -1,    -1,    -1,    30,
      48,    39,    49,    45,    31,    -1,    -1,    51,    -1,    54,
      -1,    16,    -1,    17,    -1,    15,    -1,    51,    18,    51,
      -1,    51,    13,    51,    -1,    51,    12,    51,    -1,    51,
      11,    51,    -1,    51,    19,    51,    -1,    51,    20,    51,
      -1,    51,    21,    51,    -1,    51,    22,    51,    -1,    51,
      23,    51,    -1,    52,    51,    -1,    54,    25,    53,    27,
      -1,    54,    25,    27,    -1,    25,    51,    27,    -1,    32,
      -1,    22,    -1,    20,    -1,    21,    -1,    33,    -1,    51,
      -1,    53,    28,    51,    -1,    14,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    69,    69,    72,    78,    80,    89,    88,   105,   106,
     111,   118,   120,   122,   127,   129,   131,   133,   138,   140,
     145,   152,   154,   159,   161,   163,   165,   167,   169,   171,
     174,   180,   182,   179,   190,   191,   196,   201,   204,   217,
     220,   223,   226,   229,   232,   235,   238,   241,   244,   247,
     250,   260,   268,   274,   275,   276,   277,   278,   282,   285,
     291
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"char\"", "\"else\"", "\"goto\"",
  "\"if\"", "\"int\"", "\"return\"", "\"void\"", "\"while\"", "\"==\"",
  "\"&&\"", "\"||\"", "IDENTIFIER", "STRING", "INTEGER_CONSTANT",
  "CHARACTER_CONSTANT", "'='", "'<'", "'+'", "'-'", "'*'", "'/'",
  "UNARY_OP", "'('", "';'", "')'", "','", "':'", "'{'", "'}'", "'&'",
  "'!'", "$accept", "translation_unit", "external_declaration",
  "function_definition", "@1", "declaration_list", "declaration",
  "type_specifier", "declarator", "parameter_list",
  "parameter_declaration", "statement_list", "statement",
  "compound_statement", "@2", "@3", "expression_opt", "expression",
  "unary_operator", "argument_expression_list", "identifier", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    61,    60,
      43,    45,    42,    47,   273,    40,    59,    41,    44,    58,
     123,   125,    38,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    35,    36,    36,    38,    37,    39,    39,
      40,    41,    41,    41,    42,    42,    42,    42,    43,    43,
      44,    45,    45,    46,    46,    46,    46,    46,    46,    46,
      46,    48,    49,    47,    50,    50,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    52,    52,    52,    52,    52,    53,    53,
      54
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     0,     4,     0,     2,
       3,     1,     1,     1,     1,     2,     4,     3,     1,     3,
       2,     1,     2,     2,     1,     5,     7,     5,     3,     3,
       3,     0,     0,     6,     0,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       4,     3,     3,     1,     1,     1,     1,     1,     1,     3,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    12,    13,    11,     0,     2,     4,     5,     0,     1,
       3,    60,     0,     6,    14,    15,     0,    10,     0,    17,
       0,     0,    18,    31,     7,    20,    16,     0,     8,    19,
      32,     9,     0,    34,     0,     0,     0,    34,     0,    39,
      37,    38,    55,    56,    54,     0,    53,    57,    34,    21,
      24,     0,    35,     0,    36,     0,     0,     0,    36,     0,
       0,    33,    22,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,    34,    28,     0,    30,     0,
      52,    43,    42,    41,    40,    44,    45,    46,    47,    48,
      51,    58,     0,    29,    34,    34,    50,     0,    25,    27,
      59,    34,    26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    18,    30,     7,     8,    13,    21,
      22,    48,    49,    50,    28,    33,    51,    52,    53,    92,
      58
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -48
static const yytype_int16 yypact[] =
{
     190,   -48,   -48,   -48,    55,   -48,   -48,   -48,   -12,   -48,
     -48,   -48,   -12,    -6,   -48,   -22,    32,   -48,   -25,   -48,
     -12,   -14,   -48,   -48,   -48,   -22,   -48,   190,   -48,   -48,
     190,   -48,   -12,    74,    -6,    15,   -17,   108,    41,   -48,
     -48,   -48,   -48,   -48,   -48,   108,   -48,   -48,     1,   -48,
     -48,    51,   163,   108,    36,    57,   108,    59,    56,   108,
     124,   -48,   -48,   -48,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   -48,    94,    74,   -48,   137,   -48,   150,
     -48,   186,   181,   168,   163,    23,    14,    14,   -48,   -48,
     -48,   163,    24,   -48,    74,    74,   -48,   108,    88,   -48,
     163,    74,   -48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -48,    93,   -48,   -48,   -48,    68,    26,    18,   -48,
      73,   -48,   -47,    84,   -48,   -48,    66,     4,   -48,   -48,
      -8
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      14,    62,    11,    16,    14,    23,    35,    36,    56,    37,
      12,    38,    14,    26,    27,    11,    39,    40,    41,    16,
      17,    42,    43,    44,    14,    54,    45,    55,    93,    11,
      15,    23,    61,    46,    47,     1,    71,    72,    25,     2,
      54,     3,    20,    69,    70,    71,    72,    98,    99,    60,
      34,    96,    97,    20,   102,     9,    32,    73,     1,    19,
      77,    74,     2,    79,     3,    75,    59,    54,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    63,    91,    35,
      36,    74,    37,    76,    38,    78,    54,    54,    11,    39,
      40,    41,   101,    54,    42,    43,    44,    10,    31,    45,
      29,   100,    24,    57,    23,     0,    46,    47,    11,    39,
      40,    41,     0,     0,    42,    43,    44,     0,     0,    45,
       0,    90,    11,    39,    40,    41,    46,    47,    42,    43,
      44,     0,     0,    45,     0,    64,    65,    66,     0,     0,
      46,    47,    67,    68,    69,    70,    71,    72,    64,    65,
      66,    80,     0,     0,     0,    67,    68,    69,    70,    71,
      72,    64,    65,    66,    94,     0,     0,     0,    67,    68,
      69,    70,    71,    72,    64,    65,    66,    95,     0,    64,
      65,    67,    68,    69,    70,    71,    72,    68,    69,    70,
      71,    72,    64,     1,     0,     0,     0,     2,     0,     3,
      68,    69,    70,    71,    72,    68,    69,    70,    71,    72
};

static const yytype_int8 yycheck[] =
{
       8,    48,    14,    25,    12,    30,     5,     6,    25,     8,
      22,    10,    20,    27,    28,    14,    15,    16,    17,    25,
      26,    20,    21,    22,    32,    33,    25,    35,    75,    14,
      12,    30,    31,    32,    33,     3,    22,    23,    20,     7,
      48,     9,    16,    20,    21,    22,    23,    94,    95,    45,
      32,    27,    28,    27,   101,     0,    30,    53,     3,    27,
      56,    25,     7,    59,     9,    29,    25,    75,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    26,    74,     5,
       6,    25,     8,    26,    10,    26,    94,    95,    14,    15,
      16,    17,     4,   101,    20,    21,    22,     4,    30,    25,
      27,    97,    18,    37,    30,    -1,    32,    33,    14,    15,
      16,    17,    -1,    -1,    20,    21,    22,    -1,    -1,    25,
      -1,    27,    14,    15,    16,    17,    32,    33,    20,    21,
      22,    -1,    -1,    25,    -1,    11,    12,    13,    -1,    -1,
      32,    33,    18,    19,    20,    21,    22,    23,    11,    12,
      13,    27,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      23,    11,    12,    13,    27,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    11,    12,    13,    27,    -1,    11,
      12,    18,    19,    20,    21,    22,    23,    19,    20,    21,
      22,    23,    11,     3,    -1,    -1,    -1,     7,    -1,     9,
      19,    20,    21,    22,    23,    19,    20,    21,    22,    23
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     7,     9,    35,    36,    37,    40,    41,     0,
      36,    14,    22,    42,    54,    42,    25,    26,    38,    27,
      41,    43,    44,    30,    47,    42,    27,    28,    48,    44,
      39,    40,    41,    49,    42,     5,     6,     8,    10,    15,
      16,    17,    20,    21,    22,    25,    32,    33,    45,    46,
      47,    50,    51,    52,    54,    54,    25,    50,    54,    25,
      51,    31,    46,    26,    11,    12,    13,    18,    19,    20,
      21,    22,    23,    51,    25,    29,    26,    51,    26,    51,
      27,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      27,    51,    53,    46,    27,    27,    27,    28,    46,    46,
      51,     4,    46
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
#line 70 "xcc.y"
    { (yyval) = create_AST ("AST_translation_unit_single", 1, (yyvsp[(1) - (1)]));
	  ast_root = (yyval); ;}
    break;

  case 3:
#line 73 "xcc.y"
    { (yyval) = create_AST ("AST_translation_unit_pair", 2, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	  ast_root = (yyval); ;}
    break;

  case 4:
#line 79 "xcc.y"
    { (yyval) = create_AST ("AST_external_declaration_func", 1, (yyvsp[(1) - (1)])); ;}
    break;

  case 5:
#line 81 "xcc.y"
    { (yyval) = create_AST ("AST_external_declaration_dec", 1, (yyvsp[(1) - (1)])); 
	  sym_table.arg    = NULL;
  	  sym_table.label  = NULL;
  	  sym_table.string = NULL; ;}
    break;

  case 6:
#line 89 "xcc.y"
    { (yyval) = create_AST ("AST_dummy", 2, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	  (yyval)->type = type_analyze_declarator ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)])->type); 
          /* conditonal to cause more natural syntax error */
          if ((yyval)->type->kind == TYPE_KIND_FUNCTION) {
              sym_entry_param ((yyval)->type);
              sym_entry ((yyval));
              sym_begin_function ();
          } ;}
    break;

  case 7:
#line 98 "xcc.y"
    { (yyval) = create_AST ("AST_function_definition", 3, (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
          sym_backpatch ((yyval), (yyvsp[(3) - (4)])->type);
	  sym_end_function ((yyval)); ;}
    break;

  case 8:
#line 105 "xcc.y"
    { (yyval) = create_AST ("AST_declaration_list_null", 0); ;}
    break;

  case 9:
#line 107 "xcc.y"
    { (yyval) = create_AST ("AST_declaration_list_pair", 2, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 10:
#line 112 "xcc.y"
    { (yyval) = create_AST ("AST_declaration", 2, (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])); 
	  (yyval)->type = type_analyze_declarator ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)])->type);
	  sym_entry ((yyval)); ;}
    break;

  case 11:
#line 118 "xcc.y"
    { (yyval) = create_AST ("AST_type_specifier_void", 0);
               (yyval)->type = create_prim_type (PRIM_TYPE_VOID); ;}
    break;

  case 12:
#line 120 "xcc.y"
    { (yyval) = create_AST ("AST_type_specifier_char", 0);
               (yyval)->type = create_prim_type (PRIM_TYPE_CHAR); ;}
    break;

  case 13:
#line 122 "xcc.y"
    { (yyval) = create_AST ("AST_type_specifier_int", 0);
               (yyval)->type = create_prim_type (PRIM_TYPE_INT); ;}
    break;

  case 14:
#line 128 "xcc.y"
    { (yyval) = create_AST ("AST_declarator_id", 1, (yyvsp[(1) - (1)])); ;}
    break;

  case 15:
#line 130 "xcc.y"
    { (yyval) = create_AST ("AST_declarator_pointer", 1, (yyvsp[(2) - (2)])); ;}
    break;

  case 16:
#line 132 "xcc.y"
    { (yyval) = create_AST ("AST_declarator_func1", 2, (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); ;}
    break;

  case 17:
#line 134 "xcc.y"
    { (yyval) = create_AST ("AST_declarator_func2", 1, (yyvsp[(1) - (3)])); ;}
    break;

  case 18:
#line 139 "xcc.y"
    { (yyval) = create_AST ("AST_parameter_list_single", 1, (yyvsp[(1) - (1)])); ;}
    break;

  case 19:
#line 141 "xcc.y"
    { (yyval) = create_AST ("AST_parameter_list_pair", 2, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 20:
#line 146 "xcc.y"
    { (yyval) = create_AST ("AST_parameter_declaration", 2, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	  (yyval)->type = type_analyze_declarator ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)])->type);
	  /* sym_entry ($$); */ ;}
    break;

  case 21:
#line 153 "xcc.y"
    { (yyval) = create_AST ("AST_statement_list_single", 1, (yyvsp[(1) - (1)])); ;}
    break;

  case 22:
#line 155 "xcc.y"
    { (yyval) = create_AST ("AST_statement_list_pair", 2, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 23:
#line 160 "xcc.y"
    { (yyval) = create_AST ("AST_statement_exp", 1, (yyvsp[(1) - (2)])); ;}
    break;

  case 24:
#line 162 "xcc.y"
    { (yyval) = create_AST ("AST_statement_comp", 1, (yyvsp[(1) - (1)])); ;}
    break;

  case 25:
#line 164 "xcc.y"
    { (yyval) = create_AST ("AST_statement_if", 2, (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); ;}
    break;

  case 26:
#line 166 "xcc.y"
    { (yyval) = create_AST ("AST_statement_ifelse", 3, (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)])); ;}
    break;

  case 27:
#line 168 "xcc.y"
    { (yyval) = create_AST ("AST_statement_while", 2, (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); ;}
    break;

  case 28:
#line 170 "xcc.y"
    { (yyval) = create_AST ("AST_statement_goto", 1, (yyvsp[(2) - (3)])); ;}
    break;

  case 29:
#line 172 "xcc.y"
    { (yyval) = create_AST ("AST_statement_label", 2, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	  sym_entry ((yyval)); ;}
    break;

  case 30:
#line 175 "xcc.y"
    { (yyval) = create_AST ("AST_statement_return", 1, (yyvsp[(2) - (3)])); ;}
    break;

  case 31:
#line 180 "xcc.y"
    { sym_begin_block (); ;}
    break;

  case 32:
#line 182 "xcc.y"
    { sym_middle_block (); ;}
    break;

  case 33:
#line 184 "xcc.y"
    { (yyval) = create_AST ("AST_compound_statement", 2, (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]));
	  sym_end_block ((yyval)); ;}
    break;

  case 34:
#line 190 "xcc.y"
    { (yyval) = create_AST ("AST_expression_opt_null", 0); ;}
    break;

  case 35:
#line 192 "xcc.y"
    { (yyval) = create_AST ("AST_expression_opt_single", 1, (yyvsp[(1) - (1)])); ;}
    break;

  case 36:
#line 197 "xcc.y"
    { struct Symbol *sym;
          (yyval) = create_AST ("AST_expression_id", 1, (yyvsp[(1) - (1)]));
          sym = sym_check_var_decl ((yyval));
	  (yyval)->type = sym->type; ;}
    break;

  case 37:
#line 202 "xcc.y"
    { (yyval) = create_AST ("AST_expression_int", 1, atoi (yytext));
	  (yyval)->type = types.t_int; ;}
    break;

  case 38:
#line 205 "xcc.y"
    { 
          char c;
          if (yytext [1] == '\\') { /* escape sequence */
              switch (yytext [2]) {
              case 'n': c = '\n';   break;
              default:  assert (0); break;
              }
          } else { /* normal character */
              c = yytext [1];
          }
          (yyval) = create_AST ("AST_expression_char", 1, c);
	  (yyval)->type = types.t_int; ;}
    break;

  case 39:
#line 218 "xcc.y"
    { (yyval) = create_AST ("AST_expression_string", 1, str_buf);
	  (yyval)->type = types.t_char_p; string_entry ((yyval)->u.id); ;}
    break;

  case 40:
#line 221 "xcc.y"
    { (yyval) = create_AST ("AST_expression_assign", 2, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	  (yyval)->type = (yyvsp[(1) - (3)])->type; ;}
    break;

  case 41:
#line 224 "xcc.y"
    { (yyval) = create_AST ("AST_expression_lor",    2, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	  (yyval)->type = types.t_int; ;}
    break;

  case 42:
#line 227 "xcc.y"
    { (yyval) = create_AST ("AST_expression_land",   2, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	  (yyval)->type = types.t_int; ;}
    break;

  case 43:
#line 230 "xcc.y"
    { (yyval) = create_AST ("AST_expression_eq",     2, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	  (yyval)->type = types.t_int; ;}
    break;

  case 44:
#line 233 "xcc.y"
    { (yyval) = create_AST ("AST_expression_less",   2, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	  (yyval)->type = types.t_int; ;}
    break;

  case 45:
#line 236 "xcc.y"
    { (yyval) = create_AST ("AST_expression_add",    2, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	  (yyval)->type = type_add ((yyvsp[(1) - (3)])->type, (yyvsp[(3) - (3)])->type); ;}
    break;

  case 46:
#line 239 "xcc.y"
    { (yyval) = create_AST ("AST_expression_sub",    2, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	  (yyval)->type = type_sub ((yyvsp[(1) - (3)])->type, (yyvsp[(3) - (3)])->type); ;}
    break;

  case 47:
#line 242 "xcc.y"
    { (yyval) = create_AST ("AST_expression_mul",    2, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	  (yyval)->type = types.t_int; ;}
    break;

  case 48:
#line 245 "xcc.y"
    { (yyval) = create_AST ("AST_expression_div",    2, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	  (yyval)->type = types.t_int; ;}
    break;

  case 49:
#line 248 "xcc.y"
    { (yyval) = create_AST ("AST_expression_unary",  2, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	  (yyval)->type = type_uop ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])->type); ;}
    break;

  case 50:
#line 251 "xcc.y"
    { struct Symbol *sym;
          struct AST *ast;
          ast = create_AST ("AST_expression_id", 1, (yyvsp[(1) - (4)]));
          sym = sym_check_var_decl (ast);
	  ast->type = sym->type;
          (yyval) = create_AST ("AST_expression_funcall1", 2, ast, (yyvsp[(3) - (4)]));
	  (yyval)->type = ast->type->u.t_function.ret_type;
	  if ((yyvsp[(3) - (4)])->u.arg_size > max_arg_size)
	      max_arg_size = (yyvsp[(3) - (4)])->u.arg_size; ;}
    break;

  case 51:
#line 261 "xcc.y"
    { struct Symbol *sym;
          struct AST *ast;
          ast = create_AST ("AST_expression_id", 1, (yyvsp[(1) - (3)]));
          sym = sym_check_var_decl (ast);
	  ast->type = sym->type;
          (yyval) = create_AST ("AST_expression_funcall2", 1, ast);
	  (yyval)->type = ast->type->u.t_function.ret_type; ;}
    break;

  case 52:
#line 269 "xcc.y"
    { (yyval) = create_AST ("AST_expression_paren", 1, (yyvsp[(2) - (3)]));
	  (yyval)->type = (yyvsp[(2) - (3)])->type; ;}
    break;

  case 53:
#line 274 "xcc.y"
    { (yyval) = create_AST ("AST_unary_operator_address",  0); ;}
    break;

  case 54:
#line 275 "xcc.y"
    { (yyval) = create_AST ("AST_unary_operator_deref",    0); ;}
    break;

  case 55:
#line 276 "xcc.y"
    { (yyval) = create_AST ("AST_unary_operator_plus",     0); ;}
    break;

  case 56:
#line 277 "xcc.y"
    { (yyval) = create_AST ("AST_unary_operator_minus",    0); ;}
    break;

  case 57:
#line 278 "xcc.y"
    { (yyval) = create_AST ("AST_unary_operator_negative", 0); ;}
    break;

  case 58:
#line 283 "xcc.y"
    { (yyval) = create_AST ("AST_argument_expression_list_single", 1, (yyvsp[(1) - (1)]));
	  (yyval)->u.arg_size = ROUNDUP_INT ((yyvsp[(1) - (1)])->type->size); ;}
    break;

  case 59:
#line 286 "xcc.y"
    { (yyval) = create_AST ("AST_argument_expression_list_pair", 2, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	(yyval)->u.arg_size = (yyvsp[(1) - (3)])->u.arg_size + ROUNDUP_INT ((yyvsp[(3) - (3)])->type->size); ;}
    break;

  case 60:
#line 291 "xcc.y"
    { (yyval) = create_AST ("AST_IDENTIFIER", 1, yytext); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1837 "xcc.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 293 "xcc.y"

/* ---------------------------------------------------------------------- */
static void
init (int argc, char *argv [])
{
    /* handling command line arguments */
    if (argc < 2) {
	fprintf (stderr, "Usage: %s filename\n", argv [0]);
	exit (1);
    }
    filename = argv [1];
    yyin = fopen (filename, "r");
    if (yyin == NULL) {
	fprintf (stderr, "Cannot open file: %s\n", argv [1]);
	exit (1);
    }

    /* initialization for types */
    types.t_void   = create_prim_type (PRIM_TYPE_VOID);
    types.t_char   = create_prim_type (PRIM_TYPE_CHAR);
    types.t_int    = create_prim_type (PRIM_TYPE_INT);
    types.t_char_p = create_pointer_type (types.t_char);

    xcc_out = stdout;
}
/* --------------------------------------------------------------------- */
int
yyerror (char *mesg)
{
    fprintf (stderr, "yyerror: %d: %s around `%s'\n",
	     lineno, mesg, yytext);
    exit (1);
}

int
main (int argc, char *argv [])
{
    init (argc, argv);
    yyparse (); /* semantic analysis is also done in actions */

    codegen ();
    return 0;
}
/* --------------------------------------------------------------------- */

