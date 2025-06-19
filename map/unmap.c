#include "unmap.h"

// Simple hash function for int keys
unsigned int hash_int(int key, int nCap) {
    return ((unsigned int)key) % nCap;
}

// Create a new entry
Entry* create_entry(int key, int value) {
    Entry *entry = malloc(sizeof(Entry));
    entry->key = key;
    entry->value = value;
    entry->next = NULL;
    return entry;
}

// Create a new map
HashMap* createMap(int initSize, float fLoadFactors) {
    HashMap *map = malloc(sizeof(HashMap));
    map->nCap = initSize;
    map->nSize = 0;
    map->buckets = calloc(map->nCap, sizeof(Entry*));
    map->fLoadFactor = fLoadFactors;
    return map;
}

// Insert helper (internal, skips resize logic)
void insert_no_resize(HashMap *map, int key, int value) {
    unsigned int idx = hash_int(key, map->nCap);
    Entry *head = map->buckets[idx];

    while (head) {
        if (head->key == key) {
            head->value = value;
            return;
        }
        head = head->next;
    }

    Entry *new_entry = create_entry(key, value);
    new_entry->next = map->buckets[idx];
    map->buckets[idx] = new_entry;
    map->nSize++;
}

// Resize table (called when load factor exceeded)
void resize(HashMap *map) {
    int old_nCap = map->nCap;
    Entry **old_buckets = map->buckets;

    map->nCap *= RESIZE_TIMES;
    map->buckets = calloc(map->nCap, sizeof(Entry*));
    map->nSize = 0;

    for (int i = 0; i < old_nCap; i++) {
        Entry *entry = old_buckets[i];
        while (entry) {
            insert_no_resize(map, entry->key, entry->value);
            Entry *tmp = entry;
            entry = entry->next;
            free(tmp);
        }
    }
    free(old_buckets);
}

// Public insert (resizes if needed)
void insertMap(HashMap *map, int key, int value) {
    if(map->fLoadFactor >= 1)
    {
        printf("Error: You should give a load factor lower than 1.\n");
        return;
    }
    if ((float)(map->nSize + 1) / map->nCap > map->fLoadFactor) {
        resize(map);
    }
    insert_no_resize(map, key, value);
}

// Get value by key, give representitive
int getMap(HashMap *map, int key) {
    unsigned int idx = hash_int(key, map->nCap);
    Entry *head = map->buckets[idx];

    while (head) {
        if (head->key == key)
            return head->value;
        head = head->next;
    }
    return -1;
}

// Delete key
void deleteMap(HashMap *map, int key) {
    unsigned int idx = hash_int(key, map->nCap);
    Entry *curr = map->buckets[idx];
    Entry *prev = NULL;

    while (curr) {
        if (curr->key == key) {
            if (prev)
                prev->next = curr->next;
            else
                map->buckets[idx] = curr->next;
            free(curr);
            map->nSize--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// Free map
void freeMap(HashMap *map) {
    for (int i = 0; i < map->nCap; i++) {
        Entry *entry = map->buckets[i];
        while (entry) {
            Entry *tmp = entry;
            entry = entry->next;
            free(tmp);
        }
    }
    free(map->buckets);
    free(map);
}

// Debug print
void printMap(HashMap *map) {
    for (int i = 0; i < map->nCap; i++) {
        Entry *e = map->buckets[i];
        while (e) {
            printf("Key %d => %d\n", e->key, e->value);
            e = e->next;
        }
    }
}

