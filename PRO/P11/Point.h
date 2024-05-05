#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
  public:
    Point();                                // builds (0,0)
    Point(int x, int y);                    // builds (x,y)
    Point(const Point &p);                  // copy construtor
    int    get_x() const;                   // get x coordinate
    int    get_y() const;                   // get y coordinate
    Point &operator=(const Point &p);       // assignment operator
    Point  operator+(const Point &p) const; // sum
    Point &operator+=(const Point &p);      // composed assignment and sum
    Point  operator*(int v) const;          // "right" multiplication by scalar
  private:
    int x_, y_;
};

Point operator*(int x, const Point &p); // "left" multiplication by scalar
std::ostream &operator<<(std::ostream &os, const Point &p);

#endif
