#include "print_vector.h"
#include <vector>

template <typename T>
void normalise(std::vector<T> &v, const T &min, const T &max) {
    for (T &item : v) {
        if (item < min) item = min;
        if (item > max) item = max;
    }
}
