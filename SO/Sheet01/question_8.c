#include <stdio.h>

int g(int (*h)(int), int y) { return h(y + 2); }

int f(int x) { return x * x; }

int main() {
    printf("value: %d\n", g(f, 2));
    return 0;
}