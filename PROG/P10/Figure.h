#ifndef __Figure_h__
#define __Figure_h__

#include <iostream>

class Figure {
  public:
    Figure(double x_center = 0, double y_center = 0) : x_center_(x_center), y_center_(y_center) {}

    virtual ~Figure() {}

    virtual void draw() const = 0;

  protected:
    double x_center_;
    double y_center_;
};

#endif
