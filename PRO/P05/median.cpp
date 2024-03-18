#include <algorithm>

int median(const int a[], int n) {
    if (!n) { return 0; }
    int *temp = new int[n];
    for (int i = 0; i < n; ++i) temp[i] = a[i];

    std::sort(temp, temp + n);
    int result = 0;
    if (n % 2) result = temp[n / 2];
    else result = (temp[n / 2 - 1] + temp[n / 2]) / 2;
    delete[] temp;
    return result;
}