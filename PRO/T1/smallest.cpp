#include "interval.h"

int duration(const interval a) {
    return a.end.h * 60 + a.end.m - a.start.h * 60 - a.start.m;
}

interval smallest(const interval a[], int n) {
    interval smallest   = 0 [a];
    int      smDuration = duration(0 [a]);

    for (int i = 1; i < n; ++i) {
        if (duration(i[a]) < smDuration) {
            smDuration = duration(i[a]);
            smallest   = i[a];
        }
    }
    return smallest;
}