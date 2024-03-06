/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** menubar
*/

#include "../include/my_paint.h"

dropdown_menu_t *add_dd_menu(global_t *global, char *text, int nbbuttons, ...)
{
    button_t *tmp = global->menubar->buttons;
    va_list buttons;
    sfVector2f pos;

    va_start(buttons, nbbuttons);
    for (; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(tmp->string, text) == 0) {
            pos = sfRectangleShape_getPosition(tmp->button);
            pos.y += MENUBAR_HEIGHT;
            tmp->hover_param = init_dropdown(pos, nbbuttons, global, buttons);
            return tmp->hover_param;
        }
    }
    return 0;
}

static void listbuttons(global_t *global, menubar_t *menubar, va_list buttons,
    int nbbuttons)
{
    char *text;
    sfVector2f pos = {0, 0};
    button_t *tmp = NULL;
    sfVector2f size = (sfVector2f){0, MENUBAR_HEIGHT};

    for (int i = 0; i < nbbuttons; i++) {
        text = my_strdup(va_arg(buttons, char *));
        size.x = my_strlen(text) * 16 + MENUBAR_BTN_MARGIN;
        tmp = initbutton(pos, size, text);
        sfRectangleShape_setFillColor(tmp->button,
            sfColor_fromRGB(135, 135, 135));
        if (menubar->buttons != NULL) {
            tmp->next = menubar->buttons;
            menubar->buttons->prev = tmp;
        }
        menubar->buttons = tmp;
        tmp->hover_func = &display_dropdown;
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
