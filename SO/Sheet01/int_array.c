#include <stdio.h>

int main() {
    int i;
    int primes[] = { 2, 3, 5, 7, 11 };
    for (i = 0; i < sizeof(primes) / sizeof(int); i
        printf("%p: %d <--> %p: %d\n", &(primes[i]), primes[i], primes + i, *(primes + i));

    return 0;
}
