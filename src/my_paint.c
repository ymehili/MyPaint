/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** my_paint
*/

#include "../include/my_paint.h"

global_t *initglobal(void)
{
    global_t *global = malloc(sizeof(global_t));

    global->lastPos = (sfVector2i){-1, -1};
    global->window = create_window(WINDOW_WIDTH, WINDOW_HEIGHT);
    global->windowSize = (sfVector2i){WINDOW_WIDTH, WINDOW_HEIGHT};
    global->pencil = 1;
    global->color = sfBlack;
    global->menubar = initmenubar(4, global, "File", "Edit", "Help");
    add_dd_menu(global, "File", 4, "New file", "Open file",
        "Save file", "close");
    add_dd_menu(global, "Edit", 2, "Pencil", "Eraser");
    add_dd_menu(global, "Help", 2, "About", "Help");
    add_click_func(global->menubar, "File", "close", &close_btn);
    add_click_func(global->menubar, "Edit", "Pencil", &pick_pencil);
    add_click_func(global->menubar, "Edit", "Eraser", &pick_eraser);
    global->layerbar = create_rectangle((sfVector2f){1720, 0},
        (sfVector2f){200, WINDOW_HEIGHT});
    global->layers = initlayers();
    return (global);
}

void handlevents(global_t *global, sfVector2i mousePos)
{
    switch (global->event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(global->window);
            break;
        case sfEvtMouseButtonPressed:
        case sfEvtMouseMoved:
            draw_on_layer(global, mousePos);
            break;
        case sfEvtMouseButtonReleased:
            reset_lastpos(global);
            break;
        case sfEvtMouseWheelScrolled:
            zoom_in(global->layers, mousePos,
                global->event.mouseWheelScroll.delta);
            zoom_out(global->layers, mousePos,
                global->event.mouseWheelScroll.delta);
            break;
        default:
            break;
    }
}

void event(global_t *global)
{
    sfVector2i mousePos;
    sfVector2u size = sfRenderWindow_getSize(global->window);

    while (sfRenderWindow_pollEvent(global->window, &global->event)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(global->window);
        mousePos = sfMouse_getPositionRenderWindow(global->window);
        handlevents(global, mousePos);
    }
    if (size.x != global->windowSize.x || size.y != global->windowSize.y) {
        global->windowSize = (sfVector2i){size.x, size.y};
        sfRenderWindow_setView(global->window,
            sfView_createFromRect((sfFloatRect){0, 0, size.x, size.y}));
    }
}

int my_paint(int argc, char **argv)
{
    global_t *global = initglobal();

    sfRenderWindow_setFramerateLimit(global->window, 60);
    while (sfRenderWindow_isOpen(global->window)) {
        event(global);
        sfRenderWindow_clear(global->window, sfColor_fromRGB(190, 190, 190));
        if (update(global) != 0)
            break;
        if (display(global) != 0)
            break;
        sfRenderWindow_display(global->window);
    }
    sfRenderWindow_destroy(global->window);
    return 0;
}
