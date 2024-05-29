#ifndef HOMELIB_STACK_H
#define HOMELIB_STACK_H

#include <stdio.h>
#include <stdlib.h>

// Define the Stack structure
typedef struct
{
    int *array;     // Array to store stack elements
    int top;        // Index of the top element
    int capacity;   // Capacity of the stack
} Stack;

// Create a new stack
Stack* stack_create(int capacity);

// Check if the stack is full
int stack_isFull(Stack *stack);

// Check if the stack is empty
int stack_isEmpty(Stack *stack);

// Push an element onto the stack
void stack_push(Stack *stack, int element);

// Pop an element from the stack
int stack_pop(Stack *stack);

// Peek the top element of the stack
int stack_peek(Stack *stack);

// Free the stack
void stack_free(Stack *stack);


#endif // HOMELIB_STACK_H
