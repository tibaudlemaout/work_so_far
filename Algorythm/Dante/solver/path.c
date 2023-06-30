/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-dante-tibaud.le-maout
** File description:
** path
*/
#include "include/my.h"

int find_path(struct_t *data)
{
    if (data->y > 0 && data->map[data->y - 1][data->x] == '*') {
    data->y--;
    data->map[data->y][data->x] = 'o';
    return 1;
    }
    if (data->x > 0 && data->map[data->y][data->x - 1] == '*') {
    data->x--;
    data->map[data->y][data->x] = 'o';
    return 1;
    }
    if (data->x < (data->cols) && data->map[data->y][data->x + 1] == '*') {
    data->x++;
    data->map[data->y][data->x] = 'o';
    return 1;
    }
    if (data->y < data->lines && data->map[data->y + 1][data->x] == '*') {
    data->y++;
    data->map[data->y][data->x] = 'o';
    return 1;
    }
}

void best_path(struct_t *data, int y, int x)
{
    int tmp = 0;

    while (data->y > 0 || data->x > 0) {
        if (find_path(data) != 1) {
            data->map[0] = "no solution found";
            return;
        }
    }
    return;

}
