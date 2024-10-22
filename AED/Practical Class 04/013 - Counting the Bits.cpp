#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;

typedef struct nWithBits {
    uint64_t number;
    uint8_t  bitCount;
} nWithBits;

uint8_t countBits(uint64_t n) {
    uint8_t bitCount = 0;
    while (n) {
        bitCount  += n & 1;
        n        >>= 1;
    }
    return bitCount;
}

int main() {
    uint64_t N;

    // Read data
    cin >> N;
    vector<nWithBits> v(N);
    for (uint64_t i = 0; i < N; i++) {
        cin >> v[i].number;
        v[i].bitCount = countBits(v[i].number);
    }

    // Sort data
    sort(v.rbegin(), v.rend(), [](const nWithBits &a, const nWithBits &b) {
        if (a.bitCount < b.bitCount) return true;
        if (a.bitCount > b.bitCount) return false;
        return a.number > b.number;
    });

    for (const auto &n : v) cout << n.number << endl;

    return 0;
}
