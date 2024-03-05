/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-lucas.leclerc
** File description:
** my_clamp
*/

#include "../../include/my_paint.h"

float my_clamp(float min, float max, float value)
{
    float result = value < max ? value : max;

    result = result < min ? min : result;
    return result;
}
