#include <iostream>

int main() {
    int letters      = 0;
    int numbers      = 0;
    int notLetNotNum = 0;

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        std::cin >> c;

        if ('0' <= c and c <= '9') ++numbers;
        else if (('a' <= c and c <= 'z') or ('A' <= c and c <= 'Z')) ++letters;
        else ++notLetNotNum;
    }
    std::cout << letters << " " << numbers << " " << notLetNotNum;

    return 0;
}
