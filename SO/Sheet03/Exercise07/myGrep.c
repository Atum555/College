#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myGetLine(char **const linePtr, size_t *const n, FILE *const stream) {
    if (stream == NULL) return -1;

    const size_t bufferSize = 1024;
    size_t       lineSize   = 0;
    size_t       len        = 0;

    char *line   = NULL;
    char *buffer = malloc(sizeof(char) * bufferSize);
    char *tempLine;

    while (fgets(buffer, bufferSize, stream) != NULL) {
        // Allocate new memory with Line + Buffer length
        tempLine = malloc(sizeof(char) * (lineSize + bufferSize - 1));
        // Last byte 0x0 is not copied so that string remains contiguous

        // Copy Line into new space
        memcpy(tempLine, line, lineSize);
        // Copy buffer into new space after line
        memcpy(tempLine + lineSize, buffer, bufferSize - 1);

        free(line);                 // Delete previous line
        line      = tempLine;       // Change reference to new memory
        lineSize += bufferSize - 1; // Update lineSize


        if ((len = strlen(buffer)) != bufferSize - 1
            || (len == bufferSize - 1 && buffer[bufferSize - 2] == '\n')) {
            // Buffer is not full which means line is done reading,
            // Or buffer is full but it's the end of the line;
            break;
        }
    }
    // EOF, no more to read
    free(buffer);
    *linePtr = line;
    *n       = lineSize;
    return len;
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        printf("Invalid number of arguments.");
        exit(EXIT_FAILURE);
    }

    const char *needle = argv[1];
    FILE       *file   = argc == 2 ? stdin : fopen(argv[2], "r");

    if (file == NULL) {
        printf("Can't open file.");
        exit(EXIT_FAILURE);
    }

    char  *line;
    char  *position;
    size_t len;
    size_t lineNumber = 0;

    while (myGetLine(&line, &len, file)) {
        lineNumber++;
        position = line;
        while ((position = strstr(position, needle))) {
            position++;
            printf("[%li:%li]\n", lineNumber, position - line);
        }
        free(line);
    }

    exit(EXIT_SUCCESS);
}
