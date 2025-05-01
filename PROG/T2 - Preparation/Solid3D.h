#ifndef __SOLID3D_H__
#define __SOLID3D_H__

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

struct point {
    double x, y, z;
};

ostream &operator<<(ostream &os, const point &p) {
    return os << fixed << setprecision(3) << '(' << p.x << ',' << p.y << ',' << p.z << ')';
}

class Solid3D {
  public:
    Solid3D(const point &c) : center_(c) {}

    const point &center() const { return center_; }

    virtual double volume() const = 0;

  private:
    point center_;
};

#endif
