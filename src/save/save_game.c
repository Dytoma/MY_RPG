/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-dytoma.batogouma
** File description:
** save_game
*/

#include "rpg.h"

static char *get_save_name(void)
{
    if (access("save1.rpg", F_OK) == -1) {
        return strdup("save1.rpg");
    } else if (access("save2.rpg", F_OK) == -1) {
        return strdup("save2.rpg");
    } else {
        return strdup("save3.rpg");
    }
}

char *get_content(char const *file)
{
    int fp = open(file, O_RDONLY);
    struct stat sb;
    char *content = NULL;

    if (fp == -1)
        return NULL;
    if (stat(file, &sb) == -1)
        return NULL;
    content = malloc(sizeof(char) * (sb.st_size + 1));
    read(fp, content, sb.st_size);
    content[sb.st_size] = '\0';
    close(fp);
    return content;
}

void save_game(player_t *player)
{
    char *filename = get_save_name();
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC,
        S_IRUSR | S_IRGRP | S_IROTH);

    free(filename);
    if (fd == -1)
        return;
    dprintf(fd, "Life: %d\n", player->energy);
    dprintf(fd, "X: %f Y: %f\n", player->position.x, player->position.y);
    dprintf(fd, "Weapon_ids");
    for (int i = 0; player->inv->weapons[i] != NULL; i++)
        if (player->inv->weapons[i]->state)
            dprintf(fd, ":%d", player->inv->weapons[i]->id);
    dprintf(fd, "\n");
    close(fd);
}

static void fill_weapons(char **key_val, inventory_t *inv)
{
    for (int i = 1; key_val[i] != NULL; i++) {
        (inv->weapons[atoi(key_val[i])])->state = sfTrue;
    }
    return;
}

void load_save(player_t *player, char *file)
{
    char *content = get_content(file);
    char **parse = my_str_to_word(content, "\n");
    char **key_val = NULL;

    for (int i = 0; parse[i] != NULL; i++) {
        key_val = my_str_to_word(parse[i], " :");
        if (strcmp(key_val[0], "Life") == 0)
            player->energy = atoi(key_val[1]);
        if (strcmp(key_val[0], "X") == 0) {
            player->position.x = atof(key_val[1]);
            player->position.y = atof(key_val[3]);
        }
        if (strcmp(key_val[0], "Weapon_ids") == 0)
            fill_weapons(key_val, player->inv);
        destroy_arr(key_val);
    }
    destroy_arr(parse);
    free(content);
}
