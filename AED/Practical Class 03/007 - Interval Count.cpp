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
    return -1;
}

int main() {
    int numberOfElements;
    int numberOfQueries;
    int query;
    int iA;
    int iB;
    int count;

    // Read data
    cin >> numberOfElements;
    vector<int> v(numberOfElements);
    for (int i = 0; i < numberOfElements; i++) cin >> v[i];

    // Read and Process queries
    cin >> numberOfQueries;
    for (int i = 0; i < numberOfQueries; i++) {
        // Find first >= A
        cin >> query;
        iA = lower_bound(v, [query](int v) { return v >= query; });
        if (iA == -1) iA = v.size();

        // Find first > B
        cin >> query;
        iB = lower_bound(v, [query](int v) { return v > query; });
        if (iB == -1) iB = v.size();

        // Count the elements from A to B
        cout << iB - iA << endl;
    }

    return 0;
}
