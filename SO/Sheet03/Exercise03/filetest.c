#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 13

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Invalid argument number.");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("error: could not open \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int  nchars;
    char buffer[BUFFER_SIZE];

    while ((nchars = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0)
        fwrite(buffer, sizeof(char), nchars, stdout);

    fclose(file);
    exit(EXIT_SUCCESS);
}
