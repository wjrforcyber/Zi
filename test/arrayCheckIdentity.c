#include "array.h"
#include <assert.h>

int main()
{
    ziArray a;
    ziArray b;
    int item[4] = {0,1,2, 3};
    initArray(&a, 8);
    initArray(&b, 8);
    for(int i = 0; i < 3; i++)
    {
        pushArray(&a, &item[i]);
        pushArray(&b, &item[i]);
    }
    assert(checkIdentityArray(&a, &b) == 0);
    pushArray(&a, &item[3]);
    assert(checkIdentityArray(&a, &b) == 1);
    clearArray(&a);
    clearArray(&b);
    return 0;
}