/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** for diagonal lines
*/
#include "include/stumper.h"

int check_left_line(global_t *global, char **map, char p)
{
    int win = 0;
    int x = 0;
    int y = 0;

    while (y <= global->size) {
        if (map[y][x] == p)
            win ++;
        x ++;
        y ++;
    }
    return (win);
}

int check_right_line(global_t *global, char **map, char p)
{
    int win = 0;
    int y = global->size;
    int x = 1;

    while (y >= 1) {
        if (map[y][x] == p)
            win ++;
        y --;
        x ++;
    }
    return (win);
}
