/*
    Pointers & Arrays
*/

#include <stdio.h>
#include <stdint.h>

void dump_mem(uint8_t *ptr, uint16_t size);
void dump_mem2(uint8_t ptr[], uint16_t size);

int main(void) 
{
    uint32_t i = 0;
    uint8_t c = 0;

    /* (1) Pointers arithmetic */
    uint8_t *p8bit = 0;
    uint32_t *p32bit = 0;
    printf("8-bit: %p, 32-bit: %p\n", p8bit, p32bit);
    
    p8bit += 1;
    p32bit += 1;
    printf("8-bit: %p, 32-bit: %p\n", p8bit, p32bit);


    /* (2) Array Duality */
    uint8_t letters[] = { 'r', 'o', 'b', 'o', 't' };
    uint8_t *p = NULL;
    
    /* Array duality */
    printf("Equal addresses: %p == %p\n", letters, &letters);

    /* Looping an array using pointer arithmetics */
    p = letters;
    for (i = 0; i < sizeof(letters); i++) {
        printf("[%d] = %c\n", i, *p);
        p++;
    }

    /* Pointer duality */
    printf("Those values are equals: %c == %c\n", *(letters+4), letters[4]);


    /* (3) Pointers and Arguments */
    dump_mem(letters, sizeof(letters));
    dump_mem2(letters, sizeof(letters));
    
    
    /* (4) Mother of all problems (FML) */
    /*
    int i;          // integer variable 'i'
    int *p;         // pointer 'p' to an integer
    int a[];        // array 'a' of integers
    int f();        // function 'f' with return value of type integer
    int **pp;       // pointer 'pp' to a pointer to an integer
    int (*pa)[];    // pointer 'pa' to an array of integer
    int (*pf)();    // pointer 'pf' to a function with return value integer
    int *ap[];      // array 'ap' of pointers to an integer
    int *fp();      // function 'fp' which returns a pointer to an integer
    int ***ppp;     // pointer 'ppp' to a pointer to a pointer to an integer
    int (**ppa)[];  // pointer 'ppa' to a pointer to an array of integers
    int (**ppf)();  // pointer 'ppf' to a pointer to a function with return value of type integer
    int *(*pap)[];  // pointer 'pap' to an array of pointers to an integer
    int *(*pfp)();  // pointer 'pfp' to function with return value of type pointer to an integer
    int **app[];    // array of pointers 'app' that point to pointers to integer values
    int (*apa[])[]; // array of pointers 'apa' to arrays of integers
    int (*apf[])(); // array of pointers 'apf' to functions with return values of type integer
    int ***fpp();   // function 'fpp' which returns a pointer to a pointer to a pointer to an int
    int (*fpa())[]; // function 'fpa' with return value of a pointer to array of integers
    int (*fpf())(); // function 'fpf' with return value of a pointer to function which returns an integer
    */

    return 0;
}


/* (3) As a pointer */
void dump_mem(uint8_t *ptr, uint16_t size) {
    uint16_t i = 0;

    printf("[%p](%u):\n", ptr, size);
    for (i = 0; i < size; ++i) {
        printf("\t[%d] = %c\n", i, *ptr);
        ptr++;
        // and then switch to use the array version to show it also works
    }
}

/* (3) As an array  */
void dump_mem2(uint8_t ptr[], uint16_t size) {
    uint16_t i = 0;

    printf("[%p](%u):\n", ptr, size);
    for (i = 0; i < size; ++i) {
        printf("\t[%d] = %c\n", i, ptr[i]);
        // and then switch to use the pointers version to show it also works
    }
}