/*
** EPITECH PROJECT, 2023
** Cpool
** File description:
** my_l_putnbr
*/

#include "../../include/my_paint.h"

static long pow_10(int nb)
{
    long x = 1;

    for (int i = 1; i < nb; i++) {
        x *= 10;
    }
    return x;
}

static int unite_counter(int nb)
{
    int nb_unite = 1;

    if (nb < 0)
        nb = nb * -1;
    while (nb > 9) {
        nb = nb / 10;
        nb_unite++;
    }
    return nb_unite;
}

char *my_putnbr_in_str(int nb_init)
{
    char *str;
    int nb_unite = unite_counter(nb_init);
    int nb_2 = nb_init;
    int i = 0;
    long pow;

    str = my_malloc(sizeof(char) * (nb_unite + 1));
    if (nb_init < 0) {
        str[0] = '-';
        i++;
        nb_init *= -1;
    }
    pow = pow_10(nb_unite);
    for (; nb_unite >= 1; i++) {
        nb_2 = ((nb_init % (pow * 10)) / pow);
        str[i] = nb_2 + '0';
        pow = pow / 10;
        nb_unite--;
    }
    return str;
}
