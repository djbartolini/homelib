#ifndef HOMELIB_SET_H
#define HOMELIB_SET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the SetNode structure
typedef struct SetNode
{
    int value;
    struct SetNode *next;
} SetNode;

// Define the Set structure
typedef struct
{
    SetNode **buckets;
    size_t capacity;
    size_t size;
} Set;

// Create a new set
Set* set_create(size_t capacity);

// Add an element to the set
void set_add(Set *set, int value);

// Remove an element from the set
void set_remove(Set *set, int value);

// Check if the set contains an element
int set_contains(Set *set, int value);

// Free the set
void set_free(Set *set);


#endif // HOMELIB_SET_H
