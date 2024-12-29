#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char numStr[5];
    sprintf(numStr, "%d", number);

    char *result = (char *)malloc(strlen(numStr) + 2); 
    if (result == NULL) {
        printf("Memory allocation failed!\n");
        return NULL; 
    }

    result[0] = initial;            
    strcpy(result + 1, numStr);      




    return result;
}
