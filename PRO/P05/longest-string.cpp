const char *longest(const char *pa[]) {
    const char *max     = nullptr;
    int         maxSize = 0;
    int         i       = 0;
    while (pa[i] != nullptr) {
        const char *p = pa[i];
        int         j = 0;
        while (p[j]) ++j;
        if (j >= maxSize) {
            maxSize = j;
            max     = p;
        }
        ++i;
    }
    return max;
}
