#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Invalid argument number.");
        exit(EXIT_FAILURE);
    }

    size_t size = strlen(argv[1]);
    char  *p1   = (char *)malloc(size + 1);

    for (size_t i = 0; i <= size; i++) {
        char c = argv[1][i];
        c      = tolower(c);
        p1[i]  = c;
    }

    printf("%s\n", p1);

    exit(EXIT_SUCCESS);
}
