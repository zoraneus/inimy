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

    printf("%s\n", ini_file_to_str(file));
}