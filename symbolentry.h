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


typedef struct {
    char *name;
    enum SymbolKind kind;    
    union Value value; // value of var
    bool isInitialized;
      

    enum DataType type;             // type of var
    int isConstant;
    int isused;
    int argCount;
    char **argTypes; 
    char *returnType;      
    int lineNo;  
} SymbolEntry;

// 

extern SymbolEntry *createSymbolEntry(char *name, enum SymbolKind kind,union Value  v , bool initial , int lineNo, enum DataType type, int isConstant, int argCount, char **argTypes, char *returnType)
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
    entry->lineNo = lineNo;
    entry->type = type;
    entry->isInitialized = initial;
    entry->isConstant = isConstant;
    entry->argCount = argCount;
    entry->argTypes = argTypes;
    entry->returnType = returnType ? strdup(returnType) : NULL;
    entry->isused = 0;
    return entry;
}

extern SymbolEntry *createSymbolEntryWithDefaults(char *name, enum SymbolKind kind,union Value v , bool intial, int lineNo,  enum DataType type)
{
    return createSymbolEntry(name, kind, v , intial,lineNo, type,  0, 0, NULL, NULL);
}
extern void destroyentry(SymbolEntry *entry) {
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

#endif