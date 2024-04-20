#ifndef __POLYGON_P__
#define __POLYGON_P__

#include "Point.h"
#include <vector>

class Polygon {
  public:
    Polygon();
    Polygon(std::vector<Point> v);

    bool   get_vertex(unsigned long i, Point &p) const;
    double perimeter() const;
    void   show() const;

    void add_vertex(unsigned long i, const Point &p);

  private:
    std::vector<Point> points_;
};

#endif
