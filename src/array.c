#include "../include/array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DynamicArray* createDynamicArray(size_t initial_capacity, size_t element_size)
{
    DynamicArray *dynArray = (DynamicArray *)malloc(sizeof(DynamicArray));

    dynArray->array = (void **) malloc(initial_capacity * sizeof(DynamicArray));
    dynArray->size = 0;
    dynArray->capacity = initial_capacity;
    dynArray->element_size = element_size;

    return dynArray;
}

void addElement(DynamicArray *dynArray, void *element)
{
    if (dynArray->size == dynArray->capacity)
    {
        dynArray->capacity *= 2;

        dynArray->array = realloc(
            dynArray->array, dynArray->capacity * dynArray->element_size
        );
    }

    memcpy(
        (char*)dynArray->array + dynArray->size * dynArray->element_size,
        element,
        dynArray->element_size
    );

    dynArray->size++;
}

void insertElement(DynamicArray *dynArray, int index, void *element)
{
    if (index < 0 || index > dynArray->size)
    {
        printf("Error: Index out of bounds.\n");
        return;
    }

    if (dynArray->size == dynArray->capacity)
    {
        dynArray->capacity *= 2;
        dynArray->array = realloc(
            dynArray->array, dynArray->capacity * dynArray->element_size
        );
    }

    memmove(
        (char*)dynArray->array + (index + 1) * dynArray->element_size,
        (char*)dynArray->array + index * dynArray->element_size,
        (dynArray->size - index) * dynArray->element_size
    );

    memcpy(
        (char*)dynArray->array + index * dynArray->element_size,
        element,
        dynArray->element_size
    );

    dynArray->size++;
}

void removeElement(DynamicArray *dynArray, int index)
{
    if (index < 0 || index >= dynArray->size)
    {
        printf("Error: Index out of bounds");
        return;
    }

    memmove(
            (char*)dynArray->array + (index + 1) * dynArray->element_size,
            (char*)dynArray->array + index * dynArray->element_size,
            (dynArray->size - index) * dynArray->element_size
    );

    dynArray->size--;

    if (dynArray->size > 0 && dynArray->size == dynArray->capacity / 4)
    {
        dynArray->capacity /= 2;

        dynArray->array = realloc(
                dynArray->array, dynArray->capacity * dynArray->element_size
        );
    }
}

// Free the dynamic array
void freeDynamicArray(DynamicArray *dynArray)
{
    free(dynArray->array);
    free(dynArray);
}
