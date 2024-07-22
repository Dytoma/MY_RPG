/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-dytoma.batogouma
** File description:
** inventory_page
*/

#include "rpg.h"

text_spr_t *init_spr_text(const char *file)
{
    text_spr_t *ttr_spr = malloc(sizeof(text_spr_t));

    ttr_spr->texture = sfTexture_createFromFile(file, NULL);
    if (ttr_spr->texture == NULL) {
        free(ttr_spr);
        return NULL;
    }
    ttr_spr->sprite = sfSprite_create();
    sfSprite_setTexture(ttr_spr->sprite, ttr_spr->texture, sfTrue);
    return ttr_spr;
}

void draw_sprite(sfRenderWindow *window, text_spr_t *spr)
{
    if (spr == NULL)
        return;
    sfRenderWindow_drawSprite(window, spr->sprite, NULL);
}

static char *get_weapon_desc(int i)
{
    char *weap = strdup("assets/inv/weapon0desc.png");

    weap[17] = '0' + i;
    return weap;
}

static text_spr_t **init_weapons_desc(void)
{
    text_spr_t **desc = malloc(sizeof(text_spr_t *) * 10);

    if (desc == NULL)
        return NULL;
    for (int i = 0; i < 9; i++) {
        desc[i] = init_spr_text(get_weapon_desc(i + 1));
        sfSprite_setPosition(desc[i]->sprite, (sfVector2f){1337.0, 638.0});
    }
    desc[9] = NULL;
    return desc;
}

static char *get_weapon_file(int i)
{
    char *weap = strdup("assets/inv/weapon0.png");

    weap[17] = '0' + i;
    return weap;
}

text_spr_t *set_inv_player(void)
{
    text_spr_t *player = init_spr_text("assets/img/character.png");

    if (player == NULL)
        return NULL;
    sfSprite_setTextureRect(player->sprite, (sfIntRect){128, 128, 32, 32});
    sfSprite_setPosition(player->sprite, (sfVector2f){85, 340});
    sfSprite_setScale(player->sprite, (sfVector2f){14.5, 14.5});
    return player;
}

inventory_t *init_inv(void)
{
    inventory_t *inv = malloc(sizeof(inventory_t));
    int damages[] = {30, 40, 34, 4, 50, 68, 18, 83, 62};

    inv->bg = init_spr_text("assets/img/Inv_bg.png");
    inv->weapons = malloc(sizeof(weapon_t *) * 10);
    inv->player = set_inv_player();
    inv->selected = WEAPON1;
    inv->desc = 84;
    inv->weap_desc = init_weapons_desc();
    for (int i = 0; i < 9; i++) {
        inv->weapons[i] = init_weapon(get_weapon_file(i + 1));
        inv->weapons[i]->damage = damages[i % 8];
        inv->weapons[i]->id = i;
        if (i == 0)
            inv->weapons[i]->state = sfTrue;
    }
    inv->weapons[9] = NULL;
    set_weap_pos(inv->weapons);
    return inv;
}

void draw_inv(window_t *window, player_t *player)
{
    if (inv_poll_evt(window, player->inv))
        return;
    animate_player(window, player->inv->player);
    sfSprite_setPosition(player->inv->bg->sprite, (sfVector2f){0, 0});
    sfSprite_setScale(player->inv->bg->sprite, (sfVector2f){1.0, 0.95});
    sfRenderWindow_drawSprite(window->window, player->inv->bg->sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
        player->inv->player->sprite, NULL);
    draw_weapons(window, player->inv);
}
