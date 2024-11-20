#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    // No files provided
    if (argc < 2) {
        printf("Files need to be provided.\n");
        exit(EXIT_FAILURE);
    }

    struct stat info;
    long long   totalNumberBytes  = 0;
    long long   totalNumberBlocks = 0;

    // For every file
    for (size_t i = 1; i < argc; i++) {
        int res = stat(argv[i], &info);

        // On Error
        if (res != 0) printf("Could not open %s\n", argv[i]);

        // If it is a normal file
        if ((info.st_mode & __S_IFMT) == __S_IFREG) {
            printf("File: %s\n", argv[i]);
            printf("Size: %d, Blocks: %d\n", (int)info.st_size, (int)info.st_blocks);
            printf("Owner: %d, Last Modified: %s\n", (int)info.st_uid, ctime(&info.st_mtime));
            totalNumberBytes  += (long long)info.st_size;
            totalNumberBlocks += (long long)info.st_blocks;
        }
    }

    if (argc != 2) {
        printf("Total Size: %lld\n", totalNumberBytes);
        printf("Total Blocks: %lld\n", totalNumberBlocks);
    }


    exit(EXIT_SUCCESS);
}
