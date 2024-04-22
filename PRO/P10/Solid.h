#ifndef __Solid_h__
#define __Solid_h__

#include <cmath>
#include <iomanip>
#include <iostream>

struct point {
    double x, y, z;
};

std::ostream &operator<<(std::ostream &os, const point &p) {
    return os << std::fixed << std::setprecision(3) << '(' << p.x << ',' << p.y
              << ',' << p.z << ')';
}

class Solid {
  public:
    Solid(const point &c) : center_(c) {}

    const point &center() const { return center_; }

    virtual double area() const = 0;

  private:
    point center_;
};

#endif