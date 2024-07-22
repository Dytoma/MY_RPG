/*
** EPITECH PROJECT, 2024
** map
** File description:
** functions to manage the map
*/
#include "../include/rpg.h"

static char **str_to_word_array(char *str, char *delimiters)
{
    char *temp_str = strdup(str);
    char *token = NULL;
    char **words = NULL;
    int count = 0;

    token = strtok(temp_str, delimiters);
    for (; token != NULL; count++)
        token = strtok(NULL, delimiters);
    words = malloc(sizeof(char *) * (count + 1));
    if (words == NULL)
        return NULL;
    token = strtok(strdup(str), delimiters);
    for (int i = 0; token != NULL; i++) {
        words[i] = strdup(token);
        token = strtok(NULL, delimiters);
    }
    free(temp_str);
    return words;
}

sfVector2f get_player_position(char **map)
{
    int i = 0;
    int j = 0;

    while (map[i] != NULL) {
        if (map[i][j] == '\0') {
            i++;
            j = 0;
        }
        if (map[i][j] == 'P')
            return (sfVector2f){(float)i, (float)j};
        j++;
    }
    return (sfVector2f){-1.0, -1.0};
}

char **load_map(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = NULL;
    char **tab = NULL;
    struct stat st;

    if (fd == -1)
        return NULL;
    stat(filepath, &st);
    buffer = malloc(st.st_size + 1);
    buffer[st.st_size] = '\0';
    read(fd, buffer, st.st_size);
    tab = str_to_word_array(buffer, "\n\0");
    free(buffer);
    close(fd);
    return tab;
}
