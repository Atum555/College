#ifndef __FRectangle_h__
#define __FRectangle_h__

#include "Figure.h"
#include <iostream>

class FRectangle : public Figure {
  public:
    FRectangle(
        double x_center = 0, double y_center = 0, double width = 0,
        double height = 0
    )
        : Figure(x_center, y_center), width_(width), height_(height) {}

    void draw() const override final {
        std::cout << "R(" << x_center_ << "," << y_center_ << ")(" << width_
                  << "," << height_ << ")";
    }

  private:
    double width_, height_;
};

#endif