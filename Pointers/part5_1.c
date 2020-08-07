/*
    Pointers to functions
*/

#include <stdio.h>
#include <stdint.h>

void void1()
{
    printf("Func1\n");
}


void void2()
{
    printf("Func2\n");
}


void fargs1(int x)
{
    printf("The number is: %d\n", x);
}


void fargs2(int x)
{
    printf("The next number is: %d\n", x+1);
}


int sub(int x, int y) 
{
    return x - y;
}


int mul(int x, int y) 
{
    return x * y;
}


int main(void) 
{
    /* (1) Void Pointers */
    void (*pvoid)();

    pvoid = void1;
    pvoid();

    pvoid = void2;
    pvoid();


    /* (2) Arguments in Pointers */
    void (*pfargs)(int);

    pvoid = fargs1;
    pvoid(10);

    pvoid = fargs2;
    pvoid(10);


    /* (3) Return Value */
    int (*pmath)(int, int);

    pmath = sub;
    printf("Result is: %d\n", pmath(10, 2));

    pmath = mul;
    printf("Result is: %d\n", pmath(10, 2));


    /* (4) :o */
    /*
        char* (*(*foo[5])(char*))[];

        foo is an array of 5 pointers to a function that accepts a pointer to a char and returns a pointer to an array of pointers to a char.
    */


// typedef void (*void_function)(void);
// typedef int32_t (*math_function)(int32_t, int32_t);

    return 0;
}


