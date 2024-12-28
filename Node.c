#include "Node.h"
#include "y.tab.h"


Node* createIntNode(int value , int scope ) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->name = NULL;
    node->value.iVal = value;
    node->scope = scope;
    node->dataType = TYPE_INT;
    return node;
}

Node* createIDNode(char* name , int scope,enum DataType type ) {
    Node* node = (Node*)malloc(sizeof(Node));
    bool initialized=false;
    union  Value v;
    node->initialized=initialized;
    node->value=v;



    node->name = name;
    node->scope = scope;
    node->dataType = type;
    return node;
}
Node* createDoubleNode(double value , int scope ) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->name = NULL;
    node->value.dVal = value;
    node->scope = scope;
    node->dataType = TYPE_DOUBLE;
    return node;
}
Node* createCharNode(char* value , int scope ) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->name = NULL;
    node->value.cVal = value;
    node->scope = scope;
    node->dataType = TYPE_CHAR;
    return node;
}
Node* createStringNode(char* value , int scope ) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->name = NULL;
    node->value.strVal = value;
    node->scope = scope;
    node->dataType = TYPE_STRING;
    return node;
}
Node* createBoolNode(bool value , int scope ) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->name = NULL;
    node->value.bVal = value;
    node->scope = scope;
    node->dataType = TYPE_BOOL;
    return node;
}
