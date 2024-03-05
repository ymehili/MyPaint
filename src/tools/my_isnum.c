/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-lucas.leclerc
** File description:
** my_isnum
*/

#include "../../include/my_paint.h"

int my_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}
