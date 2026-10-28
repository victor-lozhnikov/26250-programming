#ifndef DEQUE_LINKED_LIST_H
#define DEQUE_LINKED_LIST_H

#include <stdbool.h>

typedef struct node_t node_t;
struct node_t {
    int value;
    node_t *next;
    node_t *prev;
};

typedef struct linked_list_t {
    node_t *head;
    node_t *tail;
} linked_list_t;

linked_list_t *new_list();
node_t *new_node();
bool push_head(linked_list_t *list, int value);
bool push_tail(linked_list_t *list, int value);
bool pop_head(linked_list_t *list);
bool pop_tail(linked_list_t *list);
bool head(linked_list_t *list, int *out);
bool tail(linked_list_t *list, int *out);

bool list_get(linked_list_t *list, int index, int *out);
void list_print(linked_list_t *list);

#endif //DEQUE_LINKED_LIST_H
