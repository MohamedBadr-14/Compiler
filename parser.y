%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int yylex(void);
int yyerror(char *s);
//read from text file
extern FILE *yyin;
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
%token SEMICOLON
%token CONST
%token INC
%token DEC 
%token <op>COMMA
%token <op> LT GT LTE GTE EQ NEQ
%token <op> EQU 
%token ADD_EQ SUB_EQ MULT_EQ DIV_EQ 
%token PLUS MINUS MULT DIV
%token LEFT_ROUND RIGHT_ROUND LEFT_CURLY RIGHT_CURLY
%token IF ELSE FOR WHILE DO SWITCH CASE
%token AND OR NOT
%token UNKNOWN COLON BREAK DEFAULT

%type <ival> expression assign_expression

%left INC DEC LT GT LTE GTE EQ NEQ AND OR NOT PLUS MINUS MULT DIV
%right EQU ADD_EQ SUB_EQ MULT_EQ DIV_EQ
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

program:
        statements 
        ;

statements:
        statements statement
        | statement
        ;

statement:
        one_line_statement 
        | scoped_statement
        ;

scoped_statement:
        LEFT_CURLY statements RIGHT_CURLY
        ;

one_line_statement:
        default_declaration {printf("defualt Declaration\n");}
        | func_statement {printf("func_statment \n");}
        | special_declaration     {printf("special Declaration\n");}
        | conditional_statement {printf("Conditional Statement\n");}
        | for_statement {printf("For Statement\n");}
        | while_statement {printf("While Statement\n");}
        | do_while_statement {printf("Do While Statement\n");}
        | func_call SEMICOLON {printf("Function Call with semi colonnnn\n");}
        | switch_statement {printf("Switch Statement\n");}
        ;

switch_statement:
        SWITCH LEFT_ROUND expression RIGHT_ROUND LEFT_CURLY switch_cases RIGHT_CURLY
        ;
switch_cases:
        switch_case
        | switch_cases switch_case
        ;
switch_case:
        CASE expression COLON statements BREAK SEMICOLON
        | CASE expression COLON BREAK SEMICOLON
        | DEFAULT COLON statements BREAK SEMICOLON
        | DEFAULT COLON  BREAK SEMICOLON
        ;

func_statement:
        data_type IDENTIFIER LEFT_ROUND RIGHT_ROUND statement {printf("Function Statement no params\n");}
        | data_type IDENTIFIER LEFT_ROUND RIGHT_ROUND SEMICOLON {printf("Function Statement no params\n");}
        | data_type IDENTIFIER LEFT_ROUND func_params RIGHT_ROUND statement {printf("Function Statement\n");}
        | data_type IDENTIFIER LEFT_ROUND func_params RIGHT_ROUND SEMICOLON {printf("Function Statement\n");}
        ;
func_params:
        data_type IDENTIFIER
        | func_params COMMA data_type IDENTIFIER    {printf("COMAAAA\n");}
        ;
func_call_parameter:
        expression
        | func_call_parameter COMMA expression
        ;

do_while_statement:
        DO statement WHILE LEFT_ROUND conditional_expression RIGHT_ROUND SEMICOLON {printf("Do While Statement\n");}
        ;
while_statement:
        WHILE LEFT_ROUND conditional_expression RIGHT_ROUND statement {printf("While Statement\n");}
        ;
for_statement:
        FOR LEFT_ROUND default_declaration  conditional_expression SEMICOLON for_step RIGHT_ROUND statement {printf("For Statement\n");}
        ;

for_step:
        assign_expression 
        | unary_expression
        ;
conditional_statement:
        IF LEFT_ROUND conditional_if RIGHT_ROUND statement %prec LOWER_THAN_ELSE {printf("If Statement\n");}
        | IF LEFT_ROUND conditional_if RIGHT_ROUND statement ELSE statement {printf("If Else Statement\n");}
        ;

conditional_if:
        conditional_expression          {printf("Conditional Expression\n");}
        | conditional_expression AND conditional_if
        | conditional_expression OR conditional_if
        | NOT conditional_expression
        ;

conditional_expression:
        expression
        | expression LT expression      {printf("Less Than\n");}
        | expression GT expression      {printf("Greater Than\n");}
        | expression LTE expression
        | expression GTE expression
        | expression EQ expression
        | expression NEQ expression
        | BOOL
        ;

special_declaration:
        CONST data_type IDENTIFIER EQU expression SEMICOLON   
        | unary_expression SEMICOLON                   
        | data_type IDENTIFIER SEMICOLON                
        ;
default_declaration:
        data_type IDENTIFIER EQU expression SEMICOLON {
                printf("Declared: %s = %d\n", $2, $4);
            }
        | assign_expression SEMICOLON           {printf("Assign Expression\n");}
        ;

func_call:
        IDENTIFIER LEFT_ROUND RIGHT_ROUND
        | IDENTIFIER LEFT_ROUND func_call_parameter RIGHT_ROUND
        ;

expression:
    INTEGER     { $$ = $1; 
                printf("Integer: %d\n", $1);
                }
  | IDENTIFIER { printf("Variable: %s\n", $1); $$ = 0; } // You can assign a value here or do variable lookup
  | expression PLUS expression { $$ = $1 + $3; }
  | expression MINUS expression { $$ = $1 - $3; }
  | expression MULT expression { $$ = $1 * $3; }
  | expression DIV expression { $$ = 0; }
  | LEFT_ROUND expression RIGHT_ROUND { $$ = $2; }
  | func_call {printf("Function Call\n");}
;


data_type:
        INT_TYPE        {printf("Int\n");}
      | DOUBLE_TYPE
      | BOOL_TYPE
      | CHAR_TYPE
      | STRING_TYPE
      | VOID
      ;

unary_expression:
        IDENTIFIER INC {printf("Increment: %s\n", $1);}
      | IDENTIFIER DEC
      | INC IDENTIFIER
      | DEC IDENTIFIER
      ;

assign_operation:
        EQU       {  
                    printf("= EQUALLLLL \n");
                    } 
      | ADD_EQ            
      | SUB_EQ            
      | MULT_EQ
      | DIV_EQ
      ;

assign_expression:
        IDENTIFIER assign_operation expression {
            printf("Assignment:");
        }
        ;

%%
int yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 1;
}

int main(int argc, char **argv) {
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
        return 0;
    } else {
        printf("Parsing failed\n");
        return 1;
    }
}
