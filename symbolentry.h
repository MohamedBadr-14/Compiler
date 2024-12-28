#ifndef SymbolEntry_H
#define SymbolEntry_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum SymbolKind
{
    constant, //const int M
    var,      //int x
    func,     //void main
    param,    //int par
};


typedef struct {
    char *name;
    enum SymbolKind kind;               // CONST, VAR, FUNC, PARAM

    char *type;             // type of var
    int isConstant;
    char *value;

    int argCount;
    char **argTypes; 
    char *returnType;      
    int lineNo;  
} SymbolEntry;

// 

SymbolEntry *createSymbolEntry(char *name, enum SymbolKind kind, int lineNo, char *type, char *value, int isConstant, int argCount, char **argTypes, char *returnType)
{
    SymbolEntry *entry = (SymbolEntry *)malloc(sizeof(SymbolEntry));
    entry->name = strdup(name);
    entry->kind = kind;
    entry->lineNo = lineNo;
    entry->type = strdup(type);
    entry->value = strdup(value);
    entry->isConstant = isConstant;
    entry->argCount = argCount;
    entry->argTypes = argTypes;
    entry->returnType = returnType ? strdup(returnType) : NULL;
    return entry;
}

SymbolEntry *createSymbolEntryWithDefaults(char *name, enum SymbolKind kind, int lineNo, char *type, char *value)
{
    return createSymbolEntry(name, kind, lineNo, type, value, 0, 0, NULL, NULL);
}
void destroyentry(SymbolEntry *entry) {
    if (entry != NULL) {
        free(entry->name);
        free(entry->type);
        for (int i = 0; i < entry->argCount; i++) {
            free(entry->argTypes[i]);
        }
        free(entry->argTypes);

        free(entry->value);
        free(entry->returnType);


        free(entry);
    }
}

#endif