#include "array.h"

#include <assert.h>
int main() {
    int a[] = {17, 2, 35};
    ziArray p0;
    initArray(&p0, 8);
    for (int i = 0; i < 3; i++) {
        pushArray(&p0, &a[i]);
    }
    ziArray *pp0 = &p0;
    int i;
    showArray(pp0, int *,i, 0, HEX);
    showArray(pp0, int *,i, 0, DEC);
    clearArray(&p0);
    return 0;
}