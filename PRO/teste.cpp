#include <algorithm>
#include <iostream>
#include <string>
#include <unistd.h>

void slowPrint(const char *str) {
    char letters[]
        = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;
    while (char l = str[i]) {
        if (!(('a' <= l and l <= 'z') or ('A' <= l and l <= 'Z')
              or ('0' <= l and l <= '9'))) {
            ++i;
            continue;
        }
        int j = 0;
        while (letters[j] != l) {
            usleep(5000);
            std::cout << "\r";
            for (int k = 0; k < i; ++k) std::cout << str[k];
            std::cout << letters[j];
            std::flush(std::cout);
            ++j;
        }
        usleep(5000);
        std::cout << "\r";
        for (int k = 0; k <= i; ++k) std::cout << str[k];
        std::flush(std::cout);
        ++i;
    }
    std::cout << "\r";
    std::cout << str << std::endl;
}

int main() {
    ;
    ;
    return 0;
}