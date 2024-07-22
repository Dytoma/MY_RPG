/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** where it all begins
*/
#include "../include/rpg.h"

int my_rpg(int ac, char **av)
{
    sfRenderWindow *window = init_window();
    sfEvent event;
    scene_t scene = MAIN;

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        poll_event(window, &event);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}
