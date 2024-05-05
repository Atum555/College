#include <string>
#include <vector>

using namespace std;

unsigned roman_to_arab(const string &roman) {
    vector<pair<char, unsigned int>> roman_to_int = {
        {'I',    1},
        {'V',    5},
        {'X',   10},
        {'L',   50},
        {'C',  100},
        {'D',  500},
        {'M', 1000}
    };
    unsigned long result = 0;
    unsigned int  last   = 0;

    for (char c : roman) {
        for (auto kp : roman_to_int) {
            if (kp.first != c) continue;
            if (kp.second > last) result -= last * 2;
            result += kp.second;
            last    = kp.second;
        }
    }

    return result;
}