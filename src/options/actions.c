/*
** EPITECH PROJECT, 2024
** actions
** File description:
** actions of buttons in option menu
*/
#include "../../include/rpg.h"

sfBool hover_options(button_t *button, sfMouseMoveEvent *msevent,
    window_t *window)
{
    sfFloatRect inside = sfText_getGlobalBounds(button->text);

    if (msevent->type == sfEvtMouseMoved &&
        sfFloatRect_contains(&inside, msevent->x, msevent->y)) {
        sfText_setOutlineThickness(button->text, 2);
        sfText_setOutlineColor(button->text, sfYellow);
        if (button->state != PRESSED)
            button->state = HOVER;
        return sfTrue;
    } else {
        if (button->state != PRESSED)
            button->state = NONE;
        sfText_setOutlineThickness(button->text, 0);
    }
    return sfFalse;
}

sfBool back_to_main(button_t *button, sfMouseButtonEvent *msevent,
    window_t *window)
{
    sfFloatRect inside = sfText_getGlobalBounds(button->text);

    if (msevent->type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains(&inside, msevent->x, msevent->y)) {
        window->scene = MAIN;
        return sfTrue;
    }
    return sfFalse;
}
