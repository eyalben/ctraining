#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define SUPPORTED_FUNCTIONS_COUNT (2)

typedef int32_t (*math_function)(int32_t, int32_t);

typedef struct {
    char title[255];
    math_function function;
} action_t;

typedef struct {
    uint32_t actions_count;
    // action_t (*supported_actions)[];
    action_t *supported_actions;
    // action_t **supported_actions;
} calculator_t;


int sub(int x, int y) 
{
    return x - y;
}

int mul(int x, int y) 
{
    return x * y;
}


calculator_t *CALCULATOR_init() {
    calculator_t *calculator = NULL;

    /* Allocate calculator_t */
    calculator = malloc(sizeof(calculator_t));
    if (NULL == calculator) {
        return NULL;
    }

    calculator->actions_count = 0;
    calculator->supported_actions = NULL;

    return calculator;
}

// TODO: Add error_t enum, and malloc failure tests
void CALCULATOR_add_action(calculator_t *calculator, math_function action, char *title, uint32_t title_length) {
    printf(" > Adding action: %s\n", title);

    // printf("Size of action_t is %zu\n", sizeof(action_t));
    // printf("Size of action_t is %zu\n", sizeof(calculator->supported_actions[0]));

    // If nothing is allocated
    if (0 == calculator->actions_count) {
        calculator->actions_count = 1;
        calculator->supported_actions = malloc(sizeof(action_t));
        
        // // (1)
        // calculator->supported_actions[0].function = action;
        // strncpy(calculator->supported_actions[0].title, title, title_length);
    } else {
        // TODO: Realloc to different variable and test return value;
        calculator->actions_count += 1;
        calculator->supported_actions = realloc(calculator->supported_actions, sizeof(action_t) * calculator->actions_count);
    }

    // (2)
    calculator->supported_actions[calculator->actions_count - 1].function = action;
    strncpy(calculator->supported_actions[calculator->actions_count - 1].title, title, title_length);
}

void CALCULATOR_print_menu(calculator_t *calculator)
{
    int i = 0;
    printf("Choose an action: \n");
    for (i = 0 ; i < calculator->actions_count; ++i) {
        printf(" [%d] %s\n", i + 1, calculator->supported_actions[i].title);
    }
}

void CALCULATOR_free(calculator_t *calculator) {
    int i = 0;

    if (NULL == calculator) {
        return;
    }

    // Free actions
    if (NULL != calculator->supported_actions) {
        free(calculator->supported_actions);
    }

    free(calculator);
}


int main(void) 
{
    calculator_t *calculator = CALCULATOR_init();

    CALCULATOR_add_action(calculator, mul, "Multiply", 9);
    CALCULATOR_add_action(calculator, sub, "Substract", 10);
    CALCULATOR_print_menu(calculator);
    
    CALCULATOR_free(calculator);

    return 0;
}