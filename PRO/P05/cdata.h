#ifndef __cdata_h__
#define __cdata_h__

struct cdata {
  int count;
  int value;
};

int* expand_cdata(const cdata a[], int n);

#include <iostream>
using namespace std;

void print_array(const int a[], int n) {
  cout << '[' << a[0];
  for (int i = 1; i < n; i++) {
    cout << ',' << a[i];
  }
  cout << "]\n";
}

#endif // __cdata_h__