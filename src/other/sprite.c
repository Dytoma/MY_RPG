/*
** EPITECH PROJECT, 2024
** sprite
** File description:
** functions to manage sprites
*/
#include "../include/player.h"

sprite_t *sprite_create_from_file(char *filepath, sfIntRect *area)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    if (sprite == NULL)
        return NULL;
    sprite->sprite = sfSprite_create();
    if (area != NULL)
        sprite->texture = sfTexture_createFromFile(filepath, area);
    else
        sprite->texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    return sprite;
}

void destroy_sprite(sprite_t *spr)
{
    if (spr == NULL)
        return;
    sfTexture_destroy(spr->texture);
    sfSprite_destroy(spr->sprite);
    free(spr);
}
