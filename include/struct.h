/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-dytoma.batogouma
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #define WEAP_SIZE 151
    #define LIVES 5
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

typedef enum scene_s {
    MAIN,
    OPTIONS,
    GAME,
    INVENTORY,
    SAVED,
    STATS,
    COMMANDS,
} scene_t;

typedef enum state_s {
    HOVER,
    PRESSED,
    RELEASED,
} state_t;

typedef enum sword_s {
    WEAPON1,
    WEAPON2,
    WEAPON3,
    WEAPON4,
    WEAPON5,
    WEAPON6,
    WEAPON7,
    WEAPON8,
    WEAPON9,
} sword_t;

typedef struct text_spr_s {
    sfSprite *sprite;
    sfTexture *texture;
} text_spr_t;

typedef struct weapon_s {
    text_spr_t *sword;
    text_spr_t *lock;
    sfRectangleShape *rect;
    sfBool state;
    int id;
    int damage;
} weapon_t;

typedef struct inventory_s {
    text_spr_t *bg;
    int *lives;
    weapon_t **weapons;
    text_spr_t **weap_desc;
    int *description;
    text_spr_t *player;
    sword_t selected;
    int desc;
} inventory_t;

typedef struct sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
} sprite_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfEvent *event;
    sfClock *clock;
    sfFont **fonts;
    scene_t scene;
    sfView *view;
    sfRectangleShape *black;
    int transparency;
    int transition;
    sfMusic *music;
    sfMusic *village;
    sprite_t *commands;
} window_t;

typedef struct button_s {
    sfText *text;
    sfBool (*is_clicked) (struct button_s *button, sfMouseButtonEvent *msevent,
        window_t *window);
    sfBool (*is_hover) (struct button_s *button, sfMouseMoveEvent *msevent,
        window_t *window);
    state_t state;
} button_t;

typedef struct button_save_s {
    sfRectangleShape *rect;
    text_spr_t *bg;
    sfText *btn_txt;
    sfBool (*is_clicked)(struct button_save_s *, sfMouseButtonEvent *,
        window_t *window);
    sfBool (*is_hover)(struct button_save_s *, sfMouseMoveEvent *,
        window_t *window);
    state_t state;
} button_save_t;

typedef struct save_s {
    sfText *msg;
    button_t *back;
    button_save_t **saves;
    text_spr_t *bg;
} save_t;

typedef struct player_stat_s {
    text_spr_t *bg;
    text_spr_t *player;
    sfText *armor;
    sfText *experience;
    sfText *attack;
    sfText *level;
    sfText *speed;
    sfText *life;
} player_stat_t;

typedef struct data_s {
    sfSprite *sprite;
    sfTexture *background;
    button_t **buttons;
    sfText **texts;
} data_t;

typedef struct obstacle_s {
    sfFloatRect *area;
    struct obstacle_s *next;
} obstacle_t;

typedef struct message_s {
    text_spr_t *msg;
    sfTime seconds;
    sfBool state;
} message_t;

typedef enum aiming_s {
    NONE,
    NORTH,
    SOUTH,
    EAST,
    WEST,
} aiming_t;

typedef struct exp_s {
    sfRectangleShape *border;
    sfRectangleShape *xp;
} exp_t;

typedef struct player_s {
    sfIntRect area;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    aiming_t orientation;
    text_spr_t **hearts;
    int energy;
    inventory_t *inv;
    exp_t *exp;
    int speed;
    int armor;
    int attack;
    int level;
    int experience;
} player_t;

typedef struct bot_s {
    text_spr_t *bot;
    text_spr_t *message;
    sfVector2f position;
    float elapsed;
    float duration;
    float area;
} bot_t;

typedef struct game_s {
    player_t *player;
    sprite_t *ground;
    sprite_t *trees;
    obstacle_t *collisions;
    obstacle_t *doors;
    player_stat_t *stats;
    bot_t *bot1;
    bot_t *bot2;
    sfClock *bot_clock;
} game_t;

typedef struct button_esc_s {
    sfText *text;
    sfBool (*is_clicked) (struct button_esc_s *button,
        sfMouseButtonEvent *msevent, window_t *window, game_t *game);
    sfBool (*is_hover) (struct button_esc_s *button, sfMouseMoveEvent *msevent,
        window_t *window);
} button_esc_t;

typedef struct data_esc_s {
    sfSprite *sprite;
    sfTexture *img;
    button_esc_t **buttons;
} data_esc_t;

#endif /* !STRUCT_H_ */
