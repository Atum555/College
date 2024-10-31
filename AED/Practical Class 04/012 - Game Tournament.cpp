#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;

int main() {
    uint64_t N;
    uint64_t K;

    cin >> N >> K;

    // Read data
    vector<uint64_t> v(N);
    for (uint64_t i = 0; i < N; i++) cin >> v[i];

    // Sort data
    sort(v.begin(), v.end());

    for (uint64_t i = 0; i < K; i++) cout << *(v.rbegin() + i) << endl;

    return 0;
}
