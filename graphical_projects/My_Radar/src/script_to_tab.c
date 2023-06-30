/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** script_to_tab
*/
#include "../include/radar.h"

int count_lines(const char *buff)
{
    int lines = 0;
    int index = 0;

    while (buff[index] != '\0') {
        if (buff[index] == '\n') {
            lines ++;
        }
        index ++;
    }
    lines ++;
    return (lines);
}

int count_cols(const char *buff)
{
    int cols = 0;
    int index = 0;

    while (buff[index] != '\n') {
        cols ++;
        index ++;
    }
    return (cols);
}

int verif_tab(const char *buff)
{
    int index = 0;

    while (buff[index] != '\0') {
        if (buff[index] != 'A' && buff[index] != 'T' &&
            buff[index] != ' ' && buff[index] != '\n' &&
            (buff[index] < '0' || buff[index] > '9')) {
            my_printf("Script contains unwanted characters.\n");
            return (84);
        }
        index ++;
    }
    return (0);
}

void cpy(const char *buff, global_t *data)
{
    data->layers = count_lines(buff);
    data->columns = count_cols(buff);
    int i = 0;
    int j = 0;

    data->tab = malloc (sizeof(char *) * (data->layers));
    for (int q = 0; q < data->layers; q ++)
        data->tab[q] = malloc(sizeof(char) * (data->columns));
    for (int k = 0; buff[k] != '\0'; k ++) {
        data->tab[i][j] = buff[k];
        j ++;
        if (buff[k] == '\n') {
            i ++;
            j = 0;
        }
    }
    return;
}
