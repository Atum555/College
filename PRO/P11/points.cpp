#include "Point.h"

Point::Point() : Point(0, 0) {}

Point::Point(int x, int y) : x_(x), y_(y) {}

Point::Point(const Point &p) : x_(p.x_), y_(p.y_) {}

int Point::get_x() const { return x_; }

int Point::get_y() const { return y_; }

Point &Point::operator=(const Point &p) {
    x_ = p.x_;
    y_ = p.y_;
    return *this;
}

Point Point::operator+(const Point &p) const { return Point(x_ + p.x_, y_ + p.y_); }

Point &Point::operator+=(const Point &p) {
    x_ += p.x_;
    y_ += p.y_;
    return *this;
}

Point Point::operator*(int v) const { return Point(x_ * v, y_ * v); }

Point operator*(int v, const Point &p) { return p * v; }

std::ostream &operator<<(std::ostream &os, const Point &p) {
    os << '(' << p.get_x() << ',' << p.get_y() << ')';
    return os;
}
