#include "Node.h"
#include "y.tab.h"


char * concatunate(char t , int number) {
    char numStr[5];
    sprintf(numStr, "%d", number);

    char *result = (char *)malloc(strlen(numStr) + 2); 
    if (result == NULL) {
        printf("Memory allocation failed!\n");
        return NULL; 
    }

    result[0] = t;            
    strcpy(result + 1, numStr);      
    return result;
}

Node* createIntNode(int value , int scope , int new_count , bool flag ) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->name = flag ? concatunate(' ' , value) : concatunate('t',new_count);
    node->value.iVal = value;
    node->scope = scope;
    node->dataType = TYPE_INT;
    return node;
}


Node* createIDNode(char* name , int scope,enum DataType type ) {
    Node* node = (Node*)malloc(sizeof(Node));
    bool initialized=false;
    // union  Value v;
    node->initialized=initialized;
    // node->value=v;



    node->name = name;
    node->scope = scope;
    node->dataType = type;
    return node;
}
Node* createDoubleNode(double value , int scope , int new_count , bool flag) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->name = flag ? concatunate(' ' , value) : concatunate('t',new_count);
    node->value.dVal = value;
    node->scope = scope;
    node->dataType = TYPE_DOUBLE;
    return node;
}
Node* createCharNode(char* value , int scope , int new_count , bool flag) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->name = flag ? value : concatunate('t',new_count);
    node->value.cVal = value;
    node->scope = scope;
    node->dataType = TYPE_CHAR;
    return node;
}
Node* createStringNode(char* value , int scope , int new_count , bool flag) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->name = flag ? value : concatunate('t',new_count);
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
