#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Invalid argument number.");
        exit(EXIT_FAILURE);
    }

    if (strstr(argv[2], argv[1]) != NULL) printf("String B contains string A!");
    else printf("String B does NOT contain string A!");

    exit(EXIT_SUCCESS);
}
