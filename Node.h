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
    // enum NodeType nodeType;

}Node;

Node* createIntNode(int value , int scope ) ;
Node* createDoubleNode(double value , int scope ) ;
Node* createCharNode(char* value , int scope ) ;
Node* createStringNode(char* value , int scope ) ;
Node* createBoolNode(bool value , int scope ) ;
Node* createIDNode(char* name , int scope,enum DataType type ) ;
