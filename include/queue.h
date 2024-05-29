#ifndef HOMELIB_QUEUE_H
#define HOMELIB_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

// Define the Queue structure
typedef struct
{
    int *array;     // Array to store queue elements
    int front;      // Index of the front element
    int rear;       // Index of the rear element
    int capacity;   // Capacity of the queue
    int size;       // Current size of the queue
} Queue;

// Create a new queue
Queue* queue_create(int capacity);

// Check if the queue is full
int queue_isFull(Queue *queue);

// Check if the queue is empty
int queue_isEmpty(Queue *queue);

// Enqueue an element into the queue
void queue_enqueue(Queue *queue, int element);

// Dequeue an element from the queue
int queue_dequeue(Queue *queue);

// Peek the front element of the queue
int queue_peek(Queue *queue);

// Free the queue
void queue_free(Queue *queue);


#endif // HOMELIB_QUEUE_H
