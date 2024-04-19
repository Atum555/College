#ifndef POINT2D_H
#define POINT2D_H

class Point2d {
  public:
    Point2d();                   // default constructor (builds origin)
    Point2d(const Point2d &p);   // copy constructor
    Point2d(double x, double y); // constructor using supplied coordinates
    double get_x() const;        // accessor for X coordinate
    double get_y() const;        // accessor for Y coordinate
    void   set_x(double x);      // mutator for X coordinate
    void   set_y(double y);      // mutator for Y coordinate
    void   translate(const Point2d &t);         // translate coordinates
    double distance_to(const Point2d &p) const; // get distance to given point
  private:
    double x;                                   // X coordinate
    double y;                                   // Y coordinate
};

Point2d::Point2d() {
    x = 0.0;
    y = 0.0;
}

Point2d::Point2d(const Point2d &p) {
    x = p.x;
    y = p.y;
}

Point2d::Point2d(double x, double y) {
    this->x = x;
    this->y = y;
}

double Point2d::get_x() const { return x; }

double Point2d::get_y() const { return y; }

void Point2d::set_x(double x) { this->x = x; }

void Point2d::set_y(double y) { this->y = y; }

#endif