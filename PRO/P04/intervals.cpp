#include "interval.h"

bool operator<(const time_of_day &a, const time_of_day &b) {
    if (a.h < b.h) return true;
    if (a.h == b.h and a.m < b.m) return true;
    return false;
}

bool operator<=(const time_of_day &a, const time_of_day &b) {
    if (a.h < b.h) return true;
    if (a.h == b.h and a.m <= b.m) return true;
    return false;
}

interval &operator+=(interval &a, const interval &b) {
    a.start = a.start < b.start ? a.start : b.start;
    a.end   = b.end < a.end ? a.end : b.end;
    return a;
}

bool interval_Contains(const interval &a, const time_of_day &b) {
    return a.start <= b && b < a.end;
}

int countMinutes(const interval &a) {
    return a.end.h * 60 + a.end.m - a.start.h * 60 - a.start.m;
}

int search_intervals(time_of_day t, const interval a[], int n, interval &u) {
    u = { t, t };
    for (int i = 0; i < n; ++i) {
        if (interval_Contains(a[i], t)) u += a[i];
    }
    return countMinutes(u);
}