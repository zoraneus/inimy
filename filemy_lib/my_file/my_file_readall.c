/*
** EPITECH PROJECT, 2018
** my_file_readall
** File description:
** read an entire file and put it in an str
*/

#include "my_file.h"

char *my_file_readall(char const *filepath)
{
    int size = my_file_size(filepath);
    char *buffer = malloc(sizeof(char) * (size + 1));
    fd_t fd = open(filepath, O_RDONLY);

    if (fd == -1 || read(fd, buffer, size) != size) {
        free(buffer);
        return (0);
    }
    buffer[size] = '\0';
    return (buffer);
}