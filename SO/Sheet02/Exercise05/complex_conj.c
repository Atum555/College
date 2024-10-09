#include "complex.h"

complex complex_conj(complex z) {
    complex r;
    r.x = z.x;
    r.y = -z.y;
    return r;
}
