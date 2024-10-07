#include <stdio.h>

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1      = *p2;
    *p2      = temp;
}

int main() {
    int n1 = 1;
    int n2 = 2;
    swap(&n1, &n2);
    printf("n1: %d n2: %d\n", n1, n2);
    return 0;
}
