#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;

int64_t merge_and_count(
    vector<int64_t> &NUMBERS, vector<int64_t> &temp, const int64_t low, const int64_t mid,
    const int64_t high
) {
    int64_t inversions = 0;
    int64_t i          = low;     // Index first half
    int64_t j          = mid + 1; // Index second half
    int64_t k          = low;     // Index sorted

    while (k <= high) {
        // First half is over
        if (i > mid) temp[k++] = NUMBERS[j++];

        // Second half is over
        else if (j > high) temp[k++] = NUMBERS[i++];

        // First element is smaller than second
        else if (NUMBERS[i] <= NUMBERS[j]) temp[k++] = NUMBERS[i++];

        // Second element is smaller
        else {
            temp[k++]   = NUMBERS[j++];
            inversions += mid - i + 1;
        }
    }

    for (int64_t i = low; i <= high; i++) NUMBERS[i] = temp[i];

    return inversions;
}

int64_t merge_sort_and_count(
    vector<int64_t> &NUMBERS, vector<int64_t> &temp, const int64_t low, const int64_t high
) {
    int64_t inversions = 0;
    int64_t mid;

    if (low < high) {
        mid = low + (high - low) / 2;

        inversions += merge_sort_and_count(NUMBERS, temp, low, mid);
        inversions += merge_sort_and_count(NUMBERS, temp, mid + 1, high);
        inversions += merge_and_count(NUMBERS, temp, low, mid, high);
    }

    return inversions;
}

int main() {
    int64_t N;
    int64_t inversions;

    // Read Data
    cin >> N;
    vector<int64_t> NUMBERS(N);
    vector<int64_t> temp(N);
    for (int64_t i = 0; i < N; i++) cin >> NUMBERS[i];

    // Sort and Count inversions
    inversions = merge_sort_and_count(NUMBERS, temp, 0, N - 1);

    cout << inversions << endl;

    return 0;
}
