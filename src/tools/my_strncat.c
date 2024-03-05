/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-lucas.leclerc
** File description:
** my_strcat
*/

#include "../../include/my_paint.h"

int my_strncat(char *dest, char *str, int size)
{
    int y = 0;

    if (dest == NULL || size < 0 || str == NULL)
        return 84;
    for (; dest[y] != '\0'; y++);
    for (int i = 0; i < size; i++) {
        dest[y + i] = str[i];
    }
    return 0;
}
