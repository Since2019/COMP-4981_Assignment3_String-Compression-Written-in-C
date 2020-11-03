#include "file_handler.h"

int fh_file_exists(const char *filename)
{
    int fd = open(filename, O_WRONLY | O_RDONLY);

    if (fd < 0)
        return 0;

    close(fd);

    return 1;
}

int fh_set_outfile(const char *filename)
{
    int fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    dup2(fd, STDOUT_FILENO);
    return fd;
}

int fh_set_infile(const char *filename)
{
    if (fh_file_exists(filename) == 0)
    {
        fprintf(stderr, "[file handler] error: file does not exist\n");
        return 0;
    }

    int fd = open(filename, O_RDONLY);
    dup2(fd, STDIN_FILENO);
    close(fd);

    return 1;
}