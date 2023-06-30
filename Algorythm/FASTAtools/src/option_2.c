/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-tibaud.le-maout
** File description:
** option_2
*/
#include "../include/fastatools.h"

static char *change_to_rna(char *str, int q)
{
    if (str[q] == 'a')
        str[q] = 'A';
    if (str[q] == 't' || str[q] == 'T')
        str[q] = 'U';
    if (str[q] == 'c')
        str[q] = 'C';
    if (str[q] == 'g')
        str[q] = 'G';
    if (str[q] == 'n')
        str[q] = 'N';
    return (str);
}

static void clean_string(char *str, global_t *data)
{
    data->string = malloc(sizeof(char) * (strlen(str) + 1));
    int i = 0;

    for (int q = 0; str[q]; q++) {
        while (str[q] == ' ' )
            q++;
        if (str[q] == '\n')
            str[q] = '\0';
        if (str[0] != '>')
            str = change_to_rna(str, q);
        if (str[q] == 'A' || str[q] == 'U' || str[q] == 'C' ||
            str[q] == 'G' || str[q] == 'N') {
            data->string[i] = str[q];
            i++;
        }
    }
    data->string[i] = '\0';
    return;
}

void option_2(global_t *data)
{
    for (int i = 0; data->tab[i]; i++) {
        if (data->tab[i][0] == '>') {
            clean_sequence_name(data->tab[i], data);
            data->tab[i] = strdup(data->string);
        } else {
            clean_string(data->tab[i], data);
            data->tab[i] = strdup(data->string);
        }
        if (i == 0)
            printf("%s\n", data->tab[i]);
        if (data->tab[i][0] == '>' && i != 0)
            printf("\n%s\n", data->tab[i]);
        if (data->tab[i][0] != '>')
            printf("%s", data->tab[i]);
    }
    putchar('\n');
    return;
}
