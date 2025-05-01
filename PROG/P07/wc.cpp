#include <fstream>
#include <iostream>
#include <string>
#include "wc.h"

using namespace std;

wcresult wc(const string &filename) {
    ifstream  fin(filename);
    string   line;
    wcresult r = { 0, 0, 0 };
    while (getline(fin, line)) {
        ++r.lines;
        r.bytes += line.size() + 1;

        istringstream s(line);
        string       word;
        while (s >> word) ++r.words;
    }
    return r;
}