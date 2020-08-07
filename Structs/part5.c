/*
    Packed Structs
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


typedef struct line_s {
    uint32_t length;
    char contents[0]; /* might (or not) be one byte size */
} line_t;


struct ex1 {
    uint32_t a;
    uint8_t b;
    // char pad[3];
};

struct ex2 {
    uint16_t a;
    uint8_t b;
    // char pad[1];
};

#pragma pack(1)
struct pex1 {
    uint32_t a;
    uint8_t b;
    // char pad[3];
};

#pragma pack(1)
struct pex2 {
    uint16_t a;
    uint8_t b;
    // char pad[1];
};




/* (optional) Flexible Array members */
typedef struct example_s {
    uint32_t x;
    uint32_t y[];
} example_t;

/* Allowed only in globals */
example_t a = { 1, {2, 3, 4} };


int main(void) 
{
    /* (1) Dynamic Allocations */
    line_t *line = malloc(sizeof(line_t) * 10);

    line->length = 5;
    strncpy(line->contents, "hi", 10);

    free(line);

    /* (2) Packed Structures */
    printf("Size of ex1: %ld\n", sizeof(struct ex1));
    printf("Size of ex2: %ld\n", sizeof(struct ex2));
    printf("Size of pex1: %ld\n", sizeof(struct pex1));
    printf("Size of pex2: %ld\n", sizeof(struct pex2));

    struct ex1 boo[2];
    struct pex1 yaa[2];
    printf("Size of boo: %ld\n", sizeof(boo));
    printf("Size of yaa: %ld\n", sizeof(yaa));





}