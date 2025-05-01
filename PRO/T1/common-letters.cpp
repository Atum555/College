int common_letters(const char a[], const char b[], char out[]) {
    int count = 0;
    int la    = 0;
    int lb    = 0;
    int i     = 0;
    while (char l = a[i]) {
        if ('a' <= l && l <= 'z') la |= (1 << (l - 'a'));
        if ('A' <= l && l <= 'Z') la |= (1 << (l - 'A'));
        ++i;
    }
    i = 0;
    while (char l = b[i]) {
        if ('a' <= l && l <= 'z') lb |= (1 << (l - 'a'));
        if ('A' <= l && l <= 'Z') lb |= (1 << (l - 'A'));
        ++i;
    }
    for (int i = 0; i < 26; ++i) {
        if ((la & (1 << i)) && (lb & (1 << i))) {
            count[out] = 'a' + i;
            ++count;
        }
    }
    count[out] = 0;
    return count;
}
