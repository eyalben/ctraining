/*
    Dynamic Allocations
*/

#include <stdio.h>
#include <stdint.h>

/* Home of Malloc */
#include <stdlib.h> 

/* memset */
#include <string.h> 


/*void *calloc(size_t nmemb, size_t size);
void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);*/

// Casting from (void *) is unnecessary, as void * is automatically and safely promoted to any other pointer type in this case.
//          But maybe it is in the conventions?

    
#define MAX_SIZE (30)    

int main(void) 
{
    /* (0) Basic Allocation */
    int8_t *arr1 = malloc(8);
    int32_t *arr2 = malloc(8); /* WRONG */

    /* We should use sizeof */
    int32_t *arr3 = malloc(8 * sizeof(int32_t)); /* WRONG AGAIN */
    /* int32_t *arr3 = malloc(8 * sizeof(*arr3)); */  /* Correct yay! */

    // MUST FREE - else memory leaks
    free(arr1);
    free(arr2);
    free(arr3);

    /* WARN - dont free buffer not allocated by malloc
    int32_t arr[100] = {0};
    free(arr);
    */
    

    /* (1) Memory is not initialized! */
    int8_t *reset = malloc(8);
    memset(reset, 0, 8);
    free(reset);

    /* (2) That's why we use #define */
    int8_t *with_define = malloc(MAX_SIZE * sizeof(*reset));
    memset(reset, 0, MAX_SIZE * sizeof(*reset));
    free(with_define);


    /* (3) Malloc might fail */
    int32_t *items = malloc(MAX_SIZE * sizeof(*items));
    if (NULL == items) 
    {
        /* Handle Error, goto l_cleanup */
        goto l_cleanup;
    }

l_cleanup:
    /* (4) NEVER Free NULL value */
    if (NULL != items) {
        free(items);
    }
    
    return 0;
}