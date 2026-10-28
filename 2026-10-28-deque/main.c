#include <stdio.h>
#include "deque.h"

int main(void) {
    deque_t *deque = new_deque();
    deque_push_back(deque, 10);
    deque_push_front(deque, 30);
    deque_push_back(deque, 20);
    deque_push_front(deque, 40);
    deque_print(deque);

    int x, y;
    deque_front(deque, &x);
    deque_back(deque, &y);
    printf("%d %d\n", x, y);

    deque_pop_back(deque);
    deque_print(deque);
    deque_pop_front(deque);
    deque_print(deque);
    deque_pop_back(deque);
    deque_print(deque);
    deque_pop_front(deque);
    deque_print(deque);

    return 0;
}
