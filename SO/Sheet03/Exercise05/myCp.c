#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Invalid number of arguments.");
        exit(EXIT_FAILURE);
    }

    FILE *fileA, *fileB;

    if ((fileA = fopen(argv[1], "r")) == NULL) {
        printf("Can't open \"%s\"", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((fileB = fopen(argv[2], "w")) == NULL) {
        printf("Can't open \"%s\"", argv[2]);
        exit(EXIT_FAILURE);
    }

    unsigned int  nRead;
    unsigned char buffer[BUFFER_SIZE];
    while ((nRead = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, fileA)) > 0)
        fwrite(buffer, sizeof(unsigned char), nRead, fileB);

    fclose(fileA);
    fclose(fileB);

    exit(EXIT_SUCCESS);
}
