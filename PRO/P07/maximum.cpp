#include "show_file.h"
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void maximum(const string &input_fname, const string &output_fname) {
    ifstream      in(input_fname);
    ofstream      out(output_fname);
    string        str;
    unsigned long count  = 0;
    double        max    = 0;
    bool          maxSet = false;
    while (getline(in, str)) {
        if (!str.length()) continue;
        str.find_first_not_of(" ");
        size_t start = str.find_first_not_of(" ");
        size_t end   = str.find_last_not_of(" ");
        if (start == string::npos) continue;

        double        number  = 0;
        unsigned long decimal = 0;
        bool          dot     = false;
        bool          sign    = false;
        for (size_t i = start; i <= end; ++i) {
            if (str[i] == '-') {
                sign = true;
                continue;
            }
            if (str[i] == '.') {
                dot = true;
                continue;
            }
            if (dot) ++decimal;
            number *= 10;
            number += str[i] - '0';
        }
        if (sign && number != 0) number *= -1;
        number /= pow(10, decimal);
        ++count;
        max    = number > max || !maxSet ? number : max;
        maxSet = true;
        out << fixed << setprecision(3) << number << endl;
    }
    out << "count=" << count << "/max=" << max << endl;
}