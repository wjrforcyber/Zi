#include "array.h"
#include <assert.h>

int main()
{
    int item0 = 10;
    int item1 = 8;
    int item2 = 6;
    int item_change = 999;
    ziArray a;
    ziArray *ptr = &a;
    assert(initArray(ptr, 8) == 0);
    assert(pushArray(ptr, &item0) == 0);
    assert(pushArray(ptr, &item1) == 0);
    assert(pushArray(ptr, &item2) == 0);
    assert(ptr->size == 3);
    assert(changeIndexArray(ptr, 5, &item_change) == 1);
    assert(changeIndexArray(ptr, 1, &item_change) == 0);
    assert(*(int *)fetchIndexArray(ptr, 0) == 10);
    assert(*(int *)fetchIndexArray(ptr, 1) == 999);
    assert(*(int *)fetchIndexArray(ptr, 2) == 6);
    assert(ptr->size == 3);
    clearArray(ptr);
    return 0;
}