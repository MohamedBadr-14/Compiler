%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Node.h"
#include "symboltable.h"
#include "symbolentry.h"
#include "quad.h"
#include "stack.h"


extern int yylineno;
const char* filename;
int first_sem_err = 1;
int first_syn_err = 1;

int yylex(void);
void yyerror(char *s);
//read from text file
extern FILE *yyin;
//symbol table
SymbolTable *globalTable;
SymbolTable *currTable;
SymbolTable *tempTable;


Stack ifStack;
Stack whileStack;
Stack do_whileStack;
Stack forStack;
Stack switchStack;
Node **params;
void initialize() {
        initializeStack(&ifStack);
        initializeStack(&whileStack);
        initializeStack(&do_whileStack);
        initializeStack(&forStack);
        initializeStack(&switchStack);
        params = (Node **)malloc(0);
}

void logError(const char *message, int line_num) {
        FILE *errorFile;
        if (first_sem_err) {
                errorFile = fopen("semantic_errors.txt", "w");
                fprintf(errorFile, "%s: Error at line %d: %s\n", filename, line_num, message);
                first_sem_err = 0;
        } else {
                errorFile = fopen("semantic_errors.txt", "a");
                fprintf(errorFile, "%s: Error at line %d: %s\n", filename, line_num, message);
        }
        fclose(errorFile);
        fprintf(stderr, "%s: Error at line %d: %s\n", filename, line_num, message);
        //     exit(-1);
}

//FUNCTIONS
Node * handleConditionalExpression(Node * node);
Node * handleConditionalComparison(Node * first , Node * second , char* operand);
char * concatenateStrings(char * first , char * second);
void handleFunctionParameters(SymbolEntry ** enter , Node** nodes , int argCont);

int scope = 0;
// extern int yylineno;
//symbol entry
int tempCount = 0;
int labels=0;
int while_labels=0;
int do_while_labels = 0;
int for_labels = 0;
int ifCount = 0;
int switchCount = 0;
int caseCount = 0;
int paramCount = 0;
bool isElse= false;
bool isDefault = false;
int elseCount = 0;
int popped  = 0;
int popped_while = 0;
int popped_for = 0;
char* funcName;
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

%type <node> expression assign_expression char_expression expression_statement conditional_expression conditional_if ifstatement condition_only
%type <node> while_stmt do_while_stmt for_stmt switch_statement func_begin func_stmt_params func_call
%type <sval>  assign_operation  default_declaration
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
        LEFT_CURLY start_scope statements RIGHT_CURLY end_scope
        ;
start_scope:
         {printf("Start Scope\n");
        scope++;
        tempTable = createSymbolTable("local",scope, currTable);
        addChildToTable(currTable, tempTable);
        currTable = tempTable;
        }
        ;
