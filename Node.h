
#include <stdlib.h>  
#include <stdio.h>
#include <string.h>

enum DataType
{
    TYPE_INT,
    TYPE_DOUBLE,
    TYPE_CHAR,
    TYPE_VOID,
    TYPE_BOOL,
    TYPE_STRING,
};
// enum NodeType {
//     NODE_ID, //identifier 
//     NODE_CONST, //constant value
// };

typedef struct Node {
    // values
    union {
        int iVal; 
        double dVal; 
        char cVal; 
        char *idName;
    };
    char* value;
    char* name;
    int scope; 
    int line_num;
    enum DataType dataType;
    bool isConstant;
    // enum NodeType nodeType;

}Node;

Node* createIntNode(int value , int scope ) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->name = NULL;
    node->iVal = value;
    node->scope = scope;
    node->dataType = TYPE_INT;
    return node;
}

Node* createIDNode(char* name , int scope ) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->name = name;
    node->scope = scope;
    return node;
}