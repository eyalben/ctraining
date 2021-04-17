/*
    Enums
*/

#include <stdio.h>
#include <stdint.h>

enum weather_e {
    sunny,
    windy,
    cloudy,
    rain,
};

typedef enum weather_e weather_t;

int main(void) 
{
    /* (1) Basic Enums */

    printf("sunny: %d\n", sunny);
    printf("windy: %d\n", windy);
    printf("cloudy: %d\n", cloudy);
    printf("rain: %d\n", rain);

    /*
    play with init values in enum
    */


    /* (2) Switch case */
    enum weather_e w = windy;

    switch (w) {
    case sunny:
        printf("Sunny\n");
        break;
    case windy:
        printf("windy\n");
        break;
    case cloudy:
        printf("cloudy\n");
        break;
    case rain:
        printf("rain\n");
        break;
    }
   
   /* (2) Size of Enum */
   weather_t x = 0;
   printf("Size of enum: %d\n", sizeof(x));

   /*
    Actually there is no standard and the compiler can choose whatever he wants
    as long as the values can fit.

   */


    return 0;
}