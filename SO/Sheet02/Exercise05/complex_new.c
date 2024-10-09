#include "complex.h"

complex complex_new(double x, double y) {
    complex z;
    z.x = x;
    z.y = y;
    return z;
}
