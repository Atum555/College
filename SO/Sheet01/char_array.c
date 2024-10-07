#include <stdio.h>

int main() {
    int  i;
    char msg[] = "Hello World";
    for (i = 0; i < sizeof(msg); i++) 
        printf("%p: %c <--> %p: %c\n", &(msg[i]), msg[i], msg + i, *(msg + i));

    return 0;
}