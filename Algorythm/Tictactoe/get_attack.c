/*
** EPITECH PROJECT, 2023
** tik_tac_toe
** File description:
** get_attack
*/

#include "include/stumper.h"
#include <string.h>
#include <ctype.h>

static char **set_array(int save_i, char *line)
{
    int nb_separator = 0;
    char **array = NULL;

    array = malloc(sizeof(char *) * 3);
    if (array == NULL) {
    }
    array[0] = malloc(sizeof(char) * save_i);
    array[1] = malloc(sizeof(char) * ((strlen(line) - save_i) + 1));
    if (array == NULL || array[0] == NULL || array[1] == NULL) {
        exit(84);
    }
    nb_separator = 0;
    for (int i = 0, i_save = 0; line[i] != '\n'; i++, i_save++) {
        if (line[i] == ',') {
            nb_separator++;
            i_save = 0;
        }
        array[nb_separator][i_save] = line[i];
    }
    return (array);
}

static int *get_pos(int save_i, char *line, int *pos, global_t *global)
{
    int nb_separator = 0;
    char **array = NULL;

    array = set_array(save_i, line);
    pos = malloc(sizeof(int) * 2);
    if (pos == NULL) {
        exit(84);
    }
    pos[0] = my_get_nbr(array[0]);
    pos[1] = my_get_nbr(array[1]);
    free(array[0]);
    free(array[1]);
    free(array[2]);
    free(array);
    if (pos[0] > global->size - 1 || pos[1] > global->size - 1) {
        pos = get_attack(global);
    }
    return (pos);
}

static char *get_line(int turn)
{
    char *line = NULL;
    size_t len = 0;

    if (turn == 1) {
        write(1, "Player 1> ", strlen("Player 1> "));
    } else {
        write(1, "Player 2> ", strlen("Player 2> "));
    }
    write(1, "\e[3m", my_strlen("\e[3m"));
    getline(&line, &len, stdin);
    write(1, "\e[0m", my_strlen("\e[0m"));
    return (line);
}

int *get_attack(global_t *global)
{
    char *line = NULL;
    int *pos = NULL;
    int nb_separator = 0;
    int save_i = 0;

    line = get_line(global->turn);
    for (int i = 0; line[i] != '\n'; i++) {
        if (line[i] == ',') {
            nb_separator++;
            save_i = i;
        }
        if (nb_separator > 1 || (line[i] != ',' && isdigit(line[i]) == 0)) {
            pos = get_attack(global);
            return (pos);
        }
    }
    pos = get_pos(save_i, line, pos, global);
    free(line);
    return (pos);
}
