#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <math.h>

class Rectangle : public Shape {
  public:
    Rectangle(const point &center, double width, double height)
        : Shape(center), width_(width), height_(height) {}

    double area() const override final { return width_ * height_; }

    double perimeter() const override final { return 2 * width_ + 2 * height_; }

    bool contains(const point &p) const override final {
        bool x = get_center().x - width_ / 2 <= p.x
                 and p.x <= get_center().x + width_ / 2;
        bool y = get_center().y - height_ / 2 <= p.y
                 and p.y <= get_center().y + height_ / 2;

        return x and y;
    }

  private:
    double width_, height_;
};

#endif