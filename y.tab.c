
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
#include "Node.h"
#include "symboltable.h"
#include "symbolentry.h"
#include "quad.h"


extern int yylineno;
int yylex(void);
int yyerror(char *s);
//read from text file
extern FILE *yyin;
//symbol table
SymbolTable *globalTable;
SymbolTable *currTable;
SymbolTable *tempTable;

int scope = 0;
// extern int yylineno;
//symbol entry
int tempCount = 0;


/* Line 189 of yacc.c  */
#line 101 "y.tab.c"

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
     BOOLEAN = 264,
     INTEGER = 265,
     DOUBLE = 266,
     CHAR = 267,
     STRING = 268,
     BOOL = 269,
     IDENTIFIER = 270,
     SEMICOLON = 271,
     CONST = 272,
     INC = 273,
     DEC = 274,
     COMMA = 275,
     LT = 276,
     GT = 277,
     LTE = 278,
     GTE = 279,
     EQ = 280,
     NEQ = 281,
     EQU = 282,
     ADD_EQ = 283,
     SUB_EQ = 284,
     MULT_EQ = 285,
     DIV_EQ = 286,
     PLUS = 287,
     MINUS = 288,
     MULT = 289,
     DIV = 290,
     LEFT_ROUND = 291,
     RIGHT_ROUND = 292,
     LEFT_CURLY = 293,
     RIGHT_CURLY = 294,
     IF = 295,
     ELSE = 296,
     FOR = 297,
     WHILE = 298,
     DO = 299,
     SWITCH = 300,
     CASE = 301,
     AND = 302,
     OR = 303,
     NOT = 304,
     UNKNOWN = 305,
     COLON = 306,
     BREAK = 307,
     DEFAULT = 308,
     LOWER_THAN_ELSE = 309
   };
#endif
/* Tokens.  */
#define INT_TYPE 258
#define DOUBLE_TYPE 259
#define CHAR_TYPE 260
#define BOOL_TYPE 261
#define STRING_TYPE 262
#define VOID 263
#define BOOLEAN 264
#define INTEGER 265
#define DOUBLE 266
#define CHAR 267
#define STRING 268
#define BOOL 269
#define IDENTIFIER 270
#define SEMICOLON 271
#define CONST 272
#define INC 273
#define DEC 274
#define COMMA 275
#define LT 276
#define GT 277
#define LTE 278
#define GTE 279
#define EQ 280
#define NEQ 281
#define EQU 282
#define ADD_EQ 283
#define SUB_EQ 284
#define MULT_EQ 285
#define DIV_EQ 286
#define PLUS 287
#define MINUS 288
#define MULT 289
#define DIV 290
#define LEFT_ROUND 291
#define RIGHT_ROUND 292
#define LEFT_CURLY 293
#define RIGHT_CURLY 294
#define IF 295
#define ELSE 296
#define FOR 297
#define WHILE 298
#define DO 299
#define SWITCH 300
#define CASE 301
#define AND 302
#define OR 303
#define NOT 304
#define UNKNOWN 305
#define COLON 306
#define BREAK 307
#define DEFAULT 308
#define LOWER_THAN_ELSE 309




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 28 "parser.y"

    Node* node;
    int ival;    // Integer values
    double dVal; // Double values
    char *sval;  // String values (if needed)
    bool bVal;
    char* op;
    char * cval;
    char*semi;
    enum DataType dataType;



