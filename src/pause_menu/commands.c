/*
** EPITECH PROJECT, 2024
** commands
** File description:
** functions for the commands page
*/
#include "rpg.h"

static int commands_poll_event(window_t *window, game_t *game)
{
    while (sfRenderWindow_pollEvent(window->window, window->event)) {
        if (window->event->type == sfEvtClosed) {
            sfRenderWindow_close(window->window);
            return 1;
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfView_setCenter(window->view, game->player->position);
            sfView_zoom(window->view, 0.7);
            window->scene = GAME;
            return 1;
        }
    }
    return 0;
}

void draw_commands(window_t *window, game_t *game)
{
    sfRenderWindow_drawSprite(window->window, window->commands->sprite, NULL);
    if (commands_poll_event(window, game))
        return;
    sfRenderWindow_display(window->window);
}
