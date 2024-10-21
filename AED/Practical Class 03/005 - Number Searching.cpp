#include <iostream>
#include <vector>

using namespace std;

template <class T> int binary_search(vector<T> &v, T value) {
    T low = 0, mid, high = v.size() - 1;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (v[mid] < value) low = mid + 1;
        else if (v[mid] > value) high = mid - 1;
        else return mid;
    }

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
        cout << binary_search(v, query) << endl;
    }

    return 0;
}
