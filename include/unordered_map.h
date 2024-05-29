#ifndef HOMELIB_UNORDERED_MAP_H
#define HOMELIB_UNORDERED_MAP_H

#include <stdlib.h>

#define INITIAL_CAPACITY 16

// Define the HashNode structure
typedef struct HashNode
{
    char *key;
    void *value;
    struct HashNode *next;
} HashNode;

// Define the HashTable structure
typedef struct
{
    HashNode **buckets;
    size_t capacity;
    size_t size;
    size_t value_size;
} HashTable;

// Create a new node
HashNode* createHashNode(const char *key, void *value, size_t value_size);

// Create a new hash table
HashTable* createHashTable(size_t value_size);

// Insert a key-value pair into the hash table
void hashTableInsert(HashTable *hashTable, const char *key, void *value);

// Lookup a value by key
void* hashTableLookup(HashTable *hashTable, const char *key);

// Free the nodes of the hash table
void freeHashNodes(HashNode *node);

// Free the hash table
void freeHashTable(HashTable *hashTable);


#endif //HOMELIB_UNORDERED_MAP_H
