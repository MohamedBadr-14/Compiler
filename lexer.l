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
[[\-+*/<>}:|&!^%\]]    { return *yytext;}

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


    /* Reserved Words */

"const"                     { return CONST;}

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
