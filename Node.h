#pragma once

#include "definations.h"



// enum NodeType {
//     NODE_ID, //identifier 
//     NODE_CONST, //constant value
// };

typedef struct Node {
    bool initialized;
    union Value value;
    // values


    char* name;
    int scope; 
    int line_num;
    enum DataType dataType;
    bool isConstant;
    enum NodeType nodeType;

}Node;

Node* createIntNode(int value , int scope , int new_count , bool flag ) ;
Node* createDoubleNode(double value , int scope , int new_count , bool flag) ;
Node* createCharNode(char* value , int scope , int new_count , bool flag) ;
Node* createStringNode(char* value , int scope, int new_count , bool flag) ;
Node* createBoolNode(bool value , int scope , int new_count , bool flag) ;
Node* createIDNode(char* name , int scope,enum DataType type ) ;
char * concatunate(char t , int number);

