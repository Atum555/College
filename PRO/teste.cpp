#include <iostream>
#include <string>

struct atum {
    int   size;
    short height;
    short weight;
};

double sumWeights(const atum &a, const atum &b) { return a.weight + b.weight; }

int main() {
    atum myTuna   = { 12, 30, 5 };
    atum yourTuna = { 6, 20, 4 };
    std::cout << sumWeights(myTuna, yourTuna) << std::endl
              << sizeof(atum) << std::endl;
    return 0;
}