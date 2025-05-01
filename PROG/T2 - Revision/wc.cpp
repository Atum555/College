#include "wc.h"
#include <fstream>
#include <string>

using namespace std;

wcresult wc(const string &filename) {
    ifstream ifs(filename);
    wcresult r = { 0, 0, 0 };
    string   line;

    while (getline(ifs, line)) {
        r.lines++;
        r.bytes++;
        r.bytes += line.size();
        string        word;
        istringstream issLine(line);
        while (issLine >> word) r.words++;
    }

    return r;
}
