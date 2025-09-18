#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

hm_stack_t* stack_create() {
    int* data = malloc(sizeof(int) * 128);

    if (data == NULL) {
        return NULL;
    }

    hm_stack_t* stack_ptr = malloc(sizeof(*stack_ptr));

    if (stack_ptr == NULL) {
        return NULL;
    }

    stack_ptr->capacity = 128;
    stack_ptr->size = 0;
    stack_ptr->data = data;

    return stack_ptr;
}

void stack_push(hm_stack_t* stack, int value) {
    if (stack->size == stack->capacity) {
        int* tmp_data = realloc(stack->data, sizeof(int) * stack->capacity * 2);
        if (tmp_data == NULL) {
            printf("Failed to allocate memory!\n");
            return;
        }

        stack->capacity *= 2;
        stack->data = tmp_data;
    }
    stack->data[stack->size] = value;
    stack->size++;
}

void stack_pop(hm_stack_t* stack) {
    if (stack->size == 0) {
        return;
    }

    stack->size--;
}

int stack_get_top(hm_stack_t* stack) {
    if (stack->size == 0) {
        return -1;
    }

    return stack->data[stack->size - 1];
}

bool stack_is_empty(hm_stack_t* stack) { return (stack->size == 0); }

void stack_clear(hm_stack_t* stack) {
    free(stack->data);
    free(stack);
}
