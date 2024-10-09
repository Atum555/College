#include "complex.h"
#include <math.h>

double complex_mod(complex z) { return sqrt(z.x * z.x + z.y * z.y); }
