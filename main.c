#define _GNU_SOURCE

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

    if (argc != 3)
    {
        printf("Usage: %s path1 path2\n", argv[0]);
        exit(0);
    }

    const char *path1 = argv[1];
    const char *path2 = argv[2];

    int ret = renameat2(AT_FDCWD, path1, AT_FDCWD, path2, RENAME_EXCHANGE);

    if (ret == 0)
    {
        exit(EXIT_SUCCESS);
    }

    if (errno == ENOENT)
    {
        fprintf(stderr, "File or directory does not exist.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        fprintf(stderr, "Error code: %d\n", errno);
        exit(EXIT_FAILURE);
    }
}
