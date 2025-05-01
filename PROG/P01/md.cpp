#include <iostream>

int md(int ax, int ay, int bx, int by) { return abs(ax - bx) + abs(ay - by); }

int main() {
    int i, ax, ay, bx, by, d = 0;
    std::cout << i;
    std::cin >> i;
    std::cin >> ax >> ay;
    --i;
    while (i) {
        --i;
        std::cin >> bx >> by;
        d  += md(ax, ay, bx, by);
        ax  = bx;
        ay  = by;
    }

    std::cout << d << std::endl;

    return 0;
}
