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

%token <sval> INT_TYPE DOUBLE_TYPE CHAR_TYPE BOOL_TYPE STRING_TYPE 
%token <sval> VOID
%token <ival> INTEGER
%token <dVal> DOUBLE
%token <cval> CHAR
%token <bVal> BOOL
%token <sval> STRING IDENTIFIER
%token SEMICOLON
%token CONST
%token INC
%token DEC
%token <op> EQU ADD_EQ SUB_EQ MULT_EQ DIV_EQ
%token IF ELSE FOR WHILE SWITCH CASE BREAK CONTINUE RETURN

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
        data_type IDENTIFIER SEMICOLON         
        | data_type IDENTIFIER EQU expression SEMICOLON {
                printf("Declared: %s\n", $2);
            }
        | CONST data_type IDENTIFIER EQU expression SEMICOLON
        | data_type IDENTIFIER EQU unary_expression SEMICOLON                   
        | assign_expression SEMICOLON 
                  
        ;

        
expression:
        /* Terminals */
        INTEGER     { $$ = $1; }
        | DOUBLE      { /*printf("Double value: %f\n", $1);*/ $$ = $1; }
        | IDENTIFIER  { printf("Variable: %s\n", $1); $$ = 0; } // You can assign a value here or do variable lookup
        | STRING      { /*printf("String \"%s\" declared\n", $1);*/ $$ = 1; }
        | CHAR        { /*printf("Char \'%c\' declard\n", $1);*/ $$ = 1; }
        | BOOL        { /*printf("Bool %d declared\n", $1);*/ $$ = $1; }
        | expression '+' expression { $$ = $1 + $3;  printf("%d\n", $1 + $3); }
        | expression '-' expression { $$ = $1 - $3; }
        | expression '*' expression { $$ = $1 * $3; }
        | expression '/' expression { if ($3 == 0) { yyerror("Division by zero"); } $$ = $1 / $3; }
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
