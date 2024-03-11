unsigned long hstr_to_integer(const char hstr[]) {
    int           i = 0;
    unsigned long r = 0;
    while (hstr[i]) {
        r      *= 16;
        char l  = hstr[i];
        if ('a' <= l && l <= 'f') r += l - 'a' + 10;
        else if ('A' <= l && l <= 'F') r += l - 'A' + 10;
        else r += l - '0';
        ++i;
    }
    return r;
}