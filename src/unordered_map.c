#include "../include/unordered_map.h"
#include <stdlib.h>
#include <string.h>

size_t hashFunction(const char *key, size_t capacity)
{
    size_t hash = 0;
    while (*key)
    {
        hash = (hash * 31) + *key++;
    }
    return hash % capacity;
}

HashNode* createHashNode(const char *key, void *value, size_t value_size)
{
    HashNode *newNode = (HashNode*)malloc(sizeof(HashNode));

    newNode->key = strdup(key);
    newNode->value = malloc(value_size);
    memcpy(newNode->value, value, value_size);
    newNode->next = NULL;

    return newNode;
}


HashTable* createHashTable(size_t value_size)
{
    HashTable *hashTable = (HashTable*)malloc(sizeof(HashTable));

    hashTable->buckets = (HashNode**)calloc(INITIAL_CAPACITY, sizeof(HashNode*));
    hashTable->capacity = INITIAL_CAPACITY;
    hashTable->size = 0;
    hashTable->value_size = value_size;

    return hashTable;
}

void hashTableInsert(HashTable *hashTable, const char *key, void *value)
{
    size_t index = hashFunction(key, hashTable->capacity);
    HashNode *node = hashTable->buckets[index];

    while (node)
    {
        if (strcmp(node->key, key) == 0) {
            memcpy(node->value, value, hashTable->value_size);
            return;
        }
        node = node->next;
    }

    HashNode *newNode = createHashNode(key, value, hashTable->value_size);
    newNode->next = hashTable->buckets[index];
    hashTable->buckets[index] = newNode;
    hashTable->size++;
}


void* hashTableLookup(HashTable *hashTable, const char *key)
{
    size_t index = hashFunction(key, hashTable->capacity);
    HashNode *node = hashTable->buckets[index];

    while (node)
    {
        if (strcmp(node->key, key) == 0)
        {
            return node->value;
        }

        node = node->next;
    }
    return NULL;
}

void freeHashNodes(HashNode *node)
{
    while (node)
    {
        HashNode *temp = node;
        node = node->next;
        free(temp->key);
        free(temp->value);
        free(temp);
    }
}

void freeHashTable(HashTable *hashTable)
{
    for (size_t i = 0; i < hashTable->capacity; i++)
    {
        freeHashNodes(hashTable->buckets[i]);
    }

    free(hashTable->buckets);
    free(hashTable);
}