end_scope:
        {printf("End Scope\n");
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
        SWITCH LEFT_ROUND expression_statement {
                switchCount++;
                push(&switchStack , switchCount);
        } RIGHT_ROUND LEFT_CURLY start_scope switch_cases {
                if(!isDefault)
                {
                        char*label= concatunate('C' , caseCount);
                        insertQuad($3->name , NULL , "LABEL" , label , 0);
                        isDefault = false;
                }
        }RIGHT_CURLY end_scope { 
                int popped_switch = pop(&switchStack);
                char*label= concatunate('S' , popped_switch);
                insertQuad($3->name , NULL , "LABEL" , label , 0);

                
        }
        ;
switch_cases:
        switch_case     {
                int popped_switch = peek(&switchStack);
                char*label= concatunate('S' , popped_switch);
                insertQuad(NULL , NULL , "JMP" , label , 0);
        }
        | switch_cases switch_case 
        {
                int popped_switch = peek(&switchStack);
                char*label= concatunate('S' , popped_switch);
                insertQuad(NULL , NULL , "JMP" , label , 0);
        }
        ;
cases:
        CASE expression {
                char*label_1= concatunate('C' , caseCount);
                insertQuad(NULL , NULL , "LABEL" , label_1 , 0);
                if(!isDefault)
                {
                        caseCount++;
                        char*label= concatunate('C' , caseCount);
                        insertQuad($2->name , NULL , "JZ" , label , 0);
                }
        } COLON ;
switch_case:
        cases statements BREAK SEMICOLON //check with fouda
        | cases BREAK SEMICOLON
        | DEFAULT COLON {
                isDefault = true;
                char*label_1= concatunate('C' , caseCount);
                insertQuad(NULL , NULL , "LABEL" , label_1 , 0);
        } statements BREAK SEMICOLON
        | DEFAULT COLON {
                isDefault = true;
                char*label_1= concatunate('C' , caseCount);
                insertQuad(NULL , NULL , "LABEL" , label_1 , 0);
        } BREAK SEMICOLON
        ;

func_begin:  data_type IDENTIFIER LEFT_ROUND {
               
                printf("Data func Identifier\n");
                union Value val;
                SymbolEntry* entry= createSymbolEntryWithDefaults($2, func,val,false,0,$1); 
                addEntryToTable(currTable, entry);
                Node* node = createIDNode($2, scope, entry->type);
                funcName = $2;
                $$ = node;
        }

func_stmt_params:
       func_begin start_scope  func_params { $$ = $1; }
        ;
        

func_statement:
  
        func_begin RIGHT_ROUND{
                SymbolEntry *entry = getentryfromalltables(currTable, $1->name);
                if(entry != NULL && entry->kind == func){
                        if(entry->argCount == 0){
                                char* start = concatenateStrings( $1->name, "_START");
                                insertQuad(NULL , NULL , "LABEL" , start , 0);
                        }
                        else logError("Function is with parameters.", yylineno);
                }
                else logError("Function is not declared.", yylineno);

        } statement {
                SymbolEntry *entry = getentryfromalltables(currTable, $1->name);
                if(entry != NULL && entry->kind == func){
                        if(entry->argCount == 0){
                                char* end = concatenateStrings( $1->name, "_END");
                                insertQuad(NULL , NULL , "JMP" , end , 0);
                        }
                }
        }
        // | func_begin RIGHT_ROUND SEMICOLON {printf("Function Statement no params\n");}
        | func_stmt_params RIGHT_ROUND {
                SymbolEntry *entry = getentryfromalltables(currTable, $1->name);
                if(entry != NULL && entry->kind == func){
                                char* start = concatenateStrings( $1->name, "_START");
                                insertQuad(NULL , NULL , "LABEL" , start , 0);
                }
                else logError("Function is not declared.", yylineno);
        
        }statement end_scope  {
                SymbolEntry *entry = getentryfromalltables(currTable, $1->name);
                if(entry != NULL && entry->kind == func){
                        char* end = concatenateStrings( $1->name, "_END");
                        insertQuad(NULL , NULL , "JMP" , end , 0);
                        
                }
        }
        // | func_stmt_params RIGHT_ROUND SEMICOLON  {printf("Function Statement\n");}
        ;
func_params:
        data_type IDENTIFIER {         printf("Data Type Identifier\n");
                union Value val;
                SymbolEntry* entry= createSymbolEntryWithDefaults($2, param,val,false,0,$1); 
                addEntryToTable(currTable, entry);
                SymbolEntry* entryfunc = getentryfromalltables(currTable, funcName);
                printf("entryfunc %s\n", entryfunc->name);
                addparam(entryfunc,entry);       
                
                }
        | func_params COMMA data_type IDENTIFIER    {         printf("Data Type Identifier\n");
                union Value val;
                SymbolEntry* entry= createSymbolEntryWithDefaults($4, param,val,false,0,$3); 
                addEntryToTable(currTable, entry);
                      SymbolEntry* entryfunc = getentryfromalltables(currTable, funcName);
                addparam(entryfunc,entry);

                
                }
        ;
func_call_parameter:
        expression_statement{
                params = (Node **)realloc(params, (paramCount + 1) * sizeof(Node*));
                params[paramCount] = $1;
                paramCount++;
        }
        | func_call_parameter COMMA expression_statement{
                params = (Node **)realloc(params, (paramCount + 1) * sizeof(Node*));
                params[paramCount] = $3;
                paramCount++;
        }
        ;
func_call:
        IDENTIFIER LEFT_ROUND RIGHT_ROUND {
                SymbolEntry *entry = getentryfromalltables(currTable, $1);
                if(entry != NULL && entry->kind == func){
                        if(entry->argCount == 0){
                                printf("Function Call\n");
                                char* start = concatenateStrings( $1, "_START");
                                insertQuad(NULL , NULL , "JMP" , start , 0);
                                char* end = concatenateStrings( $1, "_END");
                                insertQuad(NULL , NULL , "LABEL" , end , 0);
                                Node* node = createIDNode($1, scope, entry->type);
                                $$ = node;

                        }
                        else logError("Function is with parameters.", yylineno);
                }
                else logError("Function is not declared.", yylineno);
        }
        | IDENTIFIER LEFT_ROUND func_call_parameter RIGHT_ROUND {
                SymbolEntry *entry = getentryfromalltables(currTable, $1);
                if(entry != NULL && entry->kind == func){
                        if(entry->argCount == paramCount){
                                handleFunctionParameters(entry->parameters , params, paramCount);
                                char* start = concatenateStrings( $1, "_START");
                                insertQuad(NULL , NULL , "JMP" , start , 0);
                                char* end = concatenateStrings( $1, "_END");
                                insertQuad(NULL , NULL , "LABEL" , end , 0);
                                Node* node = createIDNode($1, scope, entry->type);
                                printf("BADR FUNCTION CALLL %d\n" , entry->type);
                                paramCount = 0;
                                $$ = node;
                        }
                        else logError("Function is with parameters.", yylineno);
                }
                else logError("Function is not declared.", yylineno);
        }
        ;
do_while_stmt: conditional_if {
        int popped_do_while = pop(&do_whileStack);
        char*label= concatunate('D' , popped_do_while);
        insertQuad($1->name , NULL , "JZ" , label , 0);
        $$=$1;
};
do_word:
        DO      {
                do_while_labels++;
                insertQuad(NULL , NULL , "LABEL" , concatunate('D' , do_while_labels ) , 0);
                push(&do_whileStack , do_while_labels);
        }
        ;

do_while_statement:
        do_word statement WHILE LEFT_ROUND do_while_stmt RIGHT_ROUND SEMICOLON {printf("Do While Statement\n");}
        ;
while_statement:
        WHILE LEFT_ROUND while_stmt RIGHT_ROUND statement { 
                int popped_while_1 = pop(&whileStack);
                int popped_while_2 = pop(&whileStack);
                char*label_1= concatunate('W' , popped_while_1);
                char*label_2= concatunate('W' , popped_while_2);
                insertQuad(NULL , NULL , "JMP" ,label_2  , 0);
                insertQuad(NULL , NULL , "LABEL" ,label_1  , 0);

        }
        ;
while_stmt: conditional_if {
        while_labels++;
        insertQuad(NULL , NULL , "LABEL" , concatunate('W' , while_labels ) , 0);
        push(&whileStack , while_labels);
        while_labels++;
        insertQuad($1->name , NULL , "JZ" , concatunate('W' , while_labels ) , 0);
        push(&whileStack , while_labels);
        $$=$1;
};
for_statement:
        FOR LEFT_ROUND start_scope default_declaration {
                for_labels++;
                insertQuad(NULL , NULL , "LABEL" , concatunate('F' , for_labels ) , 0);
                push(&forStack , for_labels);
        } for_stmt SEMICOLON for_step RIGHT_ROUND end_scope statement 
        {
                int popped_for_2 = pop(&forStack);
                int popped_for_1 = pop(&forStack);
                char*label_1= concatunate('F' , popped_for_1);
                char*label_2= concatunate('F' , popped_for_2);
                insertQuad(NULL , NULL , "JMP" ,label_1  , 0);
                insertQuad(NULL , NULL , "LABEL" ,label_2  , 0);
        }
        ;
for_stmt:
        conditional_expression {
                for_labels++;
                insertQuad($1->name , NULL , "JZ" , concatunate('F' , for_labels ) , 0);
                push(&forStack , for_labels);
                $$=$1;
        }
for_step:
        assign_expression 
        | unary_expression
        ;
if_only:
        IF LEFT_ROUND {labels++;} ifstatement RIGHT_ROUND statement  
 
conditional_statement:
        if_only %prec LOWER_THAN_ELSE {
                popped = pop(&ifStack);
                char*label= concatunate('L' , popped);

                insertQuad(NULL , NULL , "LABEL" ,label  , 0);
        }
        | if_only ELSE {
                isElse = true;
                printf("If Statement\n");
                labels++;
                char*label_2= concatunate('L' , labels);
                popped = pop(&ifStack);
                char*label= concatunate('L' , popped);
                push(&ifStack , labels);

                insertQuad(NULL , NULL , "JMP" ,label_2 , 0);
                insertQuad(NULL , NULL , "LABEL" ,label  , 0);
                } statement  {
                        popped = pop(&ifStack);
                        char*label= concatunate('L' , popped);
                        insertQuad(NULL , NULL , "LABEL" ,label  , 0);
                }
        ;

ifstatement: conditional_if { 
        insertQuad($1->name , NULL , "JZ" , concatunate('L' , labels) , 0);
        push(&ifStack , labels);
        $$=$1;

}

conditional_if:
        conditional_expression          {
                printf("Conditional If: %s\n" , $1->name);
                $$ = $1;}
        | conditional_expression AND conditional_if { 
                tempCount++;
                Node * boolNode = createBoolNode($1->value.bVal && $3->value.bVal , scope , tempCount , false);
                insertQuad($1->name , $3->name , "&&" , boolNode->name , 0);    
                $$ = boolNode;  
                
        }
        | conditional_expression OR conditional_if
        {
                tempCount++;
                Node * boolNode = createBoolNode($1->value.bVal || $3->value.bVal , scope , tempCount , false);     
                insertQuad($1->name , $3->name , "||" , boolNode->name , 0);    
                $$ = boolNode;
        }
        ;
condition_only:
        expression LT expression       { 
                if($1->dataType == $3->dataType){
                                
                        Node * boolNode = handleConditionalComparison($1, $3, "<");
                        if (boolNode != NULL){
                                printf("LESS THAN %d\n" , boolNode->value.bVal ? 1:0);
                                $$ = boolNode;
                        }
                        else logError("", yylineno);
                }
                else logError("Data type mismatch.", yylineno);
        }
        | expression GT expression      {
                if($1->dataType == $3->dataType)
                {
                                Node * boolNode = handleConditionalComparison($1, $3, ">");
                        if (boolNode != NULL){
                                printf("Greater THAN %d\n" , boolNode->value.bVal ? 1:0);
                                $$ = boolNode;
                        }
                        else logError("", yylineno);
                }
                else logError("Data type mismatch.", yylineno);
        }
        | expression LTE expression {
                if($1->dataType == $3->dataType)
                {
                        Node * boolNode = handleConditionalComparison($1, $3, "<=");
                        if (boolNode != NULL){
                                printf("LESS THAN or equal %d\n" , boolNode->value.bVal ? 1:0);
                                $$ = boolNode;
                        }
                        else logError("", yylineno);
                }
                else logError("Data type mismatch.", yylineno);
        }
        | expression GTE expression {
                if($1->dataType == $3->dataType)
                {
                        Node * boolNode = handleConditionalComparison($1, $3, ">=");
                        if (boolNode != NULL){
                                printf("greater THAN equal %d\n" , boolNode->value.bVal ? 1:0);
                                $$ = boolNode;
                        }
                        else logError("", yylineno);
                }
                else logError("Data type mismatch.", yylineno);
        }
        | expression EQ expression {
                if($1->dataType == $3->dataType)
                {
                        Node * boolNode = handleConditionalComparison($1, $3, "==");
                        if (boolNode != NULL){
                                printf("equal  %d\n" , boolNode->value.bVal ? 1:0);
                                $$ = boolNode;
                        }
                        else logError("", yylineno);
                }
                else logError("Data type mismatch.", yylineno);
        }
        | expression NEQ expression {
               if($1->dataType == $3->dataType)
               { 
                        Node * boolNode = handleConditionalComparison($1, $3, "!=");
                        if (boolNode != NULL){
                                $$ = boolNode;
                                printf("not equal %d\n" , boolNode->value.bVal ? 1:0);
                        }
                        else logError("", yylineno);
                }
                else logError("Data type mismatch.", yylineno);
        }
        | LEFT_ROUND condition_only RIGHT_ROUND {$$ = $2;}
        | BOOL {
                Node* boolNode;
                if ($1)
                {
                        boolNode = createBoolNode(true , scope , tempCount , true);
                }
                else {
                        boolNode = createBoolNode(false , scope, tempCount , true);
                }
        };


conditional_expression:
        expression_statement            {
                if($1->nodeType == NODE_ID)
                {
                        printf("Conditional Expression\n");
                        Node * boolNode = handleConditionalExpression($1);
                if (boolNode != NULL){
                        printf("3azeemm %d\n" , boolNode->value.bVal ? 1:0);
                        $$ = boolNode;
                }
                else logError("", yylineno);
                }
                else logError("", yylineno);
        }
        | condition_only {$$=$1;}
        | NOT conditional_expression {
                tempCount++;
                Node * boolNode = createBoolNode(!$2->value.bVal , scope , tempCount , false);    
                insertQuad(NULL , $2->name , "!" , boolNode->name , 0); 
                $$ = boolNode;
        }
        ;

special_declaration:
        CONST data_type IDENTIFIER EQU expression_statement SEMICOLON   {
                SymbolEntry *entry = getentryfromalltables(currTable, $3);
                if(entry == NULL)
                {
                        if ($2 == $5->dataType){
                                if ($2 == TYPE_INT){
                                        SymbolEntry *entry=createSymbolEntry($3, constant, $5->value,true,0,$2, 1, 0, NULL, "");
                                        addEntryToTable(currTable, entry);
                                        insertQuad($5->name , NULL , "=" , $3 , 0);
                                }
                                else if ($2 == TYPE_DOUBLE){
                                        SymbolEntry *entry=createSymbolEntry($3, constant, $5->value,true,0,$2, 1, 0, NULL, "");
                                        addEntryToTable(currTable, entry);
                                        insertQuad($5->name , NULL , "=" , $3 , 0);
                                }
                                else if ($2 == TYPE_BOOL){
                                        SymbolEntry *entry=createSymbolEntry($3, constant, $5->value,true,0,$2, 1, 0, NULL, "");
                                        addEntryToTable(currTable, entry);
                                        insertQuad($5->name , NULL , "=" , $3 , 0);
                                }
                                else if ($2 == TYPE_CHAR){
                                        SymbolEntry *entry=createSymbolEntry($3, constant, $5->value,true,0,$2, 1, 0, NULL, "");
                                        addEntryToTable(currTable, entry);
                                        insertQuad($5->name , NULL , "=" , $3 , 0);
                                }
                                else if ($2 == TYPE_STRING){
                                        SymbolEntry *entry=createSymbolEntry($3, constant, $5->value,true,0,$2, 1, 0, NULL, "");
                                        addEntryToTable(currTable, entry);
                                        insertQuad($5->name , NULL , "=" , $3 , 0);
                                }
                        }
                        else logError("Data type mismatch.", yylineno);
                }
                else logError("Variable is already declared.", yylineno);

        }
        | unary_expression SEMICOLON                   
        | data_type IDENTIFIER SEMICOLON      {
                printf("Data Type Identifier\n");
                SymbolEntry * entry = getentryfromalltables(currTable, $2);
                if(entry == NULL)
                {       
                        union Value val;
                        SymbolEntry* entry= createSymbolEntryWithDefaults($2, var,val,false,0,$1); 
                        addEntryToTable(currTable, entry);
                }
                else logError("Variable is already declared.", yylineno);
        }
        ;
default_declaration:
        data_type IDENTIFIER EQU expression_statement SEMICOLON {  
                printf(" Default Declaration Data Type: %d data type el tanyyy %d\n", $1 , $4->dataType); 
                SymbolEntry *entry = getentryfromalltables(currTable, $2);
                if(entry == NULL)
                {
                        if($1 == $4->dataType){
                        if ($1 == TYPE_INT){
                                insertQuad($4->name , NULL , "=" , $2 , 0);
                                SymbolEntry* entry= createSymbolEntryWithDefaults($2, var, $4->value,true,0, $1);
                                printf("Default Declaration Data Type: %d %s %s\n", $1 , $2 , entry->isInitialized ? "true" : "false");
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
                                insertQuad($4->name , NULL , "=" , $2 , 0);
                                SymbolEntry* entry= createSymbolEntryWithDefaults($2, var, $4->value,true,0, $1);
                                addEntryToTable(currTable, entry);
                        }
                        else if ($1 == TYPE_STRING){
                                insertQuad($4->name , NULL , "=" , $2 , 0);
                                SymbolEntry* entry= createSymbolEntryWithDefaults($2, var, $4->value,true,0, $1);
                                addEntryToTable(currTable, entry);
                        }
                        $$ = $2;

                    
                }
                else logError("Data type mismatch.", yylineno);
                }
                else logError("Variable is already declared.", yylineno);

            
            }
        | assign_expression SEMICOLON           {printf("Assign Expression\n");}
        ;

expression_statement:
        expression {$$ = $1;}
        | char_expression {$$ = $1;}
        ; 
char_expression:
        CHAR            { 
                                Node *node= createCharNode($1, scope , tempCount , true);
                                $$ = node;
                                printf("Char: %c\n", $1);
                        }
        | STRING        { 
                                Node *node= createStringNode($1, scope, tempCount , true);
                                $$ = node;
                                printf("String: %s\n", $1);
                        }
                ;

expression:
        INTEGER     {
                        Node *node= createIntNode($1 , scope , tempCount , true);
                        $$ = node; 
                        printf("Integer: %d\n", $1);
                }
        | DOUBLE        {
                                Node *node= createDoubleNode($1, scope , tempCount , true);
                                $$ = node;
                                printf("Double: %f\n", $1);
                        }
        | IDENTIFIER {
                SymbolEntry *entry = getentryfromalltables(currTable, $1);
                if(entry != NULL && entry->isInitialized){
                        printf("Identifier:%s intialized %d \n", $1 , entry->isInitialized ? 1 : 0);
                        Node* node = createIDNode($1, scope, entry->type);
                        node->value = entry->value;
                        $$ = node;
                }
                else logError("Variable is undeclared or uninitialized.", yylineno);
                
        }
        | BOOLEAN {
                        Node *node= createBoolNode($1, scope , tempCount , true);
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
                else logError("Only int and double values can use this operator.", yylineno);
        }
        else logError("Data type mismatch.", yylineno);

     
        }
        | MINUS expression %prec PLUS { 
                if($2->dataType == TYPE_INT)
                {
                        tempCount++;
                        Node *node= createIntNode(-$2->value.iVal, scope , tempCount , false);
                        insertQuad(NULL , $2->name , "-" , node->name , 0);
                        $$ = node;
                }
                else if($2->dataType == TYPE_DOUBLE)
                {
                        tempCount++;
                        Node *node= createDoubleNode(-$2->value.dVal, scope , tempCount , false);
                        insertQuad(NULL , $2->name , "-" , node->name , 0);
                        $$ = node;
                }
                else logError("Only int and double values can use this operator.", yylineno);
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
                else logError("Only int and double values can use this operator.", yylineno);
        }
        else logError("Data type mismatch.", yylineno);
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
                else logError("Only int and double values can use this operator.", yylineno);
        }
        else logError("Data type mismatch.", yylineno);

        }
        | expression DIV expression { 
        if($1->dataType == $3->dataType )
        {
                if($1->dataType == TYPE_INT)
                {
                        if ($3->value.iVal == 0) logError("Division by zero.", yylineno);
                        tempCount++;
                        Node *node= createIntNode($1->value.iVal/ $3->value.iVal, scope, tempCount , false);
                        insertQuad($1->name , $3->name , "/" , node->name , 0);
                        $$ = node;
                }
                else if($1->dataType == TYPE_DOUBLE)
                {
                        if ($3->value.dVal == 0) logError("Division by zero.", yylineno);
                        tempCount++;
                        Node *node= createDoubleNode($1->value.dVal/ $3->value.dVal, scope , tempCount , false);
                        insertQuad($1->name , $3->name , "/" , node->name , 0);
                        $$ = node;
                }
                else logError("Only int and double values can use this operator.", yylineno);
        }
        else logError("Data type mismatch.", yylineno);
        }
        | LEFT_ROUND expression RIGHT_ROUND { $$ = $2; }
        | func_call {$$ = $1;}
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
                if(entry != NULL && ((entry->isInitialized && entry->kind != constant) || entry->kind == param) ){
                        entry->used = 1;
                        if (entry->type == TYPE_INT || entry->type == TYPE_DOUBLE){
                                insertQuad(NULL, NULL , "++" , $1 , 0);
                        }
                }
                else {
                        logError("Variable is undeclared or constant", yylineno);;
                }
        }
      | IDENTIFIER DEC {
                int flag = 1;
                SymbolEntry *entry = getentryfromalltables(currTable, $1);
                if(entry != NULL && ((entry->isInitialized && entry->kind != constant) || entry->kind == param) ){
                        entry->used = 1;
                        if (entry->type == TYPE_INT || entry->type == TYPE_DOUBLE){
                               insertQuad(NULL, NULL , "--" , $1 , 0);        
                        }

                }
                else {
                        logError("Variable is undeclared or constant", yylineno);
                }
        }
      | INC IDENTIFIER {
                int flag = 1;
                SymbolEntry *entry = getentryfromalltables(currTable, $2);
                if(entry != NULL && ((entry->isInitialized && entry->kind != constant) || entry->kind == param) ){
                        entry->used = 1;
                        if (entry->type == TYPE_INT || entry->type == TYPE_DOUBLE){                    
                                insertQuad(NULL, NULL , "++" , $2 , 0);
                        }
                }
                else {
                        logError("Variable is undeclared or constant", yylineno);
                }
        }
      | DEC IDENTIFIER {
                int flag = 1;
                SymbolEntry *entry = getentryfromalltables(currTable, $2);
                if(entry != NULL && ((entry->isInitialized && entry->kind != constant) || entry->kind == param)){
                        entry->used = 1;
                        if (entry->type == TYPE_INT || entry->type == TYPE_DOUBLE){
                                insertQuad(NULL, NULL , "--" , $2 , 0);
                        }
                        
                }
                else {
                        logError("Variable is undeclared or constant", yylineno);
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
                                SymbolEntry* rhs = getentryfromalltables(currTable, $3->name);
                                rhs->used = 1;
                                int flage = 1;
                                if($2 == "="){
                                        insertQuad($3->name , NULL , "=" , $1 , 0);
                               
                                }           
                                else if($2 == "+=" && entry->isInitialized){
                                        insertQuad($1,$3->name  , "+" , $1 , 0);
                               
                                }
                                else if($2 == "-=" && entry->isInitialized){
                                        insertQuad( $1 ,$3->name  , "-" , $1 , 0);
                                
                                }
                                else if($2 == "*=" && entry->isInitialized){
                                        insertQuad($1 , $3->name  , "*" , $1 , 0);
                                
                                }
                                else if($2 == "/=" && entry->isInitialized){
                                        insertQuad($1 , $3->name  , "/" , $1 , 0);
                                }
                                else {
                                        flage=0;
                                        logError("Variable is uninitialized.", yylineno);
                                }
                        }
                        else{
                                logError("Data type mismatch.", yylineno);
                        }
                }
                else {
                        logError("Variable is undeclared.", yylineno);
                }
                }
        ;        

