#include <assert.h>

#include "array.h"

int main() {
    int i, resCheck;
    ziArray a;
    ziArray b;
    int item[4] = {0, 1, 2, 3};
    initArray(&a, 8);
    initArray(&b, 8);
    for (int i = 0; i < 3; i++) {
        pushArray(&a, &item[i]);
        pushArray(&b, &item[i]);
    }
    ziArray *p1 = &a;
    ziArray *p2 = &b;
    ArraryCheckIndentity(p1, p2, int *, i, &resCheck);
    assert(resCheck == 0);

    pushArray(&a, &item[3]);
    ArraryCheckIndentity(p1, p2, int *, i, &resCheck);
    assert(resCheck == 1);
    clearArray(&a);
    clearArray(&b);
    return 0;
}