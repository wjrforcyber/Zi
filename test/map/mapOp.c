#include <assert.h>
#include "unmap.h"

// Example usage
int main() {
    HashMap *map = createMap(5, 0.75);

    insertMap(map, 10, 10);
    insertMap(map, 20, 20);
    insertMap(map, 30, 30);
    insertMap(map, 20, 200);
    assert(map->nCap == 10);
    insertMap(map, 50, 50);
    
    insertMap(map, 60, 60);
    assert(getMap(map, 20) == 200);
    deleteMap(map, 30);
    assert(map->nSize == 4);

    freeMap(map);
    return 0;
}