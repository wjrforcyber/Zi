#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
The unordered map, designed to update a value if there's already existed the
same key.
TODO @Jingren Wang: Also need to be modified to be aribitrary pointers.
*/

#define RESIZE_TIMES 2

typedef struct Entry_ Entry;
typedef struct HashMap_ HashMap;

struct Entry_ {
    int key;
    int value;
    Entry *next;
};

struct HashMap_ {
    Entry **buckets;
    int nCap;
    int nSize;
    float fLoadFactor;
};

HashMap *createMap(int initSize, float fLoadFactor);
void insertMap(HashMap *map, int key, int value);
int getMap(HashMap *map, int key);
void deleteMap(HashMap *map, int key);
void printMap(HashMap *map);
void freeMap(HashMap *map);