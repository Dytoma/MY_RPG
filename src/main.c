/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** rpg
*/
#include "rpg.h"

void play_music(sfMusic *sound)
{
    if (sound == NULL)
        return;
    sfMusic_play(sound);
    sfMusic_setLoop(sound, sfTrue);
}

static game_t *init_game(window_t *window)
{
    game_t *game = malloc(sizeof(game_t));

    game->ground = sprite_create_from_file("assets/img/ground.png", NULL);
    game->trees = sprite_create_from_file("assets/img/trees.png", NULL);
    game->player = player_create_from_file("assets/img/character.png",
        (sfVector2f){2304, 2368});
    game->collisions = init_collisions("assets/collisions.txt");
    game->doors = init_doors("assets/collisions.txt");
    game->stats = init_player_stats(game->player, window);
    game->bot_clock = sfClock_create();
    game->bot1 = init_bot("assets/img/bot1.png", "assets/img/mes1.png", 0.2,
        (sfVector2f){1495, 1580});
    game->bot2 = init_bot("assets/img/bot2.png", "assets/img/mes2.png", 0.24,
        (sfVector2f){2332, 2050});
    return game;
}

void print_data(window_t *window, data_t *menu)
{
    sfRenderWindow_drawSprite(window->window, menu->sprite, NULL);
    for (int i = 0; menu->buttons[i] != NULL; i++)
        sfRenderWindow_drawText(window->window, menu->buttons[i]->text, NULL);
    for (int i = 0; menu->texts[i] != NULL; i++)
        sfRenderWindow_drawText(window->window, menu->texts[i], NULL);
}

void destroy_data(game_t *game, window_t *window)
{
    destroy_player(game->player);
    destroy_sprite(game->ground);
    destroy_sprite(game->trees);
    delete_collisions(game->collisions);
    destroy_stats(game->stats);
    destroy_bot(game->bot1);
    destroy_bot(game->bot2);
    sfClock_destroy(game->bot_clock);
    free(game);
    destroy_window(window);
}

static void which_scene(window_t *window, game_t *game, data_t *menu,
    data_t *options)
{
    if (window->scene == GAME)
        game_poll_event(window, game);
    if (window->scene == MAIN)
        main_poll_event(window, menu);
    if (window->scene == OPTIONS)
        main_poll_event(window, options);
    if (window->scene == SAVED)
        display_load(window, game);
    if (window->scene == INVENTORY)
        draw_inv(window, game->player);
    if (window->scene == STATS)
        draw_stats(window, game);
    if (window->scene == COMMANDS)
        draw_commands(window, game);
}

int main(int ac, char **av)
{
    window_t *window = window_create(1920, 1080, "My_RPG");
    game_t *game = init_game(window);
    data_t *menu = init_menu(window);
    data_t *options = init_options(window);

    play_music(window->music);
    while (sfRenderWindow_isOpen(window->window)) {
        sfRenderWindow_clear(window->window, sfBlack);
        which_scene(window, game, menu, options);
        if (window->scene != MAIN)
            sfMusic_stop(window->music);
        sfRenderWindow_display(window->window);
    }
    destroy_data(game, window);
    return 0;
}
