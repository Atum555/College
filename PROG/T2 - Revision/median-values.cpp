#include "show_file.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

double median(const vector<double> &v) {
    vector<double> vCopy = v;
    sort(vCopy.begin(), vCopy.end());

    if (vCopy.size() % 2 == 1) return vCopy[vCopy.size() / 2];

    return 0.5 * (vCopy[vCopy.size() / 2 - 1] + vCopy[vCopy.size() / 2]);
}

void calc_medians(const string &input_fname, const string &output_fname) {
    ifstream ifs(input_fname);
    ofstream ofs(output_fname);
    string   line;

    while (getline(ifs, line)) {
        istringstream issLine(line);
        string        name;
        issLine >> name;
        if (not name.size()) continue;
        if (name[0] == '#') continue;

        vector<double> numbers;
        double         number;
        while (issLine >> number) numbers.push_back(number);

        ofs << name << " " << fixed << setprecision(1) << median(numbers) << endl;
    }
}
