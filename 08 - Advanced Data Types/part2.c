/*
    Simple Structs & Sizes
*/

#include <stdio.h>
#include <stdint.h>

/* (1) Simple */
struct point_s {
    int32_t x;
    int32_t y;
};

typedef struct point_s point_t;

/* (1) Complex */
typedef int32_t (*math_function)(int32_t, int32_t);

struct complex_s {
    int32_t number;
    char name[100];
    char *pointer;
    math_function func;
};

typedef struct complex_s complex_t;


void print_point(point_t p)
{
    printf("X: %d Y: %d\n", p.x, p.y);
}

void change_point(point_t *p) 
{
    p->x = 1;
    p->y = 1;
}

int main(void) 
{
    /* (2) Initializing */
    point_t p_example = { .x = 10, .y = 20 };
    print_point(p_example);

    /* (3) Sizeofs */
    point_t p1 = {0};
    complex_t c1 = {0};

    printf("Size of p1: %ld\n", sizeof(p1));
    printf("Size of c1: %ld\n", sizeof(c1));

    p1.x = 100;
    p1.y = 200;


    /* (4) Struct Pointer */
    point_t *ptr = &p1;
    p1.x = 15;
    printf("P1 X Value is: %d\n", p1.x);

    ptr->x = 30;
    printf("P1 X Value is: %d\n", p1.x);

    
    /* (4) Struct as arguments */
    print_point(p1);  /* structs will be copied entierly */
    change_point(&p1);
    print_point(p1);  /* structs will be copied entierly */

    return 0;
}