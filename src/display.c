/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** display
*/

#include "../include/my_paint.h"

int display(global_t *global)
{
    display_menubar(global->window, global->menubar);
    return 0;
}
