#include "linked_list.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

linked_list_t *new_list() {
    linked_list_t *list = malloc(sizeof(linked_list_t));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

node_t *new_node(int value) {
    node_t *node = malloc(sizeof(node_t));
    if (node == NULL) {
        return NULL;
    }
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
};

bool push_head(linked_list_t *list, int value) {
    if (list == NULL) {
        return false;
    }
    node_t *node = new_node(value);

    if (node == NULL) {
        return false;
    }

    node->next = list->head;
    if (list->head == NULL) {
        list->tail = node;
    } else {
        list->head->prev = node;
    }
    list->head = node;
    return true;
}

bool pop_head(linked_list_t *list) {
    if (list == NULL || list->head == NULL) {
        return false;
    }
    node_t *temp = list->head;

    list->head = temp->next;
    if (list->head == NULL) {
        list->tail = NULL;
    } else {
        list->head->prev = NULL;
    }
    free(temp);
    return true;
}

bool head(linked_list_t *list, int *out) {
    if (list == NULL || list->head == NULL) {
        return false;
    }
    *out = list->head->value;
    return true;
}

bool push_tail(linked_list_t *list, int value) {
    if (list == NULL) {
        return false;
    }
    node_t *node = new_node(value);
    if (node == NULL) {
        return false;
    }

    node->next = NULL;
    node->prev = list->tail;
    if (list->tail == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
    return true;
}

bool pop_tail(linked_list_t *list) {
    if (list == NULL || list->tail == NULL) {
        return false;
    }
    node_t *temp = list->tail;

    list->tail = temp->prev;
    if (list->tail == NULL) {
        list->head = NULL;
    } else {
        list->tail->next = NULL;
    }
    free(temp);
    return true;
}

bool tail(linked_list_t *list, int *out) {
    if (list == NULL || list->tail == NULL) {
        return false;
    }
    *out = list->tail->value;
    return true;
}

bool list_get(linked_list_t *list, int index, int *out) {
    if (list == NULL) {
        return false;
    }
    node_t *current = list->head;
    if (current == NULL) {
        return false;
    }
    while (index) {
        current = current->next;
        index--;
        if (current == NULL) {
            return false;
        }
    }
    *out = current->value;
    return true;
}

void list_print(linked_list_t *list) {
    if (list == NULL) {
        return;
    }
    node_t *current = list->head;
    if (current == NULL) {
        return;
    }
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
