/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-tibaud.le-maout
** File description:
** get_input
*/
#include "../include/fastatools.h"

void get_input(global_t *data)
{
    char *buff = NULL;
    size_t size = 10;
    int i = 0;

    while (getline(&buff, &size, stdin) != -1) {
        i++;
        data->tab = realloc(data->tab, sizeof(char *) * (i));
        data->tab[i - 1] = strdup(buff);
    }
    data->tab[i] = NULL;
    return;
}
