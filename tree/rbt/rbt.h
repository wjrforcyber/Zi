#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
An implementation of an ordered map using red-black tree due to high frequency
of opration insert and delete.
TODO @Jingren Wang This section should be moved to hash map later, leave a clean
red-black tree with void *.

TODO @Jingren Wang Generalize the key-value pair to structure needed. Currently,
key-value pair are constructed with int and char *
*/

typedef enum { RED, BLACK } Color;

typedef struct RBNode_ RBNode;
typedef struct Map_ Map;

struct RBNode_ {
    int key;
    char *value;
    Color color;
    RBNode *left, *right, *parent;
};

struct Map_ {
    RBNode *root;
    RBNode *NIL;
};

Map *createMap();
void mapInsert(Map *map, int key, const char *value);
void inorder(RBNode *node, RBNode *NIL);
const char *mapSearch(Map *map, int key);
RBNode *minimum(Map *map, RBNode *x);
RBNode *maximum(Map *map, RBNode *x);
void mapDelete(Map *map, int key);
void freeMap(Map *map);
