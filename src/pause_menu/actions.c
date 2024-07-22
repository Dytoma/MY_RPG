/*
** EPITECH PROJECT, 2024
** actions
** File description:
** button's actions
*/
#include "rpg.h"

sfBool back_to_menu(button_esc_t *button, sfMouseButtonEvent *msevent,
    window_t *window, game_t *game)
{
    sfFloatRect inside = sfText_getGlobalBounds(button->text);
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(window->window,
        (sfVector2i){msevent->x, msevent->y}, window->view);

    if (msevent->type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains(&inside, pos.x, pos.y)) {
        window->scene = MAIN;
        sfMusic_stop(window->village);
        play_music(window->music);
        sfView_reset(window->view, (sfFloatRect){0, 0, 1920, 1080});
        sfRenderWindow_setView(window->window, window->view);
        return sfTrue;
    }
    return sfFalse;
}

sfBool hover_esc(button_esc_t *button, sfMouseMoveEvent *msevent,
    window_t *window)
{
    sfFloatRect inside = sfText_getGlobalBounds(button->text);
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(window->window,
        (sfVector2i){msevent->x, msevent->y}, window->view);

    if (msevent->type == sfEvtMouseMoved &&
        sfFloatRect_contains(&inside, pos.x, pos.y)) {
        sfText_setOutlineThickness(button->text, 2);
        sfText_setOutlineColor(button->text, sfBlack);
        return sfTrue;
    } else
        sfText_setOutlineThickness(button->text, 0);
    return sfFalse;
}

sfBool esc_clicked(button_esc_t *button, sfMouseButtonEvent *msevent,
    window_t *window, game_t *game)
{
    sfFloatRect inside = sfText_getGlobalBounds(button->text);
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(window->window,
        (sfVector2i){msevent->x, msevent->y}, window->view);

    if (msevent->type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains(&inside, pos.x, pos.y)) {
        window->scene = GAME;
        return sfTrue;
    }
    return sfFalse;
}

sfBool esc_save(button_esc_t *button, sfMouseButtonEvent *msevent,
    window_t *window, game_t *game)
{
    sfFloatRect inside = sfText_getGlobalBounds(button->text);
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(window->window,
        (sfVector2i){msevent->x, msevent->y}, window->view);

    if (msevent->type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains(&inside, pos.x, pos.y)) {
        save_game(game->player);
        return sfTrue;
    }
    return sfFalse;
}

sfBool commands(button_esc_t *button, sfMouseButtonEvent *msevent,
    window_t *window, game_t *game)
{
    sfFloatRect inside = sfText_getGlobalBounds(button->text);
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(window->window,
        (sfVector2i){msevent->x, msevent->y}, window->view);

    if (msevent->type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains(&inside, pos.x, pos.y)) {
        sfView_reset(window->view, (sfFloatRect){0, 0, 1920, 1080});
        sfRenderWindow_setView(window->window, window->view);
        window->scene = COMMANDS;
        return sfTrue;
    }
    return sfFalse;
}
