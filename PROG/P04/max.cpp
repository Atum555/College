int max(const int a[], int n) {
    int r = a[0];
    for (int i = 0; i < n; ++i) r = a[i] > r ? a[i] : r;
    return r;
}
