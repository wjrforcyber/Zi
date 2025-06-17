#include <assert.h>
#include "rbt.h"

int main() {
    Map *map = createMap();

    mapInsert(map, 5, "NodeMFFC5");
    mapInsert(map, 3, "NodeMFFC3");
    mapInsert(map, 7, "NodeMFFC7");
    mapInsert(map, 6, "NodeMFFC6");
    mapInsert(map, 4, "NodeMFFC4");
    
    RBNode* min = minimum(map, map->root);
    assert(strcmp(min->value, "NodeMFFC3") == 0);
    RBNode* max = maximum(map, map->root);
    assert(strcmp(max->value, "NodeMFFC7") == 0);

    printf("Inorder traversal (sorted key-values):\n");
    inorder(map->root, map->NIL);

    const char *val = mapSearch(map, 4);
    assert(val != NULL);

    mapDelete(map, 3);
    printf("\nAfter deleting key 3:\n");
    inorder(map->root, map->NIL);

    freeMap(map);
    return 0;
}