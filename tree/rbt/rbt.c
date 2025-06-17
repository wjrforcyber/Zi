#include "rbt.h"

// Create NIL node
RBNode* createNIL() {
    RBNode* node = (RBNode*)malloc(sizeof(RBNode));
    node->color = BLACK;
    node->left = node->right = node->parent = NULL;
    node->key = 0;
    node->value = NULL;
    return node;
}

// Create new node
RBNode* createNode(Map *map, int key, const char *value) {
    RBNode *node = (RBNode*)malloc(sizeof(RBNode));
    node->key = key;
    node->value = strdup(value);
    node->color = RED;
    node->left = node->right = node->parent = map->NIL;
    return node;
}

// Left rotate
void leftRotate(Map *map, RBNode *x) {
    RBNode *y = x->right;
    x->right = y->left;
    if (y->left != map->NIL) y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == map->NIL)
        map->root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

// Right rotate
void rightRotate(Map *map, RBNode *x) {
    RBNode *y = x->left;
    x->left = y->right;
    if (y->right != map->NIL) y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == map->NIL)
        map->root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else x->parent->left = y;
    y->right = x;
    x->parent = y;
}

// Fix after insert
void insertFixup(Map *map, RBNode *z) {
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            RBNode *y = z->parent->parent->right;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(map, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(map, z->parent->parent);
            }
        } else {
            RBNode *y = z->parent->parent->left;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(map, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(map, z->parent->parent);
            }
        }
    }
    map->root->color = BLACK;
}

// Insert key-value
void mapInsert(Map *map, int key, const char *value) {
    RBNode *z = createNode(map, key, value);
    RBNode *y = map->NIL;
    RBNode *x = map->root;

    while (x != map->NIL) {
        y = x;
        if (z->key == x->key) {
            free(x->value);
            x->value = strdup(value);
            free(z);
            return;
        }
        if (z->key < x->key)
            x = x->left;
        else x = x->right;
    }

    z->parent = y;
    if (y == map->NIL)
        map->root = z;
    else if (z->key < y->key)
        y->left = z;
    else y->right = z;

    insertFixup(map, z);
}

// Search
const char* mapSearch(Map *map, int key) {
    RBNode *x = map->root;
    while (x != map->NIL) {
        if (key == x->key)
            return x->value;
        else if (key < x->key)
            x = x->left;
        else x = x->right;
    }
    return NULL;
}

// Inorder (sorted key-value print)
void inorder(RBNode *node, RBNode *NIL) {
    if (node != NIL) {
        inorder(node->left, NIL);
        printf("%d => %s\n", node->key, node->value);
        inorder(node->right, NIL);
    }
}

// Transplant
void transplant(Map *map, RBNode *u, RBNode *v) {
    if (u->parent == map->NIL)
        map->root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else u->parent->right = v;
    v->parent = u->parent;
}

// Minimum
RBNode* minimum(Map *map, RBNode *x) {
    while (x->left != map->NIL)
        x = x->left;
    return x;
}

// Maximum
RBNode* maximum(Map *map, RBNode *x) {
    while (x->right != map->NIL)
        x = x->right;
    return x;
}

// Fix after delete
void deleteFixup(Map *map, RBNode *x) {
    while (x != map->root && x->color == BLACK) {
        if (x == x->parent->left) {
            RBNode *w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(map, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(map, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(map, x->parent);
                x = map->root;
            }
        } else {
            RBNode *w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(map, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(map, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(map, x->parent);
                x = map->root;
            }
        }
    }
    x->color = BLACK;
}

// Delete
void mapDelete(Map *map, int key) {
    RBNode *z = map->root;
    while (z != map->NIL && z->key != key) {
        if (key < z->key)
            z = z->left;
        else z = z->right;
    }
    if (z == map->NIL) return;

    RBNode *y = z;
    Color y_original_color = y->color;
    RBNode *x;

    if (z->left == map->NIL) {
        x = z->right;
        transplant(map, z, z->right);
    } else if (z->right == map->NIL) {
        x = z->left;
        transplant(map, z, z->left);
    } else {
        y = minimum(map, z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z)
            x->parent = y;
        else {
            transplant(map, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(map, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if (y_original_color == BLACK)
        deleteFixup(map, x);

    free(z->value);
    free(z);
}

// Create a new map
Map* createMap() {
    Map *map = (Map*)malloc(sizeof(Map));
    map->NIL = createNIL();
    map->root = map->NIL;
    return map;
}

// Free tree
void freeTree(Map *map, RBNode *node) {
    if (node != map->NIL) {
        freeTree(map, node->left);
        freeTree(map, node->right);
        free(node->value);
        free(node);
    }
}

// Free map
void freeMap(Map *map) {
    freeTree(map, map->root);
    free(map->NIL);
    free(map);
}
