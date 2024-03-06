/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** menubar
*/

#include "../include/my_paint.h"

static void listbuttons(global_t *global, menubar_t *menubar, va_list buttons,
    int nbbuttons)
{
    char *text;
    sfVector2f pos = {0, 0};
    button_t *tmp = NULL;
    sfVector2f size = (sfVector2f){0, MENUBAR_HEIGHT};
    dropdown_menu_t *dd_menu;

    for (int i = 0; i < nbbuttons; i++) {
        text = my_strdup(va_arg(buttons, char *));
        size.x = my_strlen(text) * 16 + MENUBAR_BTN_MARGIN;
        tmp = initbutton(pos, size, text);
        sfRectangleShape_setFillColor(tmp->button,
            sfColor_fromRGB(135, 135, 135));
        if (menubar->buttons == NULL)
            menubar->buttons = tmp;
        else {
            tmp->next = menubar->buttons;
            menubar->buttons->prev = tmp;
            menubar->buttons = tmp;
        }
        dd_menu = init_dropdown((sfVector2f){pos.x, pos.y + MENUBAR_HEIGHT},
            4, global, "open", "save", "save in", "close");
        tmp->hover_func = &display_dropdown;
        tmp->hover_param = dd_menu;
        pos.x += my_strlen(text) * 16 + MENUBAR_BTN_MARGIN + 2;
    }
}

void display_menubar(sfRenderWindow *window, menubar_t *menubar)
{
    button_t *tmp = menubar->buttons;

    sfRenderWindow_drawRectangleShape(window, menubar->bar, NULL);
    for (; tmp != NULL; tmp = tmp->next) {
        sfRenderWindow_drawRectangleShape(window, tmp->button, NULL);
        sfRenderWindow_drawText(window, tmp->text, NULL);
    }
}

menubar_t *initmenubar(int nbbuttons, global_t *global, ...)
{
    menubar_t *menubar = my_malloc(sizeof(menubar_t));
    va_list buttons;
    sfVector2u windowSize = sfRenderWindow_getSize(global->window);

    va_start(buttons, global);
    menubar->bar = sfRectangleShape_create();
    sfRectangleShape_setSize(menubar->bar,
        (sfVector2f){windowSize.x, MENUBAR_HEIGHT});
    sfRectangleShape_setFillColor(menubar->bar,
        sfColor_fromRGB(210, 210, 210));
    listbuttons(global, menubar, buttons, nbbuttons);
    return (menubar);
}
