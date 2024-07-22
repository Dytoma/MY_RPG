/*
** EPITECH PROJECT, 2023
** menu.h
** File description:
** headers for the menu
*/

#ifndef PLAYER_H_
    #define PLAYER_H_
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
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "struct.h"
    #define EXP 193

window_t *window_create(int width, int heigth, char *name);
void player_movements(game_t *game, sfClock *clock);
sprite_t *sprite_create_from_file(char *filepath, sfIntRect *area);
void destroy_sprite(sprite_t *spr);
char **load_map(char *filepath);
sfVector2f get_player_position(char **map);
player_t *player_create_from_file(char *filepath, sfVector2f pos);
obstacle_t *init_collisions(const char *file);
sfBool check_position(float x, float y, obstacle_t *obstacles);
char **my_str_to_word(char *str, char *delim);
text_spr_t **init_lives(void);
void draw_hearts(player_t *player, window_t *window);
void destroy_text_spr(text_spr_t *text_spr);
void destroy_player(player_t *player);
void destroy_window(window_t *window);
exp_t *init_xp(player_t *player);
void destroy_exp(exp_t *exp);
void draw_exp(window_t *window, player_t *player);
void destroy_arr(char **arr);
void add_node(obstacle_t **head_ref, sfFloatRect area);
obstacle_t *init_doors(const char *filemap);
char **open_file(const char *filepath);
void delete_collisions(obstacle_t *list);
float calc_distance(sfVector2f point1, sfVector2f point2);

#endif /* !MENU_H_ */
