#include <assert.h>

#include "array.h"
int main() {
    int item0 = 2;
    int item1 = 4;
    int item2 = 6;
    ziArray a;
    ziArray *ptr = &a;
    assert(initArray(ptr, 8) == 0);
    assert(pushArray(ptr, &item0) == 0);
    assert(pushArray(ptr, &item1) == 0);
    assert(pushArray(ptr, &item2) == 0);
    assert(ptr->size == 3);
    assert(showDigitsArray(ptr) == 0);
    assert(clearArray(ptr) == 0);

    int aI[10] = {1, 2, 0};
    ziArray aICur;
    ziArray *ptrCur = &aICur;
    assert(initArray(ptrCur, 8) == 0);
    assert(pushArray(ptrCur, &aI[0]) == 0);
    assert(pushArray(ptrCur, &aI[1]) == 0);
    assert(pushArray(ptrCur, &aI[2]) == 0);
    assert(ptrCur->size == 3);
    assert(showDigitsArray(ptrCur) == 0);
    assert(clearArray(ptrCur) == 0);

    return 0;
}