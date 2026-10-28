#ifndef DEQUE_VECTOR_H
#define DEQUE_VECTOR_H

#include <stdbool.h>

typedef struct ring_vector_t {
    int *arr;
    int size;
    int capacity;
    int start_index;
} ring_vector_t;

ring_vector_t *new_ring_vector();

bool vector_push_back(ring_vector_t *vector, int x);
bool vector_pop_back(ring_vector_t *vector);
bool vector_push_front(ring_vector_t *vector, int x);
bool vector_pop_front(ring_vector_t *vector);
bool vector_back(ring_vector_t *vector, int *out);
bool vector_front(ring_vector_t *vector, int *out);

bool vector_get(ring_vector_t *vector, int index, int *out);
void vector_print(ring_vector_t *vector);

#endif //DEQUE_VECTOR_H
