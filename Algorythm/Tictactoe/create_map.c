/*
** EPITECH PROJECT, 2023
** tic_tac_toe
** File description:
** create_map
*/

#include "include/stumper.h"
#include <string.h>

static char *create_start_end_map(int size)
{
    char *map = NULL;

    map = malloc(sizeof(char) * size + 3);
    if (map == NULL) {
        exit(84);
    }
    map[0] = '+';
    for (int j = 1; j != size + 1; j++) {
        map[j] = '-';
        map[j + 1] = '+';
        map[j + 2] = '\0';
    }
    return (map);
}

static char *create_line(char *map, int size)
{
    for (int j = 1; j != size + 1; j++) {
        map[j] = ' ';
        map[j + 1] = '|';
        map[j + 2] = '\0';
    }
    return (map);
}

char **create_map(global_t *global)
{
    char **map = NULL;

    map = malloc(sizeof(char *) * global->size + 3);
    if (map == NULL) {
        exit(84);
    }
    map[0] = create_start_end_map(global->size);
    for (int i = 1; i != global->size + 1; i++) {
        map[i] = malloc(sizeof(char) * global->size + 3);
        if (map[i] == NULL) {
            exit(84);
        }
        map[i + 1] = create_start_end_map(global->size);
        map[i + 2] = NULL;
        map[i][0] = '|';
        map[i] = create_line(map[i], global->size);
    }
    map[0] = create_start_end_map(global->size);
    return (map);
}
