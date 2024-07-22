/*
** EPITECH PROJECT, 2024
** options
** File description:
** options menu
*/
#include "../../include/rpg.h"

data_t *init_options(window_t *window)
{
    data_t *menu = malloc(sizeof(data_t));

    if (menu == NULL)
        return NULL;
    menu->background = sfTexture_createFromFile("assets/img/options.png",
        NULL);
    if (menu->background == NULL) {
        free(menu);
        return NULL;
    }
    menu->buttons = init_options_buttons(window);
    menu->sprite = sfSprite_create();
    sfSprite_setTexture(menu->sprite, menu->background, sfTrue);
    menu->texts = init_options_menu(window);
    return menu;
}
