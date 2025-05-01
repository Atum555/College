char *repeat(const char str[], int n) {
    int size = 0;
    while (str[size]) ++size;

    char *result = new char[size * n + 1];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= size; ++j) result[i * size + j] = str[j];

    result[n * size] = 0;
    return result;
}
