/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-lucas.leclerc
** File description:
** my_strcat
*/

#include "../../include/my_paint.h"

char *my_strcat(char *dest, char *src)
{
    int nb = 0;
    int lenght = my_strlen(dest);
    int b;

    for (int a = 0; src[a] != '\0'; a++) {
        b = lenght + nb;
        dest[b] = src[a];
        nb = nb + 1;
    }
    dest[lenght + nb] = '\0';
    return (dest);
}

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
