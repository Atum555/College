#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void convertFile(char *txt, char *epub) {
    printf("[pid:%d] Converting %s...\n", getpid(), txt);
    fflush(stdout);

    int retValue = execlp("pandoc", "pandoc", "--quiet", txt, "-o", epub, NULL);
    if (retValue == -1) {
        printf("Failed to Convert \"%s\"", txt);
        perror(NULL);
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Insufficient arguments\n");
        exit(EXIT_FAILURE);
    }

    pid_t  children[argc];
    char **txt_files     = malloc((argc - 1) * sizeof(char *));
    char **epub_files    = malloc((argc + 2) * sizeof(char *));
    epub_files[0]        = "zip";
    epub_files[1]        = "ebooks.zip";
    epub_files[argc - 1] = NULL;

    // Parse arguments and create convert processes
    {
        char *txt_file;
        char *epub_file;
        for (int i = 1; i < argc; i++) {
            txt_file = argv[i];

            // Check if txt_file exists
            if (access(argv[i], F_OK) != 0) {
                printf("Error opening file: %s: ", argv[i]);
                perror(NULL);
                exit(EXIT_FAILURE);
            }

            int fileNameLength = strstr(txt_file, ".txt") - txt_file;
            epub_file          = malloc(fileNameLength + 6);

            strncpy(epub_file, txt_file, fileNameLength);
            strcpy(epub_file + fileNameLength, ".epub");

            txt_files[i - 1]  = txt_file;
            epub_files[i + 1] = epub_file;

            if ((children[i] = fork()) == 0) convertFile(txt_file, epub_file);
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

    // Zip all epubs
    printf("Zipping it all together...\n");
    int retValue = execvp("zip", epub_files);
    if (retValue == -1) {
        printf("Failed to Zip");
        perror(NULL);
        exit(EXIT_FAILURE);
    }


    exit(EXIT_SUCCESS);
}
