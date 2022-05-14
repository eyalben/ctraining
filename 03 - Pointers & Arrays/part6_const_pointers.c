/*
    Const Pointers (Yuck!)
*/
#include <stdio.h>
#include <stdint.h>


int main(void)
{
    long x = 100;
    long x2 = 200;

    // (1) You can change whatever ptr is pointing to
    const long *ptr = &x;
    // long const *ptr = &x; // << the same

    // (2) You can't change content
    long * const ptr2 = &x;

    printf("X value is: %ld\n", *ptr);

    ptr = &x2;
    *ptr2 = 123;

    printf("X value is: %ld\n", *ptr);

    // (3) Why? Becuase it came from C++ and C++ is the devil

    return 0;
}