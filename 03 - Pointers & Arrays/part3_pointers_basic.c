/*
    Pointers Basic
*/

#include <stdio.h>
#include <stdint.h>

void swap(int32_t *a, int32_t *b);

int main(void) 
{
    /*
     * (1) Basic declarations 
     */
    uint16_t value = 0x1337;
    uint16_t *ptr = &value;

    printf(" value = %x\n", value);
    printf("&value = %p\n", &value);
    
    printf("&ptr = %p\n", &ptr);
    printf(" ptr = %p\n", ptr);
    printf("*ptr = %x\n", *ptr);


    /* 
     * (2) Value 
     */
    value = 0xBEEF;
    printf("[value = 0xBEEF]\n");
    printf(" value = %x\n", value);
    printf("*ptr = %x\n", *ptr);

    *ptr = 0xDEAD;
    printf("[*ptr = 0xDEAD]\n");
    printf(" value = %x\n", value);
    printf("*ptr = %x\n", *ptr);

    /*
     * (3) Functions
     */
    int32_t num1 = 100, num2 = 200, num3 = 300;
    printf("num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2);
    printf("num1 = %d, num2 = %d\n", num1, num2);

    /*
     * (4) Size of pointers (gcc -m32 to show 32bit sizes)
     */
    int8_t *p1 = NULL;
    int16_t *p2 = NULL;
    int32_t *p3 = NULL;
    int64_t *p4 = NULL;
    
    printf("sizeof(p1) = %ld || sizeof(*p1) = %ld\n", sizeof(p1), sizeof(*p1));
    printf("sizeof(p2) = %ld || sizeof(*p2) = %ld\n", sizeof(p2), sizeof(*p2));
    printf("sizeof(p3) = %ld || sizeof(*p3) = %ld\n", sizeof(p3), sizeof(*p3));
    printf("sizeof(p4) = %ld || sizeof(*p4) = %ld\n", sizeof(p4), sizeof(*p4));


    /* 
     * (5) Explicit Casting
     */
    int8_t letter = 'A';
    int8_t *pointer_to_letter = NULL;
    int32_t *pointrer_to_int = NULL;
    
    pointer_to_letter = &letter;
    
    /* Implicit casting will produce WARNING */
    pointrer_to_int = pointer_to_letter;

    /* Explicit is OK */
    pointrer_to_int = (int32_t *) pointer_to_letter;


    /*
     * (6) void pointers 
     */
    void *vptr = NULL;
    uint8_t number = 8;
    uint8_t *number_ptr = NULL;

    /* Implicit might work here */
    vptr = &number;
    number_ptr = vptr;
    printf("Number: %d\n", *number_ptr);


    /*
     * (7) Confusing declarations
     */
    uint16_t *aa, bb;   /* bb is NOT a pointer */


    /* 
     * (8) Pointer to pointer 
     */
    uint16_t one = 100;
    uint16_t two = 200;
    uint16_t *ptr_to_one = NULL;
    uint16_t **ptr_to_ptr;

    ptr_to_one = &one;
    ptr_to_ptr = &ptr_to_one;
    printf("Pointer to Pointer value: %d\n", **ptr_to_ptr);
    printf("Pointer to Pointer value: %d\n", *ptr_to_ptr == &one);

    ptr_to_one = &two;
    printf("Pointer to Pointer value: %d\n", **ptr_to_ptr);
    printf("Pointer to Pointer value: %d\n", *ptr_to_ptr == &one);

    return 0;
}

void swap(int32_t *a, int32_t *b) 
{
    int32_t tmp = *a;
    *a = *b;
    *b = tmp;
}