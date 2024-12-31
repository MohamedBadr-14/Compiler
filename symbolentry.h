#ifndef SymbolEntry_H
#define SymbolEntry_H


#include "definations.h"
enum SymbolKind
{
    constant, //const int M
    var,      //int x
    func,     //void main
    param,    //int par
};

typedef struct SymbolEntry SymbolEntry;

struct SymbolEntry {
    char *name;
    enum SymbolKind kind;
    union Value value; // value of var
    bool isInitialized;
    enum DataType type; // type of var
    int isConstant;
    SymbolEntry **parameters; // parameters of function
    int argCount;
    char **argTypes;
    char *returnType;
    int lineNo;
};

// 

SymbolEntry *createSymbolEntry(char *name, enum SymbolKind kind,union Value  v , bool initial , int lineNo, enum DataType type, int isConstant, int argCount, char **argTypes, char *returnType)
{
    SymbolEntry *entry = (SymbolEntry *)malloc(sizeof(SymbolEntry));

    if (type == TYPE_INT)
    {
        entry->value.iVal = v.iVal;
    }
    else if (type == TYPE_DOUBLE)
    {
        entry->value.dVal = v.dVal;
    }
    else if (type == TYPE_CHAR)
    {
        entry->value.cVal = v.cVal;
    }
    else if (type == TYPE_STRING)
    {
        entry->value.strVal = v.strVal;
        
    }
    else if (type == TYPE_BOOL)
    {
        printf("bool   ksdmklfmsdk\n");
        entry->value.bVal = v.bVal;
    }
    

    entry->name = strdup(name);
    entry->kind = kind;
    if (kind == func)
    {
        entry->parameters = (SymbolEntry **)malloc(0);
    }
    else
    {
        entry->parameters = NULL;
    }
    entry->lineNo = lineNo;
    entry->type = type;
    entry->isInitialized = initial;
    entry->isConstant = isConstant;
    entry->argCount = argCount;
    entry->argTypes = argTypes;
    entry->returnType = returnType ? strdup(returnType) : NULL;
    return entry;
}

SymbolEntry *createSymbolEntryWithDefaults(char *name, enum SymbolKind kind,union Value v , bool intial, int lineNo,  enum DataType type)
{
    return createSymbolEntry(name, kind, v , intial,lineNo, type,  0, 0, NULL, NULL);
}
void destroyentry(SymbolEntry *entry) {
    if (entry != NULL) {
        free(entry->name);
        for (int i = 0; i < entry->argCount; i++) {
            free(entry->argTypes[i]);
        }
        free(entry->argTypes);

        free(entry->returnType);


        free(entry);
    }
}
void addparam(SymbolEntry *funcEntry, SymbolEntry *paramEntry) {
    if (funcEntry == NULL || paramEntry == NULL) {
        fprintf(stderr, "Error: Null pointer passed to addparam.\n");
        return;
    }

    // Allocate/Reallocate memory for the parameters array
    funcEntry->parameters = (SymbolEntry **)realloc(
        funcEntry->parameters, 
        (funcEntry->argCount + 1) * sizeof(SymbolEntry *)
    );
    
    if (funcEntry->parameters == NULL) {
        fprintf(stderr, "Error: Memory allocation failed in addparam.\n");
        exit(EXIT_FAILURE);
    }

    // Add the new parameter to the array
    funcEntry->parameters[funcEntry->argCount] = paramEntry;

    // Increment the parameter count
    funcEntry->argCount++;

    printf("Parameter added. argCount = %d\n", funcEntry->argCount);
}

#endif