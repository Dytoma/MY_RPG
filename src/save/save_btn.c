/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-dytoma.batogouma
** File description:
** save_btn
*/

#include "rpg.h"

sfText *init_btn_text(char *name, unsigned int size, sfFont *font)
{
    sfText *new_txt = sfText_create();

    if (font == NULL || !new_txt)
        return NULL;
    sfText_setString(new_txt, name);
    sfText_setFont(new_txt, font);
    sfText_setColor(new_txt, sfWhite);
    sfText_setCharacterSize(new_txt, size);
    return new_txt;
}

static sfVector2f txt_pos(sfVector2f pos)
{
    float x = pos.x + 200;
    float y = pos.y + 36;
    sfVector2f text_pos = {0};

    text_pos.x = x;
    text_pos.y = y;
    return text_pos;
}

void set_save_btn_pos(button_save_t *btn, sfVector2f pos)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(btn->bg->sprite);
    sfVector2f size = (sfVector2f){bounds.width + 2, bounds.height + 2};

    sfSprite_setPosition(btn->bg->sprite, pos);
    sfRectangleShape_setPosition(btn->rect,
        (sfVector2f){pos.x - 1, pos.y - 1});
    sfRectangleShape_setOutlineThickness(btn->rect, 2.0);
    sfRectangleShape_setOutlineColor(btn->rect, sfTransparent);
    sfRectangleShape_setSize(btn->rect, size);
    sfRectangleShape_setFillColor(btn->rect, sfTransparent);
    sfText_setPosition(btn->btn_txt, txt_pos(pos));
}
