#ifndef SymbolEntry_H
#define SymbolEntry_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {
    char *name;
    int kind;               // 0: variable, 1: parameter

    char *type;             // type of var
    int isConstant;
    char *value;

    int argCount;
    char **argTypes; 
    char *returnType;      
    int lineNo;  
} SymbolEntry;

// 
#include "symbolentry.h"
#include <stdlib.h>
#include <string.h>

SymbolEntry *createSymbolEntry(char *name, int kind, int lineNo, char *type, char *value, int isConstant, int argCount, char **argTypes, char *returnType)
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

SymbolEntry *createSymbolEntryWithDefaults(char *name, int kind, int lineNo, char *type, char *value)
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

#endif /* SymbolEntry_H */