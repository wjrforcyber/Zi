#include <assert.h>

#include "array.h"

// simple init and clear
int main() {
    ziArray origin;
    ziArray *a = &origin;
    if (initArray(a, 8) != 0) {
        return 1;
    }
    assert(a->cap == INCREASE_RATE * 8);
    if (clearArray(a) != 0) {
        return 1;
    }
    assert(a->c_ptr == NULL);
    assert(a->cap == 0);
    assert(a->size == 0);
    assert(a->typeSize == 0);
    return 0;
}