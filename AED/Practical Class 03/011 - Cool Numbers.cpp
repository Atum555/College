#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;

vector<uint8_t> intToVector(uint64_t n) {
    vector<uint8_t> digits;
    while (n) {
        digits.push_back(n % 10);
        n /= 10;
    }
    return digits;
}

uint64_t vectorToInt(const vector<uint8_t> &digits) {
    uint64_t n = 0;
    for (int64_t i = digits.size() - 1; i >= 0; i--) {
        n *= 10;
        n += digits[i];
    }
    return n;
}

int main() {
    uint64_t        queries;
    uint64_t        N;
    uint64_t        K;
    uint64_t        sum;
    int64_t         distance;
    vector<uint8_t> digits;

    cin >> queries;

    for (uint64_t i = 0; i < queries; i++) {
        cin >> N >> K;
        N++; // Start looking in the next number

        digits = intToVector(N);
        sum    = 0;
        for (const auto &digit : digits) sum += digit;
        distance = K - sum;


        cout << endl
             << "Looking at: " << N << " sum is: " << sum << " target: " << K
             << " distance: " << distance << endl;


        if (distance > 0) {
            while (distance) {
                digits.push_back(0);
                for (auto &digit : digits) {
                    while (distance) {
                        // cout << "Looking at digit: " << digit << " distance: " << distance <<
                        // endl;
                        if (digit == 9) break;
                        digit++;
                        distance--;
                    }
                }
            }
        }
        if (distance < 0) {
            uint64_t i = 0;
            while (distance) {
                i = 0;
                while (distance) {
                    cout << "Looking at digit: " << i << " : " << (int)digits[i] << endl;
                    if (i == digits.size() - 1) digits.push_back(0); // Increase number if necessary
                    if (digits[i] == 0) {
                        i++;
                        continue;
                    }

                    digits[i + 1]++;
                    distance--;
                    do {
                        digits[i]--;
                        distance++;
                    } while (distance and digits[i] > 0);
                    break;
                }
            }
        }

        cout << vectorToInt(digits) << endl;
    }
}
