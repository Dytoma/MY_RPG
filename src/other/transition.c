/*
** EPITECH PROJECT, 2024
** transition
** File description:
** functions to do a transition
*/
#include "rpg.h"

static void increase(window_t *window, game_t *game)
{
    sfTime time = sfClock_getElapsedTime(window->clock);
    float seconds = time.microseconds / 1000000.0;

    if (window->transition != 1)
        return;
    if (window->transparency >= 255 && window->transition == 1)
        window->transition = 2;
    if (window->transparency <= 255 && window->transition == 1) {
        if (seconds > 0.001) {
            window->transparency += 10;
            sfRectangleShape_setPosition(window->black,
                (sfVector2f){game->player->position.x - 900,
                game->player->position.y - 400});
            sfRectangleShape_setFillColor(window->black, (sfColor){0, 0, 0,
                window->transparency});
            sfClock_restart(window->clock);
        }
    }
}

static void decrease(window_t *window, game_t *game)
{
    sfTime time = sfClock_getElapsedTime(window->clock);
    float seconds = time.microseconds / 1000000.0;

    if (window->transition != 2)
        return;
    if (window->transparency <= 0 && window->transition == 2)
        window->transition = 0;
    if (window->transparency >= 0 && window->transition == 2) {
        if (seconds > 0.001) {
            window->transparency -= 10;
            sfRectangleShape_setPosition(window->black,
                (sfVector2f){game->player->position.x - 900,
                game->player->position.y - 400});
            sfRectangleShape_setFillColor(window->black, (sfColor){0, 0, 0,
                window->transparency});
            sfClock_restart(window->clock);
        }
    }
}

int tp_player(window_t *window, game_t *game)
{
    increase(window, game);
    decrease(window, game);
    if (window->transparency >= 255)
        return 1;
    return 0;
}
