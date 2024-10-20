// Count the number os times 42 appears in a sequence on numbers.

#include <iostream>

using namespace std;

int main() {
    unsigned long numberOfInputs;
    long          temp;
    unsigned long count = 0;

    // Read number of numbers
    cin >> numberOfInputs;

    // Read numbers and count
    for (unsigned long i = 0; i < numberOfInputs; i++) {
        cin >> temp;
        if (temp == 42) count++;
    }

    // Print answer
    cout << count << endl;

    return 0;
}