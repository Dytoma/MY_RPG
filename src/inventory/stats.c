/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-dytoma.batogouma
** File description:
** stats
*/

#include "rpg.h"

static void my_strcat_char(char *dest, char c)
{
    int n = strlen(dest);

    dest[n] = c;
    dest[n + 1] = '\0';
    return;
}

static void add_int_to_str(char *str, int nbr)
{
    if (nbr < 0) {
        my_strcat_char(str, '-');
        nbr = nbr * (-1);
    }
    if (nbr >= 0 && nbr <= 9) {
        my_strcat_char(str, nbr + 48);
    } else if (nbr > 9) {
        add_int_to_str(str, nbr / 10);
        my_strcat_char(str, nbr % 10 + 48);
    }
}

void set_text_string(player_t *player, player_stat_t *stats)
{
    char strings[6][64] = {"ATTACK:  ", "ARMOR:  ", "EXPERIENCE:  ",
        "LEVEL:  ", "SPEED:  ", "LIFE:  "};

    if (!player || !stats)
        return;
    add_int_to_str(strings[0], player->attack);
    add_int_to_str(strings[1], player->armor);
    add_int_to_str(strings[2], player->experience);
    add_int_to_str(strings[3], player->level);
    add_int_to_str(strings[4], player->speed);
    add_int_to_str(strings[5], player->energy);
    sfText_setString(stats->attack, strings[0]);
    sfText_setString(stats->armor, strings[1]);
    sfText_setString(stats->experience, strings[2]);
    sfText_setString(stats->level, strings[3]);
    sfText_setString(stats->speed, strings[4]);
    sfText_setString(stats->life, strings[5]);
}

sfBool stats_poll_evt(window_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, window->event)) {
        if (window->event->type == sfEvtClosed) {
            sfRenderWindow_close(window->window);
            return sfTrue;
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfView_zoom(window->view, 0.7);
            window->scene = GAME;
            return sfTrue;
        }
        if (sfKeyboard_isKeyPressed(sfKeyI)) {
            window->scene = INVENTORY;
            return sfTrue;
        }
    }
    return sfFalse;
}

static sfText *init_stat_text(sfFont *font)
{
    sfText *text = sfText_create();

    if (text == NULL)
        return NULL;
    sfText_setFont(text, font);
    sfText_setOutlineThickness(text, 4);
    sfText_setCharacterSize(text, 48);
    return text;
}

void set_stats_pos(player_stat_t *stats)
{
    sfText_setPosition(stats->attack, (sfVector2f){1180.0, 247.0});
    sfText_setPosition(stats->armor, (sfVector2f){1180.0, 354.0});
    sfText_setPosition(stats->speed, (sfVector2f){1180.0, 461.0});
    sfText_setPosition(stats->level, (sfVector2f){1180.0, 568.0});
    sfText_setPosition(stats->experience, (sfVector2f){1180.0, 675.0});
    sfText_setPosition(stats->life, (sfVector2f){1180.0, 782.0});
}

player_stat_t *init_player_stats(player_t *player, window_t *window)
{
    player_stat_t *stats = malloc(sizeof(player_stat_t));

    if (stats == NULL || window == NULL)
        return NULL;
    stats->bg = init_spr_text("assets/img/bg.png");
    stats->player = set_inv_player();
    stats->attack = init_stat_text(window->fonts[2]);
    stats->armor = init_stat_text(window->fonts[2]);
    stats->level = init_stat_text(window->fonts[2]);
    stats->life = init_stat_text(window->fonts[2]);
    stats->speed = init_stat_text(window->fonts[2]);
    stats->experience = init_stat_text(window->fonts[2]);
    set_text_string(player, stats);
    set_stats_pos(stats);
    return stats;
}

void draw_stats(window_t *window, game_t *game)
{
    if (stats_poll_evt(window))
        return;
    animate_player(window, game->stats->player);
    sfSprite_setPosition(game->stats->bg->sprite, (sfVector2f){0, 0});
    sfRenderWindow_drawSprite(window->window, game->stats->bg->sprite, NULL);
    sfRenderWindow_drawText(window->window, game->stats->armor, NULL);
    sfRenderWindow_drawText(window->window, game->stats->attack, NULL);
    sfRenderWindow_drawText(window->window, game->stats->level, NULL);
    sfRenderWindow_drawText(window->window, game->stats->speed, NULL);
    sfRenderWindow_drawText(window->window, game->stats->life, NULL);
    sfRenderWindow_drawText(window->window, game->stats->experience, NULL);
    sfRenderWindow_drawSprite(window->window, game->player->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, game->stats->player->sprite,
        NULL);
}
