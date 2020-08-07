/*
    Enums & Return Values
*/

#include <stdio.h>
#include <stdint.h>

#define NELEM(x) (sizeof((x)) / sizeof(x[0]))

typedef enum error_codes_e {
    E_SUCCESS = 0,
    E_INVALID_INPUT,
    E_FILE_NOT_FOUND,
} error_codes_t;

struct error_desc {
    error_codes_t code;
    char *message;
} g_error_desc[] = {

    { E_SUCCESS, "No Error" },
    { E_INVALID_INPUT, "Invalid input was given to functions" },
    { E_FILE_NOT_FOUND, "File was not found on disk" },

};


void print_error(error_codes_t err) 
{
    error_codes_t i = 0;
    if (0 != err)
    {
        printf("Error occurrred:\n");

        /* find error */
        for (i = 0; i < NELEM(g_error_desc); ++i)
        {
            if (g_error_desc[i].code == err) {
                printf(" >> %s\n", g_error_desc[i].message);
            }
        }
    }
    
}

error_codes_t func(void)
{
    return E_FILE_NOT_FOUND;
}


int main(void) 
{
    /* (0) */
    print_error(func());
    
    return 0;
}