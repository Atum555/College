#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Insufficient arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s dirname\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Change Working directory
    if (chdir(argv[1]) != 0) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

    // Open directory
    DIR *directory = opendir(".");
    if (directory == NULL) {
        switch (errno) {
        case ENOTDIR: fprintf(stderr, "%s: %s is not a directory.\n", argv[0], argv[1]); break;
        case ENOENT : fprintf(stderr, "%s: %s does not exist.\n", argv[0], argv[1]); break;
        default     : fprintf(stderr, "Cannot open directory: %s\n", argv[1]); break;
        }
        exit(EXIT_FAILURE);
    }

    // Read files
    struct dirent *dir_entry;
    struct stat    file_info;
    struct passwd *user_info;
    struct group  *group_info;
    struct tm     *mod_time_struct;
    char           mod_time_string[120];

    while ((dir_entry = readdir(directory)) != NULL) {
        if (stat(dir_entry->d_name, &file_info) != 0) {
            printf("Error on file %s:", dir_entry->d_name);
            perror(NULL);
        }

        // Permissions
        if (S_ISDIR(file_info.st_mode)) printf("d");  // Directory of File
        else printf("-");
        if (file_info.st_mode & S_IRUSR) printf("r"); // User Read
        else printf("-");
        if (file_info.st_mode & S_IWUSR) printf("w"); // User Write
        else printf("-");
        if (file_info.st_mode & S_IXUSR) printf("x"); // User Execute
        else printf("-");
        if (file_info.st_mode & S_IRGRP) printf("r"); // Group Read
        else printf("-");
        if (file_info.st_mode & S_IWGRP) printf("w"); // Group Write
        else printf("-");
        if (file_info.st_mode & S_IXGRP) printf("x"); // Group Execute
        else printf("-");
        if (file_info.st_mode & S_IROTH) printf("r"); // Other Read
        else printf("-");
        if (file_info.st_mode & S_IWOTH) printf("w"); // Other Write
        else printf("-");
        if (file_info.st_mode & S_IXOTH) printf("x"); // Other Execute
        else printf("-");

        // Links
        printf(" %ld ", file_info.st_nlink);

        // Owner
        user_info = getpwuid(file_info.st_uid);
        if (user_info == NULL) perror("\nError in getting user name");
        printf("%s ", user_info->pw_name);

        // Group
        group_info = getgrgid(file_info.st_gid);
        if (group_info == NULL) perror("\nError in getting group name");
        printf("%s ", group_info->gr_name);

        // Size
        printf("%ld ", file_info.st_size);

        // Last mod
        mod_time_struct = localtime(&file_info.st_mtime);
        strftime(mod_time_string, sizeof(mod_time_string), "%b %d %H:%M", mod_time_struct);
        printf("%s ", mod_time_string);

        // Name
        printf("%s\n", dir_entry->d_name);
    }

    // Close directory
    closedir(directory);
    exit(EXIT_SUCCESS);
}
