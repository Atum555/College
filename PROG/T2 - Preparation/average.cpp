#include "show_file.h"
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void average(const string &input_fname, const string &output_fname) {
    ifstream ifs(input_fname);
    ofstream ofs(output_fname);
    string   line;
    size_t   lineCount = 0;

    while (getline(ifs, line)) {
        lineCount++;

        double        number;
        size_t        count   = 0;
        double        average = 0;
        istringstream iss(line);

        while (iss >> number) {
            count++;
            average += number;
        }
        average /= count;
        ofs << fixed << setprecision(3) << average << endl;
    }
    ofs << "lines=" << lineCount << endl;
}
