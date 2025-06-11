#include "set.h"
#include <string.h>

//give limits on maximum memory cost on storing the data, on MegaBytes
int checkMemSet(unsigned long nMaxM)
{
    if(nMaxM > INTERNAL_SETMEM_MAX)
    {
        printf("The overall memory allocated will exceed 1G.");
        return 1;
    }
    return 0;
}

//given a (index) value and set the corresponding bit to 1 in an array
void fillSet(set * sData, int index)
{
    int blockBack = index/64;
    int blockShift = index%64;
    int nOriItem = sData->s->size;
    /*
    0 / fetch nOriItem - 1
    1 / fetch nOriItem - 2
    2 / fetch nOriItem - 3
    ...
    */
    int realBack = nOriItem - (blockBack + 1);
    int realShift = blockShift;
    unsigned long *select = fetchIndexArray(sData->s, realBack);
    //printf("realBack %d, realShift %d\n", realBack, realShift);
    //printf("Seleted num: 0x%lX\n", *select);
    //printf("Shifted 1: 0x%lX\n", (unsigned long)1ULL << realShift);
    (*select) |= (1ULL << realShift);
    //printf("Res: 0x%lX\n", *select);
}


//initialize set container
int initSet( set* sData, ziArray *iData )
{
    //how many unsigned long is enough?
    int * maxItem;
    maxArray(iData, int *, maxItem);
    int mSize = (*maxItem)/64 + 1;
    if(checkMemSet(mSize * 8/(1024 * 104)) == 1)
    {
        return 1;
    }
    sData->s = (ziArray *)malloc(sizeof(ziArray));
    initArray(sData->s, mSize);
    sData->sSize = 0;

    unsigned long* setCheck = (unsigned long*)malloc(sizeof(unsigned long) * mSize);
    memset(setCheck, 0, sizeof(unsigned long) * mSize);
    //push the unsigned int array into customized array
    int i;
    for(i = 0; i < mSize; i++)
    {
        pushArray(sData->s, &setCheck[i]);
        sData->sSize++;
    }

    ArrayForEachItem(iData, i)
    {
        fillSet(sData, *(int*)fetchIndexArray(iData, i));
    }
    showArray(sData->s, unsigned int *, i, 0, HEX);
    return 0;
}

//clear set
int clearSet( set* sData)
{
    clearArray(sData->s);
    return 0;
}
