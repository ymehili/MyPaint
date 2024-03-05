/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-lucas.leclerc
** File description:
** my_strmp
*/

#include "../../include/my_paint.h"

int my_strcmp(char const *s1, char const *s2)
{
    int a = 0;
    int b = 0;

    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        a += s1[i];
        b += s2[i];
        if (a != b)
            return a - b;
    }
    if (my_strlen(s1) > my_strlen(s2))
        return 1;
    if (my_strlen(s2) > my_strlen(s1))
        return -1;
    return 0;
}
