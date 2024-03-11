/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** layers
*/

#include "../include/my_paint.h"

void initlayerbutton(layer_t *layers)
{
    layers->button = malloc(sizeof(layerbutton_t));
    layers->button->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(layers->button->shape, (sfVector2f){200, 100});
    sfRectangleShape_setFillColor(layers->button->shape, sfWhite);
    sfRectangleShape_setPosition(layers->button->shape, (sfVector2f){0, 0});
    layers->button->text = create_text(my_strdup(layers->name),
        (sfVector2f){50, 50}, FONT_PATH, 20);
}

int addlayer(global_t *global, void *param)
{
    layer_t *new = malloc(sizeof(layer_t));
    layer_t *tmp = global->layers;

    for (; tmp->next != NULL; tmp = tmp->next)
        tmp->selected = 0;
    new->texture = sfTexture_create(800, 600);
    new->name = my_strdup("Layer 2");
    new->sprite = sfSprite_create();
    new->selected = 1;
    new->displayed = 1;
    new->next = NULL;
    new->prev = tmp;
    tmp->next = new;
    initlayerbutton(new);
    return 0;
}

int removelayer(global_t *global, void *param)
{
    layer_t *tmp = global->layers;
    layer_t *to_remove = NULL;

    for (; tmp->next != NULL; tmp = tmp->next) {
        if (tmp->next->selected) {
            printf("Removing %s\n", tmp->next->name);
            to_remove = tmp->next;
            tmp->next = tmp->next->next;
            tmp->next ? (tmp->next->prev = tmp) : 0;
            break;
        }
    }
    if (to_remove != NULL) {
        sfSprite_destroy(to_remove->sprite);
        sfTexture_destroy(to_remove->texture);
        free(to_remove->name);
        free(to_remove);
    }
    return 0;
}

static layer_t *create_layer(void)
{
    layer_t *layers = malloc(sizeof(layer_t));

    layers->texture = sfTexture_create(800, 600);
    layers->name = my_strdup("Layer 1");
    layers->selected = 1;
    layers->displayed = 1;
    layers->next = NULL;
    layers->prev = NULL;
    return layers;
}

static void set_layer_image(layer_t *layers)
{
    sfImage* image;
    sfColor color = sfWhite;

    image = sfImage_createFromColor(800, 600, color);
    sfTexture_updateFromImage(layers->texture, image, 0, 0);
    sfImage_destroy(image);
}

static void set_layer_sprite(layer_t *layers)
{
    sfVector2f position;

    layers->sprite = sfSprite_create();
    sfSprite_setTexture(layers->sprite, layers->texture, sfTrue);
    position.x = 200;
    position.y = 200;
    sfSprite_setPosition(layers->sprite, position);
}

layer_t *initlayers(void)
{
    layer_t *layers = create_layer();

    set_layer_image(layers);
    set_layer_sprite(layers);
    initlayerbutton(layers);
    return layers;
}
