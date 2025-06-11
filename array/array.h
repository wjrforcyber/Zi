#include <stdio.h>
#include <stdlib.h>
typedef struct ziArray_ ziArray;

#define INCREASE_RATE 2

struct ziArray_ {
    int cap;
    int size;
    int typeSize;
    void** c_ptr;
};

// array.c
int initArray(ziArray* a, const int size);
int initArrayFillZero(ziArray* a, const int fillSize);
int clearArray(ziArray* a);
int clearEachEntryArray(ziArray* a);
int clearExtendArray(ziArray* a);
int growArray(ziArray* a, size_t capTarget);
int pushArray(ziArray* a, void* item);
int setIndexArray(ziArray* a, int index, void* item);
int insertIndexArray(ziArray* a, int index, void* item);
int deleteIndexArray(ziArray* a, int index);
void* fetchIndexArray(ziArray* a, int index);
int changeIndexArray(ziArray* a, int index, void* item);
ziArray* addArray(ziArray* a, ziArray* b);
int productIntArray(ziArray* a, ziArray* b);
int extendArray(ziArray* ori, ziArray* extra);
int showDigitsArray(ziArray* a);

enum ITEM_TYPE { HEX, DEC };

#define ArrayForEachItem(a, i) for (i = 0; i < a->size; i++)
#define ArrayForEachItemStart(a, i, iStart) for (i = iStart; i < a->size; i++)

#define ArraryCheckIndentity(a, b, ItemType, i, res) \
    if (a->size != b->size) {                        \
        printf("Two arrays have different size.\n"); \
        *res = 1;                                    \
    } else {                                         \
        ArrayForEachItem(a, i) {                     \
            if (*(ItemType)fetchIndexArray(a, i) !=  \
                *(ItemType)fetchIndexArray(b, i)) {  \
                *res = 1;                            \
            }                                        \
        }                                            \
        *res = 0;                                    \
    }

#define maxArray(a, ItemType, maxItem)                               \
    if (a->size == 0) {                                              \
        printf("No item in the array.\n");                           \
        maxItem = NULL;                                              \
    }                                                                \
    maxItem = (ItemType)fetchIndexArray(a, 0);                       \
    for (int i = 0; i < a->size; i++) {                              \
        if (*(ItemType)maxItem < *(ItemType)fetchIndexArray(a, i)) { \
            maxItem = (ItemType)fetchIndexArray(a, i);               \
        }                                                            \
    }

#define showArray(a, ItemType, i, startIndex, showType)  \
    ArrayForEachItemStart(a, i, startIndex) {            \
        ItemType Item = (ItemType)fetchIndexArray(a, i); \
        if (showType == HEX) {                           \
            printf("0x");                                \
            if (i == a->size - 1)                        \
                printf("%X\n", *Item);                   \
            else                                         \
                printf("%X ", *Item);                    \
        } else {                                         \
            if (i == a->size - 1)                        \
                printf("%d\n", *Item);                   \
            else                                         \
                printf("%d ", *Item);                    \
        }                                                \
    }