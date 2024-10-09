#include "complex.h"

complex complex_div(complex z, complex w) {
    complex r;
    double  d = w.x * w.x + w.y * w.y;
    r.x       = (z.x * w.x + z.y * w.y) / d;
    r.y       = (-z.x * w.y + z.y * w.x) / d;
    return r;
}
