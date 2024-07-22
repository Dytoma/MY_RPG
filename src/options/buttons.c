/*
** EPITECH PROJECT, 2024
** buttons.c
** File description:
** buttons in the option menu
*/
#include "../../include/rpg.h"

button_t *init_button_opt(char *text, sfVector2f pos, int size, sfFont *font)
{
    button_t *button = malloc(sizeof(button_t));

    if (font == NULL) {
        free(button);
        return NULL;
    }
    if (button == NULL) {
        sfFont_destroy(font);
        return NULL;
    }
    button->text = sfText_create();
    button->is_clicked = is_clicked;
    button->is_hover = hover_options;
    button->state = NONE;
    sfText_setPosition(button->text, pos);
    sfText_setString(button->text, text);
    sfText_setFont(button->text, font);
    sfText_setCharacterSize(button->text, size);
    return button;
}

button_t **init_options_buttons(window_t *window)
{
    button_t **tab = malloc(sizeof(button_t *) * 4);
    sfFont *font = window->fonts[2];

    tab[0] = init_button_opt("<", (sfVector2f){1000, 440}, 35, font);
    tab[1] = init_button_opt(">", (sfVector2f){1300, 440}, 35, font);
    tab[2] = init_button_opt("Back", (sfVector2f){620, 180}, 35, font);
    tab[2]->is_clicked = back_to_main;
    tab[3] = NULL;
    return tab;
}
