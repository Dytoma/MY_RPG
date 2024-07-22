/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-dytoma.batogouma
** File description:
** handle_collisions
*/
#include "../include/player.h"

void add_node(obstacle_t **head_ref, sfFloatRect area)
{
    obstacle_t *new_node = malloc(sizeof(obstacle_t));
    obstacle_t *last = *head_ref;

    new_node->area = malloc(sizeof(sfFloatRect));
    new_node->area->height = area.height;
    new_node->area->top = area.top;
    new_node->area->width = area.width;
    new_node->area->left = area.left;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

char **open_file(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = NULL;
    struct stat st;
    char **map = NULL;

    if (fd == -1)
        return NULL;
    stat(filepath, &st);
    buffer = malloc(st.st_size + 1);
    read(fd, buffer, st.st_size);
    buffer[st.st_size] = '\0';
    map = my_str_to_word(buffer, "\n\t");
    close(fd);
    free(buffer);
    return map;
}

void delete_collisions(obstacle_t *list)
{
    obstacle_t *current;
    obstacle_t *next;

    if (list == NULL)
        return;
    current = list->next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

static void add_collision(char **map, int i, obstacle_t **list)
{
    sfFloatRect area = {0.0, 0.0, 32.0, 32.0};

    for (int j = 0; map[i][j] != '\0'; j++) {
        if (map[i][j] == '#') {
            area.top = (i + 1) * 32.0;
            area.left = (j + 1.5) * 32.0;
            add_node(list, area);
        }
    }
}

obstacle_t *init_collisions(const char *filemap)
{
    char **map = open_file(filemap);
    obstacle_t *list = NULL;

    for (int i = 0; map[i] != NULL; i++) {
        add_collision(map, i, &list);
    }
    destroy_arr(map);
    return list;
}

sfBool check_position(float x, float y, obstacle_t *obstacles)
{
    obstacle_t *last = obstacles;

    while (last != NULL) {
        if (sfFloatRect_contains(last->area, x, y))
            return sfTrue;
        last = last->next;
    }
    return sfFalse;
}
