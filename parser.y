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

%token <sval> INT_TYPE
%token <sval> DOUBLE_TYPE
%token <sval> CHAR_TYPE
%token <sval> BOOL_TYPE
%token <sval> STRING_TYPE
%token <sval> VOID
%token <ival> INTEGER
%token <dVal> DOUBLE
%token <cval> CHAR
%token <bVal> BOOL
%token <sval> IDENTIFIER
%token SEMICOLON
%token CONST
%token INC
%token DEC
%token <op> EQU ADD_EQ SUB_EQ MULT_EQ DIV_EQ

%type <ival> expression assign_expression
%type <op> assign_operation
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
        INT_TYPE
      | DOUBLE_TYPE
      | BOOL_TYPE
      | CHAR_TYPE
      | STRING_TYPE
      | VOID
      ;

unary_expression:
        IDENTIFIER INC
      | IDENTIFIER DEC
      | INC IDENTIFIER
      | DEC IDENTIFIER
      ;

assign_operation:
        EQU        
      | ADD_EQ            
      | SUB_EQ            
      | MULT_EQ
      | DIV_EQ
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
