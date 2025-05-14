/*
    Operators
*/
#include <stdio.h>
#include <stdint.h>

/* (3) */
#define O_READ   (0b00000001)
#define O_WRITE  (0b00000010)
#define O_APPEND (0b00000100)

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
    uint8_t bitwise_or = 0b00000001 | 0b00000010;
    uint8_t bitwise_and = 0b00001111 & 0b11110001;
    uint8_t bitwise_xor = 0b110 ^ 0b011;
    bitwise_of |= 0b100;

    // (4) Bit Flags
    uint8_t flags = O_OPEN | O_WRITE; // 0b00000001 | 0b00000010 = 0b00000011

    // Test if flag is set
    if (flags & O_OPEN)
    {
        printf("Flag of open if set\n");
    }

    // Flags manipulation
    flags |= O_APPEND; // Add append flag
    flags &= ~O_WRITE; // Clear the write flag
    flags ^= O_APPEND; // Flip the state of the append flag

    /* (5) Shift operators */
    printf("24 shift left once is %d\n", 25 << 1);
    printf("24 shift right once is %d\n", 25 >> 1);

    // (6) Logical Operators && and ||
    // Note: If left was false --> won't evaluate right
    printf("Logical Operators result is: %d\n", (1 == 1) && (2 == 2));
    printf("Logical Operators result is: %d\n", (3 == 1) && (2 == 2));

    /* Note: C is NOT javascript*/
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