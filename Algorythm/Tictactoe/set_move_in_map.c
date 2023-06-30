/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** display the moves
*/
#include "include/stumper.h"

static char **fill_map(int *pos, char **map, char p)
{
    int x = pos[0] + 1;
    int y = pos[1] + 1;

    map[y][x] = p;
    return (map);
}

char **display_move(global_t *global, int *pos, char **map)
{
    char p;
    int x = pos[0] + 1;
    int y = pos[1] + 1;

    if (global->turn == 1)
        p = global->p1;
    else
        p = global->p2;
    if (map[y][x] == ' ') {
        map = fill_map(pos, map, p);
    } else {
        pos = get_attack(global);
        map = display_move(global, pos, map);
        return (map);
    }
    return (map);
}
