#include "cdata.h"

int *expand_cdata(const cdata a[], int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) count += a[i].count;

    int *res = new int[count];
    count    = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[i].count; ++j) {
            res[count] = a[i].value;
            ++count;
        }
    }
    return res;
}
