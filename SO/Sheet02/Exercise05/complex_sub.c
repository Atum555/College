#include "complex.h"

complex complex_sub(complex z, complex w) {
    complex r;
    r.x = z.x - w.x;
    r.y = z.y - w.y;
    return r;
}
