#include "vector.h"
#include <math.h>
#include <stdlib.h>

vector *vector_new(double x, double y, double z) {
    vector *v = malloc(sizeof(vector));
    v->x      = x;
    v->y      = y;
    v->z      = z;
    return v;
}

vector *vector_add(vector *v1, vector *v2) {
    return vector_new(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z);
}

vector *vector_sub(vector *v1, vector *v2) {
    return vector_new(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
}

vector *vector_scale(double k, vector *v) { return vector_new(v->x * k, v->y * k, v->z * k); }

vector *vector_vprod(vector *v1, vector *v2) {
    double x = v1->y * v2->z - v1->z * v2->y;
    double y = v1->z * v2->x - v1->x * v2->z;
    double z = v1->x * v2->y + v1->y * v2->x;

    return vector_new(x, y, z);
}

double vector_sprod(vector *v1, vector *v2) {
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

double vector_mod(vector *v) { return sqrt(v->x * v->x + v->y * v->y + v->z * v->z); }
