#include "../include/set.h"

// Hash function
size_t hashFunction(int value, size_t capacity) {
    return (size_t)(value % capacity);
}

// Create a new node
SetNode* createSetNode(int value)
{
    SetNode *newNode = (SetNode*)malloc(sizeof(SetNode));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

Set* set_create(size_t capacity)
{
    Set *set = (Set*)malloc(sizeof(Set));
    set->buckets = (SetNode**)calloc(capacity, sizeof(SetNode*));
    set->capacity = capacity;
    set->size = 0;
    return set;
}

void set_add(Set *set, int value)
{
    size_t index = hashFunction(value, set->capacity);
    SetNode *node = set->buckets[index];

    // Check if the value is already in the set
    while (node)
    {
        if (node->value == value)
        {
            return; // Value already exists in the set
        }

        node = node->next;
    }

    // Insert the new value at the beginning of the list
    SetNode *newNode = createSetNode(value);
    newNode->next = set->buckets[index];
    set->buckets[index] = newNode;
    set->size++;
}

void set_remove(Set *set, int value)
{
    size_t index = hashFunction(value, set->capacity);
    SetNode *node = set->buckets[index];
    SetNode *prev = NULL;

    // Find the node to be removed
    while (node)
    {
        if (node->value == value)
        {
            if (prev)
            {
                prev->next = node->next;
            }
            else
            {
                set->buckets[index] = node->next;
            }

            free(node);
            set->size--;

            return;
        }

        prev = node;
        node = node->next;
    }
}

int set_contains(Set *set, int value)
{
    size_t index = hashFunction(value, set->capacity);
    SetNode *node = set->buckets[index];

    // Search for the value in the linked list
    while (node)
    {
        if (node->value == value)
        {
            return 1; // Value found
        }

        node = node->next;
    }

    return 0; // Value not found
}

void set_free(Set *set)
{
    for (size_t i = 0; i < set->capacity; i++)
    {
        SetNode *node = set->buckets[i];

        while (node)
        {
            SetNode *temp = node;
            node = node->next;
            free(temp);
        }
    }

    free(set->buckets);
    free(set);
}
