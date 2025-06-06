#include <assert.h>

#include "array.h"
int main() {
    int item = 10;
    ziArray a;
    ziArray *ptr = &a;
    assert(initArray(ptr, 8) == 0);
    assert(pushArray(ptr, &item) == 0);
    assert(ptr->size == 1);
    assert(clearArray(ptr) == 0);
    return 0;
}