/* Line 214 of yacc.c  */
#line 259 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 271 "y.tab.c"

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
#define YYLAST   406

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  176

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
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
     229,   234,   236,   238,   240,   242,   244,   246,   250,   254,
     258,   262,   266,   268,   270,   272,   274,   276,   278,   280,
     283,   286,   289,   292,   294,   296,   298,   300,   302
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    57,    58,    -1,    -1,    58,    59,    -1,
      59,    -1,    63,    -1,    60,    -1,    61,    58,    62,    -1,
      38,    -1,    39,    -1,    78,    -1,    67,    -1,    77,    -1,
      74,    -1,    72,    -1,    71,    -1,    70,    -1,    79,    16,
      -1,    64,    -1,    45,    36,    80,    37,    61,    65,    62,
      -1,    66,    -1,    65,    66,    -1,    46,    80,    51,    58,
      52,    16,    -1,    46,    80,    51,    52,    16,    -1,    53,
      51,    58,    52,    16,    -1,    53,    51,    52,    16,    -1,
      81,    15,    36,    37,    59,    -1,    81,    15,    36,    37,
      16,    -1,    81,    15,    36,    68,    37,    59,    -1,    81,
      15,    36,    68,    37,    16,    -1,    81,    15,    -1,    68,
      20,    81,    15,    -1,    80,    -1,    69,    20,    80,    -1,
      44,    59,    43,    36,    76,    37,    16,    -1,    43,    36,
      76,    37,    59,    -1,    42,    36,    78,    76,    16,    73,
      37,    59,    -1,    84,    -1,    82,    -1,    40,    36,    75,
      37,    59,    -1,    40,    36,    75,    37,    59,    41,    59,
      -1,    76,    -1,    76,    47,    75,    -1,    76,    48,    75,
      -1,    49,    76,    -1,    80,    -1,    80,    21,    80,    -1,
      80,    22,    80,    -1,    80,    23,    80,    -1,    80,    24,
      80,    -1,    80,    25,    80,    -1,    80,    26,    80,    -1,
      14,    -1,    17,    81,    15,    27,    80,    16,    -1,    82,
      16,    -1,    81,    15,    16,    -1,    81,    15,    27,    80,
      16,    -1,    84,    16,    -1,    15,    36,    37,    -1,    15,
      36,    69,    37,    -1,    10,    -1,    11,    -1,    12,    -1,
      13,    -1,    15,    -1,     9,    -1,    80,    32,    80,    -1,
      80,    33,    80,    -1,    80,    34,    80,    -1,    80,    35,
      80,    -1,    36,    80,    37,    -1,    79,    -1,     3,    -1,
       4,    -1,     6,    -1,     5,    -1,     7,    -1,     8,    -1,
      15,    18,    -1,    15,    19,    -1,    18,    15,    -1,    19,
      15,    -1,    27,    -1,    28,    -1,    29,    -1,    30,    -1,
      31,    -1,    15,    83,    80,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    81,    81,    83,    91,    92,    96,    97,   101,   104,
     112,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     136,   139,   140,   143,   144,   145,   146,   150,   151,   152,
     153,   156,   157,   160,   161,   165,   168,   171,   175,   176,
     179,   180,   184,   185,   186,   187,   191,   192,   193,   194,
     195,   196,   197,   198,   202,   207,   208,   219,   254,   258,
     259,   263,   268,   273,   278,   283,   296,   306,   330,   356,
     383,   409,   410,   415,   418,   421,   424,   427,   430,   436,
     461,   486,   510,   538,   541,   544,   547,   550,   556
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_TYPE", "DOUBLE_TYPE", "CHAR_TYPE",
  "BOOL_TYPE", "STRING_TYPE", "VOID", "BOOLEAN", "INTEGER", "DOUBLE",
  "CHAR", "STRING", "BOOL", "IDENTIFIER", "SEMICOLON", "CONST", "INC",
  "DEC", "COMMA", "LT", "GT", "LTE", "GTE", "EQ", "NEQ", "EQU", "ADD_EQ",
  "SUB_EQ", "MULT_EQ", "DIV_EQ", "PLUS", "MINUS", "MULT", "DIV",
  "LEFT_ROUND", "RIGHT_ROUND", "LEFT_CURLY", "RIGHT_CURLY", "IF", "ELSE",
  "FOR", "WHILE", "DO", "SWITCH", "CASE", "AND", "OR", "NOT", "UNKNOWN",
  "COLON", "BREAK", "DEFAULT", "LOWER_THAN_ELSE", "$accept", "program",
  "start", "statements", "statement", "scoped_statement", "start_scope",
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
     305,   306,   307,   308,   309
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    58,    58,    59,    59,    60,    61,
      62,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      64,    65,    65,    66,    66,    66,    66,    67,    67,    67,
      67,    68,    68,    69,    69,    70,    71,    72,    73,    73,
      74,    74,    75,    75,    75,    75,    76,    76,    76,    76,
      76,    76,    76,    76,    77,    77,    77,    78,    78,    79,
      79,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    81,    81,    81,    81,    81,    81,    82,
      82,    82,    82,    83,    83,    83,    83,    83,    84
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
       4,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,    73,    74,    76,    75,    77,    78,
       0,     0,     0,     0,     9,     0,     0,     0,     0,     0,
       2,     5,     7,     0,     6,    19,    12,    17,    16,    15,
      14,    13,    11,     0,     0,     0,     0,    79,    80,    83,
      84,    85,    86,    87,     0,     0,     0,    81,    82,     0,
       0,     0,     0,     0,     4,     0,    18,     0,    55,    58,
      66,    61,    62,    63,    64,    65,     0,    59,     0,    72,
      33,    88,     0,    53,     0,     0,    42,    46,     0,     0,
       0,     0,     0,     0,    10,     8,    56,     0,     0,     0,
       0,    60,     0,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,    34,    67,    68,
      69,    70,     0,    40,    43,    44,    47,    48,    49,    50,
      51,    52,     0,    36,     0,     0,    57,    28,    27,     0,
       0,    31,    54,     0,     0,     0,    39,    38,     0,     0,
       0,     0,    21,     0,    30,    29,    41,     0,    35,     0,
       0,    20,    22,    32,    37,     0,     0,     0,     0,     0,
      26,     0,    24,     0,    25,    23
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    20,    21,    22,    23,    85,    24,    25,
     151,   152,    26,   114,    68,    27,    28,    29,   145,    30,
      75,    76,    31,    32,    69,    77,    34,    35,    45,    36
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -40
static const yytype_int16 yypact[] =
{
     -40,     1,   322,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     350,   268,    -9,     4,   -40,     6,    16,    19,   322,    25,
     322,   -40,   -40,   322,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,    47,    49,    58,    66,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   159,    35,    73,   -40,   -40,    13,
     368,   282,    52,    35,   -40,   245,   -40,    57,   -40,   -40,
     -40,   -40,   -40,   -40,   -40,    56,    35,   -40,    -8,   -40,
     223,   223,    70,   -40,   282,    68,   -37,   366,    92,   282,
      91,    71,    90,   144,   -40,   -40,   -40,    35,    96,   201,
      35,   -40,    35,    35,    35,    35,    35,   -40,   322,    13,
      13,    35,    35,    35,    35,    35,    35,    93,   100,   322,
     282,   105,    -1,   262,     0,   114,   -40,   223,   -40,   -40,
     -40,   -40,   102,    89,   -40,   -40,   223,   223,   223,   223,
     223,   223,    20,   -40,    94,   -39,   -40,   -40,   -40,   268,
     305,   -40,   -40,   322,   375,   103,   -40,   -40,   135,    35,
     111,   317,   -40,   138,   -40,   -40,   -40,   322,   -40,   180,
      72,   -40,   -40,   -40,   -40,   142,   140,   185,   148,   202,
     -40,   150,   -40,   157,   -40,   -40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -40,   -40,   -40,   -21,   -15,   -40,    64,    32,   -40,   -40,
     -40,    46,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -14,   -38,   -40,   149,    -2,   -36,    -7,    69,   -40,    79
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      33,     3,    55,    52,    46,    54,    47,   149,    70,    71,
      99,   100,    90,    81,   150,   136,    33,    83,    33,    48,
     139,    33,    60,    61,    62,    63,    64,    73,    65,    91,
      89,    92,    93,    94,    95,   144,    97,   140,    12,    13,
      54,   107,    49,    80,    60,    61,    62,    63,    64,    66,
      65,   112,    50,    33,   117,    51,   118,   119,   120,   121,
     122,    53,    74,    56,    57,   126,   127,   128,   129,   130,
     131,    66,   134,    86,    58,     4,     5,     6,     7,     8,
       9,   115,    59,   123,    87,   124,   125,    10,    72,    11,
      12,    13,    44,    88,   133,    82,    33,    96,   138,     4,
       5,     6,     7,     8,     9,    98,   108,    33,   109,   132,
      14,    33,    15,   159,    16,    17,    18,    19,   142,    39,
      40,    41,    42,    43,   166,   155,   110,    87,   156,   141,
     143,   148,   153,   113,    92,    93,    94,    95,    33,   167,
     157,    33,   164,    14,   169,     4,     5,     6,     7,     8,
       9,   158,    54,   163,    54,    33,   170,    10,    33,    11,
      12,    13,   160,    33,   172,    33,   174,    33,    60,    61,
      62,    63,    64,   175,    65,   135,    92,    93,    94,    95,
      14,   111,    15,   161,    16,    17,    18,    19,     4,     5,
       6,     7,     8,     9,   168,    66,    67,   162,     0,    79,
      10,   146,    11,    12,    13,     4,     5,     6,     7,     8,
       9,   147,    92,    93,    94,    95,     0,    10,     0,    11,
      12,    13,     0,    14,     0,    15,     0,    16,    17,    18,
      19,   165,     0,    92,    93,    94,    95,   171,   116,     0,
      14,     0,    15,     0,    16,    17,    18,    19,     4,     5,
       6,     7,     8,     9,   173,    92,    93,    94,    95,     0,
      10,     0,    11,    12,    13,     4,     5,     6,     7,     8,
       9,     4,     5,     6,     7,     8,     9,    10,   137,    11,
      12,    13,     0,    14,    84,    15,     0,    16,    17,    18,
      19,    60,    61,    62,    63,    64,    73,    65,     0,     0,
      14,     0,    15,     0,    16,    17,    18,    19,     4,     5,
       6,     7,     8,     9,     0,     0,     0,     0,    66,     0,
      10,   154,    11,    12,    13,     4,     5,     6,     7,     8,
       9,     0,     0,     0,     0,     0,     0,    10,     0,    11,
      12,    13,     0,    14,     0,    15,     0,    16,    17,    18,
      19,     0,     0,     0,     0,     0,    84,     0,     0,     0,
      14,     0,    15,   149,    16,    17,    18,    19,    37,    38,
     150,     4,     5,     6,     7,     8,     9,    39,    40,    41,
      42,    43,     0,    78,     0,     0,    44,   101,   102,   103,
     104,   105,   106,    37,    38,     0,     0,     0,    92,    93,
      94,    95,    39,    40,    41,    42,    43
};

