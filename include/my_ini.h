/*
** EPITECH PROJECT, 2018
** filemy
** File description:
** my_ini
*/

#ifndef MY_INI_H_
#define MY_INI_H_

#include "my_file.h"
#include "my_str.h"
#include "my_vector.h"

//double vector_value contain char*
struct ini_line {
    char *key;
    double_vector_t *value;
};
typedef struct ini_line ini_line_t;

//double vector_line contain ini_line*
struct ini_file {
    double_vector_t *lines;
    int size;
};
typedef struct ini_file ini_file_t;

//ini line gestion
ini_line_t *ini_line_create(char const *str);
void ini_line_destroy(ini_line_t *entity);
int ini_line_getcol_nb(ini_line_t *entity);
char *ini_line_get_from_col(ini_line_t *entity, int col); //return NULL if err


#endif /* !MY_INI_H_ */