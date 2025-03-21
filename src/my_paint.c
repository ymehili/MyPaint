/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** my_paint
*/

#include "../include/my_paint.h"

static void add_menubar(global_t *global)
{
    add_dd_menu(global, "File", 4, "New file", "Open file",
        "Save file", "close");
    add_dd_menu(global, "Edit", 2, "Pencil", "Eraser");
    add_dd_menu(global, "Layers", 2, "Add", "Remove");
    add_dd_menu(global, "Help", 2, "About", "Help");
    add_click_func(global->menubar, "File", "close", &close_btn);
    add_click_func(global->menubar, "Edit", "Pencil", &pick_pencil);
    add_click_func(global->menubar, "Edit", "Eraser", &pick_eraser);
    add_click_func(global->menubar, "Layers", "Add", &addlayer);
    add_click_func(global->menubar, "Layers", "Remove", &removelayer);
    add_click_func(global->menubar, "File", "Save file", &save_file);
    add_click_func(global->menubar, "File", "New file", &new_file);
    add_click_func(global->menubar, "File", "Open file", &open_file);
    add_click_func(global->menubar, "Help", "About", &about);
    add_click_func(global->menubar, "Help", "Help", &help);
}

global_t *initglobal(void)
{
    global_t *global = my_malloc(sizeof(global_t));

    global->pencil = malloc(sizeof(pencil_t));
    global->pencil->lastPos = (sfVector2i){-1, -1};
    global->window = create_window(WINDOW_WIDTH, WINDOW_HEIGHT);
    global->windowSize = (sfVector2i){WINDOW_WIDTH, WINDOW_HEIGHT};
    global->layerSize = (sfVector2i){LAYER_WIDTH, LAYER_HEIGHT};
    global->pencil->pencil = 1;
    global->pencil->eraser = 0;
    global->pencil->color = sfBlack;
    global->pencil->size = 1;
    global->pencil->shape = 1;
    global->menubar = initmenubar(4, global, "File", "Edit", "Layers", "Help");
    add_menubar(global);
    global->layers = initlayers(global->layerSize, global);
    global->nb_layers = 1;
    pencilpopup(global);
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
        handlepopupevents(global->popup, global);
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
        if (display(global) != 0)
            break;
        sfRenderWindow_display(global->window);
    }
    sfRenderWindow_destroy(global->window);
    return 0;
}
