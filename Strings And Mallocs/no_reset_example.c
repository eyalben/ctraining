/*
    Example: Why you must reset stack variables

    This examples shows unexpected outputs
*/

#include <stdio.h>

void foo() {
    int x;
    int y;
    int z;
    printf("Three values: %d %d %d\n", x, y, z);
}

void bar() {
    int x;
    int y;
    int z;

    x = 100;
    y = 200;
    z = 300;
}

int main(int argc, char *argv[]) {

    foo();
    bar();
    foo();

    printf("Hello my name is: %s\n", "Eyal");
    foo();

    return 0;
}
