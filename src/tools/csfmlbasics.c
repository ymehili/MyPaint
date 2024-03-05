/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** csfmlbasics.c
*/

#include "../../include/my_paint.h"

sfRenderWindow *create_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "-< My Paint >-",
        sfDefaultStyle, NULL);
    return (window);
}

sfSprite *create_sprite(int x, int y, char *filepath)
{
    sfTexture *texture;
    sfSprite *sprite;

    texture = sfTexture_createFromFile(filepath, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){x, y});
    return (sprite);
}

sfText *create_text(char *str, sfVector2f position, char *fontfile, int size)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(fontfile);

    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, position);
    return (text);
}

sfCircleShape *create_circle(float posx, float posy, float radius)
{
    sfVector2f position = {posx, posy};
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setOrigin(circle, (sfVector2f){radius, radius});
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setOutlineColor(circle, sfWhite);
    return circle;
}

sfRectangleShape *create_rectangle(sfVector2f position, sfVector2f size)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setPosition(rectangle, position);
    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setFillColor(rectangle, sfTransparent);
    sfRectangleShape_setOutlineThickness(rectangle, 1);
    sfRectangleShape_setOutlineColor(rectangle, sfGreen);
    return rectangle;
}
