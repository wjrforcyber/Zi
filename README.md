# Zi
![Zi Lib CTests](https://github.com/wjrforcyber/Zi/actions/workflows/main.yml/badge.svg)

## Introduction
C Zi library, named after "子鼠", is designed for the Synthesis and Verification Libraries of Zodiac Program.

Zi contains some of the basic data structures implemented in C, which will help algorithm implementation become easier.

> [!WARNING]
> This work is still in its early stage and designed for my own needs. Some datatype may not even be supported, if so, report an issue.

> [!CAUTION]
> Sanitize check is turned on, if mem error/leak exists, PR won't be accepted.

## Structure
The project uses CMake, and test framework is CTest.

## Build
```
mkdir build
cmake ..
make
make test
```

## Example
### Semi-tensor product

```C
#include "matrix.h"

int main()
{
    matrix test0;
    matrix* mI0 = &test0;

    matrix test1;
    matrix* mI1 = &test1;

    matrix testRes;
    matrix* mRes = &testRes;

    char mS0[100] = "[[1,0,0,0],[0,1,1,1]]";
    char mS1[100] = "[[1,1,0,1],[0,0,1,0]]";
    //Result "[[1,0,1,0,0,0,1,0],[0,1,0,1,1,1,0,1]]";
    readMatrix(mI0, mS0);
    readMatrix(mI1, mS1);
    matrix* res = stpMatrix(mI0, mI1);
    showDigitsArray(&res->m);
    clearMatrix(mI0);
    clearMatrix(mI1);
    clearMatrix(res);
    free(res);
}
```
The result will be
```bash
Warning: Only proper on int type.
Array contains:
1 0 1 0 0 0 1 0 0 1 0 1 1 1 0 1
```

### Boolean operator
#### NOT
Given truth table `[[1,0,0,0],[0,1,1,1]]`, the `NOT` operator will result in `[[0,1,1,1],[1,0,0,0]]`.
```C
#include "matrix.h"

int main()
{
    matrix test0;
    matrix* mI0 = &test0;
    char mS0[100] = "[[1,0,0,0],[0,1,1,1]]";
    //NOT should have "[[0,1,1,1],[1,0,0,0]]";
    assert(readMatrix(mI0, mS0) == 0);
    matrix *not = notMatrix();
    matrix *res = productMatrix(not, mI0);
    showDigitsArray(&res->m);
    clearMatrix(mI0);
    clearMatrix(res);
    free(res);
    clearMatrix(not);
    free(not);
    return 0;
}
```
```bash
Warning: Only proper on int type.
Array contains:
0 1 1 1 1 0 0 0
```


## Contribution 
Contribution is welcome but should illustrate three sections: Why, What and How before the review.
