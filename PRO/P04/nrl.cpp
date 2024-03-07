int nrl(const char s[], char low[]) {
    int unique = 0;
    int found  = 0;
    int i      = 0;
    while (char l = s[i]) {
        int lInt = 0;
        if ('a' <= l && l <= 'z') lInt = 1 << (l - 'a');
        if ('A' <= l && l <= 'Z') lInt = 1 << (l - 'A');
        if (lInt) {
            unique |= lInt;
            if (found & lInt) unique &= ~lInt;
            found |= lInt;
        }

        ++i;
    }

    int c = 0;
    for (int i = 0; i < 26; ++i) {
        if (unique & 1) {
            low[c] = 'a' + i;
            ++c;
        }
        unique >>= 1;
    }

    low[c] = 0;
    return c;
}