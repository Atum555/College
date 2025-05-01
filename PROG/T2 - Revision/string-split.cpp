#include "print_string.h"
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void split(const string &s, vector<string> &v) {
    istringstream ss(s);
    string        word;
    while (ss >> word) v.push_back(word);
}
