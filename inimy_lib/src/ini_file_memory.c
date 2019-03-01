/*
** EPITECH PROJECT, 2019
** inimy
** File description:
** ini_file_memory
*/

#include "my_ini.h"

ini_file_t *ini_file_create(char const *str)
{
    ini_file_t *ini = malloc(sizeof(ini_file_t));
    line_arr_t *arr = my_str_to_line_arr(str);
    
    ini->path = 0;
    ini->lines = double_vector_create();
    for (int i = 0; i < arr->nb_line; i++)
        double_vector_push_back(ini->lines, ini_line_create(arr->arr[i]));
    destroy_line_arr(arr);
    return (ini);
}

ini_file_t *ini_file_create_from_file(char const *path)
{
    char *content = my_file_readall(path);
    ini_file_t *ini;

    if (content == 0)
        return (0);
    ini = ini_file_create(content);
    ini->path = my_strdup(path);
    free(content);
    return (ini);
}

void ini_file_write(ini_file_t *entity)
{
    if (entity->path != 0)
        ini_file_write_from_path(entity, entity->path);
}

void ini_file_write_from_path(ini_file_t *entity, char const *path)
{
    fd_t fd = open(path, O_RDWR | O_CREAT | O_TRUNC);
    double_chained_t *current = entity->lines->start;

    if (fd == -1) {
        close(fd);
        return;
    }
    while (current) {
        ini_line_t *current_content = (ini_line_t*)current->content;
        char *to_write = ini_line_to_str(current_content);
        write(fd, to_write, my_strlen(to_write));
        if (current->next != 0)
            write(fd, "\n", 1);
        free(to_write);        
        current = current->next;
    }
    close(fd);
}

void ini_file_destroy(ini_file_t *entity)
{
    while (entity->lines->size != 0) {
        ini_line_destroy((ini_line_t*)entity->lines->start->content);
        double_vector_pop_top(entity->lines);
    }
    free(entity->path);
    free(entity->lines);
    free(entity);
}