/*
    Operators
*/
#include <stdio.h>
#include <stdint.h>

/* (3) */
#define BITFLAG1 (1) /* 0...0001 */
#define BITFLAG2 (2) /* 0...0010 */
#define BITFLAG3 (4) /* 0...0100 */

int main(void)
{
    /*
    (1) Unary Operators

        Operator     Meaning
        ========     =======
        !         Logical negation ( (!E) is equivalent to (0==E) )
        ++        Algebric Pre/Postfix
        --        Algebric Pre/Postfix

        ~         Bitwise NOT
    */

    // (2) Prefix/Postfix Operators (algebric)
    uint8_t value = 100;
    printf("value: %d\n", value++);
    printf("value after: %d\n", value);

    uint8_t value2 = 100;
    printf("value: %d\n", ++value2);
    printf("value after: %d\n", value2);

    // (3) Bitwise Operators (e.g. let's talk about bitflags)
    int32_t bitbucket = 2; /* 0b0010 */
    bitbucket = bitbucket | 0b1;
    printf("Bit bucket value: %d\n", bitbucket);

    // (4) Bit Flags
    //     For Example:
    //         open("filename", O_READ | O_WRITE)
    bitbucket |= BITFLAG1;  /* Set bit flag 1 */
    bitbucket &= ~BITFLAG2; /* Clear bit flag 2 */
    bitbucket ^= BITFLAG3;  /* Flip the state of bit flag 3 from off to on or */

    /* (5) Shift operators */
    printf("24 shift left once is %d\n", 25 << 1);
    printf("24 shift right once is %d\n", 25 >> 1);

    // (6) Logical Operators && and ||
    // Note: If left was false --> won't evaluate right
    printf("Logical Operators result is: %d\n", (1 == 1) && (2 == 2));
    printf("Logical Operators result is: %d\n", (3 == 1) && (2 == 2));

    /* C is NOT javascript*/
    printf("Logical Operators result is: %d\n", 5 || 3);

    // (7) Conditional Operator
    uint32_t age = 20;

    // Can we drink alcohol?)
    char is_adult = (age >= 18 ? 'y' : 'n');
    printf("Is adult (y/n)? %c\n", is_adult);

    /* (8) Assignment Operators
    Complete list:
                    =
                    *=
                    /=
                    %=
                    +=
                    -=
                    <<=
                    >>=
                    &=
                    ^=
                    |= 
    */

    return 0;
}