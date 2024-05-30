#ifndef __print_vector_h__
#define __print_vector_h__

#include <vector>
#include <iostream>
using namespace std;

//! Print vector with elements of type T.
template <typename T>
void print(const vector<T>& v) {
  cout << "[ ";
  for (size_t i = 0; i < v.size(); i++) {
    cout << v[i] << ' ';
  }
  cout << "]\n";
}

#endif // __print_vector_h__