static const yytype_int16 yycheck[] =
{
       2,     0,    23,    18,    11,    20,    15,    46,    44,    45,
      47,    48,    20,    51,    53,    16,    18,    53,    20,    15,
      20,    23,     9,    10,    11,    12,    13,    14,    15,    37,
      66,    32,    33,    34,    35,    15,    74,    37,    18,    19,
      55,    79,    36,    50,     9,    10,    11,    12,    13,    36,
      15,    87,    36,    55,    90,    36,    92,    93,    94,    95,
      96,    36,    49,    16,    15,   101,   102,   103,   104,   105,
     106,    36,   110,    16,    16,     3,     4,     5,     6,     7,
       8,    88,    16,    98,    27,    99,   100,    15,    15,    17,
      18,    19,    36,    36,   109,    43,    98,    27,   113,     3,
       4,     5,     6,     7,     8,    37,    15,   109,    37,    16,
      38,   113,    40,   149,    42,    43,    44,    45,    16,    27,
      28,    29,    30,    31,    52,   140,    36,    27,   143,    15,
      41,    37,   139,    37,    32,    33,    34,    35,   140,   160,
      37,   143,   157,    38,   165,     3,     4,     5,     6,     7,
       8,    16,   167,    15,   169,   157,    16,    15,   160,    17,
      18,    19,    51,   165,    16,   167,    16,   169,     9,    10,
      11,    12,    13,    16,    15,   111,    32,    33,    34,    35,
      38,    37,    40,   151,    42,    43,    44,    45,     3,     4,
       5,     6,     7,     8,    52,    36,    37,   151,    -1,    50,
      15,   132,    17,    18,    19,     3,     4,     5,     6,     7,
       8,   132,    32,    33,    34,    35,    -1,    15,    -1,    17,
      18,    19,    -1,    38,    -1,    40,    -1,    42,    43,    44,
      45,    51,    -1,    32,    33,    34,    35,    52,    37,    -1,
      38,    -1,    40,    -1,    42,    43,    44,    45,     3,     4,
       5,     6,     7,     8,    52,    32,    33,    34,    35,    -1,
      15,    -1,    17,    18,    19,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,    15,    16,    17,
      18,    19,    -1,    38,    39,    40,    -1,    42,    43,    44,
      45,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      38,    -1,    40,    -1,    42,    43,    44,    45,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    36,    -1,
      15,    16,    17,    18,    19,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,
      18,    19,    -1,    38,    -1,    40,    -1,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      38,    -1,    40,    46,    42,    43,    44,    45,    18,    19,
      53,     3,     4,     5,     6,     7,     8,    27,    28,    29,
      30,    31,    -1,    15,    -1,    -1,    36,    21,    22,    23,
      24,    25,    26,    18,    19,    -1,    -1,    -1,    32,    33,
      34,    35,    27,    28,    29,    30,    31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    56,    57,     0,     3,     4,     5,     6,     7,     8,
      15,    17,    18,    19,    38,    40,    42,    43,    44,    45,
      58,    59,    60,    61,    63,    64,    67,    70,    71,    72,
      74,    77,    78,    79,    81,    82,    84,    18,    19,    27,
      28,    29,    30,    31,    36,    83,    81,    15,    15,    36,
      36,    36,    59,    36,    59,    58,    16,    15,    16,    16,
       9,    10,    11,    12,    13,    15,    36,    37,    69,    79,
      80,    80,    15,    14,    49,    75,    76,    80,    15,    78,
      81,    76,    43,    80,    39,    62,    16,    27,    36,    80,
      20,    37,    32,    33,    34,    35,    27,    76,    37,    47,
      48,    21,    22,    23,    24,    25,    26,    76,    15,    37,
      36,    37,    80,    37,    68,    81,    37,    80,    80,    80,
      80,    80,    80,    59,    75,    75,    80,    80,    80,    80,
      80,    80,    16,    59,    76,    61,    16,    16,    59,    20,
      37,    15,    16,    41,    15,    73,    82,    84,    37,    46,
      53,    65,    66,    81,    16,    59,    59,    37,    16,    80,
      51,    62,    66,    15,    59,    51,    52,    58,    52,    58,
      16,    52,    16,    52,    16,    16
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
#line 83 "parser.y"
    {
        printf("Start\n");
               globalTable = createSymbolTable("global",scope, NULL);
                                    currTable = globalTable;

        }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    {printf("Start Scope\n");
        scope++;
        tempTable = createSymbolTable("local",scope, currTable);
        addChildToTable(currTable, tempTable);
        currTable = tempTable;
        }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 112 "parser.y"
    {printf("End Scope\n");
        scope--;
        currTable = currTable->parent;
        }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    {printf("defualt Declaration\n");}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    {printf("func_statment \n");}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    {printf("special Declaration\n");}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    {printf("Conditional Statement\n");}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 127 "parser.y"
    {printf("For Statement\n");}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    {printf("While Statement\n");}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    {printf("Do While Statement\n");}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    {printf("Function Call with semi colonnnn\n");}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    {printf("Switch Statement\n");}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    {printf("Switch Statement\n");}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    {printf("Function Statement no params\n");}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 151 "parser.y"
    {printf("Function Statement no params\n");}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    {printf("Function Statement\n");}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    {printf("Function Statement\n");}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    {printf("COMAAAA\n");}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    {printf("Do While Statement\n");}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    {printf("While Statement\n");}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    {printf("For Statement\n");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    {printf("If Statement\n");}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 180 "parser.y"
    {printf("If Else Statement\n");}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 184 "parser.y"
    {printf("Conditional Expression\n");}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 192 "parser.y"
    {printf("Less Than\n");}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 193 "parser.y"
    {printf("Greater Than\n");}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 202 "parser.y"
    {    
                SymbolEntry *entry=createSymbolEntry((yyvsp[(3) - (6)].sval), constant, (yyvsp[(5) - (6)].node)->value,true,0,(yyvsp[(2) - (6)].dataType), 1, 0, NULL, "");
                addEntryToTable(currTable, entry);

        }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 208 "parser.y"
    {printf("Data Type Identifier\n");
        Node *node= createIDNode((yyvsp[(2) - (3)].sval), scope,(yyvsp[(1) - (3)].dataType));

        SymbolEntry* entry= createSymbolEntryWithDefaults((yyvsp[(2) - (3)].sval), var,node->value,false,0,(yyvsp[(1) - (3)].dataType));
        addEntryToTable(currTable, entry);
        
        
        }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    {  
                printf("Default Declaration \n" );
                printf("Data Type: %d data type el tanyyy %d\n", (yyvsp[(1) - (5)].dataType) , (yyvsp[(4) - (5)].node)->dataType); 
                if((yyvsp[(1) - (5)].dataType) == (yyvsp[(4) - (5)].node)->dataType){
                        if ((yyvsp[(1) - (5)].dataType) == TYPE_INT){
                                insertQuad((yyvsp[(4) - (5)].node)->name , NULL , "=" , (yyvsp[(2) - (5)].sval) , 0);
                                SymbolEntry* entry= createSymbolEntryWithDefaults((yyvsp[(2) - (5)].sval), var, (yyvsp[(4) - (5)].node)->value,true,0, (yyvsp[(1) - (5)].dataType));
                                addEntryToTable(currTable, entry);
                        }
                        else if ((yyvsp[(1) - (5)].dataType) == TYPE_DOUBLE){
                                SymbolEntry* entry= createSymbolEntryWithDefaults((yyvsp[(2) - (5)].sval), var, (yyvsp[(4) - (5)].node)->value,true,0, (yyvsp[(1) - (5)].dataType));
                                addEntryToTable(currTable, entry);
                        }
                        else if ((yyvsp[(1) - (5)].dataType) == TYPE_BOOL){
                                printf("Bool ana geet\n");
                                SymbolEntry* entry= createSymbolEntryWithDefaults((yyvsp[(2) - (5)].sval), var, (yyvsp[(4) - (5)].node)->value,true,0, (yyvsp[(1) - (5)].dataType));
                                addEntryToTable(currTable, entry);
                        }
                        else if ((yyvsp[(1) - (5)].dataType) == TYPE_CHAR){
                                SymbolEntry* entry= createSymbolEntryWithDefaults((yyvsp[(2) - (5)].sval), var, (yyvsp[(4) - (5)].node)->value,true,0, (yyvsp[(1) - (5)].dataType));
                                addEntryToTable(currTable, entry);
                        }
                        else if ((yyvsp[(1) - (5)].dataType) == TYPE_STRING){
                                SymbolEntry* entry= createSymbolEntryWithDefaults((yyvsp[(2) - (5)].sval), var, (yyvsp[(4) - (5)].node)->value,true,0, (yyvsp[(1) - (5)].dataType));
                                addEntryToTable(currTable, entry);
                        }

                    
                }
                else{
                        printf("Error: Data Type Mismatch\n");
                }

            
            }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 254 "parser.y"
    {printf("Assign Expression\n");}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 263 "parser.y"
    {
                        Node *node= createIntNode((yyvsp[(1) - (1)].ival) , scope , tempCount , true);
                        (yyval.node) = node; 
                        printf("Integer: %d\n", (yyvsp[(1) - (1)].ival));
                }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 268 "parser.y"
    { 
                                Node *node= createDoubleNode((yyvsp[(1) - (1)].dVal), scope , tempCount , true);
                                (yyval.node) = node;
                                printf("Double: %f\n", (yyvsp[(1) - (1)].dVal));
                        }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 273 "parser.y"
    { 
                                Node *node= createCharNode((yyvsp[(1) - (1)].cval), scope , tempCount , true);
                                (yyval.node) = node;
                                printf("Char: %c\n", (yyvsp[(1) - (1)].cval));
                        }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 278 "parser.y"
    { 
                                Node *node= createStringNode((yyvsp[(1) - (1)].sval), scope, tempCount , true);
                                (yyval.node) = node;
                                printf("String: %s\n", (yyvsp[(1) - (1)].sval));
                        }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 283 "parser.y"
    {
        SymbolEntry *entry = getentryfromalltables(currTable, (yyvsp[(1) - (1)].sval));
        printf("Identifier:%s intialized %d \n", (yyvsp[(1) - (1)].sval) , entry->isInitialized ? 1 : 0);
        if(entry != NULL && entry->isInitialized){
                Node* node = createIDNode((yyvsp[(1) - (1)].sval), scope, entry->type);
                node->value = entry->value;
                (yyval.node) = node;
        }
        else{
                printf("Error: Variable not declared or intialized\n");
        }
        
        }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 296 "parser.y"
    {

     
                        Node *node= createBoolNode((yyvsp[(1) - (1)].bVal), scope);
                        (yyval.node) = node;
                

}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 306 "parser.y"
    {
        if ((yyvsp[(1) - (3)].node)->dataType == (yyvsp[(3) - (3)].node)->dataType){
                if ((yyvsp[(1) - (3)].node)->dataType == TYPE_INT){
                        tempCount++;
                        Node *node= createIntNode((yyvsp[(1) - (3)].node)->value.iVal+ (yyvsp[(3) - (3)].node)->value.iVal, scope , tempCount , false);
                        insertQuad((yyvsp[(1) - (3)].node)->name , (yyvsp[(3) - (3)].node)->name , "+" , node->name , 0);
                        (yyval.node) = node;
                }
                else if ((yyvsp[(1) - (3)].node)->dataType == TYPE_DOUBLE){
                        tempCount++;
                        Node *node= createDoubleNode((yyvsp[(1) - (3)].node)->value.dVal+ (yyvsp[(3) - (3)].node)->value.dVal, scope , tempCount , false);
                        insertQuad((yyvsp[(1) - (3)].node)->name , (yyvsp[(3) - (3)].node)->name , "+" , node->name , 0);
                        (yyval.node) = node;
                }
                else{
                        printf("Error: ERROORR");
                }
        }
        else{
                printf("Error: Data Type Mismatch\n");
        }

     
          }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 330 "parser.y"
    { 
        if((yyvsp[(1) - (3)].node)->dataType == (yyvsp[(3) - (3)].node)->dataType)
        {
                if((yyvsp[(1) - (3)].node)->dataType == TYPE_INT)
                {
                        tempCount++;
                        Node *node= createIntNode((yyvsp[(1) - (3)].node)->value.iVal- (yyvsp[(3) - (3)].node)->value.iVal, scope , tempCount , false);
                        insertQuad((yyvsp[(1) - (3)].node)->name , (yyvsp[(3) - (3)].node)->name , "-" , node->name , 0);
                        (yyval.node) = node;
                }
                else if((yyvsp[(1) - (3)].node)->dataType == TYPE_DOUBLE)
                {
                        tempCount++;
                        Node *node= createDoubleNode((yyvsp[(1) - (3)].node)->value.dVal- (yyvsp[(3) - (3)].node)->value.dVal, scope , tempCount , false);
                        insertQuad((yyvsp[(1) - (3)].node)->name , (yyvsp[(3) - (3)].node)->name , "-" , node->name , 0);
                        (yyval.node) = node;
                }
                else {
                        printf("Error: ERROORR");
                }
        }
        else
        {
                printf("Error: Data Type Mismatch\n");
        }
   }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 356 "parser.y"
    {     
        if((yyvsp[(1) - (3)].node)->dataType == (yyvsp[(3) - (3)].node)->dataType)
        {
                if((yyvsp[(1) - (3)].node)->dataType == TYPE_INT)
                {
                        tempCount++;
                        Node *node= createIntNode((yyvsp[(1) - (3)].node)->value.iVal* (yyvsp[(3) - (3)].node)->value.iVal, scope , tempCount , false);
                        insertQuad((yyvsp[(1) - (3)].node)->name , (yyvsp[(3) - (3)].node)->name , "*" , node->name , 0);
                        (yyval.node) = node;
                }
                else if((yyvsp[(1) - (3)].node)->dataType == TYPE_DOUBLE)
                {
                        tempCount++;
                        Node *node= createDoubleNode((yyvsp[(1) - (3)].node)->value.dVal* (yyvsp[(3) - (3)].node)->value.dVal, scope , tempCount , false);
                        insertQuad((yyvsp[(1) - (3)].node)->name , (yyvsp[(3) - (3)].node)->name , "*" , node->name , 0);
                        (yyval.node) = node;
                }
                else {
                        printf("Error: ERROORR");
                }
        }
        else
        {
                printf("Error: Data Type Mismatch\n");
        }

 }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 383 "parser.y"
    { 
        if((yyvsp[(1) - (3)].node)->dataType == (yyvsp[(3) - (3)].node)->dataType )
        {
                if((yyvsp[(1) - (3)].node)->dataType == TYPE_INT && (yyvsp[(3) - (3)].node)->value.iVal != 0)
                {
                        tempCount++;
                        Node *node= createIntNode((yyvsp[(1) - (3)].node)->value.iVal/ (yyvsp[(3) - (3)].node)->value.iVal, scope, tempCount , false);
                        insertQuad((yyvsp[(1) - (3)].node)->name , (yyvsp[(3) - (3)].node)->name , "/" , node->name , 0);
                        (yyval.node) = node;
                }
                else if((yyvsp[(1) - (3)].node)->dataType == TYPE_DOUBLE && (yyvsp[(3) - (3)].node)->value.dVal != 0)
                {
                        tempCount++;
                        Node *node= createDoubleNode((yyvsp[(1) - (3)].node)->value.dVal/ (yyvsp[(3) - (3)].node)->value.dVal, scope , tempCount , false);
                        insertQuad((yyvsp[(1) - (3)].node)->name , (yyvsp[(3) - (3)].node)->name , "/" , node->name , 0);
                        (yyval.node) = node;
                }
                else {
                        printf("Error: ERROORR");
                }
        }
        else
        {
                printf("Error: Data Type Mismatch\n");
        }
        }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 409 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 410 "parser.y"
    {printf("Function Call\n");}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 415 "parser.y"
    {printf("Int Type\n");
        (yyval.dataType) = TYPE_INT;
        }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 418 "parser.y"
    {printf("Double Type\n");
        (yyval.dataType) = TYPE_DOUBLE;
        }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 421 "parser.y"
    {printf("Bool Type \n");
        (yyval.dataType) = TYPE_BOOL;
        }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 424 "parser.y"
    {printf("Char Type\n");
        (yyval.dataType) = TYPE_CHAR;
        }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 427 "parser.y"
    {printf("String Type\n");
        (yyval.dataType) = TYPE_STRING;
        }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 430 "parser.y"
    {printf("Void Type\n");
        (yyval.dataType) = TYPE_VOID;
        }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 436 "parser.y"
    {
                int flag = 1;
                SymbolEntry *entry = getentryfromalltables(currTable, (yyvsp[(1) - (2)].sval));
                if(entry != NULL && entry->isInitialized && entry->kind != constant){
                        if (entry->type == TYPE_INT){
                                entry->value.iVal++;
                                
                        }
                        else if (entry->type == TYPE_DOUBLE){
                                entry->value.dVal++;
                        }
                        else {
                                flag = 0;
                                printf("Error: Data Type Mismatch\n");
                        }
                        if(flag){
                                SymbolEntry *newEntry = createSymbolEntryWithDefaults(entry->name, entry->kind, entry->value,true, 0, entry->type);
                                modifyentry(currTable, entry->name , newEntry);
                                insertQuad(NULL, NULL , "++" , (yyvsp[(1) - (2)].sval) , 0);
                        }
                }
                else {
                        printf("Error: Variable not declared and constanttttt\n");
                }
        }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 461 "parser.y"
    {
                int flag = 1;
                SymbolEntry *entry = getentryfromalltables(currTable, (yyvsp[(1) - (2)].sval));
                if(entry != NULL && entry->isInitialized && entry->kind != constant){
                        if (entry->type == TYPE_INT){
                                entry->value.iVal--;
                        }
                        else if (entry->type == TYPE_DOUBLE){
                                entry->value.dVal--;
                        }
                        else {
                                printf("Error: Data Type Mismatch\n");
                                flag = 0;
                        }
                        if(flag){
                                SymbolEntry *newEntry = createSymbolEntryWithDefaults(entry->name, entry->kind, entry->value,true, 0, entry->type);
                                modifyentry(currTable, entry->name , newEntry);
                                insertQuad(NULL, NULL , "--" , (yyvsp[(1) - (2)].sval) , 0);        
                        }

                }
                else {
                        printf("Error: Variable not declared\n");
                }
        }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 486 "parser.y"
    {
                int flag = 1;
                SymbolEntry *entry = getentryfromalltables(currTable, (yyvsp[(2) - (2)].sval));
                if(entry != NULL && entry->isInitialized && entry->kind != constant){
                        if (entry->type == TYPE_INT){
                                entry->value.iVal++;
                        }
                        else if (entry->type == TYPE_DOUBLE){
                                entry->value.dVal++;
                        }
                        else {
                                printf("Error: Data Type Mismatch\n");
                                flag = 0;
                        }
                        if(flag){
                                SymbolEntry *newEntry = createSymbolEntryWithDefaults(entry->name, entry->kind, entry->value,true, 0, entry->type);
                                modifyentry(currTable, entry->name , newEntry);
                                insertQuad(NULL, NULL , "++" , (yyvsp[(2) - (2)].sval) , 0);
                        }
                }
                else {
                        printf("Error: Variable not declared\n");
                }
        }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 510 "parser.y"
    {
                int flag = 1;
                SymbolEntry *entry = getentryfromalltables(currTable, (yyvsp[(2) - (2)].sval));
                if(entry != NULL && entry->isInitialized && entry->kind != constant){
                        if (entry->type == TYPE_INT){
                                entry->value.iVal--;
                        }
                        else if (entry->type == TYPE_DOUBLE){
                                entry->value.dVal--;
                        }
                        else {
                                printf("Error: Data Type Mismatch\n");
                                flag = 0;
                        }
                        if(flag){
                                SymbolEntry *newEntry = createSymbolEntryWithDefaults(entry->name, entry->kind, entry->value, true ,0, entry->type);
                                modifyentry(currTable, entry->name , newEntry);
                                insertQuad(NULL, NULL , "--" , (yyvsp[(2) - (2)].sval) , 0);
                        }
                        
                }
                else {
                        printf("Error: Variable not declared\n");
                }
        }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 538 "parser.y"
    {  
                        (yyval.sval) = "=";       
                }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 541 "parser.y"
    {
                        (yyval.sval) = "+=";
                        }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 544 "parser.y"
    {
                (yyval.sval) = "-=";
        }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 547 "parser.y"
    {
                (yyval.sval) = "*=";
        }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 550 "parser.y"
    {
                (yyval.sval) = "/=";
        }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 556 "parser.y"
    {
                SymbolEntry *entry = getentryfromalltables(currTable, (yyvsp[(1) - (3)].sval));
                if(entry != NULL && entry->kind != constant){
                        if (entry->type == (yyvsp[(3) - (3)].node)->dataType)
                        {
                                if((yyvsp[(2) - (3)].sval) == "="){
                                        if (entry->type == TYPE_INT){
                                                entry->value.iVal = (yyvsp[(3) - (3)].node)->value.iVal;
                                        }
                                        else if (entry->type == TYPE_DOUBLE){
                                                entry->value.dVal = (yyvsp[(3) - (3)].node)->value.dVal;
                                        }
                                        else if (entry->type == TYPE_BOOL){
                                                entry->value.bVal = (yyvsp[(3) - (3)].node)->value.bVal;
                                        }
                                        else if (entry->type == TYPE_CHAR){
                                                entry->value.cVal = (yyvsp[(3) - (3)].node)->value.cVal;
                                        }
                                        else if (entry->type == TYPE_STRING){
                                                entry->value.strVal = (yyvsp[(3) - (3)].node)->value.strVal;
                                        }
                                        insertQuad((yyvsp[(3) - (3)].node)->name , NULL , "=" , (yyvsp[(1) - (3)].sval) , 0);
                               
                                }           
                                else if((yyvsp[(2) - (3)].sval) == "+=" && entry->isInitialized){
                                        if (entry->type == TYPE_INT){
                                                entry->value.iVal += (yyvsp[(3) - (3)].node)->value.iVal;
                                        }
                                        else if (entry->type == TYPE_DOUBLE){
                                                entry->value.dVal += (yyvsp[(3) - (3)].node)->value.dVal;
                                        }
                                        else {
                                                printf("Error: Data Type Mismatch\n");
                                        }
                                        insertQuad((yyvsp[(1) - (3)].sval),(yyvsp[(3) - (3)].node)->name  , "+" , (yyvsp[(1) - (3)].sval) , 0);
                               
                                }
                                else if((yyvsp[(2) - (3)].sval) == "-=" && entry->isInitialized){
                                        if (entry->type == TYPE_INT){
                                                entry->value.iVal -= (yyvsp[(3) - (3)].node)->value.iVal;
                                        }
                                        else if (entry->type == TYPE_DOUBLE){
                                                entry->value.dVal -= (yyvsp[(3) - (3)].node)->value.dVal;
                                        }
                                        else {
                                                printf("Error: Data Type Mismatch\n");
                                        }
                                        insertQuad( (yyvsp[(1) - (3)].sval) ,(yyvsp[(3) - (3)].node)->name  , "-" , (yyvsp[(1) - (3)].sval) , 0);
                                
                                }
                                else if((yyvsp[(2) - (3)].sval) == "*=" && entry->isInitialized){
                                        if (entry->type == TYPE_INT){
                                                entry->value.iVal *= (yyvsp[(3) - (3)].node)->value.iVal;
                                        }
                                        else if (entry->type == TYPE_DOUBLE){
                                                entry->value.dVal *= (yyvsp[(3) - (3)].node)->value.dVal;
                                        }
                                        else {
                                                printf("Error: Data Type Mismatch\n");
                                        }
                                        insertQuad((yyvsp[(1) - (3)].sval) , (yyvsp[(3) - (3)].node)->name  , "*" , (yyvsp[(1) - (3)].sval) , 0);
                                
                                }
                                else if((yyvsp[(2) - (3)].sval) == "/=" && entry->isInitialized){
                                        if (entry->type == TYPE_INT){
                                                entry->value.iVal /= (yyvsp[(3) - (3)].node)->value.iVal;
                                        }
                                        else if (entry->type == TYPE_DOUBLE){
                                                entry->value.dVal /= (yyvsp[(3) - (3)].node)->value.dVal;
                                        }
                                        else {
                                                printf("Error: Data Type Mismatch\n");
                                        }
                                        insertQuad((yyvsp[(1) - (3)].sval) , (yyvsp[(3) - (3)].node)->name  , "/" , (yyvsp[(1) - (3)].sval) , 0);

                                
                                }
                                else {
                                        printf("Error: Variable not declared\n");
                                }
                                SymbolEntry *newEntry = createSymbolEntryWithDefaults(entry->name, entry->kind, entry->value,true, 0, entry->type);
                                modifyentry(currTable, entry->name , newEntry);
                        }
                        else{
                                printf("Error: Data Type Mismatch\n");
                        }
                }
                else {
                        printf("Error: Variable not declared ezay geet hena\n");
                }
                }
    break;



/* Line 1455 of yacc.c  */
#line 2473 "y.tab.c"
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
#line 649 "parser.y"

int yyerror(char *s) {
    fprintf(stderr, "Error:  %s %d\n", s , yylineno- 1);
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
        printQuadrables();
        return 0;
    } else {
        printf("Parsing failed\n");
        return 1;
    }
}

