#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;

typedef struct student {
    uint64_t start;
    uint64_t end;
} student;

int main() {
    uint64_t N;
    uint64_t maxC;
    uint64_t count;

    cin >> N;

    // Read data
    vector<uint64_t> start(N);
    vector<uint64_t> end(N);
    for (uint64_t i = 0; i < N; i++) cin >> start[i] >> end[i];

    // Sort data
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    maxC = count = 0;
    auto iS      = start.begin();
    auto iE      = end.begin();
    while (iS != start.end()) {
        //cout << "Looking at S: " << *iS << " E: " << *iE;
        if (*iS < *iE) {
            count++;
            iS++;
        }
        else if (*iE < *iS) {
            count--;
            iE++;
        }
        else if (*iS == *iE) {
            iS++;
            iE++;
        }
        maxC = max(count, maxC);
        //cout << " count: " << count << " max: " << maxC << endl;
    }

    cout << maxC << endl;

    return 0;
}
