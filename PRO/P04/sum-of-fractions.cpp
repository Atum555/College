#include "fraction.h"

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void reduce(fraction &a) {
    int div  = gcd(a.num, a.den);
    a.num   /= div;
    a.den   /= div;
    if (a.den < 0) {
        a.num = -a.num;
        a.den = -a.den;
    }
}

fraction &operator*=(fraction &a, int n) {
    a.num *= n;
    a.den *= n;
    return a;
}

fraction &operator+=(fraction &a, fraction b) {
    if (a.den != b.den) {
        int temp  = a.den;
        a        *= b.den;
        b        *= temp;
    }
    a.num += b.num;
    reduce(a);
    return a;
}

fraction sum(const fraction fa[], int n) {
    fraction r = { 0, 1 };
    for (int i = 0; i < n; ++i) r += fa[i];
    return r;
}