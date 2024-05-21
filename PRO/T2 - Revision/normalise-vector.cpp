#include "print_vector.h"
#include <vector>

template <typename T> void normalise(vector<T> &v, const T &min, const T &max) {
    for (T &value : v) {
        if (value < min) value = min;
        if (value > max) value = max;
    }
}