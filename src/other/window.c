/*
** EPITECH PROJECT, 2024
** window
** File description:
** functions to handle window
*/
#include "rpg.h"

static sfFont **init_fonts(void)
{
    sfFont **fonts = malloc(sizeof(sfFont *) * (4));

    fonts[0] = sfFont_createFromFile("assets/fonts/calibri.ttf");
    fonts[1] = sfFont_createFromFile("assets/fonts/Poppins.ttf");
    fonts[2] = sfFont_createFromFile("assets/fonts/zelda.ttf");
    fonts[3] = NULL;
    return fonts;
}

static void set_window(window_t *window)
{
    window->clock = sfClock_create();
    window->event = malloc(sizeof(sfEvent));
    window->scene = MAIN;
    window->fonts = init_fonts();
    window->view = sfView_create();
    window->black = sfRectangleShape_create();
    window->music = sfMusic_createFromFile("assets/sounds/music.ogg");
    window->village = sfMusic_createFromFile("assets/sounds/village.ogg");
    window->commands = sprite_create_from_file("assets/img/gameplay.png",
        NULL);
}

window_t *window_create(int width, int height, char *name)
{
    sfVideoMode video = {width, height, 32};
    window_t *window = malloc(sizeof(window_t));

    if (window == NULL)
        return NULL;
    window->window = sfRenderWindow_create(video, name, sfClose, NULL);
    set_window(window);
    sfRenderWindow_setFramerateLimit(window->window, 60);
    sfRectangleShape_setSize(window->black, (sfVector2f){1920, 1080});
    sfRectangleShape_setFillColor(window->black, (sfColor){0, 0, 0, 0});
    window->transparency = 0;
    window->transition = 0;
    sfView_setSize(window->view, (sfVector2f){1920, 1080});
    return window;
}

void destroy_inv(inventory_t *inv)
{
    if (inv == NULL)
        return;
    destroy_text_spr(inv->bg);
    for (int i = 0; inv->weapons[i] != NULL; i++)
        destroy_weapon(inv->weapons[i]);
    free(inv->weapons);
    for (int i = 0; inv->weap_desc[i] != NULL; i++)
        destroy_text_spr(inv->weap_desc[i]);
    free(inv->weap_desc);
    destroy_text_spr(inv->player);
    free(inv);
}

void destroy_window(window_t *window)
{
    if (window == NULL)
        return;
    destroy_sprite(window->commands);
    sfRenderWindow_destroy(window->window);
    sfClock_destroy(window->clock);
    sfView_destroy(window->view);
    sfMusic_destroy(window->music);
    sfMusic_destroy(window->village);
    free(window->event);
    free(window);
    return;
}

void mouse_event(window_t *window, data_t *menu, sfEvent *event)
{
    sfMouseButtonEvent click = event->mouseButton;
    sfMouseMoveEvent move = event->mouseMove;

    for (int i = 0; menu->buttons[i] != NULL; i++) {
        menu->buttons[i]->is_clicked(menu->buttons[i], &click, window);
        menu->buttons[i]->is_hover(menu->buttons[i], &move, window);
    }
}

sfRenderWindow *init_window(void)
{
    sfVideoMode video = {1600, 900, 32};

    return sfRenderWindow_create(video, "My_RPG", sfClose, NULL);
}
