%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Node.h"
#include "symboltable.h"
#include "symbolentry.h"
#include "quad.h"


extern int yylineno;
int yylex(void);
int yyerror(char *s);
//read from text file
extern FILE *yyin;
//symbol table
SymbolTable *globalTable;
SymbolTable *currTable;
SymbolTable *tempTable;

int scope = 0;
// extern int yylineno;
//symbol entry
int tempCount = 0;
%}

%union {
    Node* node;
    int ival;    // Integer values
    double dVal; // Double values
    char *sval;  // String values (if needed)
    bool bVal;
    char* op;
    char * cval;
    char*semi;
    enum DataType dataType;
}

%token INT_TYPE
%token DOUBLE_TYPE
%token CHAR_TYPE
%token  BOOL_TYPE
%token STRING_TYPE
%token VOID
%token <bVal> BOOLEAN

%token <ival> INTEGER
%token <dVal> DOUBLE
%token <cval> CHAR
%token <sval> STRING
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

%type <node> expression assign_expression
%type <sval>  assign_operation
%type <dataType> data_type

%left INC DEC LT GT LTE GTE EQ NEQ AND OR NOT PLUS MINUS MULT DIV
%right EQU ADD_EQ SUB_EQ MULT_EQ DIV_EQ
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

program:

        start   statements  
        ;
start:{
        printf("Start\n");
               globalTable = createSymbolTable("global",scope, NULL);
                                    currTable = globalTable;

        } ;        

statements:
        statements statement 
        | statement    
        ;

statement:
        one_line_statement 
        | scoped_statement 
        ;

scoped_statement:
        start_scope  statements end_scope
        ;
start_scope:
        LEFT_CURLY {printf("Start Scope\n");
        scope++;
        tempTable = createSymbolTable("local",scope, currTable);
        addChildToTable(currTable, tempTable);
        currTable = tempTable;
        }
        ;
end_scope:
        RIGHT_CURLY {printf("End Scope\n");
        scope--;
        currTable = currTable->parent;
        }

        
        
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
        SWITCH LEFT_ROUND expression RIGHT_ROUND start_scope switch_cases end_scope {printf("Switch Statement\n");}
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
        CONST data_type IDENTIFIER EQU expression SEMICOLON   {    
                SymbolEntry *entry=createSymbolEntry($3, constant, $5->value,true,0,$2, 1, 0, NULL, "");
                addEntryToTable(currTable, entry);
                insertQuad($5->name , NULL , "=" , $3 , 0);

        }
        | unary_expression SEMICOLON                   
        | data_type IDENTIFIER SEMICOLON      {printf("Data Type Identifier\n");
        Node *node= createIDNode($2, scope,$1);

        SymbolEntry* entry= createSymbolEntryWithDefaults($2, var,node->value,false,0,$1);
        addEntryToTable(currTable, entry);
        
        
        }

        ;
default_declaration:
        data_type IDENTIFIER EQU expression SEMICOLON {  
                printf(" Default Declaration Data Type: %d data type el tanyyy %d\n", $1 , $4->dataType); 
                if($1 == $4->dataType){
                        if ($1 == TYPE_INT){
                                insertQuad($4->name , NULL , "=" , $2 , 0);
                                SymbolEntry* entry= createSymbolEntryWithDefaults($2, var, $4->value,true,0, $1);
                                addEntryToTable(currTable, entry);
                        }
                        else if ($1 == TYPE_DOUBLE){
                                insertQuad($4->name , NULL , "=" , $2 , 0);
                                SymbolEntry* entry= createSymbolEntryWithDefaults($2, var, $4->value,true,0, $1);
                                addEntryToTable(currTable, entry);
                        }
                        else if ($1 == TYPE_BOOL){
                                insertQuad($4->name , NULL , "=" , $2 , 0);
                                SymbolEntry* entry= createSymbolEntryWithDefaults($2, var, $4->value,true,0, $1);
                                addEntryToTable(currTable, entry);
                        }
                        else if ($1 == TYPE_CHAR){

                                SymbolEntry* entry= createSymbolEntryWithDefaults($2, var, $4->value,true,0, $1);
                                addEntryToTable(currTable, entry);
                        }
                        else if ($1 == TYPE_STRING){
                                SymbolEntry* entry= createSymbolEntryWithDefaults($2, var, $4->value,true,0, $1);
                                addEntryToTable(currTable, entry);
                        }

                    
                }
                else{
                        printf("Error: Data Type Mismatch\n");
                }

            
            }
        | assign_expression SEMICOLON           {printf("Assign Expression\n");}
        ;

