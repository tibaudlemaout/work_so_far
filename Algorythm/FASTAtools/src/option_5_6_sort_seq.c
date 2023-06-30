/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-tibaud.le-maout
** File description:
** option_5_6_sort_seq
*/
#include "../include/fastatools.h"

static void sort_sequence_cont(global_t *data, int q, int i)
{
    int size1 = 0;
    int size2 = 0;

    while (data->tab[q]) {
        if (data->tab[q][0] == '>')
            break;
        size1 = strlen(data->tab[i]);
        size2 = strlen(data->tab[q]);
        data->tab[i] = realloc(data->tab[i], sizeof(char) * (size1 + size2));
        data->tab[i] = strcat(data->tab[i], data->tab[q]);
        q++;
    }
    return;
}

void sort_sequence(global_t *data)
{
    int size1 = 0;
    int size2 = 0;
    int q = 0;

    for (int i = 0; data->tab[i + 1]; i++) {
        q = i + 1;
        if (data->tab[i][0] != '>' && data->tab[q][0] != '>')
            sort_sequence_cont(data, q, i);
    }
    return;
}
