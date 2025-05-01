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

unsigned long bell(unsigned long n) {
    if (n < 2) { return 1; }

    unsigned long r = 0;
    for (unsigned long i = 0; i < n; i++) { r += bell(i) * bc(n - 1, i); }

    return r;
}
