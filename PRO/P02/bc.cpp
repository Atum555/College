unsigned long factorial(unsigned long n, unsigned long k = 1) {
    unsigned long r = 1;
    while (n >= k) {
        r *= n;
        --n;
    }
    return r;
}

unsigned long bc(unsigned long n, unsigned long k) {
    return k == 0 ? 1 : factorial(n, n - k + 1) / factorial(k);
}