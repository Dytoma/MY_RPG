/*
** EPITECH PROJECT, 2024
** scene
** File description:
** functions to manage scenes
*/
#include "rpg.h"

static void update_sprites(window_t *window, game_t *game)
{
    sfVector2f pos = game->player->position;

    draw_exp(window, game->player);
    for (int i = 0; game->player->hearts[i] != NULL; i++) {
        sfSprite_setPosition(game->player->hearts[i]->sprite,
            (sfVector2f){(pos.x - 650) + i * 40, pos.y - 350});
    }
    sfRectangleShape_setPosition(game->player->exp->border,
        (sfVector2f){(pos.x - 650), pos.y - 300});
    sfRectangleShape_setPosition(game->player->exp->xp,
        (sfVector2f){(pos.x - 650), pos.y - 300});
}

static void draw_window(window_t *window, game_t *game)
{
    sfRenderWindow_drawSprite(window->window, game->ground->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, game->player->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, game->trees->sprite, NULL);
}

void print_coordonate(sfEvent *event)
{
    sfMouseButtonEvent click = event->mouseButton;

    if (click.type == sfEvtMouseButtonPressed) {
        printf("x: %d; y: %d", click.x, click.y);
    }
}

static void poll_event(window_t *window, game_t *game)
{
    while (sfRenderWindow_pollEvent(window->window, window->event)) {
        if (window->event->type == sfEvtClosed)
            sfRenderWindow_close(window->window);
        if (sfKeyboard_isKeyPressed(sfKeyP))
            esc_menu(window, game);
        if (sfKeyboard_isKeyPressed(sfKeyT))
            window->transition = 1;
        if (sfKeyboard_isKeyPressed(sfKeyI)) {
            sfView_reset(window->view, (sfFloatRect){0, 0, 1920, 1080});
            sfRenderWindow_setView(window->window, window->view);
            window->scene = INVENTORY;
        }
    }
}

void game_poll_event(window_t *window, game_t *game)
{
    if (tp_player(window, game))
        return;
    if (check_door(game->player->position.x, game->player->position.y,
        game->doors) != -1)
        window->transition = 1;
    sfRenderWindow_setView(window->window, window->view);
    draw_window(window, game);
    draw_bots(game, window);
    poll_event(window, game);
    player_movements(game, window->clock);
    draw_hearts(game->player, window);
    update_sprites(window, game);
    sfView_setCenter(window->view, game->player->position);
    sfRenderWindow_drawRectangleShape(window->window, window->black, NULL);
    sfRenderWindow_display(window->window);
}

void main_poll_event(window_t *window, data_t *menu)
{
    print_data(window, menu);
    while (sfRenderWindow_pollEvent(window->window, window->event)) {
        if (window->event->type == sfEvtClosed)
            sfRenderWindow_close(window->window);
        mouse_event(window, menu, window->event);
    }
}

void inventory_poll_event(window_t *window, game_t *game)
{
    draw_inv(window, game->player);
    while (sfRenderWindow_pollEvent(window->window, window->event)) {
        if (window->event->type == sfEvtClosed)
            sfRenderWindow_close(window->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            window->scene = GAME;
    }
}
