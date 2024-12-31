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
    node->nodeType = NODE_CONST;
    node->initialized = true;
    return node;
}


Node* createIDNode(char* name , int scope,enum DataType type ) {
    Node* node = (Node*)malloc(sizeof(Node));
    // union  Value v;
    node->initialized=true;
    // node->value=v;



    node->name = name;
    node->scope = scope;
    node->dataType = type;
    node->nodeType = NODE_ID;

    return node;
}
Node* createDoubleNode(double value , int scope , int new_count , bool flag) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->name = flag ? concatunate(' ' , value) : concatunate('t',new_count);
    node->value.dVal = value;
    node->scope = scope;
    node->dataType = TYPE_DOUBLE;
    node->nodeType = NODE_CONST;
    node->initialized = true;
    return node;
}
Node* createCharNode(char* value , int scope , int new_count , bool flag) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->name = flag ? value : concatunate('t',new_count);
    node->value.cVal = value;
    node->scope = scope;
    node->dataType = TYPE_CHAR;
    node->nodeType = NODE_CONST;
    node->initialized = true;
    return node;
}
Node* createStringNode(char* value , int scope , int new_count , bool flag) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->name = flag ? value : concatunate('t',new_count);
    node->value.strVal = value;
    node->scope = scope;
    node->dataType = TYPE_STRING;
    node->nodeType = NODE_CONST;
    node->initialized = true;
    return node;
}
Node* createBoolNode(bool value , int scope , int new_count ,bool flag) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->name = flag ? value ? "true" : "false" : concatunate('t',new_count);
    node->value.bVal = value;
    node->scope = scope;
    node->dataType = TYPE_BOOL;
    node->nodeType = NODE_CONST;
    // node->initialized = true;
    return node;
}
