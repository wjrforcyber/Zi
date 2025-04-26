# Zi
![Zi Lib CTests](https://github.com/wjrforcyber/Zi/actions/workflows/main.yml/badge.svg)

## Introduction
C Zi library, named after "子鼠", is one of the Synthesis and Verification Libraries of Zodiac Program.

Zi contains most of the basic data structures implemented in C, which will help algorithm implementation become easier.

> [!WARNING]
> This work is still in its early stage and designed for my own needs. Some datatype may not even be supported, if so, report an issue.

> [!CAUTION]
> The tests only assure no mem error but do not guarantee on mem leak.

## Structure
The project uses CMake, and test framework is CTest.

## Build
```
mkdir build
cmake ..
make
make test
```

## Contribution 
Contribution is welcome but should illustrate three sections: Why, What and How before the review.
