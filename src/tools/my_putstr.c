/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-lucas.leclerc
** File description:
** my_putstr
*/

#include "../../include/my_paint.h"

void my_putstr(char const *str)
{
    int len = my_strlen(str);

    write(1, str, len);
}
