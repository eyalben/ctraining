/*
    Unions
*/

#include <stdio.h>
#include <stdint.h>

union example_u
{
    struct {
        uint8_t byte1;
        uint8_t byte2;
        uint8_t byte3;
        uint8_t byte4;
    } bytes;
    uint32_t dword;

};

typedef union example_u example_t;


int main(void) 
{
    example_t u;

    u.dword = 0xDEADBEEF;
    printf("Value: %x\n", u.dword);

    u.bytes.byte1 = 0xFF;
    printf("Value: %x\n", u.dword);

    return 0;
}