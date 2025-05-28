#include "array.h"
#include <assert.h>
int main()
{
    int item = 10;
    int item_modify = 12;
    ziArray a;
    ziArray *ptr = &a;
    assert(initArray(ptr, 8) == 0);
    assert(pushArray(ptr, &item) == 0);
    assert(ptr->size == 1);
    assert(setIndexArray(ptr, 0, &item_modify) == 0);
    assert(*(int *)fetchIndexArray(ptr, 0) == 12);
    assert(clearArray(ptr) == 0);
    return 0;
}