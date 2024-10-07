#include <stdio.h>

int *get_int() {
    int i = 2;
    return &i;
}

int main() {
    int *p = get_int();
    printf("integer = %d\n", *p);
    return 0;
}
