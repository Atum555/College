#include "Point.h"
#include <iostream>

Point::Point() : Point(0, 0) {}

Point::Point(int x, int y) : x_(x), y_(y) {}

int Point::getX() const { return x_; }

int Point::getY() const { return y_; }

void Point::show() const { std::cout << "(" << x_ << "," << y_ << ")"; }