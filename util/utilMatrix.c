
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int intConcatenate(int a, int b)
{
    //TODO @Jingren Wang: Check overflow before concatenate
    char * a_s = (char *)malloc(sizeof(char) * 100);
    char * b_s = (char *)malloc(sizeof(char) * 100);
    snprintf(a_s, 50, "%d", a);
    snprintf(b_s, 50, "%d", b);
    strcat(a_s, b_s);
    int res = atoi(a_s);
    free(a_s);
    free(b_s);
    return res;
}