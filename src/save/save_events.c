/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-dytoma.batogouma
** File description:
** save_events
*/

#include "rpg.h"

sfBool is_button_clicked(button_save_t *btn, sfMouseButtonEvent *msEvt,
    window_t *window)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(btn->rect);

    if (msEvt->type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains(&bounds, msEvt->x, msEvt->y)) {
        sfView_zoom(window->view, 0.7);
        sfMusic_stop(window->music);
        play_music(window->village);
        window->scene = GAME;
        return sfTrue;
    } else if (msEvt->type == sfEvtMouseButtonPressed) {
        btn->state = RELEASED;
        return sfFalse;
    }
    return sfFalse;
}

sfBool is_button_hovered(button_save_t *btn, sfMouseMoveEvent *msEvt,
    window_t *window)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(btn->rect);
    sfColor bg_clr = {216, 159, 225, 150};

    if (msEvt->type == sfEvtMouseMoved &&
        sfFloatRect_contains(&bounds, msEvt->x, msEvt->y)) {
        sfRectangleShape_setOutlineColor(btn->rect, bg_clr);
        return sfTrue;
    } else {
        sfRectangleShape_setOutlineColor(btn->rect, sfTransparent);
        return sfFalse;
    }
}

static char *get_save_file(int i)
{
    char *str = strdup("save0.rpg");

    str[4] = '0' + i;
    return str;
}

int handle_save_opt(button_save_t **saves, window_t *window, game_t *game)
{
    sfMouseMoveEvent msMvEvt = window->event->mouseMove;
    sfMouseButtonEvent msBtnEvt = window->event->mouseButton;

    if (saves == NULL)
        return 1;
    for (int i = 0; saves[i] != NULL; i++) {
        if ((saves[i])->is_clicked(saves[i], &msBtnEvt, window)) {
            load_save(game->player, get_save_file(i + 1));
            return 0;
        }
        (saves[i])->is_hover(saves[i], &msMvEvt, window);
    }
    return 1;
}

int save_event(window_t *window, save_t *save, game_t *game)
{
    sfMouseMoveEvent msMvEvt = window->event->mouseMove;
    sfMouseButtonEvent msBtnEvt = window->event->mouseButton;

    while (sfRenderWindow_pollEvent(window->window, window->event)) {
        if (window->event->type == sfEvtClosed) {
            sfRenderWindow_close(window->window);
            return 1;
        }
        if (handle_save_opt(save->saves, window, game) == 0)
            return 1;
        if (save->back->is_clicked(save->back, &msBtnEvt, window))
            return 1;
        save->back->is_hover(save->back, &msMvEvt, window);
    }
    return 0;
}
