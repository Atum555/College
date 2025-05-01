#ifndef __show_file_h__
#define __show_file_h__

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

//! Show file name and the contents.
void show_file(const string &file) {
    ifstream in(file);
    cout << "==> " << file << " <==\n";
    for (string line; getline(in, line);) cout << line << '\n';
}
#endif // __show_file_h__
