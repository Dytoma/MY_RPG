/*
** EPITECH PROJECT, 2024
** src
** File description:
** assistance
*/

#include "rpg.h"

sfVector2f normalize(sfVector2f vector)
{
    float length = sqrt(vector.x * vector.x + vector.y * vector.y);

    if (length != 0) {
        vector.x /= length;
        vector.y /= length;
    }
    return vector;
}

float calc_distance(sfVector2f point1, sfVector2f point2)
{
    return sqrt(pow(point1.x - point2.x, 2.0) + pow(point1.y - point2.y, 2.0));
}
