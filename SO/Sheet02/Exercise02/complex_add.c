#include "complex.h"

complex *complex_add(complex *z, complex *w) { return complex_new(z->x + w->x, z->y + w->y); }
