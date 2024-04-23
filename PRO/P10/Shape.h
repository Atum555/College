#ifndef SHAPE_H
#define SHAPE_H

#include <iomanip>
#include <iostream>

struct point {
    double x, y;
};

class Shape {
  public:
    Shape(const point &center) : center_(center) {}

    const point &get_center() const { return center_; }

    virtual double area() const                   = 0;
    virtual double perimeter() const              = 0;
    virtual bool   contains(const point &p) const = 0;

  private:
    point center_;
};

#endif
