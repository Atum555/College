#include "Point2d.h"
#include <math.h>

void Point2d::translate(const Point2d &t) {
    this->set_x(this->get_x() + t.get_x());
    this->set_y(this->get_y() + t.get_y());
}

double Point2d::distance_to(const Point2d &p) const {
    return sqrt(pow(this->get_x() - p.get_x(), 2) + pow(this->get_y() - p.get_y(), 2));
}
