#define VECTOR_COEF 2

typedef struct vector {
    int *arr;
    int capacity;
    int size;
} vector;

vector *init(int capacity) {
    if (capacity < 0) {
        return 0;
    }

    vector* tmp = calloc(1, sizeof(vector));
    if (!tmp) {
        return 0;
    }

    int* arr = calloc(capacity, sizeof(int));
    if (!arr) {
        free(tmp);
        return 0;
    }
    
    tmp->arr = arr;
    tmp->capacity = capacity;
 
    return tmp;
}

// если не удалось выделить память, ф-ия ничего не делает, arr не затирается
void push_back(vector *v, int x) {
    if (v->capacity <= v->size){
        int* t = v->arr;
        v->arr = realloc (v->arr, v->capacity*VECTOR_COEF*sizeof(int));
        if (!v->arr){
            v->arr = t;
            return;
        }
        v->capacity *= VECTOR_COEF;
    }
    v->arr [v->size] = x;
    v->size++;
    return;
}

int main() {
    vector *v = init(3);
    // size = 0, capacity = 3, arr = [_, _, _]
    push_back(v, 5);
    // size = 1, capacity = 3, arr = [5, _, _]
    push_back(v, 6);
    // size = 2, capacity = 3, arr = [5, 6, _]
    push_back(v, 7);
    // size = 3, capacity = 3, arr = [5, 6, 7]
    push_back(v, 8);
    // size = 4, capacity = 6, arr = [5, 6, 7, 8, _, _]
    push_back(v, 9);
    // size = 5, capacity = 6, arr = [5, 6, 7, 8, 9, _]
}
