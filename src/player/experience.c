/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-dytoma.batogouma
** File description:
** experience
*/

#include "rpg.h"

static sfRectangleShape *init_border(void)
{
    sfRectangleShape *border = sfRectangleShape_create();

    if (border == NULL)
        return NULL;
    sfRectangleShape_setSize(border, (sfVector2f){193, 21});
    sfRectangleShape_setFillColor(border, sfTransparent);
    sfRectangleShape_setOutlineThickness(border, 2.0);
    sfRectangleShape_setOutlineColor(border, sfBlack);
    return border;
}

static sfRectangleShape *init_xp_bar(player_t *player)
{
    sfRectangleShape *bar = sfRectangleShape_create();
    float exp = ((float)player->experience) * (float)EXP / 100.0;

    if (bar == NULL)
        return NULL;
    sfRectangleShape_setSize(bar, (sfVector2f){exp, 19.0});
    sfRectangleShape_setFillColor(bar, (sfColor){233, 224, 26, 255});
    return bar;
}

exp_t *init_xp(player_t *player)
{
    exp_t *exp = malloc(sizeof(exp_t));
    sfVector2f pos = {43.0, 82.0};

    if (exp == NULL)
        return NULL;
    exp->border = init_border();
    exp->xp = init_xp_bar(player);
    sfRectangleShape_setPosition(exp->xp, pos);
    sfRectangleShape_setPosition(exp->border,
        (sfVector2f){pos.x - 2, pos.y - 2});
    return exp;
}

void draw_exp(window_t *window, player_t *player)
{
    if (player->exp == NULL)
        return;
    sfRenderWindow_drawRectangleShape(window->window, player->exp->xp, NULL);
    sfRenderWindow_drawRectangleShape(window->window, player->exp->border,
        NULL);
}

void destroy_exp(exp_t *exp)
{
    if (exp == NULL)
        return;
    sfRectangleShape_destroy(exp->border);
    sfRectangleShape_destroy(exp->xp);
}
