#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

double average(const string fname) {
    ifstream       inf(fname);
    vector<double> v;
    double         x;
    while (true) {
        if (inf.eof()) break;
        if (!(inf >> x)) {
            inf.clear();
            inf.ignore(1);
            continue;
        }
        v.push_back(x);
    }
    x = 0;
    for (double y : v) x += y;
    return x / v.size();
}
