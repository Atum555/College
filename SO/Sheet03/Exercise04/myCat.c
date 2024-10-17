#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024

void printFile(FILE *file) {
    if (file == NULL) {
        printf("Error: could not open.");
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) fputs(buffer, stdout);
}

int main(int argc, char *argv[]) {
    if (argc == 1) printFile(stdin);
    else if (argc == 2) {
        FILE *file = fopen(argv[1], "r");
        printFile(file);
        fclose(file);
    } else
        for (size_t i = 1; i < argc; i++) {
            printf("%s:\n", argv[i]);

            FILE *file = fopen(argv[i], "r");
            printFile(file);
            fclose(file);

            printf("\n");
        }

    exit(EXIT_SUCCESS);
}
