/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-dante-tibaud.le-maout
** File description:
** dead_end
*/
#include "include/my.h"

void check(struct_t *data, int y, int x)
{
    int tmp = 0;

    if (y == 0 && x == 0)
        return;
    if (y == data->lines && x == (data->cols - 2))
        return;
    if (y < data->lines && data->map[y + 1][x] == '*')
        tmp = 1;
    if (y > 0 && data->map[y - 1][x] == '*')
        tmp = 1;
    if (x < data->cols && data->map[y][x + 1] == '*')
        tmp = 1;
    if (x > 0 && data->map[y][x - 1] == '*')
        tmp = 1;
    if (tmp == 0)
        data->map[y][x] = '@';
    return;
}

void find_dead_end(struct_t *data, int y)
{
    for (int x = 0; x < data->cols - 1; x++) {
        if (data->map[y][x] == '*')
            check(data, y, x);
    }
    return;
}
