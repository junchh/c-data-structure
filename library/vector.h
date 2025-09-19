typedef struct HMVector {
    int* data;
    int size;
    int capacity;
} hm_vector_t;

hm_vector_t* vector_create();
void vector_push(hm_vector_t* vector, int value);
int vector_get_data(hm_vector_t* vector, int index);
void vector_set_data(hm_vector_t* vector, int index, int value);
void vector_clear(hm_vector_t* vector);
