
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
#include "stack.h"


extern int yylineno;
int yylex(void);
int yyerror(char *s);
//read from text file
extern FILE *yyin;
//symbol table
SymbolTable *globalTable;
SymbolTable *currTable;
SymbolTable *tempTable;


Stack ifStack;
Stack whileStack;
Stack do_whileStack;
Stack forStack;
Stack switchStack;
Node **params;
void initialize() {
        initializeStack(&ifStack);
        initializeStack(&whileStack);
        initializeStack(&do_whileStack);
        initializeStack(&forStack);
        initializeStack(&switchStack);
        params = (Node **)malloc(0);
}
//FUNCTIONS
Node * handleConditionalExpression(Node * node);
Node * handleConditionalComparison(Node * first , Node * second , char* operand);
char * concatenateStrings(char * first , char * second);
void handleFunctionParameters(SymbolEntry ** enter , Node** nodes , int argCont);

int scope = 0;
// extern int yylineno;
//symbol entry
int tempCount = 0;
int labels=0;
int while_labels=0;
int do_while_labels = 0;
int for_labels = 0;
int ifCount = 0;
int switchCount = 0;
int caseCount = 0;
int paramCount = 0;
bool isElse= false;
bool isDefault = false;
int elseCount = 0;
int popped  = 0;
int popped_while = 0;
int popped_for = 0;
char* funcName;


