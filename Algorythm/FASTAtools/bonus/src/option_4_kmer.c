/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-tibaud.le-maout
** File description:
** option_4_kmer
*/
#include "../include/fastatools.h"

static int is_kmer_printed(char *tag, char **printed_tags, int count)
{
    for (int m = 0; m < count; m++) {
        if (strcmp(tag, printed_tags[m]) == 0) {
            return (1);
        }
    }
    return (0);
}

static void add_kmers(const char *tag, char ***printed_tags, int *count)
{
    (*count)++;
    *printed_tags = realloc(*printed_tags, sizeof(char *) * (*count));
    (*printed_tags)[(*count) - 1] = strdup(tag);
    return;
}

static void collect_kmer(char *tmp_mker, char ***k_mer, int *count)
{
    if (!is_kmer_printed(tmp_mker, *k_mer, *count)) {
        add_kmers(tmp_mker, k_mer, count);
    }
    return;
}

static char *save_kmer(char *tmp, char *tab, int i, int k)
{
    int j = 0;

    while (j < k) {
        tmp[j] = tab[i];
        j++;
        i++;
    }
    tmp[j] = '\0';
    return (tmp);
}

int find_k_mers(char *tab, global_t *data, int size)
{
    int count = size;
    char *tmp_kmer = NULL;
    int limit = strlen(tab);

    tmp_kmer = malloc(sizeof(char) * (data->k + 1));
    for (int i = 0; (i + data->k) <= limit; i++) {
        tmp_kmer = save_kmer(tmp_kmer, tab, i, data->k);
        printf("\033[0;32m");
        printf("%s\n", tmp_kmer);
        collect_kmer(tmp_kmer, &data->seq, &count);
    }
    bubble_sort_strings(data->seq, count);
    printf("\033[0;37m");
    return (count);
}
