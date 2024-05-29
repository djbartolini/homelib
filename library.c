#include "include/array.h"
#include "include/map.h"
#include "test/test_homelib.h"
#include <stdio.h>

void homelib_welcome()
{
    printf("===============================\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~DANIEL B'S~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~HOMELIB~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("===============================\n");
}


void homelib_initialize() {}
void homelib_init_logging() {}
void homelib_cleanup() {}
void homelib_cleanup_logging() {}

void homelib_free_memory(void *ptr)
{
    free(ptr);
}

void homelib_close_file(FILE *file)
{
    fclose(file);
}
