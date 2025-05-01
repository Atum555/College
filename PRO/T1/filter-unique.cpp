#include "print_array.h"

int filter_unique(const int arr[], int size, int out[]) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        bool unique = true;
        for (int j = 0; j < size; ++j) {
            if (i[arr] == j[arr] && i != j) unique = false;
        }
        if (unique) {
            out[count] = i[arr];
            ++count;
        }
    }
    return count;
}
