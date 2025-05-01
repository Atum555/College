#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <math.h>

class Circle : public Shape {
  public:
    Circle(const point &center, double radius) : Shape(center), radius_(radius) {}

    double area() const override final { return M_PI * radius_ * radius_; }

    double perimeter() const override final { return 2 * M_PI * radius_; }

    bool contains(const point &p) const override final {
        return (get_center().x - p.x) * (get_center().x - p.x)
                   + (get_center().y - p.y) * (get_center().y - p.y)
               <= radius_ * radius_;
    }

  private:
    double radius_;
};

#endif
