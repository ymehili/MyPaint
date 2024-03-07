/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** drawzone
*/

#include "../include/my_paint.h"

layer_t *initlayers(void)
{
    layer_t *layers = malloc(sizeof(layer_t));
    sfVector2f position;
    sfImage* image;
    sfColor color;

    layers->texture = sfTexture_create(800, 600);
    image = sfImage_create(800, 600);
    color = sfColor_fromRGB(0, 0, 0);
    sfImage_createFromColor(800, 600, color);
    sfTexture_updateFromImage(layers->texture, image, 0, 0);
    sfImage_destroy(image);
    layers->sprite = sfSprite_create();
    sfSprite_setTexture(layers->sprite, layers->texture, sfTrue);
    position.x = 200;
    position.y = 200;
    sfSprite_setPosition(layers->sprite, position);
    layers->next = NULL;
    return (layers);
}

void zoom_in(layer_t *layers, sfVector2i mousePos, int delta)
{
    sfVector2f scale;
    sfVector2f spritePos;

    if (delta > 0) {
        scale = sfSprite_getScale(layers->sprite);
        spritePos = sfSprite_getPosition(layers->sprite);
        scale.x *= 1.1;
        scale.y *= 1.1;
        sfSprite_setScale(layers->sprite, scale);
        spritePos.x -= (mousePos.x - spritePos.x) * 0.1;
        spritePos.y -= (mousePos.y - spritePos.y) * 0.1;
        sfSprite_setPosition(layers->sprite, spritePos);
    }
}

void zoom_out(layer_t *layers, sfVector2i mousePos, int delta)
{
    sfVector2f scale;
    sfVector2f spritePos;

    if (delta < 0) {
        scale = sfSprite_getScale(layers->sprite);
        spritePos = sfSprite_getPosition(layers->sprite);
        scale.x /= 1.1;
        scale.y /= 1.1;
        sfSprite_setScale(layers->sprite, scale);
        spritePos.x += (mousePos.x - spritePos.x) * 0.1;
        spritePos.y += (mousePos.y - spritePos.y) * 0.1;
        sfSprite_setPosition(layers->sprite, spritePos);
    }
}

void draw_on_layer(global_t *global, sfVector2i mousePos)
{
    sfVector2f scale;
    sfVector2f spritePos;
    sfColor color;
    sfImage *image;

    if (global->layers == NULL || !sfMouse_isButtonPressed(sfMouseLeft))
        return;
    scale = sfSprite_getScale(global->layers->sprite);
    spritePos = sfSprite_getPosition(global->layers->sprite);
    mousePos.x = (mousePos.x - spritePos.x) / scale.x;
    mousePos.y = (mousePos.y - spritePos.y) / scale.y;
    image = sfTexture_copyToImage(global->layers->texture);
    color = sfColor_fromRGB(255, 255, 255);
    sfImage_setPixel(image, mousePos.x, mousePos.y, color);
    sfTexture_updateFromImage(global->layers->texture, image, 0, 0);
    sfImage_destroy(image);
}