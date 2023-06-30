/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-tibaud.le-maout
** File description:
** option_4
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

static void option_4_cont(global_t *data, int count)
{
    for (int i = 0; data->tab[i]; i++) {
        if (data->tab[i][0] == '>') {
            printf("Searching for all K-mers in:\n\033[0;31m%s\n", data->tab[i + 1]);
            count = find_k_mers(data->tab[i + 1], data, count);
            printf("\033[0;37m<------------------------------>\n");
        }
    }
    printf("Here are all the K-mers found, in order:\n");
    printf("\033[1;32m");
    for (int n = 0; n < count; n++)
        printf("%s\n", data->seq[n]);
    printf("\033[0;37m");
    return;
}

void option_4(global_t *data)
{
    int count = 0;

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
    option_4_cont(data, count);
    return;
}
