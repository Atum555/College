#ifndef __show_file_h__
#define __show_file_h__

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//! Show file name and the contents.
void show_file(const string &file) {
    ifstream in(file);
    cout << "==> " << file << " <==\n";
    for (string line; getline(in, line);) cout << line << '\n';
}
#endif // __show_file_h__
