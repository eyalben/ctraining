/*
    Casting & Resetting Variables
*/
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    /* (0) Clarification */
    /*
    0b1 == 0b001 == 0b00000001
    */

    /* (1) Up-Casting */
    uint8_t num = 0b11;
    uint16_t num2 = num;

    /* (2) Down-Casting */
    uint32_t big = 0xdeadbeef;
    uint16_t invalid = big;         /* Illegal  `-Wall -Wconversion -Werror` */
    uint16_t valid = (uint16_t)big; /* Legal */

    printf("%x\n", valid);

    /* (3) Memory Representation */
    /*
        (32-bit) 0x00001234     ===> Down Casting ==> (16-bit) 0x1234
        (32-bit) 0xDEADBEEF     ===> Down Casting ==> (16-bit) 0xBEEF

         [addr]        0    1    2    3
        Big Endian    [DE] [AD] [BE] [EF]       ==> Casting is hard 
        Little Endian [EF] [BE] [AD] [DE]       ==> Casting is Easy

    */

    return 0;
}