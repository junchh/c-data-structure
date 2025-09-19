#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

hm_vector_t* vector_create() {
    int* data = malloc(sizeof(int) * 128);

    if (data == NULL) {
        return NULL;
    }

    hm_vector_t* vector_ptr = malloc(sizeof(*vector_ptr));

    if (vector_ptr == NULL) {
        return NULL;
    }

    vector_ptr->capacity = 128;
    vector_ptr->size = 0;
    vector_ptr->data = data;

    return vector_ptr;
}

void vector_push(hm_vector_t* vector, int value) {
    if (vector->size == vector->capacity) {
        int* tmp_data =
            realloc(vector->data, sizeof(int) * vector->capacity * 2);
        if (tmp_data == NULL) {
            printf("Failed to allocate memory!\n");
            return;
        }

        vector->capacity *= 2;
        vector->data = tmp_data;
    }

    vector->data[vector->size] = value;
    vector->size++;
}

int vector_get_data(hm_vector_t* vector, int index) {
    return vector->data[index];
}

void vector_set_data(hm_vector_t* vector, int index, int value) {
    vector->data[index] = value;
}

void vector_clear(hm_vector_t* vector) {
    free(vector->data);
    free(vector);
}