%%

Node * checkValueNotEmpty(Node* node){
        Node *boolNode;
        if(node->dataType == TYPE_INT ){
                if(node->value.iVal != 0){
                        boolNode = createBoolNode(true, scope , tempCount , true);
                }
                else{
                        boolNode = createBoolNode(false, scope, tempCount , true);
                }
        }
        else if(node->dataType == TYPE_DOUBLE){
                if(node->value.dVal != 0){
                        boolNode = createBoolNode(true, scope, tempCount , true);
                }
                else{
                        boolNode = createBoolNode(false, scope, tempCount , true);
                }
        }
        else if(node->dataType == TYPE_CHAR){
                if(node->value.cVal ){
                        boolNode = createBoolNode(true, scope, tempCount , true);
                }
                else{
                        boolNode = createBoolNode(false, scope , tempCount , true);
                }
        }
        else if(node->dataType == TYPE_STRING){
                if(node->value.strVal){
                        boolNode = createBoolNode(true, scope, tempCount , true);
                }
                else{
                        boolNode = createBoolNode(false, scope, tempCount , true);
                }
        }
        return boolNode;
}

Node * handleConditionalExpression(Node * node){
        Node * boolNode;
        if(node->dataType == TYPE_BOOL){
                return node;
        }
        else
        {
                if(node->nodeType == NODE_CONST){
                        boolNode = checkValueNotEmpty(node);
                }
                else if (node->nodeType == NODE_ID)
                {
                        SymbolEntry *entry = getentryfromalltables(currTable, node->name);
                        if(entry != NULL){
                                if (entry->isInitialized) {
                                        boolNode = checkValueNotEmpty(node);
                                        boolNode->name = node->name;
                                } else logError("Variable is uninitialized.", yylineno);

                        } else logError("Variable is undeclared.", yylineno);
                }
        }
        return boolNode;
}

