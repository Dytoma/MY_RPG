/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-dytoma.batogouma
** File description:
** bots
*/

#include "rpg.h"

void animate_bot(bot_t *character, float seconds)
{
    sfIntRect rect = sfSprite_getTextureRect(character->bot->sprite);

    character->elapsed += seconds;
    if (character->elapsed >= character->duration) {
        character->elapsed = 0.0;
        if (rect.left + 32 >= 128)
            rect.left = 0;
        else
            rect.left += 32;
        sfSprite_setTextureRect(character->bot->sprite, rect);
    }
}

bot_t *init_bot(char *file1, char *file2, float duration, sfVector2f pos)
{
    bot_t *char1 = malloc(sizeof(bot_t));

    if (char1 == NULL)
        return NULL;
    char1->bot = init_spr_text(file1);
    char1->message = init_spr_text(file2);
    char1->area = 20.0;
    sfSprite_setTextureRect(char1->bot->sprite, (sfIntRect){0, 0, 32, 32});
    char1->duration = duration;
    char1->elapsed = 0.0;
    sfSprite_setPosition(char1->bot->sprite, pos);
    sfSprite_setScale(char1->bot->sprite, (sfVector2f){3.0, 3.0});
    sfSprite_setScale(char1->message->sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(char1->message->sprite,
        (sfVector2f){pos.x, pos.y - 100});
    return char1;
}

void draw_bot(bot_t *char1, player_t *player, window_t *window, float seconds)
{
    sfVector2f pos2 = sfSprite_getPosition(player->sprite);
    sfFloatRect rect = sfSprite_getGlobalBounds(char1->bot->sprite);

    if (char1 == NULL)
        return;
    rect.left -= 20.0;
    rect.top -= 20.0;
    rect.width += 80.0;
    rect.height += 80.0;
    sfRenderWindow_drawSprite(window->window, char1->bot->sprite, NULL);
    if (sfFloatRect_contains(&rect, pos2.x, pos2.y)) {
        sfRenderWindow_drawSprite(window->window, char1->message->sprite,
            NULL);
    } else {
        animate_bot(char1, seconds);
    }
}

void draw_bots(game_t *game, window_t *window)
{
    sfTime time = sfClock_getElapsedTime(game->bot_clock);
    float seconds = sfTime_asSeconds(time);

    sfClock_restart(game->bot_clock);
    draw_bot(game->bot1, game->player, window, seconds);
    draw_bot(game->bot2, game->player, window, seconds);
    return;
}

void destroy_bot(bot_t *character)
{
    if (character == NULL)
        return;
    destroy_text_spr(character->bot);
    destroy_text_spr(character->message);
    free(character);
}
