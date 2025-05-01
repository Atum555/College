#include "complex.h"
#include <math.h>

complex operator+(complex a, complex b) { return complex{ a.x + b.x, a.y + b.y }; }

complex operator*(complex a, complex b) {
    return complex{ a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x };
}

void add(const complex &a, const complex &b, complex &r) { r = a + b; }

void mul(const complex &a, const complex &b, complex &r) { r = a * b; }

double norm(const complex &c) { return sqrt(c.x * c.x + c.y * c.y); }

void mandelbrot(const complex &c, unsigned int n, complex &z_n) {
    z_n = complex{ 0, 0 };
    while (n) {
        z_n = z_n * z_n + c;
        --n;
    }
}
