#ifndef __QUAD_H_
#define __QUAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

FILE *myfile2;

enum OperationType
{
    Q_Assign ,
    Q_ADD,
    Q_SUB,
    Q_MUL,
    Q_DIV,
    Q_LOGIC_AND,
    Q_LOGIC_OR,
    Q_NOT,
    Q_EQ,
    Q_NE,
    Q_GE,
    Q_LE,
    Q_GT,
    Q_LT,
    Q_JZ,
    Q_JNZ,
    Q_JMP,
    Q_LABEL,
    Q_INC,
    Q_DEC,
    Q_PUSH,
    Q_POP
};

enum OperationType getOper(const char* opr)
{
    if (strcmp(opr, "=") == 0)
    {
        return Q_Assign;
    }
    if (strcmp(opr, "+") == 0)
    {
        return Q_ADD;
    }
    if (strcmp(opr, "-") == 0)
    {
        return Q_SUB;
    }
    if (strcmp(opr, "*") == 0)
    {
        return Q_MUL;
    }
    if (strcmp(opr, "/") == 0)
    {
        return Q_DIV;
    }
    if (strcmp(opr, ">") == 0)
    {
        return Q_GT;
    }
    if (strcmp(opr, "<") == 0)
    {
        return Q_LT;
    }
    if (strcmp(opr, "<=") == 0)
    {
        return Q_LE;
    }
    if (strcmp(opr, ">=") == 0)
    {
        return Q_GE;
    }
    if (strcmp(opr, "==") == 0)
    {
        return Q_EQ;
    }
    if (strcmp(opr, "!=") == 0)
    {
        return Q_NE;
    }
    if (strcmp(opr, "&&") == 0)
    {
        return Q_LOGIC_AND;
    }
    if (strcmp(opr, "||") == 0)
    {
        return Q_LOGIC_OR;
    }
    if (strcmp(opr, "!") == 0)
    {
        return Q_NOT;
    }
    if (strcmp(opr, "JMP") == 0)
    {
        return Q_JMP;
    }
    if (strcmp(opr, "JZ") == 0)
    {
        return Q_JZ;
    }
    if (strcmp(opr, "JNZ") == 0)
    {
        return Q_JNZ;
    }
    if (strcmp(opr, "LABEL") == 0)
    {
        return Q_LABEL;
    }
    if (strcmp(opr, "++") == 0)
    {
        return Q_INC;
    }
    if (strcmp(opr, "--") == 0)
    {
        return Q_DEC;
    }
    if (strcmp(opr, "push") == 0)
    {
        return Q_PUSH;
    }
    if (strcmp(opr, "pop") == 0)
    {
        return Q_POP;
    }

    return -1; // Return an invalid operation type if no match is found
}
char * enumToString(enum OperationType op)
{
    switch (op)
    {
    case Q_Assign:
        return "ASSIGN";
    case Q_ADD:
        return "PLUS";
    case Q_SUB:
        return "MINUS";
    case Q_MUL:
        return "MULTIPLY";
    case Q_DIV:
        return "DIVIDE";
    case Q_LOGIC_AND:
        return "AND";
    case Q_LOGIC_OR:
        return "OR";
    case Q_NOT:
        return "NOT";
    case Q_EQ:
        return "EQUAL";
    case Q_NE:
        return "NOT EQUAL";
    case Q_GE:
        return "GOR";
    case Q_LE:
        return "LOR";
    case Q_GT:
        return "GREATER";
    case Q_LT:
        return "LESS";
    case Q_JZ:  
        return "JZ";
    case Q_JNZ:
        return "JNZ";
    case Q_JMP:
        return "JMP";
    case Q_LABEL:
        return "LABEL";
    case Q_INC:
        return "INC";
    case Q_DEC:
        return "DEC";
    case Q_PUSH:
        return "PUSH";
    case Q_POP:
        return "POP";
    }
}


typedef struct Quadruple
{
    char *Result;
    char *Src1;
    char *Src2;
    enum OperationType Operation;
    int endFor;
    struct Quadruple *next;
} Quadruple;

Quadruple *start = NULL;

void insertQuad(char *n1, char *n2, const char *opr, char *tempName, int endFor)
{
    Quadruple *newQuad = (Quadruple *)malloc(sizeof(Quadruple));
    newQuad->Result = tempName;
    newQuad->Src1 = (n1 != NULL) ? n1 : "#";
    newQuad->Src2 = (n2 != NULL) ? n2 : "#";
    newQuad->Operation = getOper(opr);
    newQuad->endFor = endFor;
    newQuad->next = NULL;

    if (start == NULL)
    {
        start = newQuad;
    }
    else
    {
        Quadruple *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newQuad;
    }
}

void printQuadrables()
{
    myfile2 = fopen("testing.txt", "w");
    Quadruple *temp = start;
    while (temp != NULL)
    {
        printf("result = %s , src1 = %s , src2 = %s opr = %d  forend = %d\n", temp->Result, temp->Src1, temp->Src2, temp->Operation, temp->endFor);
        fprintf(myfile2, "result = %s , src1 = %s , src2 = %s opr = %d  forend = %d\n", temp->Result, temp->Src1, temp->Src2, temp->Operation, temp->endFor);
        temp = temp->next;
    }
    fclose(myfile2);
}

void QuadrablesToAssembly()
{
    myfile2 = fopen("assembly.txt", "w");
    Quadruple *temp = start;
    fprintf(myfile2, "OPR   SRC1    SRC2    DEST   \n");
    while (temp != NULL)
    {
        // printf("result = %s , src1 = %s , src2 = %s opr = %s  forend = %d\n", temp->Result, temp->Src1, temp->Src2, enumToString(temp->Operation));
        fprintf(myfile2, "%s    %s  %s  %s \n", enumToString(temp->Operation), temp->Src1, temp->Src2, temp->Result);
        temp = temp->next;
    }
}

#endif // __QUAD_H_