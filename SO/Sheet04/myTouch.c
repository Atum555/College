#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <utime.h>

int main(int argc, char *argv[]) {
    if (argc == 1) printf("No files given.\n");

    for (size_t i = 1; i < argc; i++) {
        if (access(argv[i], F_OK) == 0) {
            // File Exists
            utime(argv[i], NULL); // Update Access and Modified time

        } else {
            // File does not exist
            mode_t permissions = (mode_t)0;

            permissions |= S_IRUSR | S_IWUSR;     // User Permissions
            permissions |= S_IRGRP;               // Group Permissions
            permissions |= S_IROTH;               // Other Permissions

            int fd = creat(argv[i], permissions); // Create the File
            close(fd);                            // Close the file
        }
    }

    exit(EXIT_SUCCESS);
}
