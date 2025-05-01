#ifndef __complex_h__
#define __complex_h__

//! Complex number
struct complex {
    int real; // Real part
    int img;  // Imaginary part
};

#include <iostream>
using namespace std;

//! Print array of complex numbers.
void print(const complex z[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        if (z[i].real == 0 && z[i].img == 0) cout << 0;
        else {
            if (z[i].real != 0) cout << z[i].real;
            if (z[i].img > 0) cout << '+' << z[i].img << 'i';
            else if (z[i].img < 0) cout << z[i].img << 'i';
        }
        cout << ' ';
    }
    cout << "]\n";
}

#endif // __complex_h__
