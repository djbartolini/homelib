#include "../include/map.h"

MapNode* createNode(const char *key, void *value, size_t value_size)
{
    MapNode *newNode = (MapNode*) malloc(sizeof(MapNode));

    newNode->key = strdup(key);
    newNode->value = malloc(value_size);

    memcpy(newNode->value, value, value_size);

    newNode->left = newNode->right = NULL;

    return newNode;
}

MapNode* insertNode(MapNode *node, const char *key, void *value, size_t value_size)
{
    if (node == NULL)
    {
        return createNode(key, value, value_size);
    }

    int cmp = strcmp(key, node->key);

    if (cmp < 0)
    {
        node->left = insertNode(node->left, key, value, value_size);

    }
    else if (cmp > 0)
    {
        node->right = insertNode(node->right, key, value, value_size);
    }
    else
    {
        memcpy(node->value, value, value_size);
    }

    return node;
}

void* lookupNode(MapNode *node, const char *key)
{
    if (node == NULL)
    {
        return NULL;
    }

    int cmp = strcmp(key, node->key);

    if (cmp < 0)
    {
        return lookupNode(node->left, key);
    }
    else if (cmp > 0)
    {
        return lookupNode(node->right, key);
    }
    else
    {
        return node->value;
    }
}

void freeNode(MapNode *node)
{
    if (node != NULL)
    {
        free(node->key);
        free(node->value);
        freeNode(node->left);
        freeNode(node->right);
        free(node);
    }
}

Map* createMap(size_t value_size)
{
    Map *map = (Map*)malloc(sizeof(Map));

    map->root = NULL;
    map->value_size = value_size;

    return map;
}

void mapInsert(Map *map, const char *key, void *value)
{
    map->root = insertNode(map->root, key, value, map->value_size);
}

void* mapLookup(Map *map, const char *key)
{
    return lookupNode(map->root, key);
}

void freeMap(Map *map)
{
    freeNode(map->root);
    free(map);
}
