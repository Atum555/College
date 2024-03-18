char *repeat_chars(const char str[], int max_repeat) {
    int size = 0;
    while (size[str]) ++size;
    char *result = new char[size * max_repeat + 1];
    int   ri     = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < (i < max_repeat ? i : max_repeat); ++j) {
            ri[result] = str[i];
            ++ri;
        }
    }
    ri[result] = 0;
    return result;
}