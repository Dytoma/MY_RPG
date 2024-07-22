/*
** EPITECH PROJECT, 2024
** menu
** File description:
** pause menu
*/
#include "rpg.h"

static button_esc_t *init_button(window_t *window, char *text,
    sfVector2f pos)
{
    button_esc_t *button = malloc(sizeof(button_esc_t));

    if (button == NULL)
        return NULL;
    button->text = sfText_create();
    button->is_clicked = esc_clicked;
    button->is_hover = hover_esc;
    sfText_setPosition(button->text, pos);
    sfText_setString(button->text, text);
    sfText_setFont(button->text, window->fonts[2]);
    sfText_setCharacterSize(button->text, 48);
    return button;
}

static data_esc_t *esc_menu_create(window_t *window, game_t *game)
{
    data_esc_t *data = malloc(sizeof(data_esc_t));
    sfVector2f pos = game->player->position;

    data->sprite = sfSprite_create();
    data->img = sfTexture_createFromFile("assets/img/board.png", NULL);
    sfSprite_setTexture(data->sprite, data->img, sfTrue);
    sfSprite_setScale(data->sprite, (sfVector2f){1.65, 1.65});
    sfSprite_setPosition(data->sprite, (sfVector2f){pos.x - 550, pos.y - 310});
    data->buttons = malloc(sizeof(button_esc_t *) * 4);
    data->buttons[0] = init_button(window, "Save game",
        (sfVector2f){pos.x - 85, pos.y - 145});
    data->buttons[0]->is_clicked = esc_save;
    data->buttons[1] = init_button(window, "Commands",
        (sfVector2f){pos.x - 85, pos.y - 35});
    data->buttons[2] = init_button(window, "Back to main menu",
        (sfVector2f){pos.x - 160, pos.y + 75});
    data->buttons[3] = NULL;
    data->buttons[2]->is_clicked = back_to_menu;
    data->buttons[1]->is_clicked = commands;
    return data;
}

static void destroy_esc(data_esc_t *menu)
{
    sfSprite_destroy(menu->sprite);
    sfTexture_destroy(menu->img);
    for (int i = 0; menu->buttons[i] != NULL; i++) {
        sfText_destroy(menu->buttons[i]->text);
        free(menu->buttons[i]);
    }
    free(menu->buttons);
    free(menu);
}

int display_text(window_t *window, data_esc_t *menu, game_t *game)
{
    sfMouseMoveEvent move = window->event->mouseMove;
    sfMouseButtonEvent click = window->event->mouseButton;

    for (int i = 0; menu->buttons[i] != NULL; i++) {
        if (menu->buttons[i]->is_clicked(menu->buttons[i], &click, window,
            game))
            return 1;
        menu->buttons[i]->is_hover(menu->buttons[i], &move, window);
    }
    return 0;
}

static int poll_esc(window_t *window, data_esc_t *menu, game_t *game)
{
    while (sfRenderWindow_pollEvent(window->window, window->event)) {
        if (window->event->type == sfEvtClosed) {
            sfRenderWindow_close(window->window);
            return 1;
        }
        if (display_text(window, menu, game))
            return 1;
    }
    return 0;
}

void esc_menu(window_t *window, game_t *game)
{
    data_esc_t *menu = esc_menu_create(window, game);

    while (1) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            destroy_esc(menu);
            return;
        }
        sfRenderWindow_drawSprite(window->window, menu->sprite, NULL);
        sfRenderWindow_drawText(window->window, menu->buttons[0]->text, NULL);
        sfRenderWindow_drawText(window->window, menu->buttons[1]->text, NULL);
        sfRenderWindow_drawText(window->window, menu->buttons[2]->text, NULL);
        if (poll_esc(window, menu, game)) {
            destroy_esc(menu);
            return;
        }
        sfRenderWindow_display(window->window);
    }
}
