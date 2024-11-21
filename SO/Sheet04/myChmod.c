#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    // Insufficient arguments
    if (argc < 3) {
        printf("Usage: %s [permissions] [files...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get permissions
    int permissions       = atoi(argv[1]);
    int otherPermissions  = permissions % 10;
    permissions          /= 10;
    int groupPermissions  = permissions % 10;
    permissions          /= 10;
    int userPermissions   = permissions % 10;

    mode_t newPermissions = (mode_t)0;

    // Parse User Permissions
    switch (userPermissions) {
    case 0 : break;
    case 1 : newPermissions |= S_IXUSR; break;
    case 2 : newPermissions |= S_IWUSR; break;
    case 3 : newPermissions |= S_IWUSR | S_IXUSR; break;
    case 4 : newPermissions |= S_IRUSR; break;
    case 5 : newPermissions |= S_IRUSR | S_IXUSR; break;
    case 6 : newPermissions |= S_IRUSR | S_IWUSR; break;
    case 7 : newPermissions |= S_IRUSR | S_IWUSR | S_IXUSR; break;
    default: printf("Invalid user permissions: %d", userPermissions); exit(EXIT_FAILURE);
    }

    // Parse Group Permissions
    switch (groupPermissions) {
    case 0 : break;
    case 1 : newPermissions |= S_IXGRP; break;
    case 2 : newPermissions |= S_IWGRP; break;
    case 3 : newPermissions |= S_IWGRP | S_IXGRP; break;
    case 4 : newPermissions |= S_IRGRP; break;
    case 5 : newPermissions |= S_IRGRP | S_IXGRP; break;
    case 6 : newPermissions |= S_IRGRP | S_IWGRP; break;
    case 7 : newPermissions |= S_IRGRP | S_IWGRP | S_IXGRP; break;
    default: printf("Invalid group permissions: %d", groupPermissions); exit(EXIT_FAILURE);
    }

    // Parse Other Permissions
    switch (otherPermissions) {
    case 0 : break;
    case 1 : newPermissions |= S_IXOTH; break;
    case 2 : newPermissions |= S_IWOTH; break;
    case 3 : newPermissions |= S_IWOTH | S_IXOTH; break;
    case 4 : newPermissions |= S_IROTH; break;
    case 5 : newPermissions |= S_IROTH | S_IXOTH; break;
    case 6 : newPermissions |= S_IROTH | S_IWOTH; break;
    case 7 : newPermissions |= S_IROTH | S_IWOTH | S_IXOTH; break;
    default: printf("Invalid other permissions: %d", otherPermissions); exit(EXIT_FAILURE);
    }

    for (size_t i = 2; i < argc; i++)
        if (chmod(argv[i], newPermissions) == -1)
            fprintf(stderr, "%s: cannot chmod %s\n", argv[0], argv[i]);

    exit(EXIT_SUCCESS);
}
