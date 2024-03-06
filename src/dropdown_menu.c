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
        if (menu->buttons != NULL) {
            tmp->next = menu->buttons;
            menu->buttons->prev = tmp;
        }
        menu->buttons = tmp;
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

int check_dropdown_hover(global_t *global, void *dropdown_menu)
{
    dropdown_menu_t *dropdown = (dropdown_menu_t *)dropdown_menu;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(global->window);
    sfVector2f dd_pos = sfRectangleShape_getPosition(dropdown->shape);
    sfVector2f dd_size = sfRectangleShape_getSize(dropdown->shape);

    if (dropdown_menu == NULL)
        return 0;
    if (dropdown->displayed == 0)
        return 0;
    if (mouse.x > dd_pos.x && mouse.x < dd_pos.x + dd_size.x &&
        mouse.y > dd_pos.y && mouse.y < dd_pos.y + dd_size.y) {
        display_dropdown(global, dropdown);
        return 1;
    }
    dropdown->displayed -= 1;
    return 0;
}

dropdown_menu_t *init_dropdown(sfVector2f pos,
    int nbbutton, global_t *global, va_list ls)
{
    dropdown_menu_t *menu = malloc(sizeof(dropdown_menu_t));
    sfVector2f size = (sfVector2f){150, MENUBAR_HEIGHT};

    size.y = init_dropdown_btns(ls, nbbutton, pos, menu);
    menu->shape = sfRectangleShape_create();
    sfRectangleShape_setFillColor(menu->shape, sfColor_fromRGB(200, 200, 200));
    sfRectangleShape_setSize(menu->shape, size);
    sfRectangleShape_setPosition(menu->shape, pos);
    return menu;
}
