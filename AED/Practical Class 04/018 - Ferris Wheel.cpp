#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;

int main() {
    uint64_t N_CHILD;
    uint64_t MAX_WEIGHT;
    uint64_t N_CABINS;

    // Read Data
    cin >> N_CHILD >> MAX_WEIGHT;
    vector<uint64_t> CHILDREN(N_CHILD);
    for (uint64_t i = 0; i < N_CHILD; i++) cin >> CHILDREN[i];

    // Sort weights
    sort(CHILDREN.begin(), CHILDREN.end());

    N_CABINS = 0;

    int64_t a = 0;
    int64_t b = N_CHILD - 1;
    while (a <= b) {
        // The same child
        if (a == b) N_CABINS++;

        // Both can fit
        else if (CHILDREN[a] + CHILDREN[b] <= MAX_WEIGHT) {
            N_CABINS++;
            a++;
        }

        // Only b fits
        else
            N_CABINS++;
        b--;
    }

    cout << N_CABINS << endl;

    return 0;
}
