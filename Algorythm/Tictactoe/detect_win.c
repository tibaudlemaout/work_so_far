/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** detect when you win
*/
#include "include/stumper.h"

static int check_x_line(global_t *global, char **map, int y)
{
    int win = 0;
    int x = 0;
    char p_char;

    if (global->turn == 1)
        p_char = global->p1;
    else
        p_char = global->p2;
    while (x <= global->size + 1) {
        if (map[y][x] == p_char)
            win ++;
        x ++;
    }
    return (win);
}

static int check_y_line(global_t *global, char **map, int x)
{
    int win = 0;
    int y = 1;
    char p_char;

    if (global->turn == 1)
        p_char = global->p1;
    else
        p_char = global->p2;
    while (y <= global->size + 1) {
        if (map[y][x] == p_char)
            win ++;
        y ++;
    }
    return (win);
}

static int diagonal_line(global_t *global, char **map, int x, int y)
{
    int win = 0;
    char p_char;

    if (global->turn == 1)
        p_char = global->p1;
    else
        p_char = global->p2;
    if (x == y) {
        win = check_left_line(global, map, p_char);
        if (win == global->size)
            return (win);
    }
    if ((x + y - 1) == global->size) {
        win = check_right_line(global, map, p_char);
        if (win == global->size)
            return (win);
    }
    return (win);
}

int win_cond(global_t *global, char **map, int *pos)
{
    int end = 0;

    end = check_x_line(global, map, pos[1] + 1);
    if (end == global->size) {
        printf("Player %i won !\n", global->turn);
        return (1);
    }
    end = check_y_line(global, map, pos[0] + 1);
    if (end == global->size) {
        printf("Player %i won !\n", global->turn);
        return (1);
    }
    end = diagonal_line(global, map, pos[0] + 1, pos[1] + 1);
    if (end == global->size) {
        printf("Player %i won !\n", global->turn);
        return (1);
    }
    return (0);
}
