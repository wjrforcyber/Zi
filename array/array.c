#include <stdio.h>
#include <stdlib.h>
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
    a->c_ptr = (void *)malloc(a->cap);
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