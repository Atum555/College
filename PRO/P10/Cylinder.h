#ifndef __Cylinder_h__
#define __Cylinder_h__

#include "Solid.h"
#include <math.h>

class Cylinder : public Solid {
  public:
    Cylinder(const point &center, double radius, double height)
        : Solid(center), radius_(radius), height_(height) {}

    double radius() const { return radius_; }

    double height() const { return height_; }

    double area() const final {
        return 2 * M_PI * radius_ * (radius_ + height_);
    }


  private:
    double radius_, height_;
};

#endif