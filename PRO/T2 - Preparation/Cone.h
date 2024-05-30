#include "Solid3D.h"
#include <cmath>

class Cone : public Solid3D {
  private:
    double radius_;
    double height_;

  public:
    Cone(const point &c, double radius, double height) : Solid3D(c), radius_(radius), height_(height) {}

    double radius() const { return radius_; }

    double height() const { return height_; }

    double volume() const override { return (M_PI * radius_ * radius_ * height_) / 3; }
};