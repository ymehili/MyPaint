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
    sfRectangleShape_setSize(layers->button->shape, (sfVector2f){200, 70});
    sfRectangleShape_setFillColor(layers->button->shape, sfWhite);
    sfRectangleShape_setPosition(layers->button->shape, (sfVector2f){0, 0});
    layers->button->text = create_text(my_strdup(layers->name),
        (sfVector2f){50, 50}, FONT_PATH, 20);
}

static void init_layer(layer_t *new, layer_t *tmp, global_t *global)
{
    new->texture = sfTexture_create(800, 600);
    new->name = my_malloc(sizeof(char) * 7 + my_strlen(my_putnbr_in_str(
        global->nb_layers + 1)));
    new->name = my_strcat(new->name, "Layer ");
    new->name = my_strcat(new->name, my_putnbr_in_str(global->nb_layers + 1));
    new->sprite = sfSprite_create();
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setPosition(new->sprite, (sfVector2f){200, 200});
    new->selected = 1;
    new->displayed = 1;
    tmp->selected = 0;
    new->next = NULL;
    new->prev = tmp;
    tmp->next = new;
}

int addlayer(global_t *global, void *param)
{
    layer_t *new = malloc(sizeof(layer_t));
    layer_t *tmp = global->layers;

    if (global->nb_layers >= 10)
        return 0;
    for (; tmp->next != NULL; tmp = tmp->next)
        tmp->selected = 0;
    init_layer(new, tmp, global);
    global->nb_layers++;
    initlayerbutton(new);
    return 0;
}

static void remove_layer(layer_t *to_remove)
{
    if (to_remove == NULL)
        return;
    sfSprite_destroy(to_remove->sprite);
    sfTexture_destroy(to_remove->texture);
    free(to_remove->name);
    free(to_remove);
}

int removelayer(global_t *global, void *param)
{
    layer_t *tmp = global->layers;
    layer_t *to_remove = NULL;

    for (; tmp->next != NULL; tmp = tmp->next) {
        if (tmp->next->selected) {
            to_remove = tmp->next;
            tmp->next = tmp->next->next;
            tmp->selected = 1;
            global->nb_layers--;
            break;
        }
    }
    if (tmp->next)
        tmp->next->prev = tmp;
    remove_layer(to_remove);
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
