/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** my_strdup
*/

#include "../../include/my_paint.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;

    if (src == NULL)
        return NULL;
    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (; src[i] != '\0'; i++) {
        str[i] = src[i];
    }
    str[i] = 0;
    return str;
}
