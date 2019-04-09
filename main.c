/*
** EPITECH PROJECT, 2019
** inimy
** File description:
** main
*/

#include "my_ini.h"
#include <stdio.h>

int main()
{
    ini_file_t *file = ini_file_create_from_file("map2.ini");

    char *buff = ini_line_get_value_from_col(ini_file_get_from_key(file, "X_TURRET"), 0);
    printf("%s\n", buff);
}