Node * handleConditionalComparison(Node* first , Node* second , char* oper){
        Node * boolNode;
        if(first->dataType == second->dataType) {
                if(strcmp(oper, "==") == 0)
                {   
                        if(first->dataType == TYPE_INT)
                        {
                                if(first->value.iVal == second->value.iVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope , tempCount , false);
                                        insertQuad(first->name , second->name , "==" , boolNode->name , 0);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                        insertQuad(first->name , second->name , "==" , boolNode->name , 0);
                                }
                        }
                        else if(first->dataType == TYPE_DOUBLE)
                        {
                                if(first->value.dVal == second->value.dVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope , tempCount , false);
                                        insertQuad(first->name , second->name , "==" , boolNode->name , 0);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                        insertQuad(first->name , second->name , "==" , boolNode->name , 0);
                                }
                        }
                        else if(first->dataType == TYPE_CHAR)
                        {
                                if(strcmp(first->value.cVal, second->value.cVal) == 0)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , "==" , boolNode->name , 0);
                        }
                        else if(first->dataType == TYPE_STRING)
                        {
                                if(strcmp(first->value.strVal, second->value.strVal) == 0)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , "==" , boolNode->name , 0);
                        }
                        
                }
                else if(strcmp(oper, ">") == 0)
                {
                        if(first->dataType == TYPE_INT)
                        {
                                if(first->value.iVal > second->value.iVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , ">" , boolNode->name , 0);
                        }
                        else if(first->dataType == TYPE_DOUBLE)
                        {
                                if(first->value.dVal > second->value.dVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , ">" , boolNode->name , 0);
                        }
                }
                else if(strcmp(oper, "<") == 0)
                {
                        if(first->dataType == TYPE_INT)
                        {
                                if(first->value.iVal < second->value.iVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , "<" , boolNode->name , 0);
                        }
                        else if(first->dataType == TYPE_DOUBLE)
                        {
                                if(first->value.dVal < second->value.dVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , "<" , boolNode->name , 0);
                        }
                }
                else if(strcmp(oper, ">=") == 0){
                        if(first->dataType == TYPE_INT)
                        {
                                if(first->value.iVal >= second->value.iVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , ">=" , boolNode->name , 0);
                        }
                        else if(first->dataType == TYPE_DOUBLE)
                        {
                                if(first->value.dVal >= second->value.dVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , ">=" , boolNode->name , 0);
                        }
                }
                else if(strcmp(oper, "<=") == 0){
                        if(first->dataType == TYPE_INT)
                        {

                                if(first->value.iVal <= second->value.iVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , "<=" , boolNode->name , 0);
                        }
                        else if(first->dataType == TYPE_DOUBLE)
                        {
                                if(first->value.dVal <= second->value.dVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , "<=" , boolNode->name , 0);
                        }
                }
                else if(strcmp(oper, "!=") == 0){
                        if(first->dataType == TYPE_INT)
                        {
                                if(first->value.iVal != second->value.iVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , "!=" , boolNode->name , 0);
                        }
                        else if(first->dataType == TYPE_DOUBLE)
                        {
                                if(first->value.dVal != second->value.dVal)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , "!=" , boolNode->name , 0);
                        }
                        else if(first->dataType == TYPE_CHAR)
                        {
                                if(strcmp(first->value.cVal, second->value.cVal) != 0)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , "!=" , boolNode->name , 0);
                        }
                        else if(first->dataType == TYPE_STRING)
                        {
                                if(strcmp(first->value.strVal, second->value.strVal) != 0)
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(true, scope, tempCount , false);
                                }
                                else
                                {
                                        tempCount++;
                                        boolNode = createBoolNode(false, scope, tempCount , false);
                                }
                                insertQuad(first->name , second->name , "!=" , boolNode->name , 0);
                        }
                }
        }
        return boolNode;
}

