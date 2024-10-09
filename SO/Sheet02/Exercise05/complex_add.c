#include "complex.h"

complex complex_add(complex z, complex w) {
    complex r;
    r.x = z.x + w.x;
    r.y = z.y + w.y;
    return r;
}
