#include "print_array.h"

int *merge_arrays(const int a[], int na, const int b[], int nb) {
    int *c = new int[na + nb];
    int  ia, ib, ic;
    ia = ib = ic = 0;
    while (true) {
        if (ia < na && ib < nb) {
            if (a[ia] < b[ib]) {
                c[ic] = a[ia];
                ++ic;
                ++ia;
                continue;
            } else {
                c[ic] = b[ib];
                ++ic;
                ++ib;
                continue;
            }
        } else if (ia < na) {
            c[ic] = a[ia];
            ++ic;
            ++ia;
            continue;
        } else if (ib < nb) {
            c[ic] = b[ib];
            ++ic;
            ++ib;
            continue;
        } else return c;
    }
}