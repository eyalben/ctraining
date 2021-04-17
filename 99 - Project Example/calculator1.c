#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SUPPORTED_FUNCTIONS_COUNT (2)

typedef int32_t (*math_function)(int32_t, int32_t);

typedef struct {
    char title[255];
    math_function function;
} action_t;

typedef struct {
    uint32_t actions_count;
    action_t supported_actions[SUPPORTED_FUNCTIONS_COUNT];
} calculator_t;


int sub(int x, int y) 
{
    return x - y;
}


int mul(int x, int y) 
{
    return x * y;
}

calculator_t CALCULATOR = {
    .supported_actions =
        {        
            {.title = "Multiply", .function = mul},
            {.title =  "Subtract", .function = sub},
        },
    .actions_count = SUPPORTED_FUNCTIONS_COUNT
};

void print_menu(calculator_t *calculator)
{
    int i = 0;
    printf("Choose an action: \n");
    for (i = 0 ; i < calculator->actions_count; ++i) {
        printf(" [%d] %s\n", i + 1, calculator->supported_actions[i].title);
    }
}

// calculator_t *CALCULATOR_init() {
//     calculator_t *calculator = NULL;

//     calculator = malloc(sizeof(calculator_t));
//     if (NULL == calculator) {
//         return NULL;
//     }

//     return calculator;
// }

// void CALCULATOR_free(calculator_t *calculator) {
//     if (calculator != NULL) {
//         free(calculator);
//     }
// }


int main(void) 
{
    // action_t supported_actions[2] = {
    //     {.title = "Multiply", .function = mul},
    //     {.title =  "Subtract", .function = sub}
    // };

    // print_menu(supported_actions, 2);

    print_menu(&CALCULATOR);

    return 0;
}