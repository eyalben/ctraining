/*
    Magic Numbers, const and define
*/
#include <stdio.h>
#include <stdint.h>

// (2) Defined value
#define MAX_AGE (100)

// (3) Common Mistakes with #define
#define BOYS 10
#define GIRL 15
#define TOTAL 10 + 15
#define PONPONS 2 * TOTAL
// 2 * 10 + 15    is not    2 * (10 + 15)

int main(void)
{
    // (1) Const value
    const uint8_t MAX_AGE_2 = 100;

    // Magic number
    uint8_t age = 0;
    if (age > 120)
    {
        printf("Invalid age");
    }

    return 0;
}