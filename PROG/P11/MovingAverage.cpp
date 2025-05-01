#include "MovingAverage.h"

using namespace std;

MovingAverage::MovingAverage(size_t n) : n_(n) {}

void MovingAverage::update(double value) {
    values_.push_back(value);
    if (values_.size() > n_) values_.pop_front();
}

double MovingAverage::get() const {
    double sum = 0;
    for (double v : values_) sum += v;
    double divisor = min(n_, values_.size());
    return sum / divisor;
}
