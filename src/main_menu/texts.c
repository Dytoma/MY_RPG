/*
** EPITECH PROJECT, 2024
** texts
** File description:
** functions to handle texts
*/
#include "../../include/rpg.h"

static sfText *init_text(char *str, sfVector2f pos, int size, sfFont *font)
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

sfText **init_texts_menu(window_t *window)
{
    sfText **tab = malloc(sizeof(sfText *) * 3);

    tab[0] = init_text("The Fallen Kingdom", (sfVector2f){750, 150}, 115,
        window->fonts[2]);
    tab[1] = init_text("FORBIDDEN QUEST", (sfVector2f){950, 250}, 70,
        window->fonts[2]);
    sfText_setOutlineThickness(tab[0], 3);
    sfText_setOutlineThickness(tab[1], 3);
    sfText_setOutlineColor(tab[1], sfBlack);
    sfText_setOutlineColor(tab[1], sfBlack);
    tab[2] = NULL;
    return tab;
}
