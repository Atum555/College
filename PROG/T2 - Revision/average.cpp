#include <fstream>
#include <string>
#include <vector>

using namespace std;

double average(const string fname) {
    ifstream       ifs(fname);
    vector<double> numbers;
    double         number;

    while (true) {
        if (ifs.eof()) break;
        if (ifs >> number) numbers.push_back(number);
        else {
            ifs.clear();
            ifs.ignore(1);
        }
    }

    double result = 0;
    for (double number : numbers) result += number;
    return result / numbers.size();
}