func_call:
        IDENTIFIER LEFT_ROUND RIGHT_ROUND
        | IDENTIFIER LEFT_ROUND func_call_parameter RIGHT_ROUND
        ;

expression:
        INTEGER     {
                        Node *node= createIntNode($1 , scope , tempCount , true);
                        $$ = node; 
                        printf("Integer: %d\n", $1);
                }
        | DOUBLE      { 
                                Node *node= createDoubleNode($1, scope , tempCount , true);
                                $$ = node;
                                printf("Double: %f\n", $1);
                        }
        | CHAR          { 
                                Node *node= createCharNode($1, scope , tempCount , true);
                                $$ = node;
                                printf("Char: %c\n", $1);
                        }
        | STRING        { 
                                Node *node= createStringNode($1, scope, tempCount , true);
                                $$ = node;
                                printf("String: %s\n", $1);
                        }
        | IDENTIFIER {
        SymbolEntry *entry = getentryfromalltables(currTable, $1);
        printf("Identifier:%s intialized %d \n", $1 , entry->isInitialized ? 1 : 0);
        if(entry != NULL && entry->isInitialized){
                Node* node = createIDNode($1, scope, entry->type);
                node->value = entry->value;
                $$ = node;
        }
        else{
                printf("Error: Variable not declared or intialized\n");
        }
        
        }
        | BOOLEAN {

     
                        Node *node= createBoolNode($1, scope);
                        $$ = node;
                

}
 
       
  | expression PLUS expression {
        if ($1->dataType == $3->dataType){
                if ($1->dataType == TYPE_INT){
                        tempCount++;
                        Node *node= createIntNode($1->value.iVal+ $3->value.iVal, scope , tempCount , false);
                        insertQuad($1->name , $3->name , "+" , node->name , 0);
                        $$ = node;
                }
                else if ($1->dataType == TYPE_DOUBLE){
                        tempCount++;
                        Node *node= createDoubleNode($1->value.dVal+ $3->value.dVal, scope , tempCount , false);
                        insertQuad($1->name , $3->name , "+" , node->name , 0);
                        $$ = node;
                }
                else{
                        printf("Error: ERROORR");
                }
        }
        else{
                printf("Error: Data Type Mismatch\n");
        }

     
          }
  | expression MINUS expression { 
        if($1->dataType == $3->dataType)
        {
                if($1->dataType == TYPE_INT)
                {
                        tempCount++;
                        Node *node= createIntNode($1->value.iVal- $3->value.iVal, scope , tempCount , false);
                        insertQuad($1->name , $3->name , "-" , node->name , 0);
                        $$ = node;
                }
                else if($1->dataType == TYPE_DOUBLE)
                {
                        tempCount++;
                        Node *node= createDoubleNode($1->value.dVal- $3->value.dVal, scope , tempCount , false);
                        insertQuad($1->name , $3->name , "-" , node->name , 0);
                        $$ = node;
                }
                else {
                        printf("Error: ERROORR");
                }
        }
        else
        {
                printf("Error: Data Type Mismatch\n");
        }
   }
  | expression MULT expression {     
        if($1->dataType == $3->dataType)
        {
                if($1->dataType == TYPE_INT)
                {
                        tempCount++;
                        Node *node= createIntNode($1->value.iVal* $3->value.iVal, scope , tempCount , false);
                        insertQuad($1->name , $3->name , "*" , node->name , 0);
                        $$ = node;
                }
                else if($1->dataType == TYPE_DOUBLE)
                {
                        tempCount++;
                        Node *node= createDoubleNode($1->value.dVal* $3->value.dVal, scope , tempCount , false);
                        insertQuad($1->name , $3->name , "*" , node->name , 0);
                        $$ = node;
                }
                else {
                        printf("Error: ERROORR");
                }
        }
        else
        {
                printf("Error: Data Type Mismatch\n");
        }

 }
  | expression DIV expression { 
        if($1->dataType == $3->dataType )
        {
                if($1->dataType == TYPE_INT && $3->value.iVal != 0)
                {
                        tempCount++;
                        Node *node= createIntNode($1->value.iVal/ $3->value.iVal, scope, tempCount , false);
                        insertQuad($1->name , $3->name , "/" , node->name , 0);
                        $$ = node;
                }
                else if($1->dataType == TYPE_DOUBLE && $3->value.dVal != 0)
                {
                        tempCount++;
                        Node *node= createDoubleNode($1->value.dVal/ $3->value.dVal, scope , tempCount , false);
                        insertQuad($1->name , $3->name , "/" , node->name , 0);
                        $$ = node;
                }
                else {
                        printf("Error: ERROORR");
                }
        }
        else
        {
                printf("Error: Data Type Mismatch\n");
        }
        }
  | LEFT_ROUND expression RIGHT_ROUND { $$ = $2; }
  | func_call {printf("Function Call\n");}
