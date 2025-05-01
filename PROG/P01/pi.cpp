#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    int    k, d;
    double r = 0;
    std::cin >> k >> d;

    for (int i = 0; i <= k; i++) r += pow((double)-1, (double)i) / (2 * i + 1);

    std::cout << std::fixed << std::setprecision(d) << 4 * r;

    return 0;
}
