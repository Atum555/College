#include "print_array.h"

int filter_duplicates(const int a[], int n, int b[]) {
    int bi   = 0;
    int last = 0;
    for (int ai = 0; ai < n; ++ai) {
        if (ai == 0 || last != a[ai]) {
            last  = a[ai];
            b[bi] = a[ai];
            ++bi;
        }
    }
    return bi;
}