/*
** EPITECH PROJECT, 2019
** inimy
** File description:
** ini_file_op
*/

#include "my_ini.h"

ini_line_t *ini_file_get_line_from_key(ini_file_t *entity, char const *key)
{
    double_chained_t *current = entity->lines->start;
    ini_line_t *current_content;

    while (current != 0) {
        current_content = current->content;
        if (my_strcmp(key, current_content->key))
            return (current->content);
        current = current->next;
    }
    return (0);
}

void ini_file_push_with_line(ini_file_t *entity, ini_line_t *to_push)
{
    if (ini_file_get_line_from_key(entity, to_push->key) != 0)
        return;
    double_vector_push_back(entity->lines, to_push);
}

void ini_file_push_with_key(ini_file_t *entity, char const *key)
{
    ini_line_t *line;

    if (ini_file_get_line_from_key(entity, key) != 0)
        return;
    line = ini_line_create(key);
    double_vector_push_back(entity->lines, line);
}

void ini_file_pop_line(ini_file_t *entity, char const *key)
{
    double_chained_t *current = entity->lines->start;
    ini_line_t *current_content = current->content;

    while (current != 0 && my_strcmp(current_content->key, key) == 0) {
        current = current->next;
        current_content = current->content;
    }
    if (current != 0) {
        ini_line_destroy(current_content);
        double_vector_pop_me(entity->lines, current);
    }
}