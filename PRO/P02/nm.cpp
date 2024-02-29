unsigned long next_mersenne(unsigned long n) {
    unsigned long r = 0;
    for (int i = 0; i <= 64; i++) {
        if (r >= n) return r;
        r <<= 1;
        ++r;
    }
    return 0;
}