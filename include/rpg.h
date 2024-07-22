/*
** EPITECH PROJECT, 2023
** menu.h
** File description:
** headers for the menu
*/

#ifndef MENU_H_
    #define MENU_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <string.h>
    #include <stdint.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include "struct.h"
    #include "player.h"
    #include <fcntl.h>
    #include "inventory.h"

int my_rpg(int ac, char **av);
sfRenderWindow *init_window(void);
button_t **init_menu_buttons(window_t *window);
sfText **init_texts_menu(window_t *window);
data_t *init_menu(window_t *window);
sfBool is_clicked(button_t *button, sfMouseButtonEvent *msevent,
    window_t *window);
sfBool is_exit(button_t *button, sfMouseButtonEvent *msevent,
    window_t *window);
sfBool is_load(button_t *button, sfMouseButtonEvent *msevent,
    window_t *window);
sfBool is_options(button_t *button, sfMouseButtonEvent *msevent,
    window_t *window);
sfBool hover_menu(button_t *button, sfMouseMoveEvent *msevent,
    window_t *window);
window_t *init_window_menu(void);
sfBool hover_options(button_t *button, sfMouseMoveEvent *msevent,
    window_t *window);
data_t *init_options(window_t *window);
button_t **init_options_buttons(window_t *window);
sfText **init_options_menu(window_t *window);
sfBool back_to_main(button_t *button, sfMouseButtonEvent *msevent,
    window_t *window);
void mouse_event(window_t *window, data_t *menu, sfEvent *event);
void destroy_inv(inventory_t *inv);
void game_poll_event(window_t *window, game_t *game);
void main_poll_event(window_t *window, data_t *menu);
void print_data(window_t *window, data_t *menu);
void delete_collisions(obstacle_t *list);
button_t *init_button_opt(char *text, sfVector2f pos, int size, sfFont *font);
sfBool hover_esc(button_esc_t *button, sfMouseMoveEvent *msevent,
    window_t *window);
sfBool back_to_menu(button_esc_t *button, sfMouseButtonEvent *msevent,
    window_t *window, game_t *game);
void esc_menu(window_t *window, game_t *game);
sfBool esc_clicked(button_esc_t *button, sfMouseButtonEvent *msevent,
    window_t *window, game_t *game);
sfBool esc_save(button_esc_t *button, sfMouseButtonEvent *msevent,
    window_t *window, game_t *game);
void inventory_poll_event(window_t *window, game_t *game);
void play_music(sfMusic *sound);
int tp_player(window_t *window, game_t *game);
int check_door(float x, float y, obstacle_t *doors);
sfBool commands(button_esc_t *button, sfMouseButtonEvent *msevent,
    window_t *window, game_t *game);
void draw_commands(window_t *window, game_t *game);
void destroy_bot(bot_t *character);
bot_t *init_bot(char *file1, char *file2, float duration, sfVector2f pos);
void draw_bots(game_t *game, window_t *window);

#endif /* !MENU_H_ */
