unsigned long pell(unsigned long n) {
    if (n < 2) return n == 0 ? 0 : 1;
    unsigned long n2 = 0;
    unsigned long n1 = 0;
    unsigned long r  = 1;
    unsigned long i  = 1;
    while (true) {
        if (i == n) { return r; }
        ++i;
        n2 = n1;
        n1 = r;
        r  = 2 * n1 + n2;
    }
}