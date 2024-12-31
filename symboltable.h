
#ifndef Symboltable_H
#define Symboltable_H



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolentry.h"
typedef struct SymbolTable SymbolTable;

struct SymbolTable {
    char *name;
    int scope;
    SymbolTable *parent;
    SymbolEntry **entries;
    size_t size;
    SymbolTable **children;
    size_t childCount;
};



SymbolTable *createSymbolTable(char *name, int scope, SymbolTable *parent)
{
    SymbolTable *table = (SymbolTable *)malloc(sizeof(SymbolTable));
    table->name = strdup(name);
    table->scope = scope;
    table->parent = parent;
    table->entries = (SymbolEntry **)malloc(0);
    table->size = 0;
    table->children = (SymbolTable **)malloc(0);
    table->childCount = 0;
    return table;
}
void addEntryToTable(SymbolTable *table, SymbolEntry *entry)
{
    table->entries = (SymbolEntry **)realloc(table->entries, (table->size + 1) * sizeof(SymbolEntry *));
    table->entries[table->size] = entry;
    table->size++;
}
void addChildToTable(SymbolTable *parent, SymbolTable *child)
{
    parent->children = (SymbolTable **)realloc(parent->children, (parent->childCount + 1) * sizeof(SymbolTable *));
    parent->children[parent->childCount] = child;
    parent->childCount++;
}

SymbolEntry * getentryfromalltables(SymbolTable *table, char *name)
{
    SymbolEntry *entry = NULL;
    while (table != NULL)
    {
        printf("table name %s\n",table->name);
        for (int i = 0; i < table->size; i++)
        {
            if (strcmp(table->entries[i]->name, name) == 0)
            {
                entry = table->entries[i];
                return entry;
            }
        }
        table = table->parent;
    }
    printf("RAGE3 entryyy : %d\n" , entry==NULL ? 1 : 0);
    return entry;
}

void modifyentry (SymbolTable *table, char *name,SymbolEntry *newentry)
{
    SymbolEntry *entry = getentryfromalltables(table, name);
    if (entry != NULL)
    {
        entry->isInitialized = newentry->isInitialized;
        if (newentry->type == TYPE_INT)
        {
            entry->value.iVal = newentry->value.iVal;
        }
        else if (newentry->type == TYPE_DOUBLE)
        {
            entry->value.dVal = newentry->value.dVal;
        }
        else if (newentry->type == TYPE_CHAR)
        {
            entry->value.cVal = newentry->value.cVal;
        }
        else if (newentry->type == TYPE_STRING)
        {
            entry->value.strVal = newentry->value.strVal;
        }
        else if (newentry->type == TYPE_BOOL)
        {
            entry->value.bVal = newentry->value.bVal;
        }
    }
}


