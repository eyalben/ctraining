/*
    Usage example of double pointer
*/

#include <stdio.h>
#include <stdint.h>

/* Home of Malloc */
#include <stdlib.h> 

/* memset */
#include <string.h> 
    
typedef enum {
    MYLIB_SUCCESS,
    MYLIB_MEMORY_ERROR
} MY_LIB_status_t;

MY_LIB_status_t MY_LIB_init(int32_t **item, int32_t size) {
    MY_LIB_status_t status = MYLIB_SUCCESS;

    int32_t *new_array = malloc(size * sizeof(*new_array));

    if (NULL == new_array) {
        status = MYLIB_MEMORY_ERROR;
        goto cleanup;
    }

    // Reset Values immediately (that's why I didn't use memset)
    for (int i = 0; i < size; ++i) {
        new_array[i] = i;
    };

    *item = new_array;

cleanup:
    return status;
}

void MY_LIB_free(int32_t **item) {
    free(*item);
    *item = NULL;
}


int main(void) 
{
    /* (0) Basic Allocation */
    int32_t *example = NULL;
    MY_LIB_init(&example, 20);
    // TBD: Check error value
    
    for (size_t i = 0; i < 20; ++i)
    {
        printf("%d\n", example[i]);
    }
    
    MY_LIB_free(&example);

    return 0;
}