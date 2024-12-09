%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int yylex(void);
int yyerror(char *s);
%}

%union {
    int ival;    // Integer values
    double dVal; // Double values
    char *sval;  // String values (if needed)
    bool bVal;
    char* op;
    char cval;
    char*semi;
}

%token INT_TYPE
%token DOUBLE_TYPE
%token CHAR_TYPE
%token BOOL_TYPE
%token STRING_TYPE
%token VOID
%token <ival> INTEGER
%token <dVal> DOUBLE
%token <cval> CHAR
%token <bVal> BOOL
%token <sval> IDENTIFIER
%token   SEMICOLON
%token CONST
%token INC
%token DEC
%token <op> EQU
%token ADD_EQ SUB_EQ MULT_EQ DIV_EQ

%type <ival> expression assign_expression
%type<op> assign_operation
%type <sval> data_type
%left '+' '-'
%left '*' '/'
%left INC DEC
%right EQU ADD_EQ SUB_EQ MULT_EQ DIV_EQ

%%

program:
        program statement '\n'
        | statement 
        ;

statement:
        declaration
        
        ;

declaration:
        data_type IDENTIFIER EQU expression SEMICOLON {
                printf("Declared: %s = %d\n", $2, $4);
            }
        | CONST data_type IDENTIFIER EQU expression SEMICOLON   
        | unary_expression SEMICOLON                   
        | data_type IDENTIFIER SEMICOLON                
        | assign_expression SEMICOLON 
             
            
        ;

expression:
    INTEGER { $$ = $1; }
  | IDENTIFIER { printf("Variable: %s\n", $1); $$ = 0; } // You can assign a value here or do variable lookup
  | expression '+' expression { $$ = $1 + $3; }
  | expression '-' expression { $$ = $1 - $3; }
  | expression '*' expression { $$ = $1 * $3; }
  | expression '/' expression { $$ = $1 / $3; }
  | '(' expression ')' { $$ = $2; }
;

data_type:
        INT_TYPE                { $$ = "int"; }
      | DOUBLE_TYPE             { $$ = "double"; }
      | BOOL_TYPE               { $$ = "bool"; }
      | CHAR_TYPE               { $$ = "char"; }
      | STRING_TYPE             { $$ = "string"; }
      | VOID                    { $$ = NULL; }
      ;

unary_expression:
        IDENTIFIER INC
      | IDENTIFIER DEC
      | INC IDENTIFIER
      | DEC IDENTIFIER
      ;

assign_operation:
        EQU             { $$ = "="; }
      | ADD_EQ          { $$ = "+="; }  
      | SUB_EQ          { $$ = "-="; }  
      | MULT_EQ         { $$ = "*="; }
      | DIV_EQ          { $$ = "/="; }
      ;

assign_expression:
        IDENTIFIER assign_operation expression {
            printf("Assignment: %s %s %d\n", $1, $2, $3);
            $$ = $3;
        }
        ;

%%

int main(void) {
    yyparse();
    return 0;
}

int yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 1;
}
