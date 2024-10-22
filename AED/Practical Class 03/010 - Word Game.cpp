#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// Return the first position where f is true
template <class T, class P> int lower_bound(const vector<T> &v, P f) {
    T low = 0, mid, high = v.size() - 1;

    while (low < high) {
        mid = low + (high - low) / 2;
        if (f(mid)) high = mid;
        else low = mid + 1;
    }

    return low;
}

bool isPossible(const string &A, const string &B, const unordered_set<int> &removed) {
    /*
    cout << endl << "Currently with set: " << removed.size() << endl;
    for (const auto &i : removed) cout << i << " ";
    cout << endl;
    */

    int iA = 0;

    // Search all the letters in B
    for (const auto b : B) {
        while (true) {
            // cout << "Looking for: " << b << " at: " << iA << " : " << A[iA] << endl;

            if (iA >= A.size()) return false; // Until A is empty

            // Letter in A and not removed
            if (A[iA] == b and removed.find(iA + 1) == removed.end()) {
                iA++;
                break;
            }
            iA++;
        }
    }
    return true;
}

int main() {
    string      A;
    string      B;
    vector<int> removed;
    int         t;

    cin >> A >> B;

    while (cin >> t) removed.push_back(t);

    cout << lower_bound(removed, [&A, &B, &removed](int max) {
        unordered_set<int> removedSet(removed.begin(), removed.begin() + max + 1);
        return !isPossible(A, B, removedSet);
    }) << endl;

    return 0;
}
