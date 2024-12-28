
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


enum DataType
{
    TYPE_INT,
    TYPE_DOUBLE,
    TYPE_CHAR,
    TYPE_VOID,
    TYPE_BOOL,
    TYPE_STRING,
};
     union Value {
        int iVal; 
        double dVal; 
        bool bVal;
        char * cVal; 
        
        char *strVal;
    };      