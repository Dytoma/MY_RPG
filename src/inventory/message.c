/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-dytoma.batogouma
** File description:
** message
*/

#include "rpg.h"

void display_image(window_t *window, message_t *message)
{
    float seconds = 0.0;

    message->seconds = sfClock_getElapsedTime(window->clock);
    seconds = message->seconds.microseconds / 1000000;
    if (seconds <= 10.0 && message->state)
        sfRenderWindow_drawSprite(window->window, message->msg->texture, NULL);
    else
        message->seconds = (sfTime){0};
}
