/*
** EPITECH PROJECT, 2024
** menu
** File description:
** functions for the menu
*/
#include "rpg.h"

data_t *init_menu(window_t *window)
{
    data_t *menu = malloc(sizeof(data_t));

    if (menu == NULL)
        return NULL;
    menu->background = sfTexture_createFromFile("assets/img/main_menu.png",
        NULL);
    if (menu->background == NULL) {
        free(menu);
        return NULL;
    }
    menu->buttons = init_menu_buttons(window);
    menu->sprite = sfSprite_create();
    sfSprite_setTexture(menu->sprite, menu->background, sfTrue);
    menu->texts = init_texts_menu(window);
    return menu;
}

window_t *init_window_menu(void)
{
    window_t *window = malloc(sizeof(window_t));

    window->window = init_window();
    window->scene = MAIN;
    return window;
}

static button_t *init_button(window_t *window, char *text,
    sfVector2f pos, int size)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL)
        return NULL;
    button->text = sfText_create();
    button->is_clicked = is_clicked;
    button->is_hover = hover_menu;
    button->state = NONE;
    sfText_setPosition(button->text, pos);
    sfText_setString(button->text, text);
    sfText_setFont(button->text, window->fonts[2]);
    sfText_setOutlineThickness(button->text, 4);
    sfText_setCharacterSize(button->text, size);
    return button;
}

button_t **init_menu_buttons(window_t *window)
{
    button_t **tab = malloc(sizeof(button_t *) * 5);

    tab[0] = init_button(window, "START", (sfVector2f){150, 600}, 50);
    tab[1] = init_button(window, "LOAD SAVE", (sfVector2f){150, 670}, 50);
    tab[2] = init_button(window, "OPTIONS", (sfVector2f){150, 740}, 50);
    tab[3] = init_button(window, "EXIT GAME", (sfVector2f){150, 810}, 50);
    tab[2]->is_clicked = is_options;
    tab[3]->is_clicked = is_exit;
    tab[1]->is_clicked = is_load;
    tab[4] = NULL;
    return tab;
}
