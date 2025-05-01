#include <iostream>

bool isPrime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i < n; i++)
        if (n % i == 0) return false;

    return true;
}

bool isPernicious(int n) {
    int count = 0;
    while (n) {
        count  += n & 1;
        n     >>= 1;
    }
    return isPrime(count);
}

int main() {
    int a, b;
    std::cin >> a >> b;

    for (int i = a; i <= b; i++)
        if (isPrime(i) and isPernicious(i)) std::cout << i << " ";

    return 0;
}
