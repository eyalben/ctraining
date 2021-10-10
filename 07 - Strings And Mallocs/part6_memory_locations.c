/*
    Memory Locations

    We have multiple interesting sections:
        .text       The code (read-only)
        .data       Data Section (read/write)
        .bss        Data Section, initially zeroed (read/write)
        .rodata     Literal Strings (read only)
        .stack      Temporary variables
        .heap       Dynamic memory allocations
*/

#include <stdio.h>
#include <stdint.h>

// Global variable resides in .data
int32_t g_value = 123;

// Global variable, reset to zero, resides in .bss
int32_t g_value2 = 0;

// Global array is like global variable, .data (3 items of int32_t == 3 * 4 bytes)
int32_t arr[3] = { 1, 2, 3};

// Same as before (notice: it's an array)
char g_question1[] = { "Hodor?" };

// Global pointer is still a variable, in .data
int32_t *someptr;

// g_questions2 is the same as before, a pointer stored in .data
// it points to a string literal, "Hodor?" which stored in .rodata (and is read-only) 
char *g_question2 = "Hodor?";

int main(void) 
{

    // All are arrays stored in .stack, read-write
    char name1[] = { "hodor" };
    char name2[] = { 'h', 'o', 'd', 'o', 'r', '\0' };
    char name3[6] = { 'h', 'o', 'd', 'o', 'r', '\0' };
    char name4[] = "hodor";

    // Pointer is still a local variable, stored in .stack
    char *question;

    // Pointer points to a string literal, stored in .rodata
    question = "Aha?";

    // Altough question is stored in .stack, the destination is in .rodata and therefore can not be modified
    // question[3] = '!';     <== Invalid
    question = "Aha!";

    // ptr is a variable stored in the .stack
    // the address returned from malloc() is from .heap
    void *ptr = malloc(100);

    return 0;
}