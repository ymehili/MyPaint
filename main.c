/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** main
*/

#include "include/my_paint.h"

int helper(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        my_putstr("USAGE\n");
        my_putstr("    ./my_paint\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("    my_paint is a drawing software\n");
        return 0;
    }
    return 1;
}

int main(int ac, char **av)
{
    if (helper(ac, av) == 0)
        return 0;
    my_paint(ac, av);
    return 0;
}
