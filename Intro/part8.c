/*
    Flow Control (1)
*/
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t age = 18;

    /* (1) Conditions */
    if (18 == age)
    {
        /* do something */
    }

    /*
    Note:
        1. Always use {} blocks
        2. Don't age = 18 or age == 18
    */

    /* (2) Conditional */
    uint32_t num1 = 100;
    uint32_t num2 = 200;

    uint32_t bigger_number = (num1 > num2) ? num1 : num2;

    /* (3) Else if */
    /*
    if (grade == 1)
    {
        printf("A\n");
    }
    else if (grade == 2)
    {
        printf("B\n");
    }
    else if ....
    */

    /* Switch Case */
    uint8_t grade = 2;
    switch (grade)
    {
    case 1:
        printf("A\n");
        break;
    case 2:
        printf("B\n");
        break;
    case 3:
        printf("C\n");
        break;
    case 4:
        printf("D\n");
        break;
    default:
        printf("F\n");
        break;
    }

    /* Note: we can join two cases:
            case 1:
            case 2:
            case 3:
                do_something();
    */

    return 0;
}