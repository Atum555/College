#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void compileFile(char *file) {
    printf("[pid:%d] Compiling %s...\n", getpid(), file);
    fflush(stdout);

    int retValue = execlp("gcc", "gcc", "-Wall", "-c", file, NULL);
    if (retValue == -1) {
        printf("Failed to Compile \"%s\"", file);
        perror(NULL);
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Insufficient arguments\n");
        exit(EXIT_FAILURE);
    }

    char *output_file = NULL;
    pid_t children[argc];

    // Parse arguments and setup Other Processes
    {
        int child_i = 0;
        for (int i = 1; i < argc; i++) {
            // Get output Files
            if (strcmp(argv[i], "-o") == 0) output_file = argv[++i];

            // Get input files and send it to children
            else if (access(argv[i], F_OK) == 0)
                if ((children[child_i++] = fork()) == 0) compileFile(argv[i]);
        }
        children[child_i] = 0;

        if (output_file == NULL) {
            printf("No output file was given, aborting...\n");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for Children
    {
        int   failed = 0;
        pid_t pid;
        int   i = 0;
        while ((pid = children[i++]) != 0) {
            int status;
            waitpid(pid, &status, 0);
            if (WIFEXITED(status))
                if (WEXITSTATUS(status) != EXIT_SUCCESS) {
                    failed = 1;
                    printf("[pid:%d] Failed, aborting...\n", pid);
                }
        }
        if (failed) exit(EXIT_FAILURE);
    }

    // Compile final executable
    {
        char *gccStr = "gcc";
        char *oStr   = "-o";
        char *args[argc];

        args[0] = gccStr;
        args[1] = oStr;
        args[2] = output_file;

        int   arg_i = 3;
        char *str;
        for (int i = 1; i < argc; i++) {
            str = argv[i];
            if (strcmp(str, oStr) == 0) continue;
            if (strcmp(str, output_file) == 0) continue;
            str[strlen(str) - 1] = 'o';
            args[arg_i++]        = str;
        }
        args[arg_i] = NULL;

        printf("Compiling final executable %s...\n", output_file);
        execvp("gcc", args);
    }

    exit(EXIT_SUCCESS);
}
