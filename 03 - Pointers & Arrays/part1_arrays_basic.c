/*
    One dimensional Arrays
*/

#include <stdio.h>
#include <stdint.h>

#define NELEM(x) (sizeof((x)) / sizeof(x[0]))

/* (5) */
void print_array(int32_t arr[], uint32_t size);

/* (6) Bad Macros */
#define BAD_SQUARE(x) x * x
#define SQUARE(x) ((x) * (x))

void bad_vs_good_macro(void) 
{
    int32_t a = 1;
    printf("Bad Square: %d\n",  BAD_SQUARE(a + 1));
    printf("Good Square: %d\n", SQUARE(a + 1));
    // BAD_SQUARE(a + 1) ==> a + 1 * a + 1
}

int main(void) 
{
    /* (1) Basic initialization */ 
    uint32_t array[10]; /* uninitialized */
    uint32_t i = 0;

    for (i = 0; i < 10; ++i) {
        array[i] = i*3;
    }

    printf(">> Uninitialized array: \n");
    for (i = 0; i < 10; ++i) {
        printf("array[%d] = %d\n", i, array[i]);
    }

    /* (2) Initialization types */
    int32_t a1[10] = {100, 200, 300}; /* Implicit 0 */
    int32_t a2[] = {10, 20, 30};
    int16_t a3[] = { 0x0001, 0x0002, 0x0003 };
    int8_t a4[] = { "Hello" };


    /* (3) Size of array */
    /* WRONG */
    printf("Size of three16 is %zu\n", (sizeof(a3)));

    /* BETTER */
    printf("Size of a3 is %zu\n", (sizeof(a3) / sizeof(int8_t)));

    /* RIGHT */
    printf("Size of a3 is %zu\n", (sizeof(a3) / sizeof((a3)[0])));

    /* As MACRO */
    #define NELEM(x) (sizeof((x)) / sizeof(x[0]))

    /* (4) Out of boundary */
    /* Compiler might not complain
    i = a1[10];
    i = a1[-5];
    */

    /* (5) Passing array to a function */
    print_array(a1, NELEM(a1));
    
    return 0;
}

void print_array(int32_t arr[], uint32_t size) {
    int32_t i = 0;

    for (i = 0; i < size; i++) {
        printf("array[%d] = %d\n", i, arr[i]);
    }
}