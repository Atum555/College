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

    // Read data
    cin >> numberOfElements;
    vector<int> v(numberOfElements);
    for (int i = 0; i < numberOfElements; i++) cin >> v[i];

    // Read and Process queries
    cin >> numberOfQueries;
    for (int i = 0; i < numberOfQueries; i++) {
        cin >> query;
        cout << lower_bound(v, [query](int value) { return value >= query; }) << endl;
    }

    return 0;
}
