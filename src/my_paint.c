/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** my_paint
*/
#include "../include/my_paint.h"

button_t *initbutton(sfVector2f pos, char *text)
{
    button_t *button = my_malloc(sizeof(button_t));
    sfFont *font = sfFont_createFromFile("../assets/font.ttf");

    button->string = text;
}

static void listbuttons(global_t *global, menubar_t *menubar, va_list buttons,
    int nbbuttons)
{
    char *text;
    sfVector2f pos = {0, 0};
    button_t *tmp = NULL;

    for (int i = 0; i < nbbuttons; i++) {
        text = va_arg(buttons, char *);
        tmp = initbutton(pos, text);
        if (menubar->buttons == NULL)
            menubar->buttons = tmp;
        else {
            tmp->next = global->menubar->buttons;
            menubar->buttons->prev = tmp;
            menubar->buttons = tmp;
        }
        pos.x += my_strlen(text) * 20 + 20;
    }
}

menubar_t *initmenubar(int nbbuttons, global_t *global, ...)
{
    menubar_t *menubar = my_malloc(sizeof(menubar_t));
    va_list buttons;

    va_start(buttons, nbbuttons);
    listbuttons(global, menubar, buttons, nbbuttons);
    return (menubar);
}

global_t *initglobal(void)
{
    global_t *global = malloc(sizeof(global_t));

    global->window = create_window(1920, 1080);
    global->menubar = initmenubar(3, global, "File", "Edit", "Help");
    return (global);
}

void event(global_t *global)
{
    while (sfRenderWindow_pollEvent(global->window, &global->event)) {
        if (global->event.type == sfEvtClosed)
            sfRenderWindow_close(global->window);
    }
}

int my_paint(int argc, char **argv)
{
    global_t *global = initglobal();

    while (sfRenderWindow_isOpen(global->window)) {
        event(global);
        sfRenderWindow_clear(global->window, sfBlack);
        sfRenderWindow_display(global->window);
    }
    sfRenderWindow_destroy(global->window);
    return 0;
}
