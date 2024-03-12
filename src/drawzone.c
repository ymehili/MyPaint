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

void reset_lastpos(global_t *global)
{
    global->pencil->lastPos.x = -1;
    global->pencil->lastPos.y = -1;
}

static int findposonlayer(global_t *global, sfVector2i *mousePos,
    drawing_t **drw, layer_t *layer)
{
    if (layer == NULL || !sfMouse_isButtonPressed(sfMouseLeft))
        return 1;
    (*drw)->scale = sfSprite_getScale(layer->sprite);
    (*drw)->spritePos = sfSprite_getPosition(layer->sprite);
    (*drw)->textureSize = sfTexture_getSize(layer->texture);
    if (mousePos->x < (*drw)->spritePos.x || mousePos->y < (*drw)->spritePos.y
        || mousePos->x >= (*drw)->spritePos.x + (*drw)->textureSize.x
        * (*drw)->scale.x || mousePos->y >= (*drw)->spritePos.y +
        (*drw)->textureSize.y * (*drw)->scale.y)
        return 1;
    mousePos->x = (mousePos->x - (*drw)->spritePos.x) / (*drw)->scale.x;
    mousePos->y = (mousePos->y - (*drw)->spritePos.y) / (*drw)->scale.y;
    if (global->pencil->eraser == 1)
        (*drw)->color = sfTransparent;
    else
        (*drw)->color = global->pencil->color;
    (*drw)->image = sfTexture_copyToImage(layer->texture);
    return 0;
}

static void drawline(global_t *global, sfVector2i mousePos, drawing_t *drw)
{
    drw->diff.x = mousePos.x - global->pencil->lastPos.x;
    drw->diff.y = mousePos.y - global->pencil->lastPos.y;
    drw->steps = my_abs(drw->diff.x) > my_abs(drw->diff.y) ?
        my_abs(drw->diff.x) : my_abs(drw->diff.y);
    drw->steps = drw->steps == 0 ? 1 : drw->steps;
    for (int i = 0; i <= drw->steps; i++) {
        drw->interpolatedPos.x = global->pencil->lastPos.x + drw->diff.x * i
            / drw->steps;
        drw->interpolatedPos.y = global->pencil->lastPos.y + drw->diff.y * i
            / drw->steps;
        sfImage_setPixel(drw->image, drw->interpolatedPos.x,
            drw->interpolatedPos.y, drw->color);
    }
}

void draw_on_layer(global_t *global, sfVector2i mousePos)
{
    drawing_t *drw = malloc(sizeof(drawing_t));
    layer_t *layer = global->layers;

    for (; layer->selected != 1; layer = layer->next);
    if (findposonlayer(global, &mousePos, &drw, layer) == 1)
        return;
    if (global->pencil->lastPos.x != -1 && global->pencil->lastPos.y != -1) {
        drawline(global, mousePos, drw);
    } else
        sfImage_setPixel(drw->image, mousePos.x, mousePos.y, drw->color);
    sfTexture_updateFromImage(layer->texture, drw->image, 0, 0);
    sfImage_destroy(drw->image);
    global->pencil->lastPos = mousePos;
}
