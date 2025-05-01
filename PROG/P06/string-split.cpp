#include "print_string.h"
#include <string>
#include <vector>

void split(const std::string &s, std::vector<std::string> &v) {
    v.clear();
    size_t pos = 0;
    do {
        size_t nextSpace = s.find(' ', pos);
        if (nextSpace == std::string::npos) nextSpace = s.length();

        string sub = s.substr(pos, nextSpace - pos);
        if (sub.length()) v.push_back(sub);
        pos = nextSpace + 1;
    } while (pos != s.length() + 1);
}
