# Zi
![Zi Lib CTests](https://github.com/wjrforcyber/Zi/actions/workflows/main.yml/badge.svg)
[![pre-commit](https://img.shields.io/badge/pre--commit-enabled-brightgreen?logo=pre-commit)](https://github.com/wjrforcyber/Zi)

## Introduction
C Zi library, named after "子鼠", is designed for the Synthesis and Verification Libraries of Zodiac Program.

Zi contains some basic data structures implemented in C, which will help algorithm implementation become easier.

> [!WARNING]
> This work is still in its early stage and designed for my own needs. Some datatype may not even be supported, if so, report an issue.

> [!CAUTION]
> Sanitize check is turned on, if mem error/leak exists, PR won't be accepted.

## Structure
The project uses `CMake` with `CTest`.

## Build
```
mkdir build
cmake ..
make
make test
```

## Example
Some usage of the library will be shown here to give a minimum reproducible example([MRE](https://en.wikipedia.org/wiki/Minimal_reproducible_example)), there's no proper documentation right now, if detailed usage example of the interface is needed, you could check the interface test in `test` folder.
> [!IMPORTANT]
> Arbitrary feature should be enabled if possible, so in most of the case, pointers are extensively used, original data should be separated from the data structure here, still WIP.

> [!NOTE]
> Sections are collapsed if there's long examples, click on the section name to expand.

### Array
Simple arbitrary array reconstruct.
- [x] Add
- [x] Delete
- [x] Get
- [x] Modify
### Tree
Some tree structure such as
- [x] BST(Binary Search Tree)
- [ ] AVL Tree(Self-balancing Binary Search Tree)
- [ ] Red-black tree
### Matrix
Matrix can be read from a string, every row of the matrix is wrapped by $[$ and $]$, when reading a matrix, no need to worry about the space between numbers, it will be automatically normalized. 
- [x] Read a matrix
You could read matrix without worrying about the space between, it will automatically be normalized, eg, `[[ 1     ,2, 3 ],[ 2, 4,6   ]]` is good to go.
- [x] Add two matrix
- [x] Concatenate matrix Left-Right/Up-Down
- [x] Show a matrix


> [!CAUTION]
> Now most of the matrix implementation is on `int` type and two dimension, in the future it should be arbitrary. However, in boolean algebra context, `int` type is enough.


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
    showDigitsMatrix(res);
    clearMatrix(mI0);
    clearMatrix(mI1);
    clearMatrix(res);
    free(res);
}
```
The result will be
```bash
Matrix contains:
[
[ 1, 0, 1, 0, 0, 0, 1, 0 ],
[ 0, 1, 0, 1, 1, 1, 0, 1 ]
]
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
    showDigitsMatrix(res);
    clearMatrix(mI0);
    clearMatrix(res);
    free(res);
    clearMatrix(not);
    free(not);
    return 0;
}
```
```bash
Matrix contains:
[
[ 0, 1, 1, 1 ],
[ 1, 0, 0, 0 ]
]
```
#### AND
According to $a \ \sigma \ b = M_\sigma \ a \ b$, given boolean definition of **_AND_** 
```math
\begin{bmatrix} 1 & 0 & 0 & 0 \\ 0 & 1 & 1 & 1 \end{bmatrix}
```
, and truth value of variable $a$ (**_TURE_**), $b$ (**_FALSE_**), apply **_AND_** to $a$, $b$, will result in **_FALSE_**.

Note that the **_AND_** matrix could be generalized to support $n$ variables.

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
    matrix *and = andNMatrix(2);
    matrix *kPro_and_a = stpMatrix(and, mI0);
    matrix *res_and_a_b = stpMatrix(kPro_and_a, mI1);
    showDigitsMatrix(res_and_a_b);
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
Matrix contains:
[
[ 0 ],
[ 1 ]
]
```

#### Other boolean operators/handy interface
Besides **_AND_**(conjunction) and **_NOT_** operators mentioned above(which is already boolean complete), there are other handy interfaces for boolean algebra, here we only list some main interfaces.
- [x] Get const1/const0 under $n$ variable context <br>`matrix* getConst1(int n)`/`matrix* getConst0(int n)`
- [x] Boolean **_OR_**(Disjunction) operator under $n$ variables context <br>`matrix* orNMatrix(int n)`
- [ ] Implication.
- [x] Equivalence. <br>`matrix* eqMatrix(int n)`
- [x] Show the truth table(matrix) <br>`int showDigitsMatrix(matrix* m0)`

## Contribution 
Contribution is welcome but should illustrate three sections: Why, What and How before the review.
