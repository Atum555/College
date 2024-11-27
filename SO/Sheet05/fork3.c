#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int   value = 0;
    pid_t pid   = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        /* child process */
        value = 1;
        printf("CHILD: value = %d, addr = %p\n", value, &value);
        exit(EXIT_SUCCESS);
    } else {
        /* parent process */
        int retv = waitpid(pid, NULL, 0);
        if (retv == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }
        printf("PARENT: value = %d, addr = %p\n", value, &value);
        exit(EXIT_SUCCESS);
    }
}
