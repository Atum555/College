#include <string>

bool pangram(const std::string &s, std::string &m) {
    m.clear();
    int letters = 67108863;
    for (const char l : s) {
        if ('a' <= l && l <= 'z') letters &= ~(1 << (l - 'a'));
        if ('A' <= l && l <= 'Z') letters &= ~(1 << (l - 'A'));
    }
    if (!letters) {
        m[0] = 0;
        return true;
    }
    int i = 0;
    while (letters) {
        if (letters & 1) m.push_back('a' + i);
        letters >>= 1;
        ++i;
    }
    return false;
}