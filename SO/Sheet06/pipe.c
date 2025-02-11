#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#define LINESIZE 256

int main(int argc, char *argv[]) {
    int   fd[2];
    pid_t pid;
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid > 0) { /* parent */
        char line[LINESIZE] = "Lorem ipsum dolor sit amet ...";
        close(fd[0]);
        write(fd[1], line, strlen(line));
        close(fd[1]);
        if (wait(NULL) == -1) {
            perror("wait");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    } else { /* child */
        char line[LINESIZE];
        close(fd[1]);
        int nbytes = read(fd[0], line, LINESIZE);
        write(STDOUT_FILENO, line, nbytes);
        close(fd[0]);
        exit(EXIT_SUCCESS);
    }
}
