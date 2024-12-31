
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

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 174 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


