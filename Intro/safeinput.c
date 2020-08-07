/*
    Recap: Safe user input (on linux, since we don't have scanf_s)
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    unsigned short age = 0;
    unsigned char name[255] = {0};
    char *dynamic = NULL;

    printf("Hi!\n");
    printf("Your name: ");

    // Method 1: Unsafe
    // scanf("%s", name);

    // Method 2: Safer
    // scanf("%254s", name);

    // Method 3: Safer (but we will have \n)
    // fgets(name, 255, stdin);
    
    // printf("Your age: ");
    // scanf("%hu", &age);

    // printf("\n");
    // printf("Welcome %s of age %d!\n", name, age);


    // Method 4: Dynamic allocations
    // scanf("%ms", &dynamic);
    // printf("Dynamic: %s\n", dynamic);
    // free(dynamic);

    // Method 5: Windows Only
    // TBD: scanf_s


    return 0;
}