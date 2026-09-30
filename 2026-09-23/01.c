void increment(int *a) {
    (*a) += 1000;
}

int main() {
    char c = 1;
    char d = 2;
    increment(&c);
    printf("%d %d", c, d); // -23 2 undefined behaviour
}
