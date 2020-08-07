/*
    Functions
*/
#include <stdio.h>
#include <stdint.h>

/* (3) Forward Declaration */
int32_t mul(int32_t a, int32_t b);

/* (1) */
int32_t sum(int32_t a, int32_t b)
{
    return a + b;
}

/* (2) Void function */
void print_number(int32_t number)
{
    printf("Number is: %d\n", number);
}

int main(void)
{
    printf("Sum of 10+5 is: %d\n", sum(10, 5));

    return 0;
}

int32_t mul(int32_t a, int32_t b)
{
    return a * b;
}
