/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-dytoma.batogouma
** File description:
** handle_events
*/

#include "rpg.h"

sfBool key_event(window_t *window, sfKeyCode code)
{
    if (window->event->type == sfEvtKeyPressed) {
        if (window->event->key.code == code)
            return sfTrue;
    }
    return sfFalse;
}

void inv_event(window_t *window, sfEvent *event)
{
    if (key_event(window, sfKeyR) || key_event(window, sfKeyL))
        return;
    return;
}

void weapon_state_clicked(window_t *window, inventory_t *inv)
{
    sfVector2i m_pos = sfMouse_getPosition((const sfWindow *)window->window);
    sfFloatRect pos;

    for (int i = 0; inv->weapons[i] != NULL; i++) {
        pos = sfRectangleShape_getGlobalBounds(inv->weapons[i]->rect);
        if (sfMouse_isButtonPressed(window->event->mouseButton.button) &&
            sfFloatRect_contains(&pos, m_pos.x, m_pos.y))
            inv->selected = i;
        if (inv->weapons[i]->state == sfFalse)
            inv->selected = WEAPON1;
    }
}

void weapon_state_hover(window_t *window, inventory_t *inv)
{
    sfVector2i m_pos = sfMouse_getPosition((const sfWindow *)window->window);
    sfFloatRect pos;

    for (int i = 0; inv->weapons[i] != NULL; i++) {
        pos = sfRectangleShape_getGlobalBounds(inv->weapons[i]->rect);
        if (window->event->mouseMove.type == sfEvtMouseMoved &&
            sfFloatRect_contains(&pos, m_pos.x, m_pos.y)) {
            inv->desc = i;
            return;
        }
        if (window->event->mouseMove.type == sfEvtMouseMoved)
            inv->desc = 84;
    }
}

sfBool inv_poll_evt(window_t *window, inventory_t *inv)
{
    while (sfRenderWindow_pollEvent(window->window, window->event)) {
        if (window->event->type == sfEvtClosed) {
            window->scene = GAME;
            sfRenderWindow_close(window->window);
            return sfTrue;
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            window->scene = GAME;
            sfView_zoom(window->view, 0.7);
            return sfTrue;
        }
        if (sfKeyboard_isKeyPressed(sfKeyK)) {
            window->scene = STATS;
            return sfTrue;
        }
        weapon_state_clicked(window, inv);
        weapon_state_hover(window, inv);
    }
    return sfFalse;
}
