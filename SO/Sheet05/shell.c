#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// History File
char *history_file = ".shell_history";

// Changes the Current Working Directory
void cd(char *dir_name) {
    if (chdir(dir_name) == -1) perror("cd");
}

void createHistoryFile() {
    // Creat File if it doesn't exist
    int fd;
    if ((fd = open(history_file, O_CREAT | O_WRONLY, (mode_t)0644)) == -1)
        perror("Shell History File Creator");
    else close(fd);
}

// Prints out the Command History
void history(char *n) {
    createHistoryFile();

    // Fork
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // Child
    if (pid == 0)
        if (execlp("tail", "tail", history_file, (n == NULL ? NULL : "-n"), n, NULL) == -1) {
            perror(NULL);
            exit(EXIT_FAILURE);
        }

    // Wait for tail
    if (waitpid(pid, NULL, 0) == -1) perror("waitpid");
}

void storeHistory(char *command) {
    createHistoryFile();

    // Write to File
    int fd = open(history_file, O_WRONLY | O_APPEND);
    if (fd == -1) perror("Write to History");
    write(fd, command, strlen(command));
    write(fd, "\n", 1);
    close(fd);
}

int main(int argc, char *argv[]) {
    char  buffer[1024];
    char *arguments[1024];
    char *arg;

    for (;;) {
        printf("\n$ ");

        // Read input
        char *command = fgets(buffer, sizeof(buffer), stdin);

        // Remove last new line
        if (command != NULL) command[strlen(buffer) - 1] = '\0';

        // Exit
        if (command == NULL || strcmp(command, "exit") == 0) break;

        // Continue if empty command
        if (strcmp(command, "") == 0) continue;

        // Store command in history
        storeHistory(command);

        // Extract the arguments from the input
        for (int i = 0; i < sizeof(arguments) / sizeof(char *); i++)
            if ((arg = strsep(&command, " ")) == NULL) {
                arguments[i] = NULL; // Arguments must be NULL terminated
                break;
            } else if (strlen(arg)) arguments[i] = arg;

        // Change Working Directory
        if (strcmp(arguments[0], "cd") == 0) {
            cd(arguments[1]);
            continue;
        }

        // Print history
        if (strcmp(arguments[0], "history") == 0) {
            history(arguments[1]);
            continue;
        }

        // Execute Program
        {
            // Fork
            pid_t pid = fork();
            if (pid == -1) {
                perror("fork");
                exit(EXIT_FAILURE);
            }

            // Child
            if (pid == 0)
                if (execvp(arguments[0], arguments) == -1) {
                    perror(NULL);
                    exit(EXIT_FAILURE);
                }

            // Wait for command
            if (waitpid(pid, NULL, 0) == -1) perror("waitpid");
        }
    }

    exit(EXIT_SUCCESS);
}