void handleFunctionParameters(SymbolEntry ** params , Node** nodes , int argCount){
        for(int j = 0 ; j < argCount ; j++)
        {
             if(params[j]->type == nodes[j]->dataType){
                        if(params[j]->type == TYPE_INT){
                                insertQuad(nodes[j]->name , NULL , "=" , params[j]->name , 0);
                        }
                        else if(params[j]->type == TYPE_DOUBLE){
                                insertQuad(nodes[j]->name , NULL , "=" , params[j]->name , 0);
                        }
                        else if(params[j]->type == TYPE_BOOL){
                                insertQuad(nodes[j]->name , NULL , "=" , params[j]->name , 0);
                        }
                        else if(params[j]->type == TYPE_CHAR){
                                insertQuad(nodes[j]->name , NULL , "=" , params[j]->name , 0);
                        }
                        else if(params[j]->type == TYPE_STRING){
                                insertQuad(nodes[j]->name , NULL , "=" , params[j]->name , 0);
                        }
                }
                else logError("Data type mismatch.", yylineno);
        }
}

char *concatenateStrings(char *str1, char *str2){
        char *result = malloc(strlen(str1) + strlen(str2) + 1);
        strcpy(result, str1);
        strcat(result, str2);
        return result;
}

void yyerror(char *s) {
        FILE* syntaxErrorFile;
        if (first_syn_err == 1) {
                syntaxErrorFile = fopen("syntax_errors.txt", "w");
                fprintf(syntaxErrorFile, "%s: %s at line %d\n", filename, s, yylineno);
                first_syn_err = 0;
        } else {
                syntaxErrorFile = fopen("syntax_errors.txt", "a");
                fprintf(syntaxErrorFile, "%s: %s at line %d\n", filename, s , yylineno);
        }
        fprintf(stderr, "%s %d\n", s , yylineno);
        // return 0;
}

int main(int argc, char **argv) {
        initialize();
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        // Print file name 
        filename = argv[1];
        printf("File name: %s\n", filename);
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
        printTable(globalTable , false);
        printUnusedVariables(globalTable);
        printQuadrables();
        QuadrablesToAssembly();
        return 0;
    } else {
        printf("Parsing failed\n");
        return 1;
    }
}
