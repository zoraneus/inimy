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

struct ini_line {
    char *key;
    char **value;
};
typedef struct ini_line ini_line_t;

struct ini_file {
    ini_line_t *lines;
    int size;
};
typedef struct ini_file ini_file_t;

//ini line gestion

#endif /* !MY_INI_H_ */