;


data_type:
        INT_TYPE        {printf("Int Type\n");
        $$ = TYPE_INT;
        }
      | DOUBLE_TYPE    {printf("Double Type\n");
        $$ = TYPE_DOUBLE;
        }
      | BOOL_TYPE     {printf("Bool Type \n");
        $$ = TYPE_BOOL;
        }
      | CHAR_TYPE    {printf("Char Type\n");
        $$ = TYPE_CHAR;
        }
      | STRING_TYPE {printf("String Type\n");
        $$ = TYPE_STRING;
        }
      | VOID         {printf("Void Type\n");
        $$ = TYPE_VOID;
        }
      ;

unary_expression:
        IDENTIFIER INC {
                int flag = 1;
                SymbolEntry *entry = getentryfromalltables(currTable, $1);
                if(entry != NULL && entry->isInitialized && entry->kind != constant){
                        if (entry->type == TYPE_INT){
                                entry->value.iVal++;
                                
                        }
                        else if (entry->type == TYPE_DOUBLE){
                                entry->value.dVal++;
                        }
                        else {
                                flag = 0;
                                printf("Error: Data Type Mismatch\n");
                        }
                        if(flag){
                                SymbolEntry *newEntry = createSymbolEntryWithDefaults(entry->name, entry->kind, entry->value,true, 0, entry->type);
                                modifyentry(currTable, entry->name , newEntry);
                                insertQuad(NULL, NULL , "++" , $1 , 0);
                        }
                }
                else {
                        printf("Error: Variable not declared and constanttttt\n");
                }
        }
      | IDENTIFIER DEC {
                int flag = 1;
                SymbolEntry *entry = getentryfromalltables(currTable, $1);
                if(entry != NULL && entry->isInitialized && entry->kind != constant){
                        if (entry->type == TYPE_INT){
                                entry->value.iVal--;
                        }
                        else if (entry->type == TYPE_DOUBLE){
                                entry->value.dVal--;
                        }
                        else {
                                printf("Error: Data Type Mismatch\n");
                                flag = 0;
                        }
                        if(flag){
                                SymbolEntry *newEntry = createSymbolEntryWithDefaults(entry->name, entry->kind, entry->value,true, 0, entry->type);
                                modifyentry(currTable, entry->name , newEntry);
                                insertQuad(NULL, NULL , "--" , $1 , 0);        
                        }

                }
                else {
                        printf("Error: Variable not declared\n");
                }
        }
      | INC IDENTIFIER {
                int flag = 1;
                SymbolEntry *entry = getentryfromalltables(currTable, $2);
                if(entry != NULL && entry->isInitialized && entry->kind != constant){
                        if (entry->type == TYPE_INT){
                                entry->value.iVal++;
                        }
                        else if (entry->type == TYPE_DOUBLE){
                                entry->value.dVal++;
                        }
                        else {
                                printf("Error: Data Type Mismatch\n");
                                flag = 0;
                        }
                        if(flag){
                                SymbolEntry *newEntry = createSymbolEntryWithDefaults(entry->name, entry->kind, entry->value,true, 0, entry->type);
                                modifyentry(currTable, entry->name , newEntry);
                                insertQuad(NULL, NULL , "++" , $2 , 0);
                        }
                }
                else {
                        printf("Error: Variable not declared\n");
                }
        }
      | DEC IDENTIFIER {
                int flag = 1;
                SymbolEntry *entry = getentryfromalltables(currTable, $2);
                if(entry != NULL && entry->isInitialized && entry->kind != constant){
                        if (entry->type == TYPE_INT){
                                entry->value.iVal--;
                        }
                        else if (entry->type == TYPE_DOUBLE){
                                entry->value.dVal--;
                        }
                        else {
                                printf("Error: Data Type Mismatch\n");
                                flag = 0;
                        }
                        if(flag){
                                SymbolEntry *newEntry = createSymbolEntryWithDefaults(entry->name, entry->kind, entry->value, true ,0, entry->type);
                                modifyentry(currTable, entry->name , newEntry);
                                insertQuad(NULL, NULL , "--" , $2 , 0);
                        }
                        
                }
                else {
                        printf("Error: Variable not declared\n");
                }
        }
      ;

