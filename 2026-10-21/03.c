void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// a != b
void xor_swap(int *a, int *b) {
    if (a == b) {
        return;
    }

    // a_0, b_0

    *a ^= *b; // a = a_0 ^ b_0, b = b_0
    *b ^= *a; // a = a_0 ^ b^0, b = b_0 ^ a^0 ^ b_0 = a_0
    *a ^= *b; // a = b_0, b= a_0  
 
}

int main() {
    int a = 3;
    int b = 4;
    swap(&a, &b);
}
