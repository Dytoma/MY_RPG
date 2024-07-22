/*
** EPITECH PROJECT, 2024
** texts
** File description:
** texts in the option menu
*/
#include "../../include/rpg.h"

static sfText *init(char *str, sfVector2f pos, int size, sfFont *font)
{
    sfText *text = sfText_create();

    if (font == NULL) {
        sfText_destroy(text);
        return NULL;
    }
    sfText_setString(text, str);
    sfText_setPosition(text, pos);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    return text;
}

sfText **init_options_menu(window_t *window)
{
    sfText **tab = malloc(sizeof(sfText *) * 7);
    sfFont *font = window->fonts[2];

    tab[0] = init("Resolution", (sfVector2f){620, 340}, 35, font);
    tab[1] = init("1920 x 1080", (sfVector2f){1075, 340}, 35, font);
    tab[2] = init("Sound", (sfVector2f){620, 440}, 35, font);
    tab[3] = init("Frame Per Second", (sfVector2f){620, 540}, 35, font);
    tab[4] = init("60", (sfVector2f){1140, 540}, 35, font);
    tab[5] = init("Fullscreen", (sfVector2f){620, 700}, 35, font);
    tab[6] = NULL;
    return tab;
}
