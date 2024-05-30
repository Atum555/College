#include "show_file.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void maximum(const string &input_fname, const string &output_fname) {
    ifstream      ifs(input_fname);
    ofstream      ofs(output_fname);
    double        number;
    unsigned long count = 0;
    double        max;
    bool          first = true;
    while (ifs >> number) {
        ofs << fixed << setprecision(3) << number << endl;
        if (first) max = number;
        first = false;
        max   = max < number ? number : max;
        count++;
    }
    ofs << fixed << setprecision(3) << "count=" << count << "/max=" << max << endl;
}