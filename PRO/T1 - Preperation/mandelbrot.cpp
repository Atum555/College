#include "complex.h"

complex operator*(const complex a, const complex b) {
    return complex{ a.real * b.real - a.img * b.img, a.real * b.img + a.img * b.real };
}

complex operator+(const complex a, const complex b) {
    return complex{ a.real + b.real, a.img + b.img };
}

void mandel(complex c, int n, complex z[]) {
    complex number = { 0, 0 };
    z[0]           = number;
    for (int i = 1; i < n; ++i) {
        number = number * number + c;
        z[i]   = number;
    }
}
