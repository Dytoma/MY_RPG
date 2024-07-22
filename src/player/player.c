/*
** EPITECH PROJECT, 2024
** player
** File description:
** functions to manage player
*/
#include "rpg.h"

static void fill_player(player_t *player)
{
    player->orientation = NONE;
    player->inv = init_inv();
    player->experience = 35;
    player->exp = init_xp(player);
    player->attack = 5;
    player->speed = 8;
    player->level = 1;
    player->energy = 10;
}

player_t *player_create_from_file(char *filepath, sfVector2f pos)
{
    player_t *player = malloc(sizeof(player_t));
    sfIntRect area = {0, 0, 32, 32};

    player->area = area;
    player->sprite = sfSprite_create();
    player->texture = sfTexture_createFromFile(filepath, NULL);
    player->position = pos;
    player->hearts = init_lives();
    fill_player(player);
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setPosition(player->sprite, player->position);
    sfSprite_setScale(player->sprite, (sfVector2f){3.0, 3.0});
    sfSprite_setOrigin(player->sprite, (sfVector2f){32, 32});
    return player;
}

void destroy_player(player_t *player)
{
    if (player == NULL)
        return;
    sfSprite_destroy(player->sprite);
    sfTexture_destroy(player->texture);
    destroy_exp(player->exp);
    for (int i = 0; player->hearts[i] != NULL; i++)
        destroy_text_spr(player->hearts[i]);
    free(player->hearts);
    destroy_inv(player->inv);
    free(player);
}
