#include <fstream>
#include <iostream>
#include <string>

int count(const std::string &fname, const std::string &word) {
    std::ifstream fin(fname);
    std::string   w0(word);
    std::string   w1;
    int           c = 0;
    for (char &c : w0)
        if ('A' <= c && c <= 'Z') c = c - 'A' + 'a';

    while (fin >> w1) {
        for (char &c : w1)
            if ('A' <= c && c <= 'Z') c = c - 'A' + 'a';
        if (w0 == w1) ++c;
    }
    return c;
}