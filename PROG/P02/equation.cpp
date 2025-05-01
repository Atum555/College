#include <cmath>

int solve_eq(int a, int b, int c, double &x1, double &x2) {
    double delta = b * b - 4 * a * c;
    if (delta < 0 || a == 0) {
        x1 = x2 = NAN;
        return 0;
    }
    if (delta == 0) {
        x1 = -b / (2.0 * a);
        x2 = NAN;
        return 1;
    }
    x1 = (-b - sqrt(delta)) / (2.0 * a);
    x2 = (-b + sqrt(delta)) / (2.0 * a);
    return 2;
}
