/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-tibaud.le-maout
** File description:
** option_5_seq
*/
#include "../include/fastatools.h"

static int is_seq_printed(char *tag, char **printed_tags, int count)
{
    for (int m = 0; m < count; m++) {
        if (strcmp(tag, printed_tags[m]) == 0) {
            return (1);
        }
    }
    return (0);
}

static void add_seq(const char *tag, char ***printed_tags, int *count)
{
    (*count)++;
    *printed_tags = realloc(*printed_tags, sizeof(char *) * (*count));
    (*printed_tags)[(*count) - 1] = strdup(tag);
    return;
}

static void collect_seq(char *tmp_mker, char ***k_mer, int *count)
{
    if (tmp_mker) {
        if (!is_seq_printed(tmp_mker, *k_mer, *count))
            add_seq(tmp_mker, k_mer, count);
    }
    return;
}

static char *copy_seq(char *tab, char *tmp, int i)
{
    int q = 0;
    int limit = (strlen(tab));
    int done = 0;

    tmp = malloc(sizeof(char) * (strlen(tab) + 1));
    while (i + 3 < limit ) {
        if ((tab[i] == 'T' && tab[i + 1] == 'G' && tab[i + 2] == 'A') ||
            (tab[i] == 'T' && tab[i + 1] == 'A' && tab[i + 2] == 'G') ||
            (tab[i] == 'T' && tab[i + 1] == 'A' && tab[i + 2] == 'A'))
            break;
        tmp[q] = tab[i];
        tmp[q + 1] = tab[i + 1];
        tmp[q + 2] = tab[i + 2];
        tmp[q + 3] = '\0';
        q += 3;
        i += 3;
    }
    if (i + 3 >= limit || q + 3 >= limit)
        return (NULL);
    return (tmp);
}

int get_sequence(char *tab, global_t *data, int size)
{
    char *tmp = NULL;
    int count = size;

    for (int i = 0; tab[i + 3]; i++) {
        if (tab[i] == 'A' && tab[i + 1] == 'T' && tab[i + 2] == 'G') {
            tmp = copy_seq(tab, tmp, i);
            collect_seq(tmp, &data->seq, &count);
            tmp = NULL;
        }
    }
    bubble_sort_strings(data->seq, count);
    return (count);
}
