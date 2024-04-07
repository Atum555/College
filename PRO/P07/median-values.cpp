#include "show_file.h"
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T> class Line {
  public:
    string    name;
    vector<T> v;
    T         median = 0;
};

template <class T> void median(Line<T> &line) {
    sort(line.v.begin(), line.v.end());
    size_t s = line.v.size();
    line.median
        = s % 2 ? line.v[s / 2] : 0.5 * (line.v[s / 2 - 1] + line.v[s / 2]);
}

void calc_medians(const string &input_fname, const string &output_fname) {
    ifstream inf(input_fname);
    ofstream outf(output_fname);
    string   str;
    while (getline(inf, str)) {
        // Skip Comment Lines
        if (str.find('#') != string::npos) continue;

        stringstream lineStr(str);
        Line<double> line;

        // Get Line Name
        lineStr >> line.name;

        // Parse Numbers
        while (lineStr >> str) {
            double        number   = 0;
            bool          negative = false;
            bool          dot      = false;
            unsigned long decimal  = 0;
            for (char c : str) {
                if (c == '-') negative = true;
                else if (c == '.') dot = true;
                else {
                    if (dot) ++decimal;
                    number *= 10;
                    number += c - '0';
                }
            }
            if (negative && number != 0) number *= -1;
            number /= pow(10, decimal);
            line.v.push_back(number);
        }

        // Calcular a média
        median(line);
        outf << line.name << " " << fixed << setprecision(1) << line.median
             << endl;
    }
}