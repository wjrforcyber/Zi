#include <assert.h>

#include "array.h"

int main() {
    ziArray a;
    ziArray* ptr = &a;
    assert(initArray(ptr, 8) == 0);
    assert(growArray(ptr, 20) == 0);
    assert(ptr->cap == 20);
    assert(clearArray(ptr) == 0);
    return 0;
}