void destroyTable(SymbolTable *table)
{
    if (table != NULL)
    {
        free(table->name);
        for (int i = 0; i < table->size; i++)
        {
            destroyentry(table->entries[i]);
        }
        free(table->entries);
        for (int i = 0; i < table->childCount; i++)
        {
            destroyTable(table->children[i]);
        }
        free(table->children);
        free(table);
    }
}
void printTable(SymbolTable *table , bool inside_file)
{
    //also print in file
    FILE * myfile2;
    if(inside_file)
    {
        myfile2 = fopen("SymbolTable.txt", "a");
    }
    else 
    {
        myfile2 = fopen("SymbolTable.txt", "w");
    }
    if (table != NULL)
    {
        printf("Table: %s\n", table->name);
        fprintf(myfile2, "Table: %s\n", table->name);
        for (int i = 0; i < table->size; i++)
        {
            if(table->entries[i]->kind == func)
            {
                fprintf(myfile2, "Name: %s, DataType: %d, type: %d  \n", table->entries[i]->name, table->entries[i]->type, table->entries[i]->kind);
                printf("Name: %s, DataType: %d, type: %d  \n", table->entries[i]->name, table->entries[i]->type, table->entries[i]->kind);
                for(int j = 0 ; j < table->entries[i]->argCount ; j++)
                {
                    fprintf(myfile2, "Name: %s, Type: %d, type: %d\n", table->entries[i]->parameters[j]->name, table->entries[i]->parameters[j]->type, table->entries[i]->parameters[j]->kind);
                    printf("Name: %s, Type: %d, type: %d\n", table->entries[i]->parameters[j]->name, table->entries[i]->parameters[j]->type, table->entries[i]->parameters[j]->kind);
                }
            }

            if (table->entries[i]->type == TYPE_INT)
            {
                fprintf(myfile2, "Name: %s, Type: int, Value: %d, type: %d , isIntialized: %s\n", table->entries[i]->name, table->entries[i]->isInitialized ? table->entries[i]->value.iVal : 0, table->entries[i]->kind , table->entries[i]->isInitialized ? "true" : "false");
                printf("Name: %s, Type: int, Value: %d, type: %d , isIntialized: %s\n", table->entries[i]->name, table->entries[i]->isInitialized ? table->entries[i]->value.iVal : 0, table->entries[i]->kind , table->entries[i]->isInitialized ? "true" : "false");
            }
            else if (table->entries[i]->type == TYPE_DOUBLE)
            {
                // printf("MOSHKELA HENA %s\n" , table->entries[i]->name);
                fprintf(myfile2, "Name: %s, Type: double, Value: %.1f, type: %d , isIntialized: %s\n", table->entries[i]->name, table->entries[i]->isInitialized ? table->entries[i]->value.dVal : 0.0, table->entries[i]->kind , table->entries[i]->isInitialized ? "true" : "false");
                printf("Name: %s, Type: double, Value: %.1f, type: %d , isIntialized: %s\n", table->entries[i]->name, table->entries[i]->isInitialized ? table->entries[i]->value.dVal : 0.0 , table->entries[i]->kind , table->entries[i]->isInitialized ? "true" : "false");
            }
            else if (table->entries[i]->type == TYPE_CHAR)
            {
                fprintf(myfile2, "Name: %s, Type: char, Value: %s, type: %d , isIntialized: %s\n", table->entries[i]->name, table->entries[i]->isInitialized ? table->entries[i]->value.cVal : " ", table->entries[i]->kind , table->entries[i]->isInitialized ? "true" : "false");
                printf("Name: %s, Type: char, Value: %s, type: %d , isIntialized: %s\n", table->entries[i]->name, table->entries[i]->isInitialized ? table->entries[i]->value.cVal : " ", table->entries[i]->kind , table->entries[i]->isInitialized ? "true" : "false");
            }
            else if (table->entries[i]->type == TYPE_STRING)
            {
                fprintf(myfile2, "Name: %s, Type: string, Value: %s, type: %d , isIntialized: %s\n", table->entries[i]->name, table->entries[i]->isInitialized ? table->entries[i]->value.strVal : " ", table->entries[i]->kind , table->entries[i]->isInitialized ? "true" : "false");
                printf("Name: %s, Type: string, Value: %s, type: %d , isIntialized: %s\n", table->entries[i]->name, table->entries[i]->isInitialized ? table->entries[i]->value.strVal: " ", table->entries[i]->kind , table->entries[i]->isInitialized ? "true" : "false");
            }
            else if (table->entries[i]->type == TYPE_BOOL)
            {
                fprintf(myfile2, "Name: %s, Type: bool, Value: %d, type: %d , isIntialized: %s\n", table->entries[i]->name, table->entries[i]->isInitialized ? table->entries[i]->value.bVal : false, table->entries[i]->kind , table->entries[i]->isInitialized ? "true" : "false");
                printf("Name: %s, Type: bool, Value: %d, type: %d , isIntialized: %s\n", table->entries[i]->name, table->entries[i]->isInitialized ? table->entries[i]->value.bVal : false, table->entries[i]->kind , table->entries[i]->isInitialized ? "true" : "false");
            }
        }
        for (int i = 0; i < table->childCount; i++)
        {
            printTable(table->children[i] , true);
        }
    }
}

void printUnusedVariables(SymbolTable *table, bool inside_file)
{
    FILE* unused_variables;
    if (inside_file)
        unused_variables = fopen("unused_variables.txt", "a");
    else unused_variables = fopen("unused_variables.txt", "w");

    if (table != NULL)
    {
        for (int i = 0; i < table->size; i++)
        {
            if (table->entries[i]->used == 0 && (table->entries[i]->kind == var || table->entries[i]->kind == constant)) {
                printf("Variable: %s is not used.\n", table->entries[i]->name);
                fprintf(unused_variables, "Variable: %s is not used.\n", table->entries[i]->name); 
            }
        }
        for (int i = 0; i < table->childCount; i++)
            printUnusedVariables(table->children[i], true);
    }
    fclose(unused_variables);
}





#endif /* SYMBOLTABLE_H */