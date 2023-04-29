
/*
    Multi dimensional Arrays
*/

#include <stdio.h>
#include <stdint.h>

#define NELEM(x) (sizeof((x)) / sizeof(x[0]))

void print_mul(int32_t arr[][3], size_t rows) {
    size_t i = 0;
    size_t j = 0;

    /* Pay attention to sizes */
    /* printf("sizeof(arr[0][0]): %zu | sizeof(arr[0]) | sizeof(arr)\n", sizeof(arr[0][0]), sizeof(arr[0]), sizeof(arr)); */
    /* printf("NELEM of arr[0]: %zu\n", NELEM(arr[0])); */

    for (i = 0 ; i < rows ; i++)
    {
        for (j = 0; j < 3; j++) 
        {
            printf("Array[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }
}

int main(void) 
{
    /* (1) Basic initialization */
    int32_t a1[10][10] = {0};

    int32_t a2[3][3] = {{ 1, 2, 3 },
                        { 4, 5, 6 },
                        { 7, 8, 9 }};

    int32_t a3[3][3] = {{ 1, 2, 3 },
                        { 4 },
                        { 7, 8, 9 }};

    /* Looping over a multi-dim array */
    int32_t i = 0;
    int32_t j = 0;

    for (i = 0 ; i < 3 ; i++)
    {
        for (j = 0; j < 3; j++) 
        {
            printf("Array[%d][%d] = %d\n", i, j, a3[i][j]);
        }
    }

    /* (2) Passing to a function */
    print_mul(a3, 3);

    /*
        Memory Layout of A3
        =================== 
            Logical
            [1] [2] [3]
            [4] [5] [6]
            [7] [8] [9]

            Actual (in memory)
            [1] [2] [3] [4] [5] [6] [7] [8]
    */

    /* (2) Three dimensions (never do that!) */
    int32_t a4[2][2][2] = {
        {{10, 20},
         {30, 40}},

         {{50, 60},
         {70, 80}}
    };

    /* (3) Sizeofs */
    printf("%ld %ld %ld %ld \n", sizeof(a4), sizeof(a4[0]), sizeof(a4[0][0]), sizeof(a4[0][0][0]));


    return 0;
}
