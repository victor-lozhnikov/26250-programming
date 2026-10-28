#ifndef DEQUE_DEQUE_H
#define DEQUE_DEQUE_H

#include <stdbool.h>

typedef struct deque_t deque_t;
struct deque_t {
    void *data;
};

deque_t *new_deque();

bool deque_push_back(deque_t *deque, int x);
bool deque_pop_back(deque_t *deque);
bool deque_push_front(deque_t *deque, int x);
bool deque_pop_front(deque_t *deque);
bool deque_back(deque_t *deque, int *out);
bool deque_front(deque_t *deque, int *out);

bool deque_get(deque_t *deque, int index, int *out);
void deque_print(deque_t *deque);

#endif //DEQUE_DEQUE_H
