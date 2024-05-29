#include "../include/queue.h"

Queue* queue_create(int capacity)
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->array = (int*)malloc(capacity * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->size = 0;
    return queue;
}

int queue_isFull(Queue *queue)
{
    return queue->size == queue->capacity;
}

int queue_isEmpty(Queue *queue)
{
    return queue->size == 0;
}

void queue_enqueue(Queue *queue, int element)
{
    if (queue_isFull(queue))
    {
        printf("Queue is full\n");
        return;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = element;
    queue->size++;
}

int queue_dequeue(Queue *queue)
{
    if (queue_isEmpty(queue))
    {
        printf("Warning: Queue is empty\n");
        return -1;
    }

    int frontElement = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    return frontElement;
}

int queue_peek(Queue *queue)
{
    if (queue_isEmpty(queue))
    {
        printf("Warning: Queue is empty\n");
        return -1;
    }

    return queue->array[queue->front];
}

void queue_free(Queue *queue)
{
    free(queue->array);
    free(queue);
}
