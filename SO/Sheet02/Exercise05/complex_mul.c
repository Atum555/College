#include "complex.h"

complex complex_mul(complex z, complex w) {
    complex r;
    r.x = z.x * w.x - z.y * w.y;
    r.y = z.x * w.y + z.y * w.x;
    return r;
}
