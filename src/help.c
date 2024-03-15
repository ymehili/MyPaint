/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** help
*/

#include "../include/my_paint.h"

static sfText *init(void)
{
    sfText *text = create_text("This is a simple paint software\n\n\n"
        "In the File dropdown, you can close the app,\n"
        "open a file, create a new file\n"
        "or save it in .png, .jpg or .bmp format.\n\n"
        "In the Edit dropdown, you can choose the pencil or the eraser.\n\n"
        "In the Layer dropdown, you can add a layer\n"
        "and delete the layer selected.\n\n"
        "In the Help dropdown, you can find the about and the help page.\n\n"
        "At the left side, their is the layer panel.\n"
        "Left click on a layer to select it\n"
        "and right click to toggle it's display.\n\n"
        "At the bottom, you can find the pencil colors, shapes and sizes.\n\n"
        "You can zoom in and out the canvas with the mouse wheel.\n\n"
        "Finally, you can close the app with Escape key or the cross button\n",
        (sfVector2f){40, 90}, FONT_PATH, 18);

    return text;
}

static void event(sfRenderWindow *new_window, global_t *global)
{
    while (sfRenderWindow_pollEvent(new_window, &global->event)) {
        if (global->event.type == sfEvtClosed)
            sfRenderWindow_close(new_window);
    }
}

int help(global_t *global, void *param)
{
    sfRenderWindow *new_window = create_window(800, 600);
    sfText *title = create_text("My Paint",
        (sfVector2f){320, 20}, FONT_PATH, 40);
    sfText *text = init();

    sfText_setColor(title, sfColor_fromRGB(220, 0, 180));
    sfRenderWindow_setFramerateLimit(new_window, 60);
    while (sfRenderWindow_isOpen(new_window)) {
        sfRenderWindow_clear(new_window, sfWhite);
        sfRenderWindow_drawText(new_window, text, NULL);
        sfRenderWindow_drawText(new_window, title, NULL);
        sfRenderWindow_display(new_window);
        sfRenderWindow_display(global->window);
        event(new_window, global);
    }
    return 0;
}
