#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longest_prefix(const vector<string> &v) {
    string result;
    if (not v.size()) return result;

    size_t index = 0;
    while (true) {
        char c = 0;
        for (string s : v) {
            if (s.size() == index) return result;
            if (not c) c = s[index];
            if (c != s[index]) return result;
        }
        result.push_back(c);
        ++index;
    }
}
