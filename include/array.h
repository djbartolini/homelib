#ifndef HOMELIB_ARRAY_H
#define HOMELIB_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

// Dynamic Array Structure
typedef struct
{
    void **array;
    size_t size;
    size_t capacity;
    size_t element_size;
} DynamicArray;

// Initializes the dynamic array structure
DynamicArray* createDynamicArray(size_t initial_capacity, size_t element_size);

// Adds an element to the dynamic array structure
void addElement(DynamicArray *dynArray, void *element);

// Inserts an element at a given index in the dynamic array
void insertElement(DynamicArray *dynArray, int index, void *element);

// Removes an element from the dynamic array structure
void removeElement(DynamicArray *dynArray, int index);

// Free the dynamic array
void freeDynamicArray(DynamicArray *dynArray);


#endif // HOMELIB_ARRAY_H
