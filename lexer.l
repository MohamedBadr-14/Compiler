%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#include "y.tab.h"
int multiline_comment_start = 0;
char currentType[32];
char currentID[32];
char currentValue[32]; //int,char,double,bool
char currentOp[10];
int globalScope = 0;





%}

%{
/////////////////////////////////////////////////////////
//                  Definitions                        //
/////////////////////////////////////////////////////////
%}

%option yylineno

LETTER              [a-zA-Z]
INTEGER             [0-9]+
DIGIT               [0-9]

IDENTIFIER          (_|{LETTER})({LETTER}|{DIGIT}|_)*


%%
    /* Operators */
"+"    { return PLUS; }
"-"    { return MINUS; }
"*"    { return MULT; }
"/"    { return DIV; }
    /*UNKNOWNS */
"\\"     { return UNKNOWN; }
"%"     { return UNKNOWN; }
"^"     { return UNKNOWN; }
"|"     { return UNKNOWN; }
"&"     { return UNKNOWN; }
"~"     { return UNKNOWN; }
"<<"    { return UNKNOWN; }
">>"    { return UNKNOWN; }
"?"     { return UNKNOWN; }
"<>"    { return UNKNOWN; }

"+="                         {
                                
                                yylval.op = strdup(yytext);
                                return  ADD_EQ;}
"++"                         {
                                
                                yylval.op = strdup(yytext);
                                return  INC;}
"--"                         {
                                
                                yylval.op = strdup(yytext);
                                return  DEC;}
"-="                         {
                                
                                yylval.op = strdup(yytext);
                                return  SUB_EQ;
                            }
"*="                         {
                                
                                yylval.op = strdup(yytext);
                                return  MULT_EQ;
                            }
"/="                         {
                                
                                yylval.op = strdup(yytext);
                                return  DIV_EQ;
                            }



"="                         {
                                
                                yylval.op = strdup(yytext);
                                return EQU;
                            }

"<"                        {
                                
                                yylval.op = strdup(yytext);
                                return LT;
                            }
">"                        {
                                
                                yylval.op = strdup(yytext);
                                return GT;
                            }
"<="                        {
                                
                                yylval.op = strdup(yytext);
                                return LTE;
                            }
">="                        {
                                
                                yylval.op = strdup(yytext);
                                return GTE;
                            }
"=="                        {
                                
                                yylval.op = strdup(yytext);
                                return EQ;
                            }
"!="                        {
                                
                                yylval.op = strdup(yytext);
                                return NEQ;
                            }
"&&"                        {
                                
                                yylval.op = strdup(yytext);
                                return AND;
                            }
"||"                        {
                                
                                yylval.op = strdup(yytext);
                                return OR;
                            }


"!"                        {
                                
                                yylval.op = strdup(yytext);
                                return NOT;
                            }
","                        {
                                
                                yylval.op = strdup(yytext);
                                return COMMA;
                            }


    /* Brackets */

"("                         { return LEFT_ROUND;}
")"                         { return RIGHT_ROUND;}
"{"                         { return LEFT_CURLY;}
"}"                         { return RIGHT_CURLY;}
":"                         { return COLON; }

    /* Reserved Words */

"const"                     { return CONST;}
"if"                        { return IF;}
"else"                      { return ELSE;}
"for"                       { return FOR;}
"while"                     { return WHILE;}
"do"                        { return DO;}
"switch"                    { return SWITCH;}
"case"                      { return CASE;}
"break"                     { return BREAK;}
"default"                   { return DEFAULT;}


";"                         { /*yylval.semi=strdup(yytext);*/ return SEMICOLON;}

    /* DataTypes and likes */
"void"                     {strcpy(currentType, yytext); return  VOID;}
"int"                      {strcpy(currentType, yytext); return INT_TYPE;}
"double"                   {strcpy(currentType, yytext); return DOUBLE_TYPE;}
"char"                     {strcpy(currentType, yytext); return CHAR_TYPE;}
"string"                   {strcpy(currentType, yytext); return STRING_TYPE;}
"bool"                     {strcpy(currentType, yytext);  return BOOL_TYPE;}

    /* Values of Types */

{IDENTIFIER}                 {
                                // printf("CurrentType: %s ", currentType);
                                // printf("Identifier: %s \n", yytext); 
                                yylval.sval = strdup(yytext);
                                return IDENTIFIER;}
(\'.\')                      {
                                //printf("char value: %s\n", yytext);
                                yylval.cval = yytext[1];
                                strcpy(currentValue, yytext);
                                //yylval.node->cVal = yytext[1];
                                return CHAR; }
{INTEGER}                    {
                                //printf("integer valueee: %s\n", yytext);
                                yylval.ival = atoi(yytext);
                                //yylval.node->iVal = atoi(yytext);
                                //printf("integer valueee: %d\n", atoi(yytext));
                                //strcpy(currentValue, yytext);
                                //yylval.node->nodeType = NODE_CONST_VALUE;
                                //printf("[lexer]:: integer value: %d", yylval.node->iVal );
                                return INTEGER;
                            }


%%

int yywrap(void) {
    return 1;
}
