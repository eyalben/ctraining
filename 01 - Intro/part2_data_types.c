/*
    Data Types
*/
#include <stdio.h>

/* (2) */
#include <stdint.h>

int main(void)
{
    /* (1) Data types and sizes */
    char a = 'a'; /* ASCII */
    short s = 1234;
    int i = 1234;
    long l = 0x1337;
    long long ll = 1234;

    float f = 1.5;
    double d = 1.5;

    unsigned ui = 1234;
    /* no bool => 0 is false, all other numbers are true */
    /* <stdbool.h> was introduced in C99 */

    printf("Size of: %zu\n", sizeof(a));
    printf("Size of: %zu\n", sizeof(s));
    printf("Size of: %zu\n", sizeof(i));
    printf("Size of: %zu\n", sizeof(l));
    printf("Size of: %zu\n", sizeof(ll));
    printf("Size of: %zu\n", sizeof(f));
    printf("Size of: %zu\n", sizeof(d));

    /* (1.5) Void Pointer (we'll talk about this later) */
    void *ptr = NULL;
    printf("Size of: %zu\n", sizeof(ptr)); /* (1.6) The difference between 32 and 64 */

    /* (2) STDINT Data Types */
    int32_t number = 1234;
    uint8_t age = 120;

    /* (3) We'll talk about static variables later */

    /* Different bases */
    int32_t bases = 12;
    printf("bases=%d\n", bases);

    // Octal
    bases = 012;
    printf("bases=%d\n", bases);

    // Hexadecimal
    bases = 0x12;
    printf("bases=%d\n", bases);

    return 0;
}

/*
    %d - signed decimal integers
    %ld - long int (same as %li)
    %hd - short int

    %u - unsigned integer
    %lu - unsigned long int
    %hu - unsigned short integer

    %f - float
    %lf - double[1]
    
    %c - char
    %s - string
    %x - hexadecimal
    %o - octal integers
    %p - pointers

    %zu - size_t / sizeof()
*/