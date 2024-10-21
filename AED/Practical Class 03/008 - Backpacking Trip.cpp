#include <iostream>
#include <vector>

using namespace std;

bool isPossible(const vector<int> &v, int maxValue, int partitions) {
    int count = 1;
    int sum   = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] > maxValue) return false; // Single item bigger than max partition sum

        sum += v[i];

        if (sum > maxValue) {
            count++;
            sum = v[i];
        }

        if (count > partitions) return false; // More partitions needed
    }
    return true;
}

template <class F> int my_lower_bound(int min, int max, F f) {
    int low = 0, mid, high = max;

    while (low < high) {
        mid = low + (high - low) / 2;
        if (f(mid)) high = mid;
        else low = mid + 1;
    }

    if (f(low)) return low;
    return -1;
}

int main() {
    int numberOfElements;
    int numberOfQueries;
    int partitions;
    int totalSum;

    // Read data
    cin >> numberOfElements;
    vector<int> v(numberOfElements);
    for (int i = 0; i < numberOfElements; i++) {
        cin >> v[i];
        totalSum += v[i];
    }

    // Read and Process queries
    cin >> numberOfQueries;
    for (int i = 0; i < numberOfQueries; i++) {
        cin >> partitions;
        cout << my_lower_bound(0, totalSum, [&v, partitions](int maxValue) {
            return isPossible(v, maxValue, partitions);
        }) << endl;
    }

    return 0;
}
