#include <iostream>
#include <stdint.h>
#include <string>
#include <vector>

using namespace std;

// Transform an int into a vector of digits
vector<int8_t> intToVector(int64_t n) {
    vector<int8_t> digits;
    while (n) {
        digits.push_back(n % 10);
        n /= 10;
    }
    return digits;
}

// Transform a vector of digits into an int
int64_t vectorToInt(const vector<int8_t> &digits) {
    int64_t n = 0;
    for (int64_t i = digits.size() - 1; i >= 0; i--) {
        n *= 10;
        n += digits[i];
    }
    return n;
}

// Calculate the sum of the digits of an int
int64_t digitSum(int64_t number) {
    int64_t sum = 0;
    while (number > 0) {
        sum    += number % 10;
        number /= 10;
    }
    return sum;
}

// Calculate the next number after N whose digits add
// up to K, by brute forcing
int64_t bruteForce(int64_t N, const int64_t K) {
    while (digitSum(++N) != K);
    return N;
}

// Gets the next number after N whose digits add up to K
int64_t getResultDistancePositive(int64_t N, const int64_t K, bool debug = false) {
    N++; // Get next number
    vector<int8_t> digits   = intToVector(N);
    int64_t        sum      = digitSum(N);
    int64_t        distance = K - sum;


    while (distance) {                 // While sum is not equal to K
        digits.push_back(0);           // Increase number of digits just in case
        for (auto &digit : digits) {   // Loop through each digit
            while (distance) {         // While sum is not equal to K
                if (digit == 9) break; // Break if can't increase digit anymore

                if (debug)             // Print for debug
                    cout << "N: " << vectorToInt(digits) << " - " << (int)digit << " : " << distance
                         << endl;

                digit++;    // Increase digit
                distance--; // Decrease distance to target sum
            }
        }
    }

    return vectorToInt(digits);
}

// Gets the next number after N whose digits add up to K
int64_t getResultDistanceNegative(int64_t N, const int64_t K, bool debug = false) {
    N++;
    vector<int8_t> digits = intToVector(N);
    int64_t        sum    = digitSum(N);

    while (sum > K) {                                     // While sum is greater than K
        digits.push_back(0);                              // Increase number of digits just in case
        for (int64_t i = 0; i < digits.size() - 1; i++) { // Loop through each digit

            if (debug)                                    // Print for debug
                cout << "N: " << vectorToInt(digits) << " - " << (int)digits[i] << " : "
                     << digitSum(vectorToInt(digits)) << endl;

            if (digits[i] < 10 and (sum = digitSum(vectorToInt(digits))) <= K)
                break;       // If sum is no longer greater than k stop

            digits[i] = 0;   // Set digit to 0
            digits[i + 1]++; // Increase next digit by one
        }
    }

    N   = vectorToInt(digits);                          // Convert digits to int
    sum = digitSum(N);                                  // Calculate final sum
    if (sum == K) return N;                             // Return N if correct
    else return getResultDistancePositive(N, K, debug); // Calculate again if less than target
}

int main(int argc, char **argv) {
    // Collect debug params
    bool debug = false; // Enable debug
    bool bf    = false; // Enable brute force answer
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "bf") bf = true;
        else if (string(argv[i]) == "debug") {
            debug = true;
            bf    = true;
        }
    }

    // Declare variables
    int64_t T;                 // Number of test cases
    int64_t N;                 // Number given
    int64_t K;                 // Target sum
    int64_t sum;               // Current sum
    int64_t distance;          // Current distance to target sum
    int64_t result;            // Result for current test case
    int64_t result_bruteForce; // Result given by brute force

    // Loop through test cases
    cin >> T;
    for (uint64_t i = 0; i < T; i++) {
        cin >> N >> K;
        result = N + 1; // Start looking in the next number

        sum      = digitSum(result);
        distance = K - sum;

        if (debug) // Print for debug
            cout << endl
                 << "Query number: " << i << endl
                 << "Number given: " << N << endl
                 << "Sum is: " << sum << endl
                 << "Target sum: " << K << endl
                 << "Distance: " << distance << endl
                 << endl;

        // Distance is positive, meaning
        // We need to increase the sum
        if (distance > 0) result = getResultDistancePositive(N, K, debug);

        // Distance is negative, meaning
        // We need to decrease the sum
        else if (distance < 0) result = getResultDistanceNegative(N, K, debug);

        if (bf) // Calculate BruteForce answer
            result_bruteForce = bruteForce(N, K);

        // Print debug results
        if (debug or bf) {
            // Print Success
            if (result == result_bruteForce)
                cout << "Smart: \033[92m" << result << "\033[0m" << endl
                     << "Brute: " << result_bruteForce << endl;

            // Print Failure
            else
                cout << "Smart: \033[91m" << result << "\033[0m" << endl
                     << "Brute: " << result_bruteForce << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}
