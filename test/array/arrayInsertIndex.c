#include "array.h"
#include <assert.h>

int main()
{
    int item0 = 10;
    int item1 = 8;
    int item2 = 6;
    int item_insert = 999;
    ziArray a;
    ziArray *ptr = &a;
    assert(initArray(ptr, 8) == 0);
    assert(pushArray(ptr, &item0) == 0);
    assert(pushArray(ptr, &item1) == 0);
    assert(pushArray(ptr, &item2) == 0);
    assert(ptr->size == 3);
    assert(insertIndexArray(ptr, 1, &item_insert) == 0);
    assert(*fetchIndexArray(ptr, 0) == 10);
    assert(*fetchIndexArray(ptr, 1) == 999);
    assert(*fetchIndexArray(ptr, 2) == 8);
    assert(*fetchIndexArray(ptr, 3) == 6);
    assert(ptr->size == 4);
    return 0;
}