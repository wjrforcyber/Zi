#include <stdlib.h>
typedef struct ziArray_ ziArray;

#define INCREASE_RATE 2

struct ziArray_
{
    int cap;
    int size;
    int typeSize;
    void ** c_ptr;
};


//array.c
int initArray(ziArray* a, const int size);
int clearArray(ziArray* a);
int growArray(ziArray* a, size_t capTarget);
int pushArray(ziArray* a, void* item);
int deleteIndexArrary(ziArray* a, int index);