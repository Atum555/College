
#ifndef __print_h__
#define __print_h__

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//! Show file contents with line number information and 
//! the '|' character indicating the begining and end of lines.
void print(const string& file) {
  ifstream in(file);
  size_t line_nr = 1;
  for (string line; getline(in, line);) {
     cout << line_nr << "|" << line << "|\n";
     line_nr++;
  }
}
#endif // __print_h__