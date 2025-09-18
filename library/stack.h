#include <stdbool.h>

typedef struct HMStack {
    int* data;
    int size;
    int capacity;
} hm_stack_t;

hm_stack_t* stack_create();
void stack_push(hm_stack_t* stack, int value);
void stack_pop(hm_stack_t* stack);
int stack_get_top(hm_stack_t* stack);
bool stack_is_empty(hm_stack_t* stack);
void stack_clear(hm_stack_t* stack);
