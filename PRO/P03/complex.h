#ifndef __complex_h__
#define __complex_h__

// Representation of a complex number z = x + y i
struct complex {
    double x; // Real part
    double y; // Imaginary part
};

double norm(const complex &c);
void   add(const complex &a, const complex &b, complex &r);
void   mul(const complex &a, const complex &b, complex &r);

#include <iomanip>
#include <iostream>
using namespace std;

ostream &operator<<(ostream &out, const complex &c) {
    return out << fixed << setprecision(3) << c.x << (c.y >= 0.0 ? "+" : "")
               << c.y << "i";
}

#endif // __complex_h__
