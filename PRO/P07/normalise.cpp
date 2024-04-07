#include "print.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void normalise(const string &input_fname, const string &output_fname) {
    ifstream in(input_fname);
    ofstream out(output_fname);
    string   str;
    while (getline(in, str)) {
        if (!str.length()) continue;
        str.find_first_not_of(" ");
        size_t start = str.find_first_not_of(" ");
        size_t end   = str.find_last_not_of(" ");
        if (start == string::npos) continue;
        for (size_t i = start; i <= end; ++i) out << (char)toupper(str[i]);
        out << endl;
    }
}