/*
** EPITECH PROJECT, 2024
** player_movements
** File description:
** functions for the player's movements
*/
#include "player.h"
#include "rpg.h"

static void player_up(game_t *game, sfClock *clock)
{
    sfTime time;
    float seconds;

    if (check_position(game->player->position.x, game->player->position.y - 8,
        game->collisions))
        return;
    game->player->area.top = 96;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.01)
        game->player->position.y -= 3;
    if (seconds > 0.1) {
        if (game->player->area.left + 32 >= 160)
            game->player->area.left = 0;
        else
            game->player->area.left += 32;
        sfClock_restart(clock);
    }
}

static void player_down(game_t *game, sfClock *clock)
{
    sfTime time;
    float seconds;

    if (check_position(game->player->position.x, game->player->position.y + 8,
        game->collisions))
        return;
    game->player->area.top = 0;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.001)
        game->player->position.y += 3;
    if (seconds > 0.1) {
        if (game->player->area.left + 32 >= 160)
            game->player->area.left = 0;
        else
            game->player->area.left += 32;
        sfClock_restart(clock);
    }
}

static void player_left(game_t *game, sfClock *clock)
{
    sfTime time;
    float seconds;

    if (check_position(game->player->position.x - 8, game->player->position.y,
        game->collisions))
        return;
    game->player->area.top = 32;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.01)
        game->player->position.x -= 3;
    if (seconds > 0.1) {
        if (game->player->area.left + 32 >= 160)
            game->player->area.left = 0;
        else
            game->player->area.left += 32;
        sfClock_restart(clock);
    }
}

static void player_right(game_t *game, sfClock *clock)
{
    sfTime time;
    float seconds;

    if (check_position(game->player->position.x + 8, game->player->position.y,
        game->collisions))
        return;
    game->player->area.top = 64;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.001)
        game->player->position.x += 3;
    if (seconds > 0.1) {
        if (game->player->area.left + 32 >= 160)
            game->player->area.left = 0;
        else
            game->player->area.left += 32;
        sfClock_restart(clock);
    }
}

void player_movements(game_t *game, sfClock *clock)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        player_up(game, clock);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        player_down(game, clock);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        player_left(game, clock);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        player_right(game, clock);
    if (!sfKeyboard_isKeyPressed(sfKeyZ) && !sfKeyboard_isKeyPressed(sfKeyQ) &&
        !sfKeyboard_isKeyPressed(sfKeyS) && !sfKeyboard_isKeyPressed(sfKeyD)) {
        game->player->area.left = 0;
        game->player->area.top = 0;
    }
    sfSprite_setPosition(game->player->sprite, game->player->position);
    sfSprite_setTextureRect(game->player->sprite, game->player->area);
}
