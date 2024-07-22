/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-dytoma.batogouma
** File description:
** weapon
*/

#include "rpg.h"

weapon_t *init_weapon(char *file)
{
    weapon_t *weap = malloc(sizeof(weapon_t));

    weap->state = sfFalse;
    weap->sword = init_spr_text(file);
    weap->lock = init_spr_text("assets/inv/locker.png");
    weap->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(weap->rect, (sfVector2f){154.0, 154.0});
    sfRectangleShape_setFillColor(weap->rect, sfTransparent);
    sfRectangleShape_setOutlineThickness(weap->rect, 1.5);
    free(file);
    if (!weap->lock || !weap->sword)
        return NULL;
    return weap;
}

void destroy_weapon(weapon_t *weap)
{
    if (weap == NULL)
        return;
    destroy_text_spr(weap->sword);
    destroy_text_spr(weap->lock);
    sfRectangleShape_destroy(weap->rect);
}

void draw_weapon(weapon_t *weap, window_t *window, int id)
{
    if (weap == NULL)
        return;
    draw_sprite(window->window, weap->sword);
    if (weap->state == sfFalse)
        draw_sprite(window->window, weap->lock);
    sfRenderWindow_drawRectangleShape(window->window, weap->rect, NULL);
    if (weap->state == sfTrue && weap->id == id)
        sfRectangleShape_setOutlineColor(weap->rect, sfYellow);
    else
        sfRectangleShape_setOutlineColor(weap->rect, sfTransparent);
}

static void set_pos(sfSprite *spr, int i)
{
    sfVector2f pos = {740.0, 305.0};

    pos.x += (float)(i % 3) * (151.0 + 30.0);
    pos.y += round(i / 3) * (151.0 + 30.0);
    if (spr == NULL)
        return;
    sfSprite_setPosition(spr, pos);
}

static void set_pos_rect(sfRectangleShape *rect, int i)
{
    sfVector2f pos = {739.0, 304.0};

    pos.x += (float)(i % 3) * (151.0 + 30.0);
    pos.y += round(i / 3) * (151.0 + 30.0);
    if (rect == NULL)
        return;
    sfRectangleShape_setPosition(rect, pos);
}

void set_weap_pos(weapon_t **weapons)
{
    if (weapons == NULL)
        return;
    for (int i = 0; weapons[i] != NULL; i++) {
        set_pos(weapons[i]->sword->sprite, i);
        set_pos(weapons[i]->lock->sprite, i);
        set_pos_rect(weapons[i]->rect, i);
    }
}

void draw_weapons(window_t *window, inventory_t *inv)
{
    if (inv->weapons == NULL)
        return;
    for (int i = 0; inv->weapons[i] != NULL; i++) {
        draw_weapon(inv->weapons[i], window, inv->selected);
        if (inv->desc == 84)
            draw_sprite(window->window, inv->weap_desc[inv->selected]);
        else
            draw_sprite(window->window, inv->weap_desc[inv->desc]);
    }
}
