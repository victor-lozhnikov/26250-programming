typedef struct node node;

struct node {
    int val;
    node *next;
};

node *init(int val) {
    node *tmp = calloc(1, sizeof(node));
    if (!tmp) {
        return NULL;
    }
    tmp->val = val;
    tmp->next = NULL;
    return tmp;
    
}

// возвращает добавленную вершину
node *add_next(node *prev, int val) {
    node *elem = init(val);
    
    if (elem == 0) {
        return 0;
    }

    elem -> next = prev -> next;
    prev -> next = elem;
    return elem;
}

void remove_next(node *prev) {
    node *td = prev -> next;
    prev -> next = td -> next;
    free(td);
}


int main() {
    node *head = init(3);
    // 3 -> NULL
    node *second = add_next(head, 5);
    // 3 -> 5 -> NULL
    node *third = add_next(second, 8);
    // 3 -> 5 -> 8 -> NULL
    second = add_next(head, 4);
    // 3 -> 4 -> 5 -> 8 -> NULL
    remove_next(second);
    // 3 -> 4 -> 8 -> NULL
    remove_next(second);
    // 3 -> 4 -> NULL
}
