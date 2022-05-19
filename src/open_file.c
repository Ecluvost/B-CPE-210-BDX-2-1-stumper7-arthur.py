/*
** EPITECH PROJECT, 2022
** open_file
** File description:
** stumper07
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

char *open_file(char const *filepath)
{
    struct stat info;
    int fd = open(filepath, O_RDONLY);
    int size = 0;
    char *buf = NULL;

    if (fd == -1)
        return NULL;
    stat(filepath, &info);
    size = info.st_size;
    if (size == 0)
        return NULL;
    buf = malloc(sizeof(char) * (size + 1));
    read(fd, buf, size);
    if (!buf)
        return NULL;
    buf[size] = '\0';
    return buf;
}
