
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
     LT = 273,
     GT = 274,
     LTE = 275,
     GTE = 276,
     EQ = 277,
     NEQ = 278,
     EQU = 279,
     ADD_EQ = 280,
     SUB_EQ = 281,
     MULT_EQ = 282,
     DIV_EQ = 283,
     PLUS = 284,
     MINUS = 285,
     MULT = 286,
     DIV = 287,
     LEFT_ROUND = 288,
     RIGHT_ROUND = 289,
     LEFT_CURLY = 290,
     RIGHT_CURLY = 291,
     IF = 292,
     ELSE = 293,
     FOR = 294,
     WHILE = 295,
     DO = 296,
     SWITCH = 297,
     CASE = 298,
     AND = 299,
     OR = 300,
     NOT = 301,
     UNKNOWN = 302,
     LOWER_THAN_ELSE = 303
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
#define LT 273
#define GT 274
#define LTE 275
#define GTE 276
#define EQ 277
#define NEQ 278
#define EQU 279
#define ADD_EQ 280
#define SUB_EQ 281
#define MULT_EQ 282
#define DIV_EQ 283
#define PLUS 284
#define MINUS 285
#define MULT 286
#define DIV 287
#define LEFT_ROUND 288
#define RIGHT_ROUND 289
#define LEFT_CURLY 290
#define RIGHT_CURLY 291
#define IF 292
#define ELSE 293
#define FOR 294
#define WHILE 295
#define DO 296
#define SWITCH 297
#define CASE 298
#define AND 299
#define OR 300
#define NOT 301
#define UNKNOWN 302
#define LOWER_THAN_ELSE 303




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 12 "parser.y"

    int ival;    // Integer values
    double dVal; // Double values
    char *sval;  // String values (if needed)
    bool bVal;
    char* op;
    char cval;
    char*semi;



/* Line 1676 of yacc.c  */
#line 160 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


