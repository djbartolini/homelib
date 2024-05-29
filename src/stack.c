#include "../include/stack.h"

Stack* stack_create(int capacity)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));

    stack->array = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;

    return stack;
}

int stack_isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

int stack_isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void stack_push(Stack *stack, int element)
{
    if (stack_isEmpty(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = element;
    printf("%d pushed to stack\n", element);
}

int stack_pop(Stack *stack)
{
    if (stack_isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int stack_peek(Stack *stack)
{
    if (stack_isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top];
}

void stack_free(Stack *stack)
{
    free(stack->array);
    free(stack);
}

