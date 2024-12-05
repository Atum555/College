#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

void printFile(int fd) {
    int  nbytes;
    char buffer[BUFFER_SIZE];
    while ((nbytes = read(fd, buffer, BUFFER_SIZE)) > 0) write(STDOUT_FILENO, buffer, nbytes);
}

int main(int argc, char *argv[]) {
    if (argc == 1) printFile(STDIN_FILENO);
    else
        for (size_t i = 1; i < argc; i++) {
            int fd = open(argv[i], O_RDONLY);
            if (fd == -1) printf("error: cannot open %s\n", argv[i]);
            else printFile(fd);
            close(fd);
        }

    exit(EXIT_SUCCESS);
}
