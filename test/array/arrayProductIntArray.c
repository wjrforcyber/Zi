#include "array.h"
#include <assert.h>

int main()
{
    int a[] = {1, 2, 3};
    int b[] = {4,5,6};
    ziArray p0;
    initArray(&p0, 8);
    ziArray p1;
    initArray(&p1, 8);
    for(int i = 0; i < 3; i++)
    {
        pushArray(&p0, &a[i]);
        pushArray(&p1, &b[i]);
    }
    assert(productIntArray(&p0, &p1) == 32);
    clearArray(&p0);
    clearArray(&p1);
    return 0;
}