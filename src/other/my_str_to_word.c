/*
** EPITECH PROJECT, 2024
** B-PSU-200-TLS-2-1-bsminishell2-dytoma.batogouma
** File description:
** my_str_to_word
*/

#include "../include/player.h"

int str_has_char(char *delim, char c)
{
    int len = strlen(delim);

    for (int i = 0; i <= len; i++) {
        if (delim[i] == c) {
            return 0;
        }
    }
    return 1;
}

int count_words(char *str, char *delim)
{
    int n = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str_has_char(delim, str[i]) == 1 &&
            str_has_char(delim, str[i + 1]) == 0) {
                n++;
        }
    }
    return n;
}

void destroy_arr(char **arr)
{
    if (arr == NULL)
        return;
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
    return;
}

static void fill_2d_arr(char *str, char *delim, char *temp, char **arr)
{
    int n = 0;

    if (str_has_char(delim, str[0]) == 1) {
        arr[n] = strdup(temp);
        n++;
    }
    for (int i = 0; i < strlen(str); i++) {
        if (temp[i] == 0 && temp[i + 1] != 0 && str[i + 1] != '\0') {
            arr[n] = strdup(temp + i + 1);
            n++;
        }
    }
    arr[n] = NULL;
}

char **my_str_to_word(char *str, char *delim)
{
    char *temp = strdup(str);
    const int count = count_words(str, delim);
    char **arr = NULL;
    int n = 0;

    if (count == 0)
        return NULL;
    arr = malloc(sizeof(char *) * (count + 1));
    for (int i = 0; temp[i] != '\0'; i++) {
        if (str_has_char(delim, temp[i]) == 0)
            temp[i] = 0;
    }
    fill_2d_arr(str, delim, temp, arr);
    free(temp);
    return arr;
}
