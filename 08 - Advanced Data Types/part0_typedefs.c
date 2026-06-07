/*
    Typedefs
*/

#include <stdio.h>
#include <stdint.h>

typedef void (*void_function)(void);
typedef int32_t (*math_function)(int32_t, int32_t);

// (3 - Advanced) - gcc -E with stdint, take a look how int32_t is defined

void void1()
{
    printf("Func1\n");
}


void void2()
{
    printf("Func2\n");
}


int32_t sub(int32_t x, int32_t y) 
{
    return x - y;
}


int32_t mul(int32_t x, int32_t y) 
{
    return x * y;
}


void call_math(math_function m, int32_t x, int32_t y) 
{
    printf("Result is: %d\n", m(x,y));
}

int main(void) 
{
    
    void_function v = NULL;
    v = void1;
    v();
    v = void2;
    v();


    call_math(sub, 10, 20);
    call_math(mul, 10, 20);

    return 0;
}