#include "print.h"
#include <fstream>
#include <string>

using namespace std;

void normalise(const string &input_fname, const string &output_fname) {
    ifstream ifs(input_fname);
    ofstream ofs(output_fname);
    string   line;

    while (getline(ifs, line)) {
        if (line.find_first_not_of(' ') == string::npos) continue;

        size_t start = line.find_first_not_of(' ');
        size_t end   = line.find_last_not_of(' ');
        for (; start <= end; ++start) { ofs << char(toupper(line[start])); }
        ofs << endl;
    }
}
