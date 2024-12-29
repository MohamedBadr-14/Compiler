#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* discard_quotes(const char* strin) {
    size_t len = strlen(strin) - 2;
    char* str = (char*)malloc(len + 1);
    for (int i = 1; i < strlen(strin) - 1; i++) {
        str[i - 1] = strin[i];
    }
    str[len] = '\0';
    return str;
}

void main() {
// const char* arkam = "80.91";
// double rakam = strtod(arkam, NULL);
// printf("%f", rakam);
// char* st = "\'c\'";
// printf("%s\n%s\n", st, discard_quotes(st));
double x = 9.80808;
printf("%f\n", ++x);
}