/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-lucas.leclerc
** File description:
** my_strlen
*/

#include "../../include/my_paint.h"

int my_strlen(char const *str)
{
    int len = 0;

    for (; str[len] != '\0'; len++);
    return len;
}
