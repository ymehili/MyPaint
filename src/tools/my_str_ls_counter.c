/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-lucas.leclerc
** File description:
** my_argv_counter
*/

#include "../../include/my_paint.h"

int my_str_ls_counter(char **argv)
{
    int nb_params = 0;

    if (argv == NULL)
        return 0;
    for (; argv[nb_params] != NULL; nb_params++);
    return nb_params;
}
