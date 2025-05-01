#include <iostream>

int main() {
    int n, r;
    std::cin >> n;

    while (n) {
        r *= 10;
        r += n % 10;
        n /= 10;
    }

    std::cout << r;
    return 0;
}
