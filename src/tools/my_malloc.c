/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-lucas.leclerc
** File description:
** my_malloc
*/

#include "../../include/my_paint.h"

void *my_malloc(unsigned int size)
{
    void *ptr = malloc(size);

    memset(ptr, 0, size);
    return ptr;
}
