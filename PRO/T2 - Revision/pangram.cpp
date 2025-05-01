#include <set>
#include <string>

using namespace std;

bool pangram(const string &s, string &m) {
    set<char> seen;
    for (char c : s)
        if (isalpha(c)) seen.insert(tolower(c));

    m.clear();
    if (seen.size() == 26) return true;

    for (char c = 'a'; c <= 'z'; c++)
        if (seen.find(c) == seen.end()) m.push_back(c);

    return false;
}
