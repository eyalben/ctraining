/*
    Dynamic Struct Allocations
*/

#include <stdio.h>
#include <stdint.h>

/* Home of malloc */
#include <stdlib.h> 

/* memset */
#include <string.h> 


struct point_s {
    int32_t x;
    int32_t y;
};

typedef struct point_s point_t;


void print_point(point_t p)
{
    printf("X: %d Y: %d\n", p.x, p.y);
}

int main(void) 
{

    /* (5) Dynamic Allocations */
    point_t *p = malloc(sizeof(point_t));
    p->x = 10;
    p->y = 99;
    print_point(*p);
    free(p);


    /* (6) Dynamic Allocs and memset */
    point_t *p2 = malloc(sizeof(point_t));
    memset(p2, 0, sizeof(*p2));

    free(p2);

    return 0;
}