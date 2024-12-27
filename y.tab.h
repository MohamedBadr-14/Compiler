
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 24 "parser.y"

    int ival;    // Integer values
    double dVal; // Double values
    char *sval;  // String values (if needed)
    bool bVal;
    char* op;
    char cval;
    char*semi;



/* Line 1676 of yacc.c  */
#line 168 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


