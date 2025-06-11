#include "set.h"

#include <assert.h>

int main() {
    int a[] = {17, 2, 35};
    ziArray p0;
    initArray(&p0, 8);
    for (int i = 0; i < 3; i++) {
        pushArray(&p0, &a[i]);
    }
    set sData;
    set *pDataSet = &sData;
    assert(initSet( pDataSet, &p0 ) == 0);
    //1000 0000 0000 0000 0010 0000 0000 0000 0100
    assert(*(unsigned long *)fetchIndexArray(pDataSet->s, 0) == 0x800020004);
    clearSet(pDataSet);
    clearArray(&p0);
    return 0;
}