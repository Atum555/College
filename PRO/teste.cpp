#include <cstring>
#include <iostream>
#include <string>

int main() {
    int a[] = { 1, 1, 1 };
    for (int &b : a) { b++; }
    std::cout << a[0] << a[1] << a[2] << std::endl;
    return 0;
}