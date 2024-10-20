// Given integers N, K, T and a sequence of N integers,
// compute the number of valid sections of length K such
// that at least half of its elements are bigger or equal than T.

#include <iostream>

using namespace std;

void bruteForce() {
    int numberOfPositions;
    int length;
    int minimum;
    int result = 0;

    // Read input conditions
    cin >> numberOfPositions >> length >> minimum;

    int *list = new int[numberOfPositions];

    // Read depth data
    for (int i = 0; i < numberOfPositions; i++) cin >> list[i];

    // Loop through all intervals of items
    for (int i = 0; i < numberOfPositions - length + 1; i++) {
        int count = 0;

        for (int j = 0; j < length; j++) {
            // Count valid items
            count += list[i + j] >= minimum ? 1 : 0;

            // Stop if enough
            if (count * 2 >= length) {
                result++;
                break;
            }
        }
    }

    // Print Result
    cout << result << endl;
}

void smart() {
    int numberOfPositions;
    int length;
    int minimum;
    int result = 0;

    // Read input conditions
    cin >> numberOfPositions >> length >> minimum;

    int *list = new int[numberOfPositions];

    // Read depth data
    for (int i = 0; i < numberOfPositions; i++) cin >> list[i];

    int count = 0;

    // Count the number of valid items in the first interval
    for (int i = 0; i < length; i++)
        if (list[i] >= minimum) count++;

    // Check if the first interval is valid
    if (count * 2 >= length) result++;

    for (int i = length; i < numberOfPositions; i++) {
        // Update valid items count
        if (list[i] >= minimum) count++;
        if (list[i - length] >= minimum) count--;

        // Check if interval is valid
        if (count * 2 >= length) result++;
    }

    // Print out result
    cout << result << endl;
}

int main() {
    smart();
    return 0;
}