/* Line 189 of yacc.c  */
#line 138 "y.tab.c"

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
#line 65 "parser.y"

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
#line 296 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 308 "y.tab.c"

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
#define YYLAST   377

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNRULES -- Number of states.  */
#define YYNSTATES  209

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
       0,     0,     3,     6,     7,    10,    12,    14,    16,    22,
      23,    24,    26,    28,    30,    32,    34,    36,    38,    41,
      43,    44,    45,    57,    59,    62,    63,    68,    73,    77,
      78,    85,    86,    92,    96,   100,   101,   106,   107,   113,
     116,   121,   123,   127,   131,   136,   138,   140,   148,   154,
     156,   157,   169,   171,   173,   175,   176,   183,   185,   186,
     191,   193,   195,   199,   203,   207,   211,   215,   219,   223,
     227,   231,   233,   235,   237,   240,   247,   250,   254,   260,
     263,   265,   267,   269,   271,   273,   275,   277,   279,   283,
     286,   290,   294,   298,   302,   304,   306,   308,   310,   312,
     314,   316,   319,   322,   325,   328,   330,   332,   334,   336,
     338
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    57,    58,    -1,    -1,    58,    59,    -1,
      59,    -1,    63,    -1,    60,    -1,    38,    61,    58,    39,
      62,    -1,    -1,    -1,    99,    -1,    75,    -1,    98,    -1,
      92,    -1,    86,    -1,    84,    -1,    83,    -1,    80,    16,
      -1,    64,    -1,    -1,    -1,    45,    36,   100,    65,    37,
      38,    61,    67,    66,    39,    62,    -1,    70,    -1,    67,
      70,    -1,    -1,    46,   102,    69,    51,    -1,    68,    58,
      52,    16,    -1,    68,    52,    16,    -1,    -1,    53,    51,
      71,    58,    52,    16,    -1,    -1,    53,    51,    72,    52,
      16,    -1,   103,    15,    36,    -1,    73,    61,    78,    -1,
      -1,    73,    37,    76,    59,    -1,    -1,    74,    37,    77,
      59,    62,    -1,   103,    15,    -1,    78,    20,   103,    15,
      -1,   100,    -1,    79,    20,   100,    -1,    15,    36,    37,
      -1,    15,    36,    79,    37,    -1,    95,    -1,    44,    -1,
      82,    59,    43,    36,    81,    37,    16,    -1,    43,    36,
      85,    37,    59,    -1,    95,    -1,    -1,    42,    36,    61,
      99,    87,    88,    16,    89,    37,    62,    59,    -1,    97,
      -1,   106,    -1,   104,    -1,    -1,    40,    36,    91,    94,
      37,    59,    -1,    90,    -1,    -1,    90,    41,    93,    59,
      -1,    95,    -1,    97,    -1,    97,    47,    95,    -1,    97,
      48,    95,    -1,   102,    21,   102,    -1,   102,    22,   102,
      -1,   102,    23,   102,    -1,   102,    24,   102,    -1,   102,
      25,   102,    -1,   102,    26,   102,    -1,    36,    96,    37,
      -1,    14,    -1,   100,    -1,    96,    -1,    49,    97,    -1,
      17,   103,    15,    27,   100,    16,    -1,   104,    16,    -1,
     103,    15,    16,    -1,   103,    15,    27,   100,    16,    -1,
     106,    16,    -1,   102,    -1,   101,    -1,    12,    -1,    13,
      -1,    10,    -1,    11,    -1,    15,    -1,     9,    -1,   102,
      32,   102,    -1,    33,   102,    -1,   102,    33,   102,    -1,
     102,    34,   102,    -1,   102,    35,   102,    -1,    36,   102,
      37,    -1,    80,    -1,     3,    -1,     4,    -1,     6,    -1,
       5,    -1,     7,    -1,     8,    -1,    15,    18,    -1,    15,
      19,    -1,    18,    15,    -1,    19,    15,    -1,    27,    -1,
      28,    -1,    29,    -1,    30,    -1,    31,    -1,    15,   105,
     102,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   119,   119,   121,   129,   130,   134,   135,   139,   142,
     150,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     174,   177,   174,   193,   198,   206,   206,   217,   218,   219,
     219,   224,   224,   231,   243,   249,   249,   273,   273,   294,
     303,   314,   319,   326,   347,   370,   377,   385,   388,   398,
     408,   408,   423,   430,   431,   434,   434,   437,   443,   443,
     461,   469,   472,   479,   488,   504,   520,   536,   552,   568,
     584,   585,   598,   615,   616,   625,   665,   666,   681,   727,
     731,   732,   735,   740,   748,   753,   758,   771,   778,   802,
     821,   847,   874,   900,   901,   906,   909,   912,   915,   918,
     921,   927,   939,   952,   964,   980,   983,   986,   989,   992,
     998
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
  "end_scope", "one_line_statement", "switch_statement", "$@1", "$@2",
  "switch_cases", "cases", "$@3", "switch_case", "$@4", "$@5",
  "func_begin", "func_stmt_params", "func_statement", "$@6", "$@7",
  "func_params", "func_call_parameter", "func_call", "do_while_stmt",
  "do_word", "do_while_statement", "while_statement", "while_stmt",
  "for_statement", "$@8", "for_stmt", "for_step", "if_only", "$@9",
  "conditional_statement", "$@10", "ifstatement", "conditional_if",
  "condition_only", "conditional_expression", "special_declaration",
  "default_declaration", "expression_statement", "char_expression",
  "expression", "data_type", "unary_expression", "assign_operation",
  "assign_expression", 0
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
      65,    66,    64,    67,    67,    69,    68,    70,    70,    71,
      70,    72,    70,    73,    74,    76,    75,    77,    75,    78,
      78,    79,    79,    80,    80,    81,    82,    83,    84,    85,
      87,    86,    88,    89,    89,    91,    90,    92,    93,    92,
      94,    95,    95,    95,    96,    96,    96,    96,    96,    96,
      96,    96,    97,    97,    97,    98,    98,    98,    99,    99,
     100,   100,   101,   101,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   103,   103,   103,   103,   103,
     103,   104,   104,   104,   104,   105,   105,   105,   105,   105,
     106
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     5,     0,
       0,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       0,     0,    11,     1,     2,     0,     4,     4,     3,     0,
       6,     0,     5,     3,     3,     0,     4,     0,     5,     2,
       4,     1,     3,     3,     4,     1,     1,     7,     5,     1,
       0,    11,     1,     1,     1,     0,     6,     1,     0,     4,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     2,     6,     2,     3,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,    95,    96,    98,    97,    99,   100,
       0,     0,     0,     0,     9,     0,     0,     0,    46,     0,
       2,     5,     7,     6,    19,     9,     0,    12,     0,     0,
      17,    16,    15,    57,    14,    13,    11,     0,     0,     0,
     101,   102,   105,   106,   107,   108,   109,     0,     0,     0,
     103,   104,     0,    55,     9,     0,     0,     4,    35,     0,
      37,    18,     0,    58,     0,    76,    79,    87,    84,    85,
      82,    83,    86,     0,     0,    43,     0,    94,    41,    81,
      80,   110,     0,     0,     0,     0,    71,     0,     0,     0,
      49,    73,    61,    72,    80,    20,     0,    34,     0,     0,
       0,     0,    77,     0,    33,    89,     0,     0,    44,     0,
       0,     0,     0,     0,    10,     0,    60,     0,    50,     0,
       0,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,     0,    39,    10,     0,    59,     0,
      93,    42,    88,    90,    91,    92,     0,     8,     0,     0,
       0,    70,    48,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    38,     0,    45,    78,    75,    56,     0,
      52,     9,    40,     0,     0,     0,    47,     0,     0,    54,
      53,     0,     0,    21,     0,    23,    10,    25,    29,     0,
      24,     0,     0,     0,     0,     0,     0,    10,    28,     0,
      51,    26,     0,     0,    22,    27,     0,    32,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    20,    21,    22,    52,   147,    23,    24,
     132,   189,   183,   184,   194,   185,   195,   196,    25,    26,
      27,    96,    99,    97,    76,    77,   164,    29,    30,    31,
      89,    32,   149,   169,   178,    33,    84,    34,   101,   115,
      90,    91,    92,    35,    36,    93,    79,    94,    37,    38,
      48,    39
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -124
static const yytype_int16 yypact[] =
{
    -124,    11,   281,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
     309,    53,     2,     8,  -124,     0,     7,     9,  -124,    16,
     281,  -124,  -124,  -124,  -124,    -3,    10,  -124,    49,   281,
    -124,  -124,  -124,    35,  -124,  -124,  -124,    60,    62,    67,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,   148,   108,    69,
    -124,  -124,   281,  -124,  -124,   101,   222,  -124,  -124,    53,
    -124,  -124,    50,  -124,    -8,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,    56,   108,   108,  -124,   -17,  -124,  -124,  -124,
     154,   154,    71,   264,   101,    34,  -124,    15,   101,    59,
    -124,  -124,   -26,  -124,   342,  -124,   281,    80,    87,   281,
      84,   281,  -124,   222,  -124,  -124,    98,   222,  -124,   108,
     108,   108,   108,   222,  -124,    66,  -124,    78,  -124,   109,
      90,   325,  -124,   281,   101,   101,   108,   108,   108,   108,
     108,   108,   102,  -124,    53,  -124,  -124,   101,  -124,   122,
    -124,  -124,  -124,  -124,  -124,  -124,   129,  -124,   281,   101,
     135,  -124,  -124,  -124,  -124,   154,   154,   154,   154,   154,
     154,   111,   141,  -124,   133,  -124,  -124,  -124,  -124,   155,
    -124,  -124,  -124,   156,   107,   -37,  -124,   124,   138,  -124,
    -124,   108,   126,   -37,   161,  -124,  -124,   154,   140,   157,
    -124,   178,   204,   281,   144,   281,   145,  -124,  -124,   182,
    -124,  -124,   221,   186,  -124,  -124,   198,  -124,  -124
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,  -124,   -48,   -19,  -124,   -23,  -123,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,    32,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,    -2,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
     -70,   130,   -76,  -124,   131,   -12,  -124,   -41,    -6,    44,
    -124,    46
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -32
static const yytype_int16 yytable[] =
{
      28,    57,    59,   107,    83,    49,    80,    81,   102,   181,
      62,     3,   122,   163,   116,    80,   182,    50,    28,   103,
     108,   124,   125,    51,    67,    68,    69,    28,   104,    86,
      72,    85,   105,   106,    58,    78,    53,     4,     5,     6,
       7,     8,     9,    54,    95,    55,   121,    60,    73,   117,
      28,    87,    56,    98,   153,   154,     4,     5,     6,     7,
       8,     9,    80,   193,    57,    61,    80,   165,   142,   143,
     144,   145,    80,   170,   204,    64,    63,   133,    65,   119,
     136,    28,   138,    66,    82,   155,   156,   157,   158,   159,
     160,   139,    47,   100,    28,   141,   123,    28,   113,    28,
     134,   146,   135,   148,   152,    42,    43,    44,    45,    46,
      67,    68,    69,    70,    71,    86,    72,    67,    68,    69,
     137,    28,   177,    72,   150,    12,    13,   151,   162,   168,
     109,   110,   111,   112,    73,   140,   192,    87,   166,   161,
     187,    73,    40,    41,    74,   167,    28,   202,   175,   171,
      88,    42,    43,    44,    45,    46,   172,    67,    68,    69,
      70,    71,   103,    72,     4,     5,     6,     7,     8,     9,
     173,   174,   176,    57,   200,   186,    10,   188,    11,    12,
      13,    73,    28,    57,    74,    75,   109,   110,   111,   112,
      28,    28,   -31,    28,   198,   201,   197,   203,   205,    14,
      28,    15,   207,    16,    17,    18,    19,     4,     5,     6,
       7,     8,     9,   191,   208,   190,   118,   120,   179,    10,
     180,    11,    12,    13,     4,     5,     6,     7,     8,     9,
       0,    67,    68,    69,    70,    71,    10,    72,    11,    12,
      13,     0,    14,     0,    15,     0,    16,    17,    18,    19,
       0,     0,     0,     0,     0,    73,   199,     0,    74,    14,
       0,    15,     0,    16,    17,    18,    19,     4,     5,     6,
       7,     8,     9,   206,     0,     0,     0,     0,     0,    10,
       0,    11,    12,    13,     4,     5,     6,     7,     8,     9,
       0,     0,     0,     0,     0,     0,    10,     0,    11,    12,
      13,     0,    14,   114,    15,     0,    16,    17,    18,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
       0,    15,     0,    16,    17,    18,    19,    40,    41,     0,
       0,     0,     0,     0,     0,     0,    42,    43,    44,    45,
      46,     0,     0,     0,     0,    47,   126,   127,   128,   129,
     130,   131,     0,     0,     0,     0,     0,   109,   110,   111,
     112,     0,   140,   126,   127,   128,   129,   130,   131,     0,
       0,     0,     0,     0,   109,   110,   111,   112
};

static const yytype_int16 yycheck[] =
{
       2,    20,    25,    20,    52,    11,    47,    48,    16,    46,
      29,     0,    88,   136,    84,    56,    53,    15,    20,    27,
      37,    47,    48,    15,     9,    10,    11,    29,    36,    14,
      15,    54,    73,    74,    37,    47,    36,     3,     4,     5,
       6,     7,     8,    36,    56,    36,    87,    37,    33,    15,
      52,    36,    36,    59,   124,   125,     3,     4,     5,     6,
       7,     8,   103,   186,    83,    16,   107,   137,   109,   110,
     111,   112,   113,   149,   197,    15,    41,    96,    16,    85,
      99,    83,   101,    16,    15,   126,   127,   128,   129,   130,
     131,   103,    36,    43,    96,   107,    37,    99,    27,   101,
      20,   113,    15,    37,   123,    27,    28,    29,    30,    31,
       9,    10,    11,    12,    13,    14,    15,     9,    10,    11,
      36,   123,    15,    15,    15,    18,    19,    37,   134,   148,
      32,    33,    34,    35,    33,    37,   184,    36,    16,    37,
     181,    33,    18,    19,    36,    16,   148,   195,   171,    38,
      49,    27,    28,    29,    30,    31,    15,     9,    10,    11,
      12,    13,    27,    15,     3,     4,     5,     6,     7,     8,
      37,    16,    16,   192,   193,    37,    15,    51,    17,    18,
      19,    33,   184,   202,    36,    37,    32,    33,    34,    35,
     192,   193,    52,   195,    16,    51,    39,    52,    16,    38,
     202,    40,    16,    42,    43,    44,    45,     3,     4,     5,
       6,     7,     8,    52,    16,   183,    85,    87,   174,    15,
     174,    17,    18,    19,     3,     4,     5,     6,     7,     8,
      -1,     9,    10,    11,    12,    13,    15,    15,    17,    18,
      19,    -1,    38,    -1,    40,    -1,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    33,    52,    -1,    36,    38,
      -1,    40,    -1,    42,    43,    44,    45,     3,     4,     5,
       6,     7,     8,    52,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    17,    18,    19,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    18,
      19,    -1,    38,    39,    40,    -1,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    40,    -1,    42,    43,    44,    45,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    36,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    -1,    37,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    56,    57,     0,     3,     4,     5,     6,     7,     8,
      15,    17,    18,    19,    38,    40,    42,    43,    44,    45,
      58,    59,    60,    63,    64,    73,    74,    75,    80,    82,
      83,    84,    86,    90,    92,    98,    99,   103,   104,   106,
      18,    19,    27,    28,    29,    30,    31,    36,   105,   103,
      15,    15,    61,    36,    36,    36,    36,    59,    37,    61,
      37,    16,    59,    41,    15,    16,    16,     9,    10,    11,
      12,    13,    15,    33,    36,    37,    79,    80,   100,   101,
     102,   102,    15,    58,    91,    61,    14,    36,    49,    85,
      95,    96,    97,   100,   102,   100,    76,    78,   103,    77,
      43,    93,    16,    27,    36,   102,   102,    20,    37,    32,
      33,    34,    35,    27,    39,    94,    95,    15,    99,   103,
      96,   102,    97,    37,    47,    48,    21,    22,    23,    24,
      25,    26,    65,    59,    20,    15,    59,    36,    59,   100,
      37,   100,   102,   102,   102,   102,   100,    62,    37,    87,
      15,    37,    59,    95,    95,   102,   102,   102,   102,   102,
     102,    37,   103,    62,    81,    95,    16,    16,    59,    88,
      97,    38,    15,    37,    16,    61,    16,    15,    89,   104,
     106,    46,    53,    67,    68,    70,    37,   102,    51,    66,
      70,    52,    58,    62,    69,    71,    72,    39,    16,    52,
      59,    51,    58,    52,    62,    16,    52,    16,    16
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
#line 121 "parser.y"
    {
        printf("Start\n");
               globalTable = createSymbolTable("global",scope, NULL);
                                    currTable = globalTable;

        }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    {printf("Start Scope\n");
        scope++;
        tempTable = createSymbolTable("local",scope, currTable);
        addChildToTable(currTable, tempTable);
        currTable = tempTable;
        }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    {printf("End Scope\n");
        scope--;
        currTable = currTable->parent;
        }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    {printf("defualt Declaration\n");}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    {printf("func_statment \n");}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    {printf("special Declaration\n");}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    {printf("Conditional Statement\n");}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    {printf("For Statement\n");}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    {printf("While Statement\n");}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    {printf("Do While Statement\n");}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    {printf("Function Call with semi colonnnn\n");}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    {printf("Switch Statement\n");}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 174 "parser.y"
    {
                switchCount++;
                push(&switchStack , switchCount);
        }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 177 "parser.y"
    {
                if(!isDefault)
                {
                        char*label= concatunate('C' , caseCount);
                        insertQuad((yyvsp[(3) - (8)].node)->name , NULL , "LABEL" , label , 0);
                        isDefault = false;
                }
        }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 184 "parser.y"
    { 
                int popped_switch = pop(&switchStack);
                char*label= concatunate('S' , popped_switch);
                insertQuad((yyvsp[(3) - (11)].node)->name , NULL , "LABEL" , label , 0);

                
        }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 193 "parser.y"
    {
                int popped_switch = peek(&switchStack);
                char*label= concatunate('S' , popped_switch);
                insertQuad(NULL , NULL , "JMP" , label , 0);
        }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 199 "parser.y"
    {
                int popped_switch = peek(&switchStack);
                char*label= concatunate('S' , popped_switch);
                insertQuad(NULL , NULL , "JMP" , label , 0);
        }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 206 "parser.y"
    {
                char*label_1= concatunate('C' , caseCount);
                insertQuad(NULL , NULL , "LABEL" , label_1 , 0);
                if(!isDefault)
                {
                        caseCount++;
                        char*label= concatunate('C' , caseCount);
                        insertQuad((yyvsp[(2) - (2)].node)->name , NULL , "JZ" , label , 0);
                }
        }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    {
                isDefault = true;
                char*label_1= concatunate('C' , caseCount);
                insertQuad(NULL , NULL , "LABEL" , label_1 , 0);
        }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    {
                isDefault = true;
                char*label_1= concatunate('C' , caseCount);
                insertQuad(NULL , NULL , "LABEL" , label_1 , 0);
        }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 231 "parser.y"
    {
               
                printf("Data func Identifier\n");
                union Value val;
                SymbolEntry* entry= createSymbolEntryWithDefaults((yyvsp[(2) - (3)].sval), func,val,false,0,(yyvsp[(1) - (3)].dataType)); 
                addEntryToTable(currTable, entry);
                Node* node = createIDNode((yyvsp[(2) - (3)].sval), scope, entry->type);
                funcName = (yyvsp[(2) - (3)].sval);
                (yyval.node) = node;
        }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 243 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (3)].node); }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 249 "parser.y"
    {
                SymbolEntry *entry = getentryfromalltables(currTable, (yyvsp[(1) - (2)].node)->name);
                if(entry != NULL && entry->kind == func){
                        if(entry->argCount == 0){
                                char* start = concatenateStrings( (yyvsp[(1) - (2)].node)->name, "_START");
                                insertQuad(NULL , NULL , "LABEL" , start , 0);
                        }
                        else{
                                printf("Error: Function is with parameters\n");
                        }
                }
                else{
                        printf("Error: Function not declared\n");
                }
        }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 263 "parser.y"
    {
                SymbolEntry *entry = getentryfromalltables(currTable, (yyvsp[(1) - (4)].node)->name);
                if(entry != NULL && entry->kind == func){
                        if(entry->argCount == 0){
                                char* end = concatenateStrings( (yyvsp[(1) - (4)].node)->name, "_END");
                                insertQuad(NULL , NULL , "JMP" , end , 0);
                        }
                }
        }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 273 "parser.y"
    {
                SymbolEntry *entry = getentryfromalltables(currTable, (yyvsp[(1) - (2)].node)->name);
                if(entry != NULL && entry->kind == func){
                                char* start = concatenateStrings( (yyvsp[(1) - (2)].node)->name, "_START");
                                insertQuad(NULL , NULL , "LABEL" , start , 0);
                }
                else{
                        printf("Error: Function not declared\n");
                }
        
        }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 283 "parser.y"
    {
                SymbolEntry *entry = getentryfromalltables(currTable, (yyvsp[(1) - (5)].node)->name);
                if(entry != NULL && entry->kind == func){
                        char* end = concatenateStrings( (yyvsp[(1) - (5)].node)->name, "_END");
                        insertQuad(NULL , NULL , "JMP" , end , 0);
                        
                }
        }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 294 "parser.y"
    {         printf("Data Type Identifier\n");
                union Value val;
                SymbolEntry* entry= createSymbolEntryWithDefaults((yyvsp[(2) - (2)].sval), param,val,false,0,(yyvsp[(1) - (2)].dataType)); 
                addEntryToTable(currTable, entry);
                SymbolEntry* entryfunc = getentryfromalltables(currTable, funcName);
                printf("entryfunc %s\n", entryfunc->name);
                addparam(entryfunc,entry);       
                
                }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 303 "parser.y"
    {         printf("Data Type Identifier\n");
                union Value val;
                SymbolEntry* entry= createSymbolEntryWithDefaults((yyvsp[(4) - (4)].sval), param,val,false,0,(yyvsp[(3) - (4)].dataType)); 
                addEntryToTable(currTable, entry);
                      SymbolEntry* entryfunc = getentryfromalltables(currTable, funcName);
                addparam(entryfunc,entry);

                
                }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 314 "parser.y"
    {
                params = (Node **)realloc(params, (paramCount + 1) * sizeof(Node*));
                params[paramCount] = (yyvsp[(1) - (1)].node);
                paramCount++;
        }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 319 "parser.y"
    {
                params = (Node **)realloc(params, (paramCount + 1) * sizeof(Node*));
                params[paramCount] = (yyvsp[(3) - (3)].node);
                paramCount++;
        }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 326 "parser.y"
    {
                SymbolEntry *entry = getentryfromalltables(currTable, (yyvsp[(1) - (3)].sval));
                if(entry != NULL && entry->kind == func){
                        if(entry->argCount == 0){
                                printf("Function Call\n");
                                char* start = concatenateStrings( (yyvsp[(1) - (3)].sval), "_START");
                                insertQuad(NULL , NULL , "JMP" , start , 0);
                                char* end = concatenateStrings( (yyvsp[(1) - (3)].sval), "_END");
                                insertQuad(NULL , NULL , "LABEL" , end , 0);
                                Node* node = createIDNode((yyvsp[(1) - (3)].sval), scope, entry->type);
                                (yyval.node) = node;

                        }
                        else{
                                printf("Error: Function is with parameters\n");
                        }
                }
                else{
                        printf("Error: Function not declared\n");
                }
        }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 347 "parser.y"
    {
                SymbolEntry *entry = getentryfromalltables(currTable, (yyvsp[(1) - (4)].sval));
                if(entry != NULL && entry->kind == func){
                        if(entry->argCount == paramCount){
                                handleFunctionParameters(entry->parameters , params, paramCount);
                                char* start = concatenateStrings( (yyvsp[(1) - (4)].sval), "_START");
                                insertQuad(NULL , NULL , "JMP" , start , 0);
                                char* end = concatenateStrings( (yyvsp[(1) - (4)].sval), "_END");
                                insertQuad(NULL , NULL , "LABEL" , end , 0);
                                Node* node = createIDNode((yyvsp[(1) - (4)].sval), scope, entry->type);
                                printf("BADR FUNCTION CALLL %d\n" , entry->type);
                                paramCount = 0;
                                (yyval.node) = node;
                        }
                        else{
                                printf("Error: Function is with parameters %d\n" , entry->argCount);
                        }
                }
                else{
                        printf("Error: Function not declared\n");
                }
        }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 370 "parser.y"
    {
        int popped_do_while = pop(&do_whileStack);
        char*label= concatunate('D' , popped_do_while);
        insertQuad((yyvsp[(1) - (1)].node)->name , NULL , "JZ" , label , 0);
        (yyval.node)=(yyvsp[(1) - (1)].node);
}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 377 "parser.y"
    {
                do_while_labels++;
                insertQuad(NULL , NULL , "LABEL" , concatunate('D' , do_while_labels ) , 0);
                push(&do_whileStack , do_while_labels);
        }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 385 "parser.y"
    {printf("Do While Statement\n");}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 388 "parser.y"
    { 
                int popped_while_1 = pop(&whileStack);
                int popped_while_2 = pop(&whileStack);
                char*label_1= concatunate('W' , popped_while_1);
                char*label_2= concatunate('W' , popped_while_2);
                insertQuad(NULL , NULL , "JMP" ,label_2  , 0);
                insertQuad(NULL , NULL , "LABEL" ,label_1  , 0);

        }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 398 "parser.y"
    {
        while_labels++;
        insertQuad(NULL , NULL , "LABEL" , concatunate('W' , while_labels ) , 0);
        push(&whileStack , while_labels);
        while_labels++;
        insertQuad((yyvsp[(1) - (1)].node)->name , NULL , "JZ" , concatunate('W' , while_labels ) , 0);
        push(&whileStack , while_labels);
        (yyval.node)=(yyvsp[(1) - (1)].node);
}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 408 "parser.y"
    {
                for_labels++;
                insertQuad(NULL , NULL , "LABEL" , concatunate('F' , for_labels ) , 0);
                push(&forStack , for_labels);
        }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 413 "parser.y"
    {
                int popped_for_2 = pop(&forStack);
                int popped_for_1 = pop(&forStack);
                char*label_1= concatunate('F' , popped_for_1);
                char*label_2= concatunate('F' , popped_for_2);
                insertQuad(NULL , NULL , "JMP" ,label_1  , 0);
                insertQuad(NULL , NULL , "LABEL" ,label_2  , 0);
        }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 423 "parser.y"
    {
                for_labels++;
                insertQuad((yyvsp[(1) - (1)].node)->name , NULL , "JZ" , concatunate('F' , for_labels ) , 0);
                push(&forStack , for_labels);
                (yyval.node)=(yyvsp[(1) - (1)].node);
        }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 434 "parser.y"
    {labels++;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 437 "parser.y"
    {
                popped = pop(&ifStack);
                char*label= concatunate('L' , popped);

                insertQuad(NULL , NULL , "LABEL" ,label  , 0);
        }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 443 "parser.y"
    {
                isElse = true;
                printf("If Statement\n");
                labels++;
                char*label_2= concatunate('L' , labels);
                popped = pop(&ifStack);
                char*label= concatunate('L' , popped);
                push(&ifStack , labels);

                insertQuad(NULL , NULL , "JMP" ,label_2 , 0);
                insertQuad(NULL , NULL , "LABEL" ,label  , 0);
                }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 454 "parser.y"
    {
                        popped = pop(&ifStack);
                        char*label= concatunate('L' , popped);
                        insertQuad(NULL , NULL , "LABEL" ,label  , 0);
                }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 461 "parser.y"
    { 
        insertQuad((yyvsp[(1) - (1)].node)->name , NULL , "JZ" , concatunate('L' , labels) , 0);
        push(&ifStack , labels);
        (yyval.node)=(yyvsp[(1) - (1)].node);

}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 469 "parser.y"
    {
                printf("Conditional If: %s\n" , (yyvsp[(1) - (1)].node)->name);
                (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 472 "parser.y"
    { 
                tempCount++;
                Node * boolNode = createBoolNode((yyvsp[(1) - (3)].node)->value.bVal && (yyvsp[(3) - (3)].node)->value.bVal , scope , tempCount , false);
                insertQuad((yyvsp[(1) - (3)].node)->name , (yyvsp[(3) - (3)].node)->name , "&&" , boolNode->name , 0);    
                (yyval.node) = boolNode;  
                
        }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 480 "parser.y"
    {
                tempCount++;
                Node * boolNode = createBoolNode((yyvsp[(1) - (3)].node)->value.bVal || (yyvsp[(3) - (3)].node)->value.bVal , scope , tempCount , false);     
                insertQuad((yyvsp[(1) - (3)].node)->name , (yyvsp[(3) - (3)].node)->name , "||" , boolNode->name , 0);    
                (yyval.node) = boolNode;
        }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 488 "parser.y"
    { 
                if((yyvsp[(1) - (3)].node)->dataType == (yyvsp[(3) - (3)].node)->dataType){
                                
                        Node * boolNode = handleConditionalComparison((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "<");
                        if (boolNode != NULL){
                                printf("LESS THAN %d\n" , boolNode->value.bVal ? 1:0);
                                (yyval.node) = boolNode;
                        }
                        else{
                                printf("Error: MOSHKELA\n");
                        }
                }
                else{
                        printf("Error: Data Type Mismatch\n");
                }
        }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 504 "parser.y"
    {
                if((yyvsp[(1) - (3)].node)->dataType == (yyvsp[(3) - (3)].node)->dataType)
                {
                                Node * boolNode = handleConditionalComparison((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), ">");
                        if (boolNode != NULL){
                                printf("Greater THAN %d\n" , boolNode->value.bVal ? 1:0);
                                (yyval.node) = boolNode;
                        }
                        else{
                                printf("Error: MOSHKELA\n");
                        }
                }
                else {
                        printf("Error: Data Type Mismatch\n");
                }
        }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 520 "parser.y"
    {
                if((yyvsp[(1) - (3)].node)->dataType == (yyvsp[(3) - (3)].node)->dataType)
                {
                        Node * boolNode = handleConditionalComparison((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "<=");
                        if (boolNode != NULL){
                                printf("LESS THAN or equal %d\n" , boolNode->value.bVal ? 1:0);
                                (yyval.node) = boolNode;
                        }
                        else{
                                printf("Error: MOSHKELA\n");
                        }
                }
                else {
                        printf("Error: Data Type Mismatch\n");
                }
        }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 536 "parser.y"
    {
                if((yyvsp[(1) - (3)].node)->dataType == (yyvsp[(3) - (3)].node)->dataType)
                {
                        Node * boolNode = handleConditionalComparison((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), ">=");
                        if (boolNode != NULL){
                                printf("greater THAN equal %d\n" , boolNode->value.bVal ? 1:0);
                                (yyval.node) = boolNode;
                        }
                        else{
                                printf("Error: MOSHKELA\n");
                        }
                }
                else {
                        printf("Error: Data Type Mismatch\n");
                }
        }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 552 "parser.y"
    {
                if((yyvsp[(1) - (3)].node)->dataType == (yyvsp[(3) - (3)].node)->dataType)
                {
                        Node * boolNode = handleConditionalComparison((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "==");
                        if (boolNode != NULL){
                                printf("equal  %d\n" , boolNode->value.bVal ? 1:0);
                                (yyval.node) = boolNode;
                        }
                        else{
                                printf("Error: MOSHKELA\n");
                        }
                }
                else {
                        printf("Error: Data Type Mismatch\n");
                }
        }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 568 "parser.y"
    {
               if((yyvsp[(1) - (3)].node)->dataType == (yyvsp[(3) - (3)].node)->dataType)
               { 
                        Node * boolNode = handleConditionalComparison((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "!=");
                        if (boolNode != NULL){
                                (yyval.node) = boolNode;
                                printf("not equal %d\n" , boolNode->value.bVal ? 1:0);
                        }
                        else{
                                printf("Error: MOSHKELA\n");
                        }
                }
                else {
                        printf("Error: Data Type Mismatch\n");
                }
        }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 584 "parser.y"
    {(yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 585 "parser.y"
    {
                Node* boolNode;
                if ((yyvsp[(1) - (1)].bVal))
                {
                        boolNode = createBoolNode(true , scope , tempCount , true);
                }
                else {
                        boolNode = createBoolNode(false , scope, tempCount , true);
                }
        }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 598 "parser.y"
    {
                if((yyvsp[(1) - (1)].node)->nodeType == NODE_ID)
                {
                        printf("Conditional Expression\n");
                        Node * boolNode = handleConditionalExpression((yyvsp[(1) - (1)].node));
                if (boolNode != NULL){
                        printf("3azeemm %d\n" , boolNode->value.bVal ? 1:0);
                        (yyval.node) = boolNode;
                }
                else{
                        printf("Error: MOSHKELA\n");
                }
                }
                else {
                        printf("GHALATTTTTT\n");
                }
        }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 615 "parser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 616 "parser.y"
    {
                tempCount++;
                Node * boolNode = createBoolNode(!(yyvsp[(2) - (2)].node)->value.bVal , scope , tempCount , false);    
                insertQuad(NULL , (yyvsp[(2) - (2)].node)->name , "!" , boolNode->name , 0); 
                (yyval.node) = boolNode;
        }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 625 "parser.y"
    {
                SymbolEntry *entry = getentryfromalltables(currTable, (yyvsp[(3) - (6)].sval));
                if(entry == NULL)
                {
                        if ((yyvsp[(2) - (6)].dataType) == (yyvsp[(5) - (6)].node)->dataType){
                                if ((yyvsp[(2) - (6)].dataType) == TYPE_INT){
                                        SymbolEntry *entry=createSymbolEntry((yyvsp[(3) - (6)].sval), constant, (yyvsp[(5) - (6)].node)->value,true,0,(yyvsp[(2) - (6)].dataType), 1, 0, NULL, "");
                                        addEntryToTable(currTable, entry);
                                        insertQuad((yyvsp[(5) - (6)].node)->name , NULL , "=" , (yyvsp[(3) - (6)].sval) , 0);
                                }
                                else if ((yyvsp[(2) - (6)].dataType) == TYPE_DOUBLE){
                                        SymbolEntry *entry=createSymbolEntry((yyvsp[(3) - (6)].sval), constant, (yyvsp[(5) - (6)].node)->value,true,0,(yyvsp[(2) - (6)].dataType), 1, 0, NULL, "");
                                        addEntryToTable(currTable, entry);
                                        insertQuad((yyvsp[(5) - (6)].node)->name , NULL , "=" , (yyvsp[(3) - (6)].sval) , 0);
                                }
                                else if ((yyvsp[(2) - (6)].dataType) == TYPE_BOOL){
                                        SymbolEntry *entry=createSymbolEntry((yyvsp[(3) - (6)].sval), constant, (yyvsp[(5) - (6)].node)->value,true,0,(yyvsp[(2) - (6)].dataType), 1, 0, NULL, "");
                                        addEntryToTable(currTable, entry);
                                        insertQuad((yyvsp[(5) - (6)].node)->name , NULL , "=" , (yyvsp[(3) - (6)].sval) , 0);
                                }
                                else if ((yyvsp[(2) - (6)].dataType) == TYPE_CHAR){
                                        SymbolEntry *entry=createSymbolEntry((yyvsp[(3) - (6)].sval), constant, (yyvsp[(5) - (6)].node)->value,true,0,(yyvsp[(2) - (6)].dataType), 1, 0, NULL, "");
                                        addEntryToTable(currTable, entry);
                                        insertQuad((yyvsp[(5) - (6)].node)->name , NULL , "=" , (yyvsp[(3) - (6)].sval) , 0);
                                }
                                else if ((yyvsp[(2) - (6)].dataType) == TYPE_STRING){
                                        SymbolEntry *entry=createSymbolEntry((yyvsp[(3) - (6)].sval), constant, (yyvsp[(5) - (6)].node)->value,true,0,(yyvsp[(2) - (6)].dataType), 1, 0, NULL, "");
                                        addEntryToTable(currTable, entry);
                                        insertQuad((yyvsp[(5) - (6)].node)->name , NULL , "=" , (yyvsp[(3) - (6)].sval) , 0);
                                }
                        }
                        else{
                                printf("Error: Data Type Mismatch\n");
                        }
                }
                else {
                        printf("Error: Varibale already declared\n");
                }

        }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 666 "parser.y"
    {
                printf("Data Type Identifier\n");
                SymbolEntry * entry = getentryfromalltables(currTable, (yyvsp[(2) - (3)].sval));
                if(entry == NULL)
                {       
                        union Value val;
                        SymbolEntry* entry= createSymbolEntryWithDefaults((yyvsp[(2) - (3)].sval), var,val,false,0,(yyvsp[(1) - (3)].dataType)); 
                        addEntryToTable(currTable, entry);
                }
                else{
                        printf("ERROR: VARIABLE ALREADY DECLARED\n");
                }
        }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 681 "parser.y"
    {  
                printf(" Default Declaration Data Type: %d data type el tanyyy %d\n", (yyvsp[(1) - (5)].dataType) , (yyvsp[(4) - (5)].node)->dataType); 
                SymbolEntry *entry = getentryfromalltables(currTable, (yyvsp[(2) - (5)].sval));
                if(entry == NULL)
                {
                        if((yyvsp[(1) - (5)].dataType) == (yyvsp[(4) - (5)].node)->dataType){
                        if ((yyvsp[(1) - (5)].dataType) == TYPE_INT){
                                insertQuad((yyvsp[(4) - (5)].node)->name , NULL , "=" , (yyvsp[(2) - (5)].sval) , 0);
                                SymbolEntry* entry= createSymbolEntryWithDefaults((yyvsp[(2) - (5)].sval), var, (yyvsp[(4) - (5)].node)->value,true,0, (yyvsp[(1) - (5)].dataType));
                                printf("Default Declaration Data Type: %d %s %s\n", (yyvsp[(1) - (5)].dataType) , (yyvsp[(2) - (5)].sval) , entry->isInitialized ? "true" : "false");
                                addEntryToTable(currTable, entry);
                        }
                        else if ((yyvsp[(1) - (5)].dataType) == TYPE_DOUBLE){
                                insertQuad((yyvsp[(4) - (5)].node)->name , NULL , "=" , (yyvsp[(2) - (5)].sval) , 0);
                                SymbolEntry* entry= createSymbolEntryWithDefaults((yyvsp[(2) - (5)].sval), var, (yyvsp[(4) - (5)].node)->value,true,0, (yyvsp[(1) - (5)].dataType));
                                addEntryToTable(currTable, entry);
                        }
                        else if ((yyvsp[(1) - (5)].dataType) == TYPE_BOOL){
                                insertQuad((yyvsp[(4) - (5)].node)->name , NULL , "=" , (yyvsp[(2) - (5)].sval) , 0);
                                SymbolEntry* entry= createSymbolEntryWithDefaults((yyvsp[(2) - (5)].sval), var, (yyvsp[(4) - (5)].node)->value,true,0, (yyvsp[(1) - (5)].dataType));
                                addEntryToTable(currTable, entry);
                        }
                        else if ((yyvsp[(1) - (5)].dataType) == TYPE_CHAR){
                                insertQuad((yyvsp[(4) - (5)].node)->name , NULL , "=" , (yyvsp[(2) - (5)].sval) , 0);
                                SymbolEntry* entry= createSymbolEntryWithDefaults((yyvsp[(2) - (5)].sval), var, (yyvsp[(4) - (5)].node)->value,true,0, (yyvsp[(1) - (5)].dataType));
                                addEntryToTable(currTable, entry);
                        }
                        else if ((yyvsp[(1) - (5)].dataType) == TYPE_STRING){
                                insertQuad((yyvsp[(4) - (5)].node)->name , NULL , "=" , (yyvsp[(2) - (5)].sval) , 0);
                                SymbolEntry* entry= createSymbolEntryWithDefaults((yyvsp[(2) - (5)].sval), var, (yyvsp[(4) - (5)].node)->value,true,0, (yyvsp[(1) - (5)].dataType));
                                addEntryToTable(currTable, entry);
                        }
                        (yyval.sval) = (yyvsp[(2) - (5)].sval);

                    
                }
                else{
                        printf("Error: Data Type Mismatch\n");
                }
                }
                else {
                        printf("Error: Variable already declared\n");
                }

            
            }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 727 "parser.y"
    {printf("Assign Expression\n");}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 731 "parser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 732 "parser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 735 "parser.y"
    { 
                                Node *node= createCharNode((yyvsp[(1) - (1)].cval), scope , tempCount , true);
                                (yyval.node) = node;
                                printf("Char: %c\n", (yyvsp[(1) - (1)].cval));
                        }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 740 "parser.y"
    { 
                                Node *node= createStringNode((yyvsp[(1) - (1)].sval), scope, tempCount , true);
                                (yyval.node) = node;
                                printf("String: %s\n", (yyvsp[(1) - (1)].sval));
                        }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 748 "parser.y"
    {
                        Node *node= createIntNode((yyvsp[(1) - (1)].ival) , scope , tempCount , true);
                        (yyval.node) = node; 
                        printf("Integer: %d\n", (yyvsp[(1) - (1)].ival));
                }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 753 "parser.y"
    {
                                Node *node= createDoubleNode((yyvsp[(1) - (1)].dVal), scope , tempCount , true);
                                (yyval.node) = node;
                                printf("Double: %f\n", (yyvsp[(1) - (1)].dVal));
                        }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 758 "parser.y"
    {
                SymbolEntry *entry = getentryfromalltables(currTable, (yyvsp[(1) - (1)].sval));
                if(entry != NULL && entry->isInitialized){
                        printf("Identifier:%s intialized %d \n", (yyvsp[(1) - (1)].sval) , entry->isInitialized ? 1 : 0);
                        Node* node = createIDNode((yyvsp[(1) - (1)].sval), scope, entry->type);
                        node->value = entry->value;
                        (yyval.node) = node;
                }
                else{
                        printf("Error: Variable not declared or intializeddd\n");
                }
                
        }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 771 "parser.y"
    {
                        Node *node= createBoolNode((yyvsp[(1) - (1)].bVal), scope , tempCount , true);
                        (yyval.node) = node;
                
        }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 778 "parser.y"
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

  case 89:

/* Line 1455 of yacc.c  */
#line 802 "parser.y"
    { 
                if((yyvsp[(2) - (2)].node)->dataType == TYPE_INT)
                {
                        tempCount++;
                        Node *node= createIntNode(-(yyvsp[(2) - (2)].node)->value.iVal, scope , tempCount , false);
                        insertQuad(NULL , (yyvsp[(2) - (2)].node)->name , "-" , node->name , 0);
                        (yyval.node) = node;
                }
                else if((yyvsp[(2) - (2)].node)->dataType == TYPE_DOUBLE)
                {
                        tempCount++;
                        Node *node= createDoubleNode(-(yyvsp[(2) - (2)].node)->value.dVal, scope , tempCount , false);
                        insertQuad(NULL , (yyvsp[(2) - (2)].node)->name , "-" , node->name , 0);
                        (yyval.node) = node;
                }
                else {
                        printf("Error: ERROORR");
                }
        }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 821 "parser.y"
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

  case 91:

/* Line 1455 of yacc.c  */
#line 847 "parser.y"
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

  case 92:

/* Line 1455 of yacc.c  */
#line 874 "parser.y"
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

  case 93:

/* Line 1455 of yacc.c  */
#line 900 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 901 "parser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 906 "parser.y"
    {printf("Int Type\n");
        (yyval.dataType) = TYPE_INT;
        }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 909 "parser.y"
    {printf("Double Type\n");
        (yyval.dataType) = TYPE_DOUBLE;
        }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 912 "parser.y"
    {printf("Bool Type \n");
        (yyval.dataType) = TYPE_BOOL;
        }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 915 "parser.y"
    {printf("Char Type\n");
        (yyval.dataType) = TYPE_CHAR;
        }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 918 "parser.y"
    {printf("String Type\n");
        (yyval.dataType) = TYPE_STRING;
        }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 921 "parser.y"
    {printf("Void Type\n");
        (yyval.dataType) = TYPE_VOID;
        }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 927 "parser.y"
    {
                int flag = 1;
                SymbolEntry *entry = getentryfromalltables(currTable, (yyvsp[(1) - (2)].sval));
                if(entry != NULL && ((entry->isInitialized && entry->kind != constant) || entry->kind == param) ){
                        if (entry->type == TYPE_INT || entry->type == TYPE_DOUBLE){
                                insertQuad(NULL, NULL , "++" , (yyvsp[(1) - (2)].sval) , 0);
                        }
                }
                else {
                        printf("Error: Variable not declared and constanttttt\n");
                }
        }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 939 "parser.y"
    {
                int flag = 1;
                SymbolEntry *entry = getentryfromalltables(currTable, (yyvsp[(1) - (2)].sval));
                if(entry != NULL && ((entry->isInitialized && entry->kind != constant) || entry->kind == param) ){
                        if (entry->type == TYPE_INT || entry->type == TYPE_DOUBLE){
                               insertQuad(NULL, NULL , "--" , (yyvsp[(1) - (2)].sval) , 0);        
                        }

                }
                else {
                        printf("Error: Variable not declared\n");
                }
        }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 952 "parser.y"
    {
                int flag = 1;
                SymbolEntry *entry = getentryfromalltables(currTable, (yyvsp[(2) - (2)].sval));
                if(entry != NULL && ((entry->isInitialized && entry->kind != constant) || entry->kind == param) ){
                        if (entry->type == TYPE_INT || entry->type == TYPE_DOUBLE){                    
                                insertQuad(NULL, NULL , "++" , (yyvsp[(2) - (2)].sval) , 0);
                        }
                }
                else {
                        printf("Error: Variable not declared %d\n");
                }
        }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 964 "parser.y"
    {
                int flag = 1;
                SymbolEntry *entry = getentryfromalltables(currTable, (yyvsp[(2) - (2)].sval));
                if(entry != NULL && ((entry->isInitialized && entry->kind != constant) || entry->kind == param)){
                        if (entry->type == TYPE_INT || entry->type == TYPE_DOUBLE){
                                insertQuad(NULL, NULL , "--" , (yyvsp[(2) - (2)].sval) , 0);
                        }
                        
                }
                else {
                        printf("Error: Variable not declared\n");
                }
        }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 980 "parser.y"
    {  
                        (yyval.sval) = "=";       
                }
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 983 "parser.y"
    {
                        (yyval.sval) = "+=";
                        }
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 986 "parser.y"
    {
                (yyval.sval) = "-=";
        }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 989 "parser.y"
    {
                (yyval.sval) = "*=";
        }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 992 "parser.y"
    {
                (yyval.sval) = "/=";
        }
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 998 "parser.y"
    {
                SymbolEntry *entry = getentryfromalltables(currTable, (yyvsp[(1) - (3)].sval));
                if(entry != NULL && entry->kind != constant){
                        if (entry->type == (yyvsp[(3) - (3)].node)->dataType)
                        {
                                int flage = 1;
                                if((yyvsp[(2) - (3)].sval) == "="){
                                        insertQuad((yyvsp[(3) - (3)].node)->name , NULL , "=" , (yyvsp[(1) - (3)].sval) , 0);
                               
                                }           
                                else if((yyvsp[(2) - (3)].sval) == "+=" && entry->isInitialized){
                                        insertQuad((yyvsp[(1) - (3)].sval),(yyvsp[(3) - (3)].node)->name  , "+" , (yyvsp[(1) - (3)].sval) , 0);
                               
                                }
                                else if((yyvsp[(2) - (3)].sval) == "-=" && entry->isInitialized){
                                        insertQuad( (yyvsp[(1) - (3)].sval) ,(yyvsp[(3) - (3)].node)->name  , "-" , (yyvsp[(1) - (3)].sval) , 0);
                                
                                }
                                else if((yyvsp[(2) - (3)].sval) == "*=" && entry->isInitialized){
                                        insertQuad((yyvsp[(1) - (3)].sval) , (yyvsp[(3) - (3)].node)->name  , "*" , (yyvsp[(1) - (3)].sval) , 0);
                                
                                }
                                else if((yyvsp[(2) - (3)].sval) == "/=" && entry->isInitialized){
                                        insertQuad((yyvsp[(1) - (3)].sval) , (yyvsp[(3) - (3)].node)->name  , "/" , (yyvsp[(1) - (3)].sval) , 0);
                                }
                                else {
                                        flage=0;
                                        printf("Error: Variable not declared\n");
                                }
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
#line 3109 "y.tab.c"
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
#line 1038 "parser.y"


Node * checkValueNotEmpty(Node* node){
        Node *boolNode;
        if(node->dataType == TYPE_INT ){
                if(node->value.iVal != 0){
                        boolNode = createBoolNode(true, scope , tempCount , true);
                }
                else{
                        boolNode = createBoolNode(false, scope, tempCount , true);
                }
        }
        else if(node->dataType == TYPE_DOUBLE){
                if(node->value.dVal != 0){
                        boolNode = createBoolNode(true, scope, tempCount , true);
                }
                else{
                        boolNode = createBoolNode(false, scope, tempCount , true);
                }
        }
        else if(node->dataType == TYPE_CHAR){
                if(node->value.cVal ){
                        boolNode = createBoolNode(true, scope, tempCount , true);
                }
                else{
                        boolNode = createBoolNode(false, scope , tempCount , true);
                }
        }
        else if(node->dataType == TYPE_STRING){
                if(node->value.strVal){
                        boolNode = createBoolNode(true, scope, tempCount , true);
                }
                else{
                        boolNode = createBoolNode(false, scope, tempCount , true);
                }
        }
        return boolNode;
}

Node * handleConditionalExpression(Node * node){
        Node * boolNode;
        if(node->dataType == TYPE_BOOL){
                return node;
        }
        else
        {
                if(node->nodeType == NODE_CONST){
                        boolNode = checkValueNotEmpty(node);
                }
                else if (node->nodeType == NODE_ID)
                {
                        SymbolEntry *entry = getentryfromalltables(currTable, node->name);
                        if(entry != NULL && entry->isInitialized){
                                boolNode = checkValueNotEmpty(node);
                                boolNode->name = node->name;
                        }
                        else{
                                printf("Error: Variable not declared or intialized\n");
                        }
                }
        }
        return boolNode;
}

Node * handleConditionalComparison(Node* first , Node* second , char* oper){
        Node * boolNode;
        if(first->dataType == second->dataType && first->initialized && second->initialized){ 
                if(strcmp(oper, "==") == 0)
                {   
                        if(first->dataType == TYPE_INT)
                        {
                                if(first->value.iVal == second->value.iVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope , tempCount , false);
                                        insertQuad(first->name , second->name , "==" , boolNode->name , 0);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                        insertQuad(first->name , second->name , "==" , boolNode->name , 0);
                                }
                        }
                        else if(first->dataType == TYPE_DOUBLE)
                        {
                                if(first->value.dVal == second->value.dVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope , tempCount , false);
                                        insertQuad(first->name , second->name , "==" , boolNode->name , 0);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                        insertQuad(first->name , second->name , "==" , boolNode->name , 0);
                                }
                        }
                        else if(first->dataType == TYPE_CHAR)
                        {
                                if(strcmp(first->value.cVal, second->value.cVal) == 0)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , "==" , boolNode->name , 0);
                        }
                        else if(first->dataType == TYPE_STRING)
                        {
                                if(strcmp(first->value.strVal, second->value.strVal) == 0)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , "==" , boolNode->name , 0);
                        }
                        
                }
                else if(strcmp(oper, ">") == 0)
                {
                        if(first->dataType == TYPE_INT)
                        {
                                if(first->value.iVal > second->value.iVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , ">" , boolNode->name , 0);
                        }
                        else if(first->dataType == TYPE_DOUBLE)
                        {
                                if(first->value.dVal > second->value.dVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , ">" , boolNode->name , 0);
                        }
                }
                else if(strcmp(oper, "<") == 0)
                {
                        if(first->dataType == TYPE_INT)
                        {
                                if(first->value.iVal < second->value.iVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , "<" , boolNode->name , 0);
                        }
                        else if(first->dataType == TYPE_DOUBLE)
                        {
                                if(first->value.dVal < second->value.dVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , "<" , boolNode->name , 0);
                        }
                }
                else if(strcmp(oper, ">=") == 0){
                        if(first->dataType == TYPE_INT)
                        {
                                if(first->value.iVal >= second->value.iVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , ">=" , boolNode->name , 0);
                        }
                        else if(first->dataType == TYPE_DOUBLE)
                        {
                                if(first->value.dVal >= second->value.dVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , ">=" , boolNode->name , 0);
                        }
                }
                else if(strcmp(oper, "<=") == 0){
                        if(first->dataType == TYPE_INT)
                        {

                                if(first->value.iVal <= second->value.iVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , "<=" , boolNode->name , 0);
                        }
                        else if(first->dataType == TYPE_DOUBLE)
                        {
                                if(first->value.dVal <= second->value.dVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , "<=" , boolNode->name , 0);
                        }
                }
                else if(strcmp(oper, "!=") == 0){
                        if(first->dataType == TYPE_INT)
                        {
                                if(first->value.iVal != second->value.iVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , "!=" , boolNode->name , 0);
                        }
                        else if(first->dataType == TYPE_DOUBLE)
                        {
                                if(first->value.dVal != second->value.dVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , "!=" , boolNode->name , 0);
                        }
                        else if(first->dataType == TYPE_CHAR)
                        {
                                if(strcmp(first->value.cVal, second->value.cVal) != 0)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , "!=" , boolNode->name , 0);
                        }
                        else if(first->dataType == TYPE_STRING)
                        {
                                if(strcmp(first->value.strVal, second->value.strVal) != 0)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , "!=" , boolNode->name , 0);
                        }
                }
        }
        return boolNode;
}

void handleFunctionParameters(SymbolEntry ** params , Node** nodes , int argCount){
        for(int j = 0 ; j < argCount ; j++)
        {
             if(params[j]->type == nodes[j]->dataType){
                        if(params[j]->type == TYPE_INT){
                                insertQuad(nodes[j]->name , NULL , "=" , params[j]->name , 0);
                        }
                        else if(params[j]->type == TYPE_DOUBLE){
                                insertQuad(nodes[j]->name , NULL , "=" , params[j]->name , 0);
                        }
                        else if(params[j]->type == TYPE_BOOL){
                                insertQuad(nodes[j]->name , NULL , "=" , params[j]->name , 0);
                        }
                        else if(params[j]->type == TYPE_CHAR){
                                insertQuad(nodes[j]->name , NULL , "=" , params[j]->name , 0);
                        }
                        else if(params[j]->type == TYPE_STRING){
                                insertQuad(nodes[j]->name , NULL , "=" , params[j]->name , 0);
                        }
                }
                else{
                        printf("Error: Data Type Mismatch\n");
                }
        }
}

char *concatenateStrings(char *str1, char *str2){
        char *result = malloc(strlen(str1) + strlen(str2) + 1);
        strcpy(result, str1);
        strcat(result, str2);
        return result;
}

int yyerror(char *s) {
    fprintf(stderr, "Error:  %s %d\n", s , yylineno- 1);
    return 1;
}

int main(int argc, char **argv) {
        initialize();
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
        printTable(globalTable , false);
        printQuadrables();
        QuadrablesToAssembly();
        return 0;
    } else {
        printf("Parsing failed\n");
        return 1;
    }
}

