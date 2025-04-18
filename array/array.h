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
int clearExtendArray(ziArray *a);
int growArray(ziArray* a, size_t capTarget);
int pushArray(ziArray* a, void* item);
int setIndexArray(ziArray* a, int index, void * item);
int insertIndexArray(ziArray* a, int index, void * item);
int deleteIndexArray(ziArray* a, int index);
int * fetchIndexArray(ziArray* a, int index);
int changeIndexArray(ziArray* a, int index, void *item);
int checkIdentityArray(ziArray* a, ziArray* b);
ziArray* addArray(ziArray* a, ziArray* b);
int productIntArray(ziArray* a, ziArray* b);
int extendArray(ziArray* ori, ziArray* extra);
int showDigitsArray(ziArray* a);

#define ArrayForEachItem( a, i ) \
    for( i = 0; i < a->size; i++)