/*
** EPITECH PROJECT, 2024
** buttons
** File description:
** function to handle buttons
*/
#include "../../include/rpg.h"

sfBool is_clicked(button_t *button, sfMouseButtonEvent *msevent,
    window_t *window)
{
    sfFloatRect inside = sfText_getGlobalBounds(button->text);

    if (msevent->type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains(&inside, msevent->x, msevent->y)) {
        window->scene = GAME;
        sfMusic_stop(window->music);
        play_music(window->village);
        sfView_zoom(window->view, 0.7);
        return sfTrue;
    }
    return sfFalse;
}

sfBool is_exit(button_t *button, sfMouseButtonEvent *msevent,
    window_t *window)
{
    sfFloatRect inside = sfText_getGlobalBounds(button->text);

    if (msevent->type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains(&inside, msevent->x, msevent->y)) {
        sfRenderWindow_close(window->window);
        return sfTrue;
    }
    return sfFalse;
}

sfBool is_options(button_t *button, sfMouseButtonEvent *msevent,
    window_t *window)
{
    sfFloatRect inside = sfText_getGlobalBounds(button->text);

    if (msevent->type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains(&inside, msevent->x, msevent->y)) {
        window->scene = OPTIONS;
        return sfTrue;
    }
    return sfFalse;
}

sfBool hover_menu(button_t *button, sfMouseMoveEvent *msevent,
    window_t *window)
{
    sfFloatRect inside = sfText_getGlobalBounds(button->text);

    if (msevent->type == sfEvtMouseMoved &&
        sfFloatRect_contains(&inside, msevent->x, msevent->y)) {
        sfText_setOutlineColor(button->text, sfBlack);
        if (button->state != PRESSED)
            button->state = HOVER;
        return sfTrue;
    } else {
        if (button->state != PRESSED)
            button->state = NONE;
        sfText_setOutlineColor(button->text, sfTransparent);
    }
    return sfFalse;
}

sfBool is_load(button_t *button, sfMouseButtonEvent *msevent,
    window_t *window)
{
    sfFloatRect inside = sfText_getGlobalBounds(button->text);

    if (msevent->type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains(&inside, msevent->x, msevent->y)) {
        button->state = PRESSED;
        window->scene = SAVED;
        return sfTrue;
    }
    return sfFalse;
}
