#include <assert.h>

#include "array.h"

int main() {
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
    assert(deleteIndexArray(ptr, 1) == 0);
    assert(*(int *)fetchIndexArray(ptr, 0) == 10);
    assert(*(int *)fetchIndexArray(ptr, 1) == 6);
    assert(ptr->size == 2);
    clearArray(ptr);
    return 0;
}