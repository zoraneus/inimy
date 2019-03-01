/*
** EPITECH PROJECT, 2019
** inimy
** File description:
** ini_file_write
*/

#include "my_ini.h"

void ini_file_write_from_path(ini_file_t *ini, char const *path)
{
    double_chained_t *current = ini->lines->start;
    ini_line_t *current_content = (ini_line_t*)current->content;
    char *to_write;

    while (current != 0) {
        current_content = current->content;
        to_write = ini_line_to_str(current_content);
        write(0, to_write, my_strlen(to_write));
        write(0, "\n", 1);
        free(to_write);
        current = current->next;
    }
}

void ini_file_write(ini_file_t *ini)
{
    ini_file_write_from_path(ini, ini->path);
}