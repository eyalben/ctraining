/*
    Dynamic Allocations
*/

#include <stdio.h>
#include <stdint.h>

/* Home of Malloc */
#include <stdlib.h> 

/* memset */
#include <string.h> 

#define MAX_SIZE (30)    

int main(void) 
{
    /* (0) Calloc */
    int32_t *arr1 = calloc(MAX_SIZE, sizeof(int32_t));
    free(arr1);

    /* (1) Realloc NULL is equal to malloc */
    int32_t *array = NULL;
    int32_t old_array = NULL;

    array = realloc(NULL, 1000);
    if (NULL == array)
    {
        /* goto l_cleanup; */
    }

    old_array = array;
    array = realloc(array, 5000);
    if (NULL == array)
    {
        /* Not enough memory, but previous memory is still there */
        free(old_array);
    }
   
    return 0;
}