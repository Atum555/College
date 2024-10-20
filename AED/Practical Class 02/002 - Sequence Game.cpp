// Given a list of numbers compute the largest contiguous sum

#include <iostream>

using namespace std;

int main() {
    // Read number of numbers
    unsigned numberOfInputs;
    cin >> numberOfInputs;

    // Read Numbers and accumulate the sum
    int next;
    cin >> next; // First number
    int maxSum = next;
    int sum    = next;

    for (int i = 1; i < numberOfInputs; ++i) {
        cin >> next;

        // If number is positive update local sum
        if (next >= 0) {
            sum = max(sum + next, next);
            continue;
        }

        // If number is negative
        // Update maxSum
        if (sum > maxSum) maxSum = sum;

        // If sum is less than zero replace it
        if (sum < 0) sum = next;

        // If sum is positive add next
        else sum += next;
    }

    // Check for the last sum calculated
    if (sum > maxSum) maxSum = sum;

    // Print the result
    cout << maxSum << endl;

    return 0;
}
