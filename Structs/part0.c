/*
    Typedefs
*/

#include <stdio.h>
#include <stdint.h>

typedef void (*void_function)(void);
typedef int32_t (*math_function)(int32_t, int32_t);

void void1()
{
    printf("Func1\n");
}


void void2()
{
    printf("Func2\n");
}


int sub(int x, int y) 
{
    return x - y;
}


int mul(int x, int y) 
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


    call_math(sub, 10, 20);




    return 0;
}