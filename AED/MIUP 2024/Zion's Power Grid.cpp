#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;

int main() {
    uint64_t A;
    uint64_t K;

    // Read Data
    cin >> A >> K;
    vector<uint64_t> L(K);
    for (uint64_t i = 0; i < K; i++) cin >> L[i];

    // Sort data
    sort(L.begin(), L.end());

    // Find the right product
    uint64_t l = 0;
    uint64_t h = K - 1;
    uint64_t area;
    while ((area = L[l] * L[h]) != A) {
        if (area < A) l++;
        else h--;
    }

    // Print out result
    cout << L[l] << ' ' << L[h] << endl;
}
