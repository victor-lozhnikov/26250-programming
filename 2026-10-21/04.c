typedef unsigned int uint;


uint set_ith_bit_to_1(uint n, int i) {
    return n | (1 << i);    
}

uint set_ith_bit_to_0(uint n, int i) {
    return n & (~(1 << i));
}

int count_of_ones(uint n) {
    int count = 0;
    while (n != 0) {
        if ((n & 1) == 1) {
            count += 1;
        }
        n >>= 1;
    }
    return count;
}
