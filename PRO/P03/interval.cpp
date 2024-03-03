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

interval intersection(interval a, interval b) {
    const interval zero = {
        {0, 0},
        {0, 0}
    };
    if (a.start <= b.start) {
        if (b.start < a.end)
            return interval{ b.start, a.end < b.end ? a.end : b.end };
        return zero;
    }
    if (a.start < b.end) {
        return interval{ a.start, a.end < b.end ? a.end : b.end };
    }
    return zero;
}