#include "../include/array.h"
#include "../include/map.h"
#include "../include/unordered_map.h"
#include "../include/stack.h"
#include "../include/queue.h"
#include "../include/set.h"
#include <stdio.h>

void test_array()
{
    printf("///////////// DYNAMIC ARRAY ////////////////////////////////////////////\n");
    DynamicArray *intArray = createDynamicArray(2, sizeof(int));

    // INTEGERS
    int a = 0, b = 1, c = 2, d = 3;

    addElement(intArray, &a);
    addElement(intArray, &b);
    addElement(intArray, &c);

    insertElement(intArray, 1, &d);

    removeElement(intArray, 3);

    for (size_t i=0; i < intArray->size; i++)
    {
        printf("%d ", *(int*)((char*)intArray->array + i * intArray->element_size));
    }
    printf("\n");

    freeDynamicArray(intArray);

    // STRINGS
    DynamicArray *strArray = createDynamicArray(2, sizeof(char*));

    const char *str1 = "Hello";
    const char *str2 = "World";
    const char *str3 = "Dynamic";
    const char *str4 = "Array";

    // Add some strings
    addElement(strArray, &str1);
    addElement(strArray, &str2);
    addElement(strArray, &str3);

    // Insert a string at index 1
    insertElement(strArray, 1, &str4);

    // Print elements
    for (size_t i = 0; i < strArray->size; i++) {
        printf("%s\n", *(char**)((char*)strArray->array + i * strArray->element_size));
    }

    // Free the dynamic array
    freeDynamicArray(strArray);

    printf("////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void test_map()
{
    printf("/////////////////// MAP ////////////////////////////////////////////////\n");

    Map *map = createMap(sizeof(int));

    int value1 = 42;
    int value2 = 84;
    int value3 = 126;

    mapInsert(map, "key1", &value1);
    mapInsert(map, "key2", &value2);
    mapInsert(map, "key3", &value3);

    int *val = (int*)mapLookup(map, "key2");
    if (val) {
        printf("Value for 'key2': %d\n", *val);
    } else {
        printf("Key not found\n");
    }

    freeMap(map);

    printf("////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void test_unordered_map()
{
    printf("////////////////// UNORDERED MAP ///////////////////////////////////////\n");

    HashTable *hashTable = createHashTable(sizeof(int));

    int value1 = 42;
    int value2 = 84;
    int value3 = 126;

    hashTableInsert(hashTable, "key1", &value1);
    hashTableInsert(hashTable, "key2", &value2);
    hashTableInsert(hashTable, "key3", &value3);

    int *val = (int*)hashTableLookup(hashTable, "key2");
    if (val) {
        printf("Value for 'key2': %d\n", *val);
    } else {
        printf("Key not found\n");
    }

    freeHashTable(hashTable);

    printf("////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void test_stack()
{
    printf("///////////////// STACK ////////////////////////////////////////////////\n");
    Stack *stack = stack_create(5);

    stack_push(stack, 10);
    stack_push(stack, 20);
    stack_push(stack, 30);

    printf("Top element: %d\n", stack_peek(stack));
    printf("Popped element: %d\n", stack_pop(stack));
    printf("Popped element: %d\n", stack_pop(stack));
    printf("Top element: %d\n", stack_peek(stack));

    stack_push(stack, 40);
    stack_push(stack, 50);

    printf("Top element: %d\n", stack_peek(stack));

    stack_push(stack, 60);

    stack_free(stack);

    printf("////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void test_queue()
{
    printf("//////////////// QUEUE /////////////////////////////////////////////////\n");
    Queue *queue = queue_create(5);

    queue_enqueue(queue, 10);
    queue_enqueue(queue, 20);
    queue_enqueue(queue, 30);

    printf("Front element: %d\n", queue_peek(queue));
    printf("Dequeued element: %d\n", queue_dequeue(queue));
    printf("Dequeued element: %d\n", queue_dequeue(queue));
    printf("Front element: %d\n", queue_peek(queue));

    queue_enqueue(queue, 40);
    queue_enqueue(queue, 50);

    printf("Front element: %d\n", queue_peek(queue));
    queue_enqueue(queue, 60);

    queue_free(queue);

    printf("////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void test_set()
{
    printf("////////////////// SET /////////////////////////////////////////////////\n");
    Set *set = set_create(10);

    set_add(set, 10);
    set_add(set, 20);
    set_add(set, 30);
    printf("Contains 20: %d\n", set_contains(set, 20)); // Output: 1
    printf("Contains 40: %d\n", set_contains(set, 40)); // Output: 0

    set_remove(set, 20);
    printf("Contains 20: %d\n", set_contains(set, 20)); // Output: 0

    set_free(set);

    printf("////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

int main()
{
    printf("\n");
    printf("////////////////////////////////////////////////////////////////////////\n");
    printf("///////////////////////// test_homelib.c ///////////////////////////////\n");
    printf("////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\n");

    test_array();

    test_map();

    test_unordered_map();

    test_stack();

    test_queue();

    test_set();

    return 0;
}
