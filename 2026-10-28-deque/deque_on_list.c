#include "deque.h"
#include "linked_list.h"
#include <stdlib.h>

deque_t *new_deque() {
    deque_t *deque = malloc(sizeof(deque_t));
    if (!deque) {
        return NULL;
    }
    deque->data = new_list();
    if (!deque->data) {
        free(deque);
        return NULL;
    }
    return deque;
}

bool deque_push_back(deque_t *deque, int x) {
    return push_tail(deque->data, x);
}

bool deque_pop_back(deque_t *deque) {
    return pop_tail(deque->data);
}

bool deque_push_front(deque_t *deque, int x) {
    return push_head(deque->data, x);
}

bool deque_pop_front(deque_t *deque) {
    return pop_head(deque->data);
}

bool deque_front(deque_t *deque, int *out) {
    return head(deque->data, out);
}

bool deque_back(deque_t *deque, int *out) {
    return tail(deque->data, out);
}

bool deque_get(deque_t *deque, int index, int *out) {
    if (deque == NULL) {
        return false;
    }
    return list_get(deque->data, index, out);
}

void deque_print(deque_t *deque) {
    if (deque == NULL) {
        return;
    }
    list_print(deque->data);
}
