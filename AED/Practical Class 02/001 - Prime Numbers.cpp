// From a list of numbers print those that are prime and those that are composite

#include <iostream>

using namespace std;

int main() {
    unsigned long numberOfInputs;
    long          number;
    long          numberSqrt;
    char          flag;

    // Read number of numbers
    cin >> numberOfInputs;

    // Read numbers and evaluate
    for (unsigned long i = 0; i < numberOfInputs; ++i) {
        cin >> number;
        flag       = 0;

        // Smaller or equal to 2
        if (number <= 2) {
            cout << number << " is prime" << endl;
            continue;
        }

        // Check for divisors until the sqrt
        for (unsigned long j = 2; j*j <= number; ++j) {
            if (number % j == 0) {
                flag = 1;
                break;
            }
        }

        // Print answer
        if (flag) cout << number << " is composite" << endl;
        else cout << number << " is prime" << endl;
    };

    return 0;
}
