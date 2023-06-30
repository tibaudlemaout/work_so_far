/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-tibaud.le-maout
** File description:
** option_5
*/
#include "../include/fastatools.h"

static char *change_to_caps(char *str, int q)
{
    if (str[q] == 'a')
        str[q] = 'A';
    if (str[q] == 't')
        str[q] = 'T';
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
            str = change_to_caps(str, q);
        if (str[q] == 'A' || str[q] == 'T' || str[q] == 'C' ||
            str[q] == 'G' || str[q] == 'N') {
            data->string[i] = str[q];
            i++;
        }
    }
    data->string[i] = '\0';
    return;
}

static void option_5_cont(global_t *data, char *rna, int count)
{
    for (int i = 0; data->tab[i]; i++) {
        if (data->tab[i][0] == '>') {
            count = get_sequence(data->tab[i + 1], data, count);
            rna = strdup(data->tab[i + 1]);
            rna = get_rna(rna, data);
            rna = rev_str(rna);
            count = get_sequence(rna, data, count);
        }
    }
    for (int n = 0; n < count; n++) {
        printf("%s\n", data->seq[n]);
    }
    return;
}

void option_5(global_t *data)
{
    int count = 0;
    char *rna = NULL;

    for (int i = 0; data->tab[i]; i++) {
        if (data->tab[i][0] == '>') {
            clean_sequence_name(data->tab[i], data);
            data->tab[i] = strdup(data->string);
        } else {
            clean_string(data->tab[i], data);
            data->tab[i] = strdup(data->string);
        }
    }
    sort_sequence(data);
    option_5_cont(data, rna, count);
    return;
}
