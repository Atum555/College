#include <algorithm>
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

void slowPrint(const char *str) {
    char letters[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int  i         = 0;
    while (char l = str[i]) {
        if (!(('a' <= l and l <= 'z') or ('A' <= l and l <= 'Z') or ('0' <= l and l <= '9'))) {
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

// Convert int to str
void toStr(const unsigned int n, char str[], size_t &pos) {
    // Count number of digits
    size_t       count = 0;
    unsigned int nCopy = n;
    while (nCopy) {
        ++count;
        nCopy /= 10;
    }

    // Create int array
    int *digits = new int[count];

    // Fill array
    nCopy    = n;
    size_t i = count;
    while (nCopy) {
        --i;
        digits[i]  = nCopy % 10;
        nCopy     /= 10;
    }

    // Move digits to string
    for (size_t i = 0; i < count; i++) {
        str[pos] = '0' + digits[i];
        ++pos;
    }

    delete[] digits;
}

int main() {
    char   atum[] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
    size_t pos    = 3;
    toStr(2345, atum, pos);
    cout << pos << endl;
    ;
    return 0;
}