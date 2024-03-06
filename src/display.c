/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** display
*/

#include "../include/my_paint.h"

int display(global_t *global)
{
    button_t *tmp = global->menubar->buttons;

    display_menubar(global->window, global->menubar);
    for (; tmp != NULL; tmp = tmp->next) {
        check_click_btn(global, tmp);
        check_hover_btn(global, tmp);
    }
    return 0;
}
