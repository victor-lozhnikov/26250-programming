void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
    return;
    
}

int main() {
    int a, b;
    int scanf_result = scanf("%d %d", &a, &b);

    if (scanf_result != 2) {
        printf("input error");
        return 1;
    }

    swap(&a, &b); // a <-> b
}


#include <stdio.h>

int main(void) {
    int a =12;
    int b = 20;
    a = b - a;
    b -= a;
    a += b;
    printf("%d %d", a, b);
}
