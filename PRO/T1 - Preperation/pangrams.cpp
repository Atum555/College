bool pangram(const char s[], char m[]) {
    int letters = 67108863;
    int i       = 0;
    while (char l = s[i]) {
        if ('a' <= l && l <= 'z') letters &= ~(1 << (l - 'a'));
        if ('A' <= l && l <= 'Z') letters &= ~(1 << (l - 'A'));
        ++i;
    }
    if (!letters) {
        m[0] = 0;
        return true;
    }
    i     = 0;
    int j = 0;
    while (letters) {
        if (letters & 1) {
            m[j] = 'a' + i;
            ++j;
        }
        letters >>= 1;
        ++i;
    }
    return false;
}