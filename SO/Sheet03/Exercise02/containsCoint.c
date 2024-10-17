#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Invalid argument number.");
        exit(EXIT_FAILURE);
    }

    unsigned count    = 0;
    char    *position = strstr(argv[2], argv[1]);
    while (position != NULL) {
        count++;
        position = strstr(position + 1, argv[1]);
    }

    printf("String B appears in string A %d times.", count);

    exit(EXIT_SUCCESS);
}
