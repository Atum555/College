#include <iostream>

int main() {
    int h1, m1, h2, m2;
    std::cin >> h1;
    std::cin >> m1;
    std::cin >> h2;
    std::cin >> m2;
    std::cout << abs(h2 * 60 + m2 - (h1 * 60 + m1)) << std::endl;
    return 0;
}
