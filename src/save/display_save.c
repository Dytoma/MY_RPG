/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-dytoma.batogouma
** File description:
** display_save
*/

#include "rpg.h"

button_save_t *init_button_save(sfVector2f pos, char *txt, sfFont *font)
{
    button_save_t *btn = malloc(sizeof(button_save_t));
    sfText *btn_txt = init_btn_text(txt, 48, font);
    sfFloatRect bounds;
    sfVector2f size;

    if (btn_txt == NULL)
        return NULL;
    bounds = sfText_getGlobalBounds(btn_txt);
    btn->rect = sfRectangleShape_create();
    btn->is_clicked = is_button_clicked;
    btn->is_hover = is_button_hovered;
    btn->state = NONE;
    btn->btn_txt = btn_txt;
    btn->bg = init_spr_text("assets/img/btn_bg.png");
    set_save_btn_pos(btn, pos);
    return btn;
}

static void draw_btn(button_save_t *btn, window_t *window)
{
    if (btn == NULL)
        return;
    sfRenderWindow_drawRectangleShape(window->window, btn->rect, NULL);
    sfRenderWindow_drawSprite(window->window, btn->bg->sprite, NULL);
    sfRenderWindow_drawText(window->window, btn->btn_txt, NULL);
}

static button_save_t **last_save(int i, button_save_t **saved, sfFont *font)
{
    int n = i;

    if (access("save3.rpg", F_OK) == 0) {
        saved = realloc(saved, sizeof(button_save_t *) * (n + 2));
        saved[n] = init_button_save((sfVector2f){680, 684}, "SAVE 3", font);
        n++;
    }
    if (n != 0)
        saved[n] = NULL;
    return saved;
}

static button_save_t **init_save(sfFont *font)
{
    int n = 0;
    button_save_t **saved = NULL;

    if (access("save1.rpg", F_OK) == 0) {
        saved = realloc(saved, sizeof(button_save_t *) * (n + 2));
        saved[n] = init_button_save((sfVector2f){680, 320}, "SAVE 1", font);
        n++;
    }
    if (access("save2.rpg", F_OK) == 0) {
        saved = realloc(saved, sizeof(button_save_t *) * (n + 2));
        saved[n] = init_button_save((sfVector2f){680, 500}, "SAVE 2", font);
        n++;
    }
    saved = last_save(n, saved, font);
    return saved;
}

static sfBool is_back(button_t *button, sfMouseButtonEvent *msevent,
    window_t *window)
{
    sfFloatRect inside = sfText_getGlobalBounds(button->text);

    if (msevent->type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains(&inside, msevent->x, msevent->y)) {
        button->state = PRESSED;
        window->scene = MAIN;
        return sfTrue;
    }
    return sfFalse;
}

static sfText *init_empty(sfFont *font)
{
    sfText *empt = sfText_create();

    if (font == NULL || !empt)
        return NULL;
    sfText_setString(empt, "Empty");
    sfText_setFont(empt, font);
    sfText_setCharacterSize(empt, 48);
    sfText_setColor(empt, (sfColor){51, 35, 30, 150});
    sfText_setPosition(empt, (sfVector2f){849, 371});
    return empt;
}

save_t *init_save_data(sfFont *font)
{
    save_t *data = malloc(sizeof(save_t));

    data->back = init_button_opt("Back", (sfVector2f){620, 180}, 35, font);
    data->back->is_clicked = is_back;
    data->saves = init_save(font);
    data->bg = init_spr_text("assets/img/options.png");
    data->msg = init_empty(font);
    return data;
}

void draw_savings(save_t *data, window_t *window)
{
    if (data->saves == NULL)
        return;
    for (int i = 0; data->saves[i] != NULL; i++)
        draw_btn(data->saves[i], window);
}

void display_load(window_t *window, game_t *game)
{
    save_t *data = init_save_data(window->fonts[2]);

    while (1) {
        sfRenderWindow_drawSprite(window->window, data->bg->sprite, NULL);
        sfRenderWindow_drawText(window->window, data->back->text, NULL);
        if (data->saves != NULL) {
            draw_savings(data, window);
        } else {
            sfRenderWindow_drawText(window->window, data->msg, NULL);
        }
        if (save_event(window, data, game) == 1) {
            destroy_save(data);
            return;
        }
        sfRenderWindow_display(window->window);
    }
}
