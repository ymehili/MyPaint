/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** drawzone
*/

#include "../include/my_paint.h"

void zoom_in(layer_t *layers, sfVector2i mousePos, int delta)
{
    sfVector2f scale;
    sfVector2f spritePos;
    layer_t *current_layer;

    for (current_layer = layers; current_layer != NULL; current_layer =
        current_layer->next) {
        if (delta > 0) {
            scale = sfSprite_getScale(current_layer->sprite);
            spritePos = sfSprite_getPosition(current_layer->sprite);
            scale.x *= 1.1;
            scale.y *= 1.1;
            sfSprite_setScale(current_layer->sprite, scale);
            spritePos.x -= (mousePos.x - spritePos.x) * 0.1;
            spritePos.y -= (mousePos.y - spritePos.y) * 0.1;
            sfSprite_setPosition(current_layer->sprite, spritePos);
        }
    }
}

void zoom_out(layer_t *layers, sfVector2i mousePos, int delta)
{
    sfVector2f scale;
    sfVector2f spritePos;
    layer_t *current_layer;

    for (current_layer = layers; current_layer != NULL; current_layer =
        current_layer->next) {
        if (delta < 0) {
            scale = sfSprite_getScale(current_layer->sprite);
            spritePos = sfSprite_getPosition(current_layer->sprite);
            scale.x /= 1.1;
            scale.y /= 1.1;
            sfSprite_setScale(current_layer->sprite, scale);
            spritePos.x += (mousePos.x - spritePos.x) * 0.1;
            spritePos.y += (mousePos.y - spritePos.y) * 0.1;
            sfSprite_setPosition(current_layer->sprite, spritePos);
        }
    }
}

void reset_lastpos(global_t *global)
{
    global->pencil->lastPos.x = -1;
    global->pencil->lastPos.y = -1;
}
