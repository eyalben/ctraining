/*
    Bit-Fields in structs
*/
#include <stdio.h>
#include <stdint.h>

union example_u
{
    struct {
        uint8_t bit1:1;
        uint8_t bit2:1;
        uint8_t bit3:1;
        uint8_t bit4:1;
        uint8_t reserved:4;
    } bits;
    uint8_t byte;

};

typedef union example_u example_t;


int main(void) 
{
    example_t u = { .byte = 0 };

    printf("Value: %x\n", u.byte);

    u.bits.bit1 = 1;
    u.bits.bit2 = 1;
    printf("Value: %x\n", u.byte);

    return 0;
}
