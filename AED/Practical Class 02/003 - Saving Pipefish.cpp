// Given integers N, K, T and a sequence of N integers,
// compute the number of valid sections of length K such
// that at least half of its elements are bigger or equal than T.

#include <iostream>

using namespace std;

void bruteForce() {
    unsigned long numberOfPositions;
    unsigned long length;
    unsigned long minimum;
    unsigned long result = 0;
    cin >> numberOfPositions >> length >> minimum;

    unsigned long *list = new unsigned long[numberOfPositions];

    for (unsigned long i = 0; i < numberOfPositions; i++) cin >> list[i];

    for (unsigned long i = 0; i < numberOfPositions - length + 1; i++) {
        unsigned long count = 0;
        for (unsigned long j = 0; j < length; j++) {
            count += list[i + j] >= minimum ? 1 : 0;
            if (count * 2 >= length) {
                result++;
                break;
            }
        }
    }

    cout << result << endl;
}

void smart() {
    unsigned long numberOfPositions;
    unsigned long length;
    unsigned long minimum;
    unsigned long result = 0;
    cin >> numberOfPositions >> length >> minimum;

    unsigned long *list = new unsigned long[numberOfPositions];

    for (unsigned long i = 0; i < numberOfPositions; i++) cin >> list[i];

    

    cout << result << endl;
}

int main() {
    bruteForce();
    return 0;
}