#ifndef __print_string_h__
#define __print_string_h__

#include <string>
#include <vector>
#include <iostream>
using namespace std;

//! Print vector of strings.
void print(const vector<string>& v) {
  cout << "[ ";
  for (size_t i = 0; i < v.size(); i++) {
    cout << '\"' << v[i] << "\" ";
  }
  cout << "]\n";
}

#endif // __print_string_h__

