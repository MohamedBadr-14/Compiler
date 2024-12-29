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

void reArrange()
{
    Quadruple *curr = start;
    Quadruple *tempHead = NULL;
    Quadruple *temp = NULL;
    Quadruple *last = NULL;

    while (curr != NULL)
    {
        if (curr->endFor == 1)
        {
            Quadruple *newQuad = (Quadruple *)malloc(sizeof(Quadruple));
            newQuad->Result = curr->Result;
            newQuad->Src1 = curr->Src1;
            newQuad->Src2 = curr->Src2;
            newQuad->Operation = curr->Operation;
            newQuad->endFor = curr->endFor;
            newQuad->next = NULL;

            if (tempHead == NULL)
            {
                tempHead = newQuad;
            }
            else
            {
                Quadruple *tempTail = tempHead;
                while (tempTail->next != NULL)
                {
                    tempTail = tempTail->next;
                }
                tempTail->next = newQuad;
            }
        }
        if (curr->next != NULL && curr->next->endFor == -1)
        {
            last = curr;
        }
        curr = curr->next;
    }

    curr = start;
    while (curr->next != NULL)
    {
        if (curr->next->endFor == 1)
        {
            Quadruple *toDelete = curr->next;
            curr->next = curr->next->next;
            free(toDelete);
        }
        else
        {
            curr = curr->next;
        }
    }

    if (tempHead != NULL)
    {
        Quadruple *last2 = last->next;
        last->next = tempHead;
        temp = tempHead;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = last2;
    }
}

void printQuadrables()
{
    // reArrange();
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

#endif // __QUAD_H_