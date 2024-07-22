/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-dytoma.batogouma
** File description:
** destroy_stats
*/

#include "rpg.h"


void animate_player(window_t *window, text_spr_t *spr)
{
    sfTime time = sfClock_getElapsedTime(window->clock);
    float seconds = sfTime_asSeconds(time);
    sfIntRect rect = sfSprite_getTextureRect(spr->sprite);

    if (seconds >= 0.3) {
        if (rect.left + 32 >= 256) {
            rect.left = 128;
        } else {
            rect.left += 32;
        }
        sfSprite_setTextureRect(spr->sprite, rect);
        sfClock_restart(window->clock);
    }
}

void destroy_stats(player_stat_t *stats)
{
    if (stats == NULL)
        return;
    destroy_text_spr(stats->bg);
    destroy_text_spr(stats->player);
    sfText_destroy(stats->attack);
    sfText_destroy(stats->armor);
    sfText_destroy(stats->life);
    sfText_destroy(stats->experience);
    sfText_destroy(stats->speed);
    sfText_destroy(stats->level);
}
