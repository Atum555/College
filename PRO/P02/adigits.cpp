#include <algorithm>

int adigits(int a, int b, int c) {
    int ddd = std::max(std::max(a, b), c);
    int d   = std::min(std::min(a, b), c);
    int dd  = a + b + c - ddd - d;


    if (dd) {
        a = 3;
        b = 3;
    }
    return ddd * 100 + dd * 10 + d;
}
