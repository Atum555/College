char *duplicate(const char s[]) {
    int size = 0;
    while (s[size]) ++size;
    char *dup = new char[size + 1];
    for (int i = 0; i <= size; i++) dup[i] = s[i];
    return dup;
}