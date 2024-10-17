#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { DEFAULT = 0b111, BYTES = 0b001, WORDS = 0b010, LINES = 0b100, NONE = 0b0 } STATE;

unsigned totalBytes = 0;
unsigned totalWords = 0;
unsigned totalLines = 0;

void count(const char *fileName, STATE state) {
    if (state == NONE) exit(EXIT_FAILURE);

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Invalid file name: \"%s\"", fileName);
        return;
    }

    unsigned bytes = 0;
    unsigned words = 0;
    unsigned lines = 0;

    int c;
    int last = 0;
    while ((c = fgetc(file)) != EOF) {
        switch (c) {
        case '\n': lines++;
        case '\t':
        case ' ':
            if (last) words++;
            last = 0;
            bytes++;
            break;
        default: bytes++; last = 1;
        }
    }
    if (last) words++;


    if (state & LINES) printf("%d\t", lines);
    if (state & WORDS) printf("%d\t", words);
    if (state & BYTES) printf("%d\t", bytes);
    printf("%s\n", fileName);

    totalBytes += bytes;
    totalWords += words;
    totalLines += lines;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("No input files.");
        exit(EXIT_SUCCESS);
    }

    const char **fileNames = malloc(sizeof(char *) * argc);

    STATE  state     = NONE;
    size_t fileCount = 0;

    for (size_t i = 1; i < argc; i++) {
        const char *arg = argv[i];

        if (arg[0] == '-') {
            for (size_t i = 1; i < strlen(arg); i++) {
                switch (arg[i]) {
                case 'c': state |= BYTES; break;
                case 'w': state |= WORDS; break;
                case 'l': state |= LINES; break;

                default: printf("Invalid argument: \"%s\"", arg); exit(EXIT_FAILURE);
                }
            }
        }

        else {
            fileNames[fileCount] = arg;
            fileCount++;
        }
    }

    if (state == NONE) state = DEFAULT;

    for (size_t i = 0; i < fileCount; i++) count(fileNames[i], state);

    if (fileCount > 1) printf("%d\t%d\t%d\tTotal\n", totalLines, totalWords, totalBytes);

    free(fileNames);
}
