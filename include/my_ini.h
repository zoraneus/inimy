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
#include <stdio.h>

struct ini_line {
    char *key;
    double_vector_t *values;
};
typedef struct ini_line ini_line_t;

struct ini_file {
    char *path;
    double_vector_t *lines;
};
typedef struct ini_file ini_file_t;

// ini_line.c
ini_line_t *ini_line_create(char *key);
ini_line_t *ini_line_create_from_str(char *str);
void ini_line_destroy(ini_line_t *line);

// ini_line_conversion.c
char *ini_line_to_str(ini_line_t *line);

// ini_file.c
ini_file_t *ini_file_create(void);
ini_file_t *ini_file_create_from_str(char *str);
ini_file_t *ini_file_create_from_file(char *path);
void ini_file_destroy(ini_file_t *file);

<<<<<<< HEAD
// ini_file_write.c
char *ini_file_to_str(ini_file_t *file);
void ini_file_write(ini_file_t *file);
void ini_file_write_path(ini_file_t *file, char *path);

=======
//
>>>>>>> redump
#endif /* !MY_INI_H_ */
