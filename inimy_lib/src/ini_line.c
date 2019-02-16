/*
** EPITECH PROJECT, 2019
** inimy
** File description:
** ini_line
*/

#include "my_ini.h"

static double_vector_t *get_values_from_line(char const *line)
{
    double_vector_t *vect = double_vector_create();
    int i = 0;
    int size = 0;

    while (line[i] != '[')
        i++;
    i++;
    while (line[i-1] != ']') {
        while (line[i] != ']' && line[i] != ';') {
            i++;
            size++;
        }
        double_vector_push_back(vect, my_strndup(line + i - size, size));
        size = 0;
        i++;
    }
    return (vect);
}

ini_line_t *ini_line_create(char const *str)
{
    ini_line_t *new = malloc(sizeof(ini_line_t));
    int i = 0;

    while (str[i] != '[')
        i++;
    new->key = my_strndup(str, i);
    new->value = get_values_from_line(str);
    return (new);
}

void ini_line_destroy(ini_line_t *entity)
{
    while (entity->value->size != 0) {
        free(entity->value->start->content);
        double_vector_pop_top(entity->value);
    }
    free(entity->key);
    free(entity->value);
    free(entity);
}

static int ini_line_str_len(ini_line_t *entity)
{
    int size = my_strlen(entity->key) + 1 + entity->value->size;
    double_chained_t *current = entity->value->start;

    while (current != 0) {
        size += my_strlen((char*)current->content);
        current = current->next;
    }
    return (size);
}

char *ini_line_to_str(ini_line_t *entity)
{
    int size = ini_line_str_len(entity);
    double_chained_t *current = entity->value->start;
    int size_write = my_strlen(entity->key) + 1;
    char *line;

    line = malloc(sizeof(char) * (size + 1));
    my_strcpy(line, entity->key);
    line[size_write - 1] = '[';
    while (current != 0) {
        my_strcpy(line + size_write, (char*)current->content);
        size_write += my_strlen((char*)current->content) + 1;
        line[size_write - 1] = ';'; 
        current = current->next;
    }
    line[size_write - 1] = ']';
    line[size_write] = '\0';
    return (line);
}