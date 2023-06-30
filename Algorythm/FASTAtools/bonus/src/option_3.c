/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-tibaud.le-maout
** File description:
** option_3
*/
#include "../include/fastatools.h"

static char *complement_link(char *str, int q)
{
    if (str[q] == 'a' || str[q] == 'A') {
        str[q] = 'T';
        return (str);
    }
    if (str[q] == 't' || str[q] == 'T') {
        str[q] = 'A';
        return (str);
    }
    if (str[q] == 'c' || str[q] == 'C') {
        str[q] = 'G';
        return (str);
    }
    if (str[q] == 'g' || str[q] == 'G') {
        str[q] = 'C';
        return (str);
    }
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
            str = complement_link(str, q);
        if (str[q] == 'A' || str[q] == 'T' || str[q] == 'C' ||
            str[q] == 'G' || str[q] == 'N') {
            data->string[i] = str[q];
            i++;
        }
    }
    data->string[i] = '\0';
    return;
}

static void option_3_cont(global_t *data)
{
    for (int i = 0; data->tab[i]; i++) {
        if (data->tab[i][0] == '>') {
            printf("This is the original strand of DNA:\n");
            printf("\033[0;31m");
            printf("%s\n", data->tab[i + 1]);
            printf("\033[0;37m");
            printf("And here is the complementing strand:\n");
            printf("\033[0;32m");
            data->tab[i + 1] = rev_str(data->tab[i + 1]);
            printf("%s\n", data->tab[i + 1]);
            printf("\033[0;37m");
        }
    }
    printf("And here is the final result:\n");
    for (int i = 0; data->tab[i]; i++) {
        if (data->tab[i][0] == '>') {
            printf("\033[0;37m");
            printf("%s\n\033[1;32m%s\n", data->tab[i], data->tab[i + 1]);
        }
    }
    return;
}

void option_3(global_t *data)
{
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
    option_3_cont(data);
    printf("\033[0;37m");
    return;
}
