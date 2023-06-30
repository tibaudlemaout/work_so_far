/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** for freeing the map
*/
#include "include/stumper.h"

void free_map(char **map)
{
    int i = 0;

    while (map[i] != NULL) {
        free(map[i]);
        i ++;
    }
    return;
}
