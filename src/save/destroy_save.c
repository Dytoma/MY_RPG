/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-dytoma.batogouma
** File description:
** destroy_save
*/

#include "rpg.h"

void destroy_button(button_t *btn)
{
    if (btn == NULL)
        return;
    sfText_destroy(btn->text);
}

void destroy_btn_save(button_save_t *btn)
{
    if (btn == NULL)
        return;
    sfRectangleShape_destroy(btn->rect);
    destroy_text_spr(btn->bg);
    sfText_destroy(btn->btn_txt);
}

void destroy_save(save_t *save)
{
    if (save == NULL)
        return;
    destroy_text_spr(save->bg);
    destroy_button(save->back);
    if (save->saves != NULL) {
        for (int i = 0; save->saves[i] != NULL; i++)
            destroy_btn_save(save->saves[i]);
        free(save->saves);
    }
    sfText_destroy(save->msg);
    free(save);
}
