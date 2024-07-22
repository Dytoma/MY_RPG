/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-dytoma.batogouma
** File description:
** render_life
*/

#include "rpg.h"

text_spr_t *init_spr(const char *file)
{
    text_spr_t *ttr_spr = malloc(sizeof(text_spr_t));
    sfIntRect rect = {0, 0, 16, 16};

    ttr_spr->texture = sfTexture_createFromFile(file, NULL);
    if (ttr_spr->texture == NULL)
        return NULL;
    ttr_spr->sprite = sfSprite_create();
    sfSprite_setTexture(ttr_spr->sprite, ttr_spr->texture, sfTrue);
    sfSprite_setTextureRect(ttr_spr->sprite, rect);
    return ttr_spr;
}

void destroy_text_spr(text_spr_t *text_spr)
{
    if (text_spr == NULL)
        return;
    sfTexture_destroy(text_spr->texture);
    sfSprite_destroy(text_spr->sprite);
    free(text_spr);
}

text_spr_t **init_lives(void)
{
    text_spr_t **lives = malloc(sizeof(text_spr_t *) * (LIVES + 1));
    sfVector2f pos = {40.0, 40.0};

    for (int i = 0; i < LIVES; i++) {
        lives[i] = init_spr("assets/img/hearts.png");
        sfSprite_setPosition(lives[i]->sprite, pos);
        pos.x += 40.0;
    }
    lives[LIVES] = NULL;
    return lives;
}

static void set_text_rect(player_t *player, int i)
{
    sfIntRect rect = {0, 0, 16, 16};
    int n = player->energy - 2 * (i + 1);

    if (n >= 0)
        rect.left = 0;
    if (n < -1)
        rect.left = 32;
    if (n == -1)
        rect.left = 16;
    sfSprite_setTextureRect(player->hearts[i]->sprite, rect);
    sfSprite_setScale(player->hearts[i]->sprite, (sfVector2f){2.0, 2.0});
}

void set_hearts(player_t *player)
{
    for (int i = 0; player->hearts[i] != NULL; i++)
        set_text_rect(player, i);
}

void draw_hearts(player_t *player, window_t *window)
{
    if (player->hearts == NULL)
        return;
    set_hearts(player);
    for (int i = 0; i < LIVES; i++) {
        sfRenderWindow_drawSprite(window->window, (player->hearts[i])->sprite,
            NULL);
    }
    return;
}
