/*
** EPITECH PROJECT, 2023
** tictactoe
** File description:
** draw_cond
*/

#include <stddef.h>

static int find_space(char *line)
{
    for (int j = 1; line[j + 1] != '\0'; j++) {
        if (line[j] == ' ') {
            return (1);
        }
    }
    return (0);
}

int draw_cond(char **map)
{
    for (int i = 1; map[i + 1] != NULL; i++) {
        if (find_space(map[i]) == 1) {
            return (0);
        }
    }
    return (1);
}
