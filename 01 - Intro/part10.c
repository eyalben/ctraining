/*
    Goto
*/

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    /* (1) Goto Loop (don't do that!!!) */
    int counter = 0;

count_untill_five:
    printf("Counter is: %d\n", counter);
    counter += 1;
    if (counter <= 5)
    {
        goto count_untill_five;
    }

    /* (2) Proper use of goto
        There is only one - we will see further in the road.

        For now - DO NOT USE IT.
     */

    return 0;
}