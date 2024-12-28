
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "symboltable.h"
#include "symbolentry.h"



int yylex(void);
int yyerror(char *s);
//read from text file
extern FILE *yyin;
//symbol table
SymbolTable *globalTable;
SymbolTable *currTable;
SymbolTable *tempTable;

int scope = 0;
//symbol entry


/* Line 189 of yacc.c  */
#line 97 "y.tab.c"

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
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_TYPE = 258,
     DOUBLE_TYPE = 259,
     CHAR_TYPE = 260,
     BOOL_TYPE = 261,
     STRING_TYPE = 262,
     VOID = 263,
     INTEGER = 264,
     DOUBLE = 265,
     CHAR = 266,
     BOOL = 267,
     IDENTIFIER = 268,
     SEMICOLON = 269,
     CONST = 270,
     INC = 271,
     DEC = 272,
     COMMA = 273,
     LT = 274,
     GT = 275,
     LTE = 276,
     GTE = 277,
     EQ = 278,
     NEQ = 279,
     EQU = 280,
     ADD_EQ = 281,
     SUB_EQ = 282,
     MULT_EQ = 283,
     DIV_EQ = 284,
     PLUS = 285,
     MINUS = 286,
     MULT = 287,
     DIV = 288,
     LEFT_ROUND = 289,
     RIGHT_ROUND = 290,
     LEFT_CURLY = 291,
     RIGHT_CURLY = 292,
     IF = 293,
     ELSE = 294,
     FOR = 295,
     WHILE = 296,
     DO = 297,
     SWITCH = 298,
     CASE = 299,
     AND = 300,
     OR = 301,
     NOT = 302,
     UNKNOWN = 303,
     COLON = 304,
     BREAK = 305,
     DEFAULT = 306,
     LOWER_THAN_ELSE = 307
   };
#endif
/* Tokens.  */
#define INT_TYPE 258
#define DOUBLE_TYPE 259
#define CHAR_TYPE 260
#define BOOL_TYPE 261
#define STRING_TYPE 262
#define VOID 263
#define INTEGER 264
#define DOUBLE 265
#define CHAR 266
#define BOOL 267
#define IDENTIFIER 268
#define SEMICOLON 269
#define CONST 270
#define INC 271
#define DEC 272
#define COMMA 273
#define LT 274
#define GT 275
#define LTE 276
#define GTE 277
#define EQ 278
#define NEQ 279
#define EQU 280
#define ADD_EQ 281
#define SUB_EQ 282
#define MULT_EQ 283
#define DIV_EQ 284
#define PLUS 285
#define MINUS 286
#define MULT 287
#define DIV 288
#define LEFT_ROUND 289
#define RIGHT_ROUND 290
#define LEFT_CURLY 291
#define RIGHT_CURLY 292
#define IF 293
#define ELSE 294
#define FOR 295
#define WHILE 296
#define DO 297
#define SWITCH 298
#define CASE 299
#define AND 300
#define OR 301
#define NOT 302
#define UNKNOWN 303
#define COLON 304
#define BREAK 305
#define DEFAULT 306
#define LOWER_THAN_ELSE 307




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 24 "parser.y"

    int ival;    // Integer values
    double dVal; // Double values
    char *sval;  // String values (if needed)
    bool bVal;
    char* op;
    char cval;
    char*semi;



