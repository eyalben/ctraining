/*
    Scope And Initialization
*/
#include <stdio.h>
#include <stdint.h>

void func(uint32_t x, uint32_t y, uint32_t z)
{
    printf("Valued: %d %d %d\n", x, y, z);
}

void func2(void)
{
    uint32_t local_var = 0; /* remove `= 0` to make it work */
    printf("Local Var: %x\n", local_var);
    /* printed value is unexpected */
}

void static_example(void)
{
    static uint32_t count = 0;

    printf("Function called %d times\n", ++count);
}

int main(void)
{
    /* (1) Common Bug */
    func(0x111, 0x222, 0x333);
    func2();

    /* (2) Scope */

    uint32_t local_var = 6;
    printf("Local Var: %x\n", local_var);
    {
        uint32_t local_var = 5;
        printf("Local Var: %x\n", local_var);
    }
    printf("Local Var: %x\n", local_var);

    /* (3) Static Variables */
    static_example();
    static_example();
    static_example();

    return 0;
}
