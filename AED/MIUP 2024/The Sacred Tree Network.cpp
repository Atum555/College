#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <string>

using namespace std;

int main() {
    string a;

    // Read Data
    cin >> a;

    // Find longest stretch of swamp areas.
    uint64_t longest = 0;
    uint64_t count   = 0;
    for (uint64_t i = 0; i < a.length(); i++) {
        if (a[i] == '0') count++;
        else {
            longest = max(longest, count);
            count   = 0;
        }
    }

    // Count days
    uint64_t result;
    result  = longest % 2;
    result += longest / 2;

    cout << result << endl;
}
