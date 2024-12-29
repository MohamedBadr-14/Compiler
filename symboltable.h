
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
    return entry;
}

void modifyentry (SymbolTable *table, char *name,SymbolEntry *newentry)
{
    SymbolEntry *entry = getentryfromalltables(table, name);
    if (entry != NULL)
    {
        entry = newentry;    
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
void printTable(SymbolTable *table)
{
    if (table != NULL)
    {
        printf("Table: %s\n", table->name);
        for (int i = 0; i < table->size; i++)

        {
            if (table->entries[i]->type == TYPE_INT)
            {
                printf("Name: %s, Type: int, Value: %d\n", table->entries[i]->name, table->entries[i]->value.iVal);
            }
            else if (table->entries[i]->type == TYPE_DOUBLE)
            {
                printf("Name: %s, Type: double, Value: %f\n", table->entries[i]->name, table->entries[i]->value.dVal);
            }
            else if (table->entries[i]->type == TYPE_CHAR)
            {
                printf("Name: %s, Type: char, Value: %s\n", table->entries[i]->name, table->entries[i]->value.cVal);
            }
            else if (table->entries[i]->type == TYPE_STRING)
            {
                printf("Name: %s, Type: string, Value: %s\n", table->entries[i]->name, table->entries[i]->value.strVal);
            }
            else if (table->entries[i]->type == TYPE_BOOL)
            {
                printf("Name: %s, Type: bool, Value: %s\n", table->entries[i]->name, table->entries[i]->value.bVal? "true" : "false");
            }
        }
        for (int i = 0; i < table->childCount; i++)
        {
            printTable(table->children[i]);
        }
    }
}

void getUnusedEntries(SymbolTable *table)
{
    if (table != NULL)
    {
        for (int i = 0; i < table->size; i++)
        {
            if (table->entries[i]->isused == 0)
                printf("Entry: %s is not used.\n", table->entries[i]->name);
        }
        for (int i = 0; i < table->childCount; i++)
            getUnusedEntries(table->children[i]);
    }
}


#endif /* SYMBOLTABLE_H */