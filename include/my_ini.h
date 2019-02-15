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

//------------------ini line memory gestion-----------------------//
ini_line_t *ini_line_create(char const *str);
void ini_line_destroy(ini_line_t *entity);
char *ini_line_to_str(ini_line_t *entity);

//  ---------------ini_line_operation-----------------------------//
int ini_line_getcol_nb(ini_line_t *entity);
//   return null if err
char *ini_line_getstr_from_col(ini_line_t *entity, int col);
double_chained_t *ini_line_getchain_from_col(ini_line_t *entity, int col);
//  --------------------
void ini_line_remove_value(ini_line_t *entity, int col);

//  ---------------ini line add system ----------------------------//
void ini_line_add_value_from_col(ini_line_t *entity, int col, char const *str);
void ini_line_push_back_value(ini_line_t *entity, char const *str);

#endif /* !MY_INI_H_ */