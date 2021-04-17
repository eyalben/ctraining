#include <stdio.h>

typedef int32_t (*math_function)(int32_t, int32_t);

typedef struct {
    char title[255];
    math_function function;
} action_t;

int sub(int x, int y) 
{
    return x - y;
}


int mul(int x, int y) 
{
    return x * y;
}

void print_menu(action_t actions[], int size)
{
    int i = 0;
    printf("Choose an action: \n");
    for (i = 0 ; i < size; ++i) {
        printf(" [%d] %s\n", i + 1, actions[i].title);
    }
}

int main(void) 
{
    action_t supported_actions[2] = {
        {.title = "Multiply", .function = mul},
        {.title =  "Subtract", .function = sub}
    };

    print_menu(supported_actions, 2);

    return 0;
}