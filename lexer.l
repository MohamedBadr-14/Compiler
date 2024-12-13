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

char* discard_quotes(const char* strin) {
    size_t len = strlen(strin) - 2;
    char* str = (char*)malloc(len + 1);
    for (int i = 1; i < strlen(strin) - 1; i++) {
        str[i - 1] = strin[i];
    }
    str[len] = '\0';
    return str;
}

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
DOUBLE              [0-9]+\.[0-9]+
CHAR                \'[^\']\'
STRING              \"[^\"]*\"
BOOL                true|false
IDENTIFIER          (_|{LETTER})({LETTER}|{DIGIT}|_)*


%%
    /* Operators */
[[\-+*/<>}:|&!^%\]]         { return *yytext; }

"+="                        {    
                                yylval.op = strdup(yytext);
                                return  ADD_EQ;
                            }

"++"                        {    
                                yylval.op = strdup(yytext);
                                return  INC;
                            }

"--"                        {    
                                yylval.op = strdup(yytext);
                                return  DEC;
                            }

"-="                        {    
                                yylval.op = strdup(yytext);
                                return  SUB_EQ;
                            }

"*="                        {  
                                yylval.op = strdup(yytext);
                                return  MULT_EQ;
                            }

"/="                        {    
                                yylval.op = strdup(yytext);
                                return  DIV_EQ;
                            }

"="                         { 
                                yylval.op = strdup(yytext);
                                return EQU;
                            }


    /* Reserved Words */

"const"                     { return CONST; }

";"                         { /*yylval.semi=strdup(yytext);*/ return SEMICOLON; }

    /* DataTypes and likes */
"void"                      {strcpy(currentType, yytext); return  VOID;}
"int"                       {strcpy(currentType, yytext); return INT_TYPE;}
"double"                    {strcpy(currentType, yytext); return DOUBLE_TYPE;}
"char"                      {strcpy(currentType, yytext); return CHAR_TYPE;}
"string"                    {strcpy(currentType, yytext); return STRING_TYPE;}
"bool"                      {strcpy(currentType, yytext);  return BOOL_TYPE;}

    /* Values of Types */

    /* We added single and double quotes for chars and strings respecively
    so we don't cause confusion between chars, strings, and identifiers.
    x can be matched as an identifier and as a char as well, same for xy.
    Simply we will match 'x' as char, 'xy' as string, and xy as identifier.
    I added a function discard_quotes for proper values. */

    /* We should prioritize the rules */
 
{CHAR}                      {
                                // printf("Char value: %c\n", yytext[1]);
                                yylval.cval = yytext[1];
                                return CHAR;
                            }
                            
{STRING}                    {                                                                   
                                // printf("String value: %s\n", discard_quotes(yytext));
                                yylval.sval = discard_quotes(yytext);
                                return STRING;
                            }

{BOOL}                      {                                                                   
                                // printf("String value: %s\n", discard_quotes(yytext));
                                if (strcmp(yytext, "true")) {
                                    yylval.bVal = true;
                                } else if (strcmp(yytext, "false")) {
                                    yylval.bVal = false;
                                }
                                return BOOL;
                            }

{IDENTIFIER}                {
                                // printf("CurrentType: %s ", currentType);
                                // printf("Identifier: %s \n", yytext); 
                                yylval.sval = strdup(yytext);
                                return IDENTIFIER;
                            }

{INTEGER}                   {
                                //printf("integer valueee: %s\n", yytext);
                                yylval.ival = atoi(yytext);
                                //yylval.node->iVal = atoi(yytext);
                                //printf("integer valueee: %d\n", atoi(yytext));
                                //strcpy(currentValue, yytext);
                                //yylval.node->nodeType = NODE_CONST_VALUE;
                                //printf("[lexer]:: integer value: %d", yylval.node->iVal );
                                return INTEGER;
                            }

{DOUBLE}                    {
                                // printf("String double value: %s\n", yytext);
                                // printf("Double value: %f\n", strtod(yytext, NULL));
                                yylval.dVal = strtod(yytext, NULL);
                                return DOUBLE;
                            }


%%

int yywrap(void) {
    return 1;
}