assign_operation:
        EQU     {  
                        $$ = "=";       
                } 
        | ADD_EQ  {
                        $$ = "+=";
                        }          
        | SUB_EQ  {
                $$ = "-=";
        }         
        | MULT_EQ {
                $$ = "*=";
        }
        | DIV_EQ {
                $$ = "/=";
        }
      ;

assign_expression:
        IDENTIFIER assign_operation expression {
                SymbolEntry *entry = getentryfromalltables(currTable, $1);
                if(entry != NULL && entry->kind != constant){
                        if (entry->type == $3->dataType)
                        {
                                if($2 == "="){
                                        if (entry->type == TYPE_INT){
                                                entry->value.iVal = $3->value.iVal;
                                        }
                                        else if (entry->type == TYPE_DOUBLE){
                                                entry->value.dVal = $3->value.dVal;
                                        }
                                        else if (entry->type == TYPE_BOOL){
                                                entry->value.bVal = $3->value.bVal;
                                        }
                                        else if (entry->type == TYPE_CHAR){
                                                entry->value.cVal = $3->value.cVal;
                                        }
                                        else if (entry->type == TYPE_STRING){
                                                entry->value.strVal = $3->value.strVal;
                                        }
                                        insertQuad($3->name , NULL , "=" , $1 , 0);
                               
                                }           
                                else if($2 == "+=" && entry->isInitialized){
                                        if (entry->type == TYPE_INT){
                                                entry->value.iVal += $3->value.iVal;
                                        }
                                        else if (entry->type == TYPE_DOUBLE){
                                                entry->value.dVal += $3->value.dVal;
                                        }
                                        else {
                                                printf("Error: Data Type Mismatch\n");
                                        }
                                        insertQuad($1,$3->name  , "+" , $1 , 0);
                               
                                }
                                else if($2 == "-=" && entry->isInitialized){
                                        if (entry->type == TYPE_INT){
                                                entry->value.iVal -= $3->value.iVal;
                                        }
                                        else if (entry->type == TYPE_DOUBLE){
                                                entry->value.dVal -= $3->value.dVal;
                                        }
                                        else {
                                                printf("Error: Data Type Mismatch\n");
                                        }
                                        insertQuad( $1 ,$3->name  , "-" , $1 , 0);
                                
                                }
                                else if($2 == "*=" && entry->isInitialized){
                                        if (entry->type == TYPE_INT){
                                                entry->value.iVal *= $3->value.iVal;
                                        }
                                        else if (entry->type == TYPE_DOUBLE){
                                                entry->value.dVal *= $3->value.dVal;
                                        }
                                        else {
                                                printf("Error: Data Type Mismatch\n");
                                        }
                                        insertQuad($1 , $3->name  , "*" , $1 , 0);
                                
                                }
                                else if($2 == "/=" && entry->isInitialized){
                                        if (entry->type == TYPE_INT){
                                                entry->value.iVal /= $3->value.iVal;
                                        }
                                        else if (entry->type == TYPE_DOUBLE){
                                                entry->value.dVal /= $3->value.dVal;
                                        }
                                        else {
                                                printf("Error: Data Type Mismatch\n");
                                        }
                                        insertQuad($1 , $3->name  , "/" , $1 , 0);

                                
                                }
                                else {
                                        printf("Error: Variable not declared\n");
                                }
                                SymbolEntry *newEntry = createSymbolEntryWithDefaults(entry->name, entry->kind, entry->value,true, 0, entry->type);
                                modifyentry(currTable, entry->name , newEntry);
                        }
                        else{
                                printf("Error: Data Type Mismatch\n");
                        }
                }
                else {
                        printf("Error: Variable not declared ezay geet hena\n");
                }
                }
        ;        

%%
int yyerror(char *s) {
    fprintf(stderr, "Error:  %s %d\n", s , yylineno- 1);
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
        printTable(globalTable);
        printQuadrables();
        return 0;
    } else {
        printf("Parsing failed\n");
        return 1;
    }
}
