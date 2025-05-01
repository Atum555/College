#include "fraction.h"

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

fraction reduce(fraction a) {
    int div  = gcd(a.num, a.den);
    a.num   /= div;
    a.den   /= div;
    if (a.den < 0) {
        a.num = -a.num;
        a.den = -a.den;
    }
    return a;
}

fraction &operator*=(fraction &a, int n) {
    a.num *= n;
    a.den *= n;
    return a;
}

fraction operator+(fraction a, fraction b) {
    if (a.den != b.den) {
        int temp  = a.den;
        a        *= b.den;
        b        *= temp;
    }
    return reduce(fraction{ a.num + b.num, a.den });
}

fraction operator*(fraction a, fraction b) {
    fraction r;
    r.num = a.num * b.num;
    r.den = a.den * b.den;
    return reduce(r);
}

fraction add(fraction a, fraction b) { return a + b; }

fraction mul(fraction a, fraction b) { return a * b; }