/* Line 214 of yacc.c  */
#line 249 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 261 "y.tab.c"

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
# if YYENABLE_NLS
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   421

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNRULES -- Number of states.  */
#define YYNSTATES  172

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    12,    14,    16,    20,
      22,    24,    26,    28,    30,    32,    34,    36,    38,    41,
      43,    51,    53,    56,    63,    69,    75,    80,    86,    92,
      99,   106,   109,   114,   116,   120,   128,   134,   143,   145,
     147,   153,   161,   163,   167,   171,   174,   176,   180,   184,
     188,   192,   196,   200,   202,   209,   212,   216,   222,   225,
     229,   234,   236,   238,   242,   246,   250,   254,   258,   260,
     262,   264,   266,   268,   270,   272,   275,   278,   281,   284,
     286,   288,   290,   292,   294
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    55,    56,    -1,    -1,    56,    57,    -1,
      57,    -1,    61,    -1,    58,    -1,    59,    56,    60,    -1,
      36,    -1,    37,    -1,    76,    -1,    65,    -1,    75,    -1,
      72,    -1,    70,    -1,    69,    -1,    68,    -1,    77,    14,
      -1,    62,    -1,    43,    34,    78,    35,    36,    63,    37,
      -1,    64,    -1,    63,    64,    -1,    44,    78,    49,    56,
      50,    14,    -1,    44,    78,    49,    50,    14,    -1,    51,
      49,    56,    50,    14,    -1,    51,    49,    50,    14,    -1,
      79,    13,    34,    35,    57,    -1,    79,    13,    34,    35,
      14,    -1,    79,    13,    34,    66,    35,    57,    -1,    79,
      13,    34,    66,    35,    14,    -1,    79,    13,    -1,    66,
      18,    79,    13,    -1,    78,    -1,    67,    18,    78,    -1,
      42,    57,    41,    34,    74,    35,    14,    -1,    41,    34,
      74,    35,    57,    -1,    40,    34,    76,    74,    14,    71,
      35,    57,    -1,    82,    -1,    80,    -1,    38,    34,    73,
      35,    57,    -1,    38,    34,    73,    35,    57,    39,    57,
      -1,    74,    -1,    74,    45,    73,    -1,    74,    46,    73,
      -1,    47,    74,    -1,    78,    -1,    78,    19,    78,    -1,
      78,    20,    78,    -1,    78,    21,    78,    -1,    78,    22,
      78,    -1,    78,    23,    78,    -1,    78,    24,    78,    -1,
      12,    -1,    15,    79,    13,    25,    78,    14,    -1,    80,
      14,    -1,    79,    13,    14,    -1,    79,    13,    25,    78,
      14,    -1,    82,    14,    -1,    13,    34,    35,    -1,    13,
      34,    67,    35,    -1,     9,    -1,    13,    -1,    78,    30,
      78,    -1,    78,    31,    78,    -1,    78,    32,    78,    -1,
      78,    33,    78,    -1,    34,    78,    35,    -1,    77,    -1,
       3,    -1,     4,    -1,     6,    -1,     5,    -1,     7,    -1,
       8,    -1,    13,    16,    -1,    13,    17,    -1,    16,    13,
      -1,    17,    13,    -1,    25,    -1,    26,    -1,    27,    -1,
      28,    -1,    29,    -1,    13,    81,    78,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    73,    81,    82,    86,    87,    91,    94,
     102,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     125,   128,   129,   132,   133,   134,   135,   139,   140,   141,
     142,   145,   146,   149,   150,   154,   157,   160,   164,   165,
     168,   169,   173,   174,   175,   176,   180,   181,   182,   183,
     184,   185,   186,   187,   191,   197,   198,   207,   212,   216,
     217,   221,   224,   225,   226,   227,   228,   229,   230,   235,
     238,   241,   244,   247,   250,   256,   257,   258,   259,   263,
     266,   267,   268,   269,   273
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_TYPE", "DOUBLE_TYPE", "CHAR_TYPE",
  "BOOL_TYPE", "STRING_TYPE", "VOID", "INTEGER", "DOUBLE", "CHAR", "BOOL",
  "IDENTIFIER", "SEMICOLON", "CONST", "INC", "DEC", "COMMA", "LT", "GT",
  "LTE", "GTE", "EQ", "NEQ", "EQU", "ADD_EQ", "SUB_EQ", "MULT_EQ",
  "DIV_EQ", "PLUS", "MINUS", "MULT", "DIV", "LEFT_ROUND", "RIGHT_ROUND",
  "LEFT_CURLY", "RIGHT_CURLY", "IF", "ELSE", "FOR", "WHILE", "DO",
  "SWITCH", "CASE", "AND", "OR", "NOT", "UNKNOWN", "COLON", "BREAK",
  "DEFAULT", "LOWER_THAN_ELSE", "$accept", "program", "start",
  "statements", "statement", "scoped_statement", "start_scope",
  "end_scope", "one_line_statement", "switch_statement", "switch_cases",
  "switch_case", "func_statement", "func_params", "func_call_parameter",
  "do_while_statement", "while_statement", "for_statement", "for_step",
  "conditional_statement", "conditional_if", "conditional_expression",
  "special_declaration", "default_declaration", "func_call", "expression",
  "data_type", "unary_expression", "assign_operation", "assign_expression", 0
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
     305,   306,   307
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    56,    56,    57,    57,    58,    59,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      62,    63,    63,    64,    64,    64,    64,    65,    65,    65,
      65,    66,    66,    67,    67,    68,    69,    70,    71,    71,
      72,    72,    73,    73,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    74,    75,    75,    75,    76,    76,    77,
      77,    78,    78,    78,    78,    78,    78,    78,    78,    79,
      79,    79,    79,    79,    79,    80,    80,    80,    80,    81,
      81,    81,    81,    81,    82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       7,     1,     2,     6,     5,     5,     4,     5,     5,     6,
       6,     2,     4,     1,     3,     7,     5,     8,     1,     1,
       5,     7,     1,     3,     3,     2,     1,     3,     3,     3,
       3,     3,     3,     1,     6,     2,     3,     5,     2,     3,
       4,     1,     1,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,    69,    70,    72,    71,    73,    74,
       0,     0,     0,     0,     9,     0,     0,     0,     0,     0,
       2,     5,     7,     0,     6,    19,    12,    17,    16,    15,
      14,    13,    11,     0,     0,     0,     0,    75,    76,    79,
      80,    81,    82,    83,     0,     0,     0,    77,    78,     0,
       0,     0,     0,     0,     4,     0,    18,     0,    55,    58,
      61,    62,     0,    59,     0,    68,    33,    84,     0,    53,
       0,     0,    42,    46,     0,     0,     0,     0,     0,     0,
      10,     8,    56,     0,     0,     0,     0,    60,     0,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    34,    63,    64,    65,    66,     0,    40,
      43,    44,    47,    48,    49,    50,    51,    52,     0,    36,
       0,     0,    57,    28,    27,     0,     0,    31,    54,     0,
       0,     0,    39,    38,     0,     0,     0,     0,    21,     0,
      30,    29,    41,     0,    35,     0,     0,    20,    22,    32,
      37,     0,     0,     0,     0,     0,    26,     0,    24,     0,
      25,    23
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    20,    21,    22,    23,    81,    24,    25,
     147,   148,    26,   110,    64,    27,    28,    29,   141,    30,
      71,    72,    31,    32,    65,    73,    34,    35,    45,    36
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -46
static const yytype_int16 yypact[] =
{
     -46,     7,   344,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     372,   258,     4,    16,   -46,    10,    17,    25,   344,    28,
     344,   -46,   -46,   344,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,    24,    37,    27,    62,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,    11,    26,    65,   -46,   -46,     0,
     202,    14,    39,    26,   -46,   273,   -46,     8,   -46,   -46,
     -46,    57,    26,   -46,    -4,   -46,   140,   140,    68,   -46,
      14,    60,    -9,   388,   292,    14,    91,    71,    76,    87,
     -46,   -46,   -46,    26,    66,   125,    26,   -46,    26,    26,
      26,    26,    26,   -46,   344,     0,     0,    26,    26,    26,
      26,    26,    26,   102,    98,   344,    14,    89,    67,   288,
      -3,   113,   -46,   140,   -46,   -46,   -46,   -46,    82,    88,
     -46,   -46,   140,   140,   140,   140,   140,   140,    92,   -46,
      94,   -43,   -46,   -46,   -46,   258,   329,   -46,   -46,   344,
     116,    95,   -46,   -46,   117,    26,    90,    38,   -46,   123,
     -46,   -46,   -46,   344,   -46,    53,   161,   -46,   -46,   -46,
     -46,   176,   132,   217,   133,   232,   -46,   135,   -46,   138,
     -46,   -46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -46,   -46,   -46,   -21,   -15,   -46,   -46,   -46,   -46,   -46,
     -46,     6,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
      -8,   -45,   -46,   112,    -2,   -34,    -7,    47,   -46,    58
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      33,   145,    55,    52,    46,    54,    77,     3,   146,    60,
      66,    67,    69,    61,    86,   135,    33,    47,    33,    79,
      60,    33,    82,    60,    61,    93,    69,    61,    85,    48,
     103,    87,   136,    83,    62,    60,    95,    96,    56,    61,
      54,    58,    84,    76,    49,    62,    63,    70,    62,   108,
      57,    50,   113,    33,   114,   115,   116,   117,   118,    51,
      62,   130,    53,   122,   123,   124,   125,   126,   127,     4,
       5,     6,     7,     8,     9,   157,    59,   111,    68,   119,
      78,   132,   145,    88,    89,    90,    91,   120,   121,   146,
     129,    44,    33,    92,   134,    94,   138,    88,    89,    90,
      91,   109,   161,    33,   104,   140,   105,    33,    12,    13,
     106,   155,    88,    89,    90,    91,   128,    88,    89,    90,
      91,   151,   107,    83,   152,   131,   137,   139,   149,   144,
     153,   154,    37,    38,    33,   163,   159,    33,   160,   156,
     165,    39,    40,    41,    42,    43,   166,   168,    54,   170,
      54,    33,   171,   158,    33,    88,    89,    90,    91,    33,
     112,    33,    75,    33,     4,     5,     6,     7,     8,     9,
      88,    89,    90,    91,    10,   142,    11,    12,    13,     4,
       5,     6,     7,     8,     9,     0,   143,     0,     0,    10,
       0,    11,    12,    13,     0,     0,     0,    14,     0,    15,
       0,    16,    17,    18,    19,     4,     5,     6,     7,     8,
       9,   162,    14,     0,    15,    74,    16,    17,    18,    19,
       4,     5,     6,     7,     8,     9,   164,     0,     0,     0,
      10,     0,    11,    12,    13,     4,     5,     6,     7,     8,
       9,     0,     0,     0,     0,    10,     0,    11,    12,    13,
       0,     0,     0,    14,     0,    15,     0,    16,    17,    18,
      19,     4,     5,     6,     7,     8,     9,   167,    14,     0,
      15,     0,    16,    17,    18,    19,     4,     5,     6,     7,
       8,     9,   169,     0,     0,     0,    10,     0,    11,    12,
      13,     4,     5,     6,     7,     8,     9,     0,     0,     0,
       0,    10,   133,    11,    12,    13,     0,     0,     0,    14,
      80,    15,     0,    16,    17,    18,    19,    39,    40,    41,
      42,    43,     0,     0,    14,     0,    15,     0,    16,    17,
      18,    19,     4,     5,     6,     7,     8,     9,     0,     0,
       0,     0,    10,   150,    11,    12,    13,     4,     5,     6,
       7,     8,     9,     0,     0,     0,     0,    10,     0,    11,
      12,    13,     0,     0,     0,    14,     0,    15,     0,    16,
      17,    18,    19,     0,     0,     0,     0,     0,     0,     0,
      14,     0,    15,     0,    16,    17,    18,    19,    37,    38,
       0,     0,     0,     0,     0,     0,     0,    39,    40,    41,
      42,    43,     0,     0,     0,     0,    44,    97,    98,    99,
     100,   101,   102,     0,     0,     0,     0,     0,    88,    89,
      90,    91
};

