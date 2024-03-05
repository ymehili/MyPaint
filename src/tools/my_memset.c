/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-lucas.leclerc
** File description:
** my_memset
*/

#include "../../include/my_paint.h"

void *my_memset(void *ptr, char c, long nb_bytes)
{
    char *current = ptr;

    if (ptr == NULL)
        return NULL;
    for (int i = 0; current && i < nb_bytes; i++) {
        *current = c;
        current++;
    }
    return ptr;
}
