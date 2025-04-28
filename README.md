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
Given basic boolean logic **_TRUE_** 
```math
\begin{bmatrix} 1 \cr 0 \end{bmatrix}
```
and **_FALSE_** 
```math
\begin{bmatrix} 0 \cr 1 \end{bmatrix}
```
.
#### NOT
Given truth table 
```math
\begin{bmatrix} 1 & 0 & 0 & 0 \\ 0 & 1 & 1 & 1 \end{bmatrix}
```
, apply the **_NOT_** operator 
```math
\begin{bmatrix} 0 & 1 \\ 1 & 0 \end{bmatrix}
```
will result in 
```math
\begin{bmatrix} 0 & 1 & 1 & 1 \\ 1 & 0 & 0 & 0 \end{bmatrix}
```
.
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
    matrix *res = stpMatrix(not, mI0);
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
#### AND
According to $a \ \sigma \ b = M_\sigma \ a \ b$, given boolean definition of **_AND_** 
```math
\begin{bmatrix} 1 & 0 & 0 & 0 \\ 0 & 1 & 1 & 1 \end{bmatrix}
```
, and truth value of variable $a$ (**_TURE_**), $b$ (**_FALSE_**), apply **_AND_** to $a$, $b$, will result in **_FALSE_**.

```C
#include "matrix.h"

int main()
{
    matrix test0;
    matrix* mI0 = &test0;
    matrix test1;
    matrix* mI1 = &test1;
    //f_tt0 = [[1],[0]] True
    char tt0[100] = "[[1],[0]]";
    //f_tt1 = [[0],[1]] False
    char tt1[100] = "[[0],[1]]";
    readMatrix(mI0, tt0);
    readMatrix(mI1, tt1);
    matrix *and = andMatrix();
    matrix *kPro_and_a = stpMatrix(and, mI0);
    matrix *res_and_a_b = stpMatrix(kPro_and_a, mI1);
    showDigitsArray(&res_and_a_b->m);
    clearMatrix(mI0);
    clearMatrix(mI1);
    clearMatrix(and);
    free(and);
    clearMatrix(kPro_and_a);
    free(kPro_and_a);
    clearMatrix(res_and_a_b);
    free(res_and_a_b);
    return 0;
}
```
```
Warning: Only proper on int type.
Array contains:
0 1
```

## Contribution 
Contribution is welcome but should illustrate three sections: Why, What and How before the review.
