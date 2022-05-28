/*
    String Operations
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>



uint8_t string_length(char *string1)
{
    uint8_t size = 0;
    char *current = string1;
    while ('\0' != *current) {
        size += 1;
        current += 1;
    }

    return size;
}


uint8_t string_length_in_pointers(char *string1)
{
    char *current = string1;
    while ('\0' != *current) {
        current += 1;
    }
    return current - string1;
}


uint8_t string_length_safe(char *string1, uint8_t max_size)
{
    uint8_t size = 0;
    char *current = string1;

    while (('\0' != *current) && (size < max_size)) {
        size += 1;
        current += 1;
    }

    return size;
}


int main(void) 
{
    /* (0) Null-Termination */
    char name[] = "Bonzai";
    printf("String length: %d\n", string_length(name));
    printf("String length: %d\n", string_length_in_pointers(name));

    /* Might crash the code (maybe if name was on datasection - char *name="bonzai") */
    /*name[6] = '!';
    printf("String length: %d\n", string_length(name));*/

    /* safe version */
    name[6] = '!';
    printf("String length: %d\n", string_length_safe(name, 7));

    /* CRT Functions */
    printf("String length: %ld\n", strnlen(name, 7));
    
    return 0;
}



/*
strncat - concatenate one string with part of another
strncmp - compare parts of two strings
strncpy - copy part of a string
strrchr - string scanning operation

    char *name1 = "Bonzai";
    char *name2 = "Tree";
    char buf[100] = {0};
    strncat(buf, name1, 100);
    strncat(buf, " ", 100);
    strncat(buf, name2, 100);
    printf("%s\n", buf);

*/