static const yytype_int16 yycheck[] =
{
       2,    44,    23,    18,    11,    20,    51,     0,    51,     9,
      44,    45,    12,    13,    18,    18,    18,    13,    20,    53,
       9,    23,    14,     9,    13,    70,    12,    13,    62,    13,
      75,    35,    35,    25,    34,     9,    45,    46,    14,    13,
      55,    14,    34,    50,    34,    34,    35,    47,    34,    83,
      13,    34,    86,    55,    88,    89,    90,    91,    92,    34,
      34,   106,    34,    97,    98,    99,   100,   101,   102,     3,
       4,     5,     6,     7,     8,    37,    14,    84,    13,    94,
      41,    14,    44,    30,    31,    32,    33,    95,    96,    51,
     105,    34,    94,    25,   109,    35,    14,    30,    31,    32,
      33,    35,    49,   105,    13,    13,    35,   109,    16,    17,
      34,   145,    30,    31,    32,    33,    14,    30,    31,    32,
      33,   136,    35,    25,   139,    36,    13,    39,   135,    35,
      35,    14,    16,    17,   136,   156,    13,   139,   153,    49,
     161,    25,    26,    27,    28,    29,    14,    14,   163,    14,
     165,   153,    14,   147,   156,    30,    31,    32,    33,   161,
      35,   163,    50,   165,     3,     4,     5,     6,     7,     8,
      30,    31,    32,    33,    13,   128,    15,    16,    17,     3,
       4,     5,     6,     7,     8,    -1,   128,    -1,    -1,    13,
      -1,    15,    16,    17,    -1,    -1,    -1,    36,    -1,    38,
      -1,    40,    41,    42,    43,     3,     4,     5,     6,     7,
       8,    50,    36,    -1,    38,    13,    40,    41,    42,    43,
       3,     4,     5,     6,     7,     8,    50,    -1,    -1,    -1,
      13,    -1,    15,    16,    17,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    13,    -1,    15,    16,    17,
      -1,    -1,    -1,    36,    -1,    38,    -1,    40,    41,    42,
      43,     3,     4,     5,     6,     7,     8,    50,    36,    -1,
      38,    -1,    40,    41,    42,    43,     3,     4,     5,     6,
       7,     8,    50,    -1,    -1,    -1,    13,    -1,    15,    16,
      17,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    13,    14,    15,    16,    17,    -1,    -1,    -1,    36,
      37,    38,    -1,    40,    41,    42,    43,    25,    26,    27,
      28,    29,    -1,    -1,    36,    -1,    38,    -1,    40,    41,
      42,    43,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    13,    14,    15,    16,    17,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    13,    -1,    15,
      16,    17,    -1,    -1,    -1,    36,    -1,    38,    -1,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    38,    -1,    40,    41,    42,    43,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    34,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    54,    55,     0,     3,     4,     5,     6,     7,     8,
      13,    15,    16,    17,    36,    38,    40,    41,    42,    43,
      56,    57,    58,    59,    61,    62,    65,    68,    69,    70,
      72,    75,    76,    77,    79,    80,    82,    16,    17,    25,
      26,    27,    28,    29,    34,    81,    79,    13,    13,    34,
      34,    34,    57,    34,    57,    56,    14,    13,    14,    14,
       9,    13,    34,    35,    67,    77,    78,    78,    13,    12,
      47,    73,    74,    78,    13,    76,    79,    74,    41,    78,
      37,    60,    14,    25,    34,    78,    18,    35,    30,    31,
      32,    33,    25,    74,    35,    45,    46,    19,    20,    21,
      22,    23,    24,    74,    13,    35,    34,    35,    78,    35,
      66,    79,    35,    78,    78,    78,    78,    78,    78,    57,
      73,    73,    78,    78,    78,    78,    78,    78,    14,    57,
      74,    36,    14,    14,    57,    18,    35,    13,    14,    39,
      13,    71,    80,    82,    35,    44,    51,    63,    64,    79,
      14,    57,    57,    35,    14,    78,    49,    37,    64,    13,
      57,    49,    50,    56,    50,    56,    14,    50,    14,    50,
      14,    14
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
# if YYLTYPE_IS_TRIVIAL
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
        case 3:

/* Line 1455 of yacc.c  */
#line 73 "parser.y"
    {
        printf("Start\n");
               globalTable = createSymbolTable("global",scope, NULL);
                                    currTable = globalTable;

        }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 94 "parser.y"
    {printf("Start Scope\n");
        scope++;
        tempTable = createSymbolTable("local",scope, currTable);
        addChildToTable(currTable, tempTable);
        currTable = tempTable;
        }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 102 "parser.y"
    {printf("End Scope\n");
        scope--;
        currTable = currTable->parent;
        }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    {printf("defualt Declaration\n");}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 114 "parser.y"
    {printf("func_statment \n");}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 115 "parser.y"
    {printf("special Declaration\n");}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    {printf("Conditional Statement\n");}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    {printf("For Statement\n");}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 118 "parser.y"
    {printf("While Statement\n");}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 119 "parser.y"
    {printf("Do While Statement\n");}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    {printf("Function Call with semi colonnnn\n");}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    {printf("Switch Statement\n");}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    {printf("Function Statement no params\n");}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 140 "parser.y"
    {printf("Function Statement no params\n");}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    {printf("Function Statement\n");}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    {printf("Function Statement\n");}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    {printf("COMAAAA\n");}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    {printf("Do While Statement\n");}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    {printf("While Statement\n");}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 160 "parser.y"
    {printf("For Statement\n");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    {printf("If Statement\n");}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    {printf("If Else Statement\n");}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    {printf("Conditional Expression\n");}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    {printf("Less Than\n");}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    {printf("Greater Than\n");}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 191 "parser.y"
    {    
        SymbolEntry *entry=createSymbolEntry((yyvsp[(3) - (6)].sval), constant, 0,(yyvsp[(2) - (6)].sval),"", 1, 0, NULL, "");

        addEntryToTable(currTable, entry);
        
        }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 198 "parser.y"
    {printf("Data Type Identifier\n");
        SymbolEntry* entry= createSymbolEntryWithDefaults((yyvsp[(2) - (3)].sval), var,0,(yyvsp[(1) - (3)].sval),"");
        addEntryToTable(currTable, entry);
        
        
        }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 207 "parser.y"
    {    
                 SymbolEntry* entry= createSymbolEntryWithDefaults((yyvsp[(2) - (5)].sval), var,0,(yyvsp[(1) - (5)].sval),"");
        addEntryToTable(currTable, entry);

            }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 212 "parser.y"
    {printf("Assign Expression\n");}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 221 "parser.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); 
                printf("Integer: %d\n", (yyvsp[(1) - (1)].ival));
                }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    { printf("Variable: %s\n", (yyvsp[(1) - (1)].sval)); (yyval.ival) = 0; }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 225 "parser.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival) + (yyvsp[(3) - (3)].ival); }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 226 "parser.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival) - (yyvsp[(3) - (3)].ival); }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 227 "parser.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival) * (yyvsp[(3) - (3)].ival); }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 228 "parser.y"
    { (yyval.ival) = 0; }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 229 "parser.y"
    { (yyval.ival) = (yyvsp[(2) - (3)].ival); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 230 "parser.y"
    {printf("Function Call\n");}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 235 "parser.y"
    {printf("Int Type\n");
        (yyval.sval) = "int";
        }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 238 "parser.y"
    {printf("Double Type\n");
        (yyval.sval) = "double";
        }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 241 "parser.y"
    {printf("Bool Type\n");
        (yyval.sval) = "bool";
        }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 244 "parser.y"
    {printf("Char Type\n");
        (yyval.sval) = "char";
        }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 247 "parser.y"
    {printf("String Type\n");
        (yyval.sval) = "string";
        }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 250 "parser.y"
    {printf("Void Type\n");
        (yyval.sval) = "void";
        }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 256 "parser.y"
    {printf("Increment: %s\n", (yyvsp[(1) - (2)].sval));}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 263 "parser.y"
    {  
                    printf("= EQUALLLLL \n");
                    }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 273 "parser.y"
    {
            printf("Assignment:");
        }
    break;



/* Line 1455 of yacc.c  */
#line 2028 "y.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 278 "parser.y"

int yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 1;
}

int main(int argc, char **argv) {
        
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        // Print file name 
        printf("File name: %s\n", argv[1]);
        if (!yyin) {
            perror("Error opening file");
            return 1;
        }
    } else {
        printf("No input file provided\n");
        return 1;
    }

    if (yyparse() == 0) {
        printf("Parsing successful\n");
        printTable(globalTable);
        return 0;
    } else {
        printf("Parsing failed\n");
        return 1;
    }
}

