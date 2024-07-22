/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-dytoma.batogouma
** File description:
** init_doors
*/

#include "rpg.h"

static void add_door(char **map, int i, obstacle_t **list)
{
    sfFloatRect area = {0.0, 0.0, 32.0, 32.0};

    for (int j = 0; map[i][j] != '\0'; j++) {
        if (map[i][j] == '+') {
            area.top = (i - 1) * 32.0;
            area.left = (j) * 32.0;
            add_node(list, area);
        }
    }
}

obstacle_t *init_doors(const char *filemap)
{
    char **map = open_file(filemap);
    obstacle_t *list = NULL;

    for (int i = 0; map[i] != NULL; i++) {
        add_door(map, i, &list);
    }
    destroy_arr(map);
    return list;
}

int check_door(float x, float y, obstacle_t *doors)
{
    obstacle_t *last = doors;
    int n = 1;

    while (last != NULL) {
        if (sfFloatRect_contains(last->area, x, y))
            return n;
        last = last->next;
        n++;
    }
    return -1;
}
