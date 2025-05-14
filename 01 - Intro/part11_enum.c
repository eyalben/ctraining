/*
    Enums
*/
#include <stdio.h>
#include <stdint.h>

typedef enum { 
    STATUS_CODE_SUCCESS,
    STATUS_CODE_FAILURE,
    STATUS_CODE_INVALID_ARGUMENT,
    STATUS_CODE_OUT_OF_MEMORY,
    STATUS_CODE_TIMEOUT,
    STATUS_CODE_UNAUTHORIZED,
} STATUS_CODE_t;

int main(void)
{
    // exmaple of status code
    STATUS_CODE_t status_code = STATUS_CODE_SUCCESS;

    // Example of fail
    if (10 < 40) {
        status_code = STATUS_CODE_FAILURE;
        goto l_cleanup;
    }

    printf("No failure\n");

l_cleanup:
    return 0;
}
