#ifndef __print_array_h__
#define __print_array_h__

#include <iostream>
using namespace std;

void print_array(const int a[], int n){
  cout << '[' << a[0];
  for (int i = 1; i < n; i++) {
    cout << ',' << a[i];
  }
  cout << "]\n";
}

#endif // __print_array_h__

