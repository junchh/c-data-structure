#include <stdio.h>

#include "library/stack.h"

int main() {
    hm_stack_t* stack = stack_create();

    stack_push(stack, 100);
    stack_push(stack, 200);
    stack_push(stack, 400);
    stack_push(stack, 150);

    stack_pop(stack);

    while (!stack_is_empty(stack)) {
        printf("%d\n", stack_get_top(stack));
        stack_pop(stack);
    }

    stack_clear(stack);
    return 0;
}
