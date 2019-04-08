/*
** EPITECH PROJECT, 2019
** inimy
** File description:
** my_ini
*/

#ifndef MY_INI_H_
#define MY_INI_H_

#include "my_str.h"
#include "my_file.h"
#include "my_vector.h"

struct ini_line {
    char *key;
    double_vector_t *lines;
};
typedef struct ini_line ini_line_t;

ini_line_t *ini_line_create(char *key);
ini_line_t *ini_line_create_from_str(char *str);
void ini_line_destroy(ini_line_t *line);

void ini_line_to_str(ini_line_t *line);
#endif /* !MY_INI_H_ */
