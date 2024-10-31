#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;

int main() {
    uint64_t BOXES;
    uint64_t FRIENDS;
    uint64_t minDiference;

    // Read Data
    cin >> BOXES >> FRIENDS;
    vector<uint64_t> CHOCOLATES(BOXES);
    for (uint64_t i = 0; i < BOXES; i++) cin >> CHOCOLATES[i];

    // Sort Data
    sort(CHOCOLATES.begin(), CHOCOLATES.end());

    // Loop through and check min
    minDiference = CHOCOLATES[FRIENDS - 1] - CHOCOLATES[0];
    for (uint64_t i = 1; i < BOXES - FRIENDS + 1; i++)
        minDiference = min(minDiference, CHOCOLATES[FRIENDS - 1 + i] - CHOCOLATES[i]);

    cout << minDiference << endl;

    return 0;
}
