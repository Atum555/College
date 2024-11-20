#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

void printFile(int fd) {
    int  nbytesToRead;
    int  totalNBytes;
    char buffer[BUFFER_SIZE];

    // Go to the end and count the number of bytes in the file
    totalNBytes = lseek(fd, 0, SEEK_END) - 1;

    for (off_t i = totalNBytes - BUFFER_SIZE; 1; i -= BUFFER_SIZE) {
        if (i < 0) {
            nbytesToRead = BUFFER_SIZE + i;
            i            = 0;
        } else nbytesToRead = BUFFER_SIZE;

        lseek(fd, i, SEEK_SET);
        read(fd, buffer, nbytesToRead);
        for (int j = nbytesToRead - 1; j >= 0; j--) write(STDOUT_FILENO, buffer + j, 1);

        if (i <= 0) break;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc == 1) printf("This doesn't work with STDIN.");
    else
        for (size_t i = 1; i < argc; i++) {
            int fd = open(argv[i], O_RDONLY);
            if (fd == -1) printf("error: cannot open %s\n", argv[i]);
            else printFile(fd);
            close(fd);
        }

    exit(EXIT_SUCCESS);
}
