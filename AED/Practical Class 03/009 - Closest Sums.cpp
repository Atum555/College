#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <class T, class P> int lower_bound(vector<T> &v, P f) {
    T low = 0, mid, high = v.size() - 1;

    while (low < high) {
        mid = low + (high - low) / 2;
        if (f(v[mid])) high = mid;
        else low = mid + 1;
    }

    if (f(v[low])) return low;
    return v.size() - 1;
}

int main() {
    int         numberOfElements;
    int         numberOfQueries;
    int         query;
    int         mid;
    int         distance;
    vector<int> sums;
    vector<int> results;

    // Read data
    cin >> numberOfElements;
    vector<int> numbers(numberOfElements);
    for (int i = 0; i < numberOfElements; i++) cin >> numbers[i];

    // Calculate sums
    for (int i = 0; i < numbers.size() - 1; i++)
        for (int j = i + 1; j < numbers.size(); j++) sums.push_back(numbers[i] + numbers[j]);

    // Sort sums
    sort(sums.begin(), sums.end());

    // Read and Process queries
    cin >> numberOfQueries;
    for (int i = 0; i < numberOfQueries; i++) {
        results.clear();
        cin >> query;

        mid = lower_bound(sums, [query](int sum) { return sum >= query; });
        //cout << "Looking for: " << query << " Found at: " << mid << " - " << sums[mid] << endl;


        // Backwards
        mid--;
        if (mid >= 0) {
            results.push_back(sums[mid]);
            distance = abs(query - sums[mid]);
        }

        // Forwards
        mid++;
        if (!results.size()) results.push_back(sums[mid]);
        else if (abs(query - sums[mid]) == distance) results.push_back(sums[mid]);
        else if (abs(query - sums[mid]) < distance) {
            results.clear();
            results.push_back(sums[mid]);
        };

        // Print results
        cout << results[0];
        for (int i = 1; i < results.size(); i++) cout << " " << results[i];
        cout << endl;
    }

    return 0;
}
