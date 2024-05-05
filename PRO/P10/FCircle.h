#ifndef __FCircle_h__
#define __FCircle_h__

#include "Figure.h"
#include <iostream>

class FCircle : public Figure {
  public:
    FCircle(double x_center = 0, double y_center = 0, double radius = 0)
        : Figure(x_center, y_center), radius_(radius) {}

    void draw() const override final {
        std::cout << "C(" << x_center_ << "," << y_center_ << ")(" << radius_
                  << ")";
    }

  private:
    double radius_;
};

#endif