#include "Polygon.h"
#include <iostream>
#include <math.h>
#include <vector>

double distance(const Point &a, const Point &b) {
    double s1 = (a.getX() - b.getX()) * (a.getX() - b.getX());
    double s2 = (a.getY() - b.getY()) * (a.getY() - b.getY());
    return sqrt(s1 + s2);
}

Polygon::Polygon() {}

Polygon::Polygon(std::vector<Point> v) : points_(v) {}

bool Polygon::get_vertex(unsigned long i, Point &p) const {
    if (i > points_.size() or i < 1) return false;
    p = points_[i - 1];
    return true;
}

double Polygon::perimeter() const {
    double p = 0;
    for (size_t i = 0; i < points_.size() - 1; ++i) { p += distance(points_[i], points_[i + 1]); }
    p += distance(points_[0], points_[points_.size() - 1]);
    return p;
}

void Polygon::show() const {
    std::cout << "{";
    for (Point p : points_) p.show();
    std::cout << "}";
}

void Polygon::add_vertex(unsigned long i, const Point &p) {
    points_.insert(points_.begin() + i - 1, p);
}
