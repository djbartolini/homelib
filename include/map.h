#ifndef HOMELIB_MAP_H
#define HOMELIB_MAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define MapNode structure
typedef struct MapNode
{
    char *key;
    void *value;
    struct MapNode *left;
    struct MapNode *right;
} MapNode;

// Define map structure
typedef struct {
    MapNode *root;
    size_t value_size;
} Map;

// Creates a new node
MapNode* createNode(const char* key, void *value, size_t value_size);

// Inserts a key-value pair into the map
MapNode* insertNode(MapNode *node, const char *key, void *value, size_t value_size);

// Looks up a value by key
void* lookupNode(MapNode *node, const char *key);

// Frees the nodes of the map
void freeNode(MapNode *node);

// Creates a new map
Map* createMap(size_t value_size);

// Inserts a key-value pair into the map
void mapInsert(Map *map, const char *key, void *value);

// Lookup a value by key
void* mapLookup(Map *map, const char *key);

// Frees the map
void freeMap(Map *map);


#endif // HOMELIB_MAP_H
