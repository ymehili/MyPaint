/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** dropdown_menu
*/

#include "../include/my_paint.h"

int init_dropdown_btns(va_list ls, int nbbutton,
    sfVector2f pos, dropdown_menu_t *menu)
{
    char *txt;
    button_t *tmp = NULL;
    sfVector2f size = (sfVector2f){150, MENUBAR_HEIGHT};
    int height = 0;

    for (int i = 0; i < nbbutton; i++) {
        txt = my_strdup(va_arg(ls, char *));
        tmp = initbutton(pos, size, txt);
        sfRectangleShape_setFillColor(tmp->button,
            sfColor_fromRGB(135, 135, 135));
        if (menu->buttons == NULL)
            menu->buttons = tmp;
        else {
            tmp->next = menu->buttons;
            menu->buttons->prev = tmp;
            menu->buttons = tmp;
        }
        pos.y += MENUBAR_HEIGHT;
        height += MENUBAR_HEIGHT;
    }
    return height;
}

int display_dropdown(global_t *global, void *dropdown_menu)
{
    dropdown_menu_t *dropdown = (dropdown_menu_t *)dropdown_menu;
    button_t *btn = dropdown->buttons;
    sfRenderWindow *window = global->window;

    sfRenderWindow_drawRectangleShape(window, dropdown->shape, NULL);
    for (; btn != NULL; btn = btn->next) {
        sfRenderWindow_drawRectangleShape(window, btn->button, NULL);
        sfRenderWindow_drawText(window, btn->text, NULL);
    }
    return 0;
}

dropdown_menu_t *init_dropdown(sfVector2f pos, int nbbutton, global_t *global, ...)
{
    dropdown_menu_t *menu = malloc(sizeof(dropdown_menu_t));
    va_list ls;
    sfVector2f size = (sfVector2f){150, MENUBAR_HEIGHT};

    va_start(ls, global);
    size.y = init_dropdown_btns(ls, nbbutton, pos, menu);
    menu->shape = sfRectangleShape_create();
    sfRectangleShape_setFillColor(menu->shape, sfColor_fromRGB(200, 200, 200));
    sfRectangleShape_setSize(menu->shape, size);
    sfRectangleShape_setPosition(menu->shape, pos);
    return menu;
}