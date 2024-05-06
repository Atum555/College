#ifndef MOVING_AVERAGE_H
#define MOVING_AVERAGE_H

#include <list>

class MovingAverage {
  public:
    MovingAverage(std::size_t n);
    void   update(double value);
    double get() const;

  private:
    std::size_t       n_;
    std::list<double> values_;
};

#endif