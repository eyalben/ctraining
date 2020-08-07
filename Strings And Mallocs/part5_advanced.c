/*
    Advanced: Pointer and Two-Dimensionals Arrays
*/
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    /* (1) How to set a pointer to an array */
    char name1[] = { "hodor" }; /* 6 bytes */
    char (*ptr)[] = NULL; /* This is a pointer to an array */

    ptr = &name1;
    printf("First letter is: %c\n", (*ptr)[0]);

    /* (2) Dynamic allocation of NxM array */
    int *twodim = (int *) malloc(3 * 4 * sizeof(int));

    /* alternative syntax: */
    // int *twodim = (int *) malloc(sizeof(int[3][4]));

    /* You can see sizes are equal */
    // printf("Sizeof: %ld == %ld\n", sizeof(int[3][4]), 3 * 4 * sizeof(int) );

    /* usage examples (first and second alrenatives) */
    // int i = 0;
    // for (i = 0; i < 3 * 4; ++i) {
    //     twodim[i] = i;
    // }


    /* (3) Alternative syntax (pointer to an array) */
    // int (*twodim)[4] = malloc( sizeof(*twodim) * 3 );
    // int i = 0, j = 0;
    // for (i = 0; i < 3; ++i) {
    //     for (j = 0 ; j < 4; j++) {
    //         twodim[i][j] = i * j;
    //     }
    // }

    /* (3.1) Let's look on the addresses */
    // printf("Arr: %d %d %d \n", arr, arr + 1, arr + 2);
    // printf("Value: %d\n", arr[0][1]);
    // printf("Value: %d\n", arr[1][3]);

    /* (4) Jagged array */
    // int cols = 10;
    // int rows = 4;

    // int **arr = (int **)malloc(rows * sizeof(int *));
    // for (i = 0; i < rows; ++i) {
    //     arr[i] = (int *) malloc(cols * sizeof(int)); 
    // }
    

    
    // Don't forget to free
    free(twodim);

    return 0;
}
