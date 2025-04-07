#include "array.h"
#include <assert.h>

int main()
{
    int item0 = 10;
    int item1 = 8;
    int item2 = 6;
    ziArray a;
    ziArray *ptr = &a;
    assert(initArray(ptr, 8) == 0);
    assert(pushArray(ptr, &item0) == 0);
    assert(pushArray(ptr, &item1) == 0);
    assert(pushArray(ptr, &item2) == 0);
    assert(ptr->size == 3);
    assert(deleteIndexArrary(ptr, 1) == 0);
    assert(*fetchIndexArrary(ptr, 0) == 10);
    assert(*fetchIndexArrary(ptr, 1) == 6);
    assert(ptr->size == 2);
    return 0;
}