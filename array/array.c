#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

//initialize an array
int initArray(ziArray* a, const int arraySize)
{
    if(INCREASE_RATE < 1)
    {
        printf("Rate of array initialization is not proper.\n");
        return 1;
    }
    a->cap = INCREASE_RATE * arraySize;
    a->size = 0;
    a->typeSize = 0;
    a->c_ptr = calloc(a->cap, sizeof(char *));
    return 0;
}

//clear an array content
int clearArray(ziArray *a)
{
    free(a->c_ptr);
    a->c_ptr = NULL;
    a->cap = 0;
    a->size = 0;
    a->typeSize = 0;
    return 0;
}

//clear an array content
int clearExtendArray(ziArray *a)
{
    free(a->c_ptr[0]);
    free(a->c_ptr);
    free(a);
    return 0;
}

//growArray to a target capacity
int growArray(ziArray* a, const size_t capTarget)
{
    a->c_ptr = realloc(a->c_ptr, capTarget);
    a->cap = capTarget;
    return 0;
}

//push to the back of an array
int pushArray(ziArray* a, void* item)
{
    if(a->size == a->cap)
    {
        growArray(a, INCREASE_RATE * a->size);
    }
    a->c_ptr[a->size] = item;
    a->size++;
    return 0;
}

//set a value on a specific position
int setIndexArray(ziArray* a, int index, void * item)
{
    if(index > a->cap)
    {
        growArray(a, INCREASE_RATE * a->size);
    }
    a->c_ptr[index] = item;
    return 0;
}

//insert to a index of an array
int insertIndexArray(ziArray* a, int index, void * item)
{
    //check the capacity
    if(a->size == a->cap)
    {
        growArray(a, INCREASE_RATE * a->size);
    }
    int j = 0;
    j = a->size - 1;
    while(j >= index)
    {
        a->c_ptr[j + 1] = a->c_ptr[j];
        j--;
    }
    a->c_ptr[index] = item;
    a->size++;
    return 0;
}

//remove an item in a specific position index
int deleteIndexArray(ziArray* a, int index)
{
    int i = 0;
    for(i = 0; i < a->size; i++)
    {
        if(i == index)
        {
            break;
        }
    }
    while(i < a->size)
    {
        a->c_ptr[i] = a->c_ptr[i+1];
        i++;
    }
    a->size--;
    return 0;
}

//remove an item in a specific position index
int * fetchIndexArray(ziArray* a, int index)
{
    if(index >= a->size)
    {
        printf("Fetch item out of index.\n");
        return NULL;
    }
    return a->c_ptr[index];
}

//change an item in a specifc position
int changeIndexArray(ziArray* a, int index, void *item)
{
    if(index > a->size - 1)
    {
        printf("The item is out of index.\n");
        return 1;
    }
    a->c_ptr[index] = item;
    return 0;
}

//check the identity of two arrays
int checkIdentityArray(ziArray* a, ziArray* b)
{
    if(a->size != b->size)
    {
        printf("Two arrays have different size.\n");
        return 1;
    }
    for(int i = 0; i < a->size; i++)
    {
        if(*fetchIndexArray(a, i) != *fetchIndexArray(b, i))
        {
            return 1;
        }
    }
    return 0;
}

//check the identity of two arrays
ziArray* addArray(ziArray* a, ziArray* b)
{
    ziArray* res = (ziArray*)malloc(sizeof(ziArray));
    initArray(res, 8);
    //res->size = a->size;
    int* res_ini = (int *)malloc(sizeof(int) * a->size);
    memset(res_ini, 0, sizeof(int)*a->size);
    for(int i = 0; i < a->size; i++)
    {
        pushArray(res, &res_ini[i]);
    }

    if(a->size != b->size)
    {
        printf("Two arrays have different size.\n");
        free(res_ini);
        clearArray(res);
        return NULL;
    }
    for(int i = 0; i < a->size; i++)
    {
        *fetchIndexArray(res, i) = *fetchIndexArray(a, i) + *fetchIndexArray(b, i);
    }
    return res;
}

//array product
int productIntArray(ziArray* a, ziArray* b)
{
    int i = 0;
    int res = 0;
    if(a->size != b->size)
    {
        printf("Two array have different size.\n");
        return 1;
    }
    ArrayForEachItem(a, i)
    {
        ArrayForEachItem(b, i)
        {
            res += (*fetchIndexArray(a, i)) * (*fetchIndexArray(b, i));
        }
    }
    return res;
}

int extendArray(ziArray* ori, ziArray* extra)
{
    for(int i = 0; i < extra->size; i++)
    {
        pushArray(ori, fetchIndexArray(extra, i));
    }
    return 0;
}

//show digits array
int showDigitsArray(ziArray* a)
{
    if(a->size == 0)
    {
        printf("Array size is 0, nothing to print.\n");
        return 1;
    }
    printf("Warning: Only proper on int type.\n");
    int index = 0;
    printf("Array contains:\n");
    for(index = 0; index < a->size; index++)
    {
        if(index == a->size - 1)
        {
            printf("%d\n", *fetchIndexArray(a, index));
        }
        else {
            printf("%d ", *fetchIndexArray(a, index));
        }
    }
    return 0;
}