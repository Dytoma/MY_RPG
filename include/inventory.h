/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-dytoma.batogouma
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Window/Event.h>
    #include <SFML/System/Clock.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Types.h>
    #include <SFML/Audio/Export.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/Audio/Export.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/System/InputStream.h>
    #include <SFML/System/Time.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Window/Joystick.h>
    #include <SFML/Window/Keyboard.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Sensor.h>
    #include <SFML/Graphics/Export.h>
    #include "struct.h"
    #include "player.h"

weapon_t *init_weapon(char *file);
inventory_t *init_inv(void);
sfBool key_event(window_t *window, sfKeyCode code);
void inv_event(window_t *window, sfEvent *event);
void draw_inv(window_t *window, player_t *player);
sfBool inv_poll_evt(window_t *window, inventory_t *inv);
text_spr_t *init_spr_text(const char *file);
void draw_sprite(sfRenderWindow *window, text_spr_t *spr);
void set_weap_pos(weapon_t **weapons);
void draw_weapons(window_t *window, inventory_t *inv);
void destroy_weapon(weapon_t *weap);
void load_save(player_t *player, char *file);
void save_game(player_t *player);
sfBool is_button_clicked(button_save_t *btn, sfMouseButtonEvent *msEvt,
    window_t *window);
sfBool is_button_hovered(button_save_t *btn, sfMouseMoveEvent *msEvt,
    window_t *window);
int save_event(window_t *window, save_t *save, game_t *game);
save_t *init_save_data(sfFont *font);
void display_load(window_t *window, game_t *game);
void destroy_save(save_t *save);
void set_save_btn_pos(button_save_t *btn, sfVector2f pos);
sfText *init_btn_text(char *name, unsigned int size, sfFont *font);
void transition_frame(window_t *window);
text_spr_t *set_inv_player(void);
player_stat_t *init_player_stats(player_t *player, window_t *window);
void draw_stats(window_t *window, game_t *game);
void animate_player(window_t *window, text_spr_t *spr);
void destroy_stats(player_stat_t *stats);

#endif /* !INVENTORY_H_ */
