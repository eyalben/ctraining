/*
    Flow Control (2)
*/
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    /* (1) While loops */
    uint32_t result = 1;
    int start = 4;
    while (start > 0)
    {
        result *= start;
        start--;
    }
    printf("Factorial result: %d\n", result);

    /* (2) Do While */
    // do {
    //     /* do stuff */
    // } while (condition);

    /* (3) Infinite Loops */
    int32_t number = 0;
    while (1)
    {
        number++;
        if (number % 2)
        {
            continue;
        }
        if (10 == number)
        {
            break;
        }
        printf("> %d\n", number);
    }

    /* (4) For Loop */
    // for (initialization; test; increment) {
    // /* code */
    // }
    uint32_t i = 0;
    for (i = 0; i < 10; ++i)
    {
        printf("Value: %d\n", i);
    }

    // for (;;) {
    // /* block of statements */
    // }

    /*
    Note:
        The pre-increment (++i) is usually preferred where you can use either.
        This is because if you use post-increment, it can require the compiler to have to 
        generate code that creates an extra temporary variable.
        This is because both the previous and new values of the variable being incremented need to be held
        somewhere because they may be needed elsewhere in the expression being evaluated.
    */

    return 0;
}