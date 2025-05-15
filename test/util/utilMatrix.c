#include "utilMatrix.h"
#include <assert.h>

int main()
{
    int a = 15;
    int b = 26;
    int res = intConcatenate(a, b);
    assert(res == 1526);
    a = 22234;
    b = 9876;
    res = intConcatenate(a, b);
    assert(res == 222349876);
    return 0;
}
