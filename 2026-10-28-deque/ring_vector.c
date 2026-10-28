#include "ring_vector.h"
#include <stdlib.h>

#define VECTOR_COEF 2
#define INITIAL_CAPACITY 2

int math_mod(int a, int b) {
    int r = a % b;
    if (r < 0) {
        r += b;
    }
    return r;
}

ring_vector_t *new_ring_vector() {
    ring_vector_t *created_ring_vector = malloc(sizeof(ring_vector_t));

    if (created_ring_vector == NULL) {
        return NULL;
    }

    created_ring_vector->size = 0;
    created_ring_vector->capacity = INITIAL_CAPACITY;
    created_ring_vector->start_index = 0;
    created_ring_vector->arr = malloc(sizeof(int) * INITIAL_CAPACITY);

    if (created_ring_vector->arr == NULL) {
        free(created_ring_vector);
        return NULL;
    }

    return created_ring_vector;
}

bool custom_realloc(ring_vector_t *vector, int new_capacity) {
    if (vector == NULL) {
        return false;
    }
    int *new_arr = malloc(new_capacity * sizeof(int));
    if (new_arr == NULL) {
        return false;
    }
    int mn = (new_capacity > vector->size ? vector->size : new_capacity);
    for (int i = 0; i < mn; i++) {
        new_arr[i] = vector->arr[math_mod(vector->start_index + i, vector->capacity)];
    }
    free(vector->arr);
    vector->arr = new_arr;
    vector->capacity = new_capacity;
    vector->start_index = 0;
    return true;
}

bool vector_push_back(ring_vector_t *vector, int x) {
    if (vector == NULL) {
        return false;
    }
    if (vector->capacity <= vector->size) {
        if (!custom_realloc(vector, vector->capacity * VECTOR_COEF)) {
            return false;
        }
    }
    vector->arr[math_mod(vector->start_index + vector->size, vector->capacity)] = x;
    vector->size++;
    return true;
}

bool vector_push_front(ring_vector_t *vector, int x) {
    if (vector == NULL) {
        return false;
    }
    if (vector->capacity <= vector->size) {
        bool reallocated = custom_realloc(vector, vector->capacity * VECTOR_COEF);
        if (!reallocated) {
            return false;
        }
    }
    vector->start_index = math_mod(vector->start_index - 1, vector->capacity);
    vector->arr[vector->start_index] = x;
    vector->size++;
    return true;
}
