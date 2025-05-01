#ifndef __smatrix_h__
#define __smatrix_h__

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct sm_entry {
    size_t row;
    size_t col;
    int    value;
};

typedef vector<sm_entry> smatrix;

void sum(const smatrix &a, const smatrix &b, smatrix &r);

void print(const smatrix &sm) {
    cout << "[ ";
    for (sm_entry e : sm) { cout << '(' << e.row << ", " << e.col << ", " << e.value << ") "; }
    cout << "]\n";
}

#endif // __smatrix_h__
