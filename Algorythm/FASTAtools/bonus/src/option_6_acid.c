/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-tibaud.le-maout
** File description:
** option_6_acid
*/
#include "../include/fastatools.h"

static int is_acid_printed(char *tag, char **printed_tags, int count)
{
    for (int m = 0; m < count; m++) {
        if (strcmp(tag, printed_tags[m]) == 0) {
            return (1);
        }
    }
    return (0);
}

static void add_acid(const char *tag, char ***printed_tags, int *count)
{
    (*count)++;
    *printed_tags = realloc(*printed_tags, sizeof(char *) * (*count));
    (*printed_tags)[(*count) - 1] = strdup(tag);
    return;
}

static void collect_acid(char *tmp_mker, char ***k_mer, int *count)
{
    if (tmp_mker) {
        if (!is_acid_printed(tmp_mker, *k_mer, *count))
            add_acid(tmp_mker, k_mer, count);
    }
    return;
}

static char *get_acid(char *tab, char *tmp)
{
    tmp = malloc(sizeof(char) * (strlen(tab) + 1));
    int q = 0;

    for (int i = 0; i != strlen(tab) ; i += 3) {
        tmp[q] = identify_acid(tab[i], tab[i + 1], tab[i + 2]);
        q++;
    }
    tmp[q] = '\0';
    return (tmp);
}

void get_amino_acid(global_t *data, int count)
{
    char **acids = NULL;
    char *tmp = NULL;
    int size = 0;

    for (int i = 0; i < count; i++) {
        tmp = get_acid(data->seq[i], tmp);
        collect_acid(tmp, &acids, &size);
    }
    for (int i = 0; i < count; i++) {
        printf("Codon:%s contains these acids:%s\n", data->seq[i], acids[i]);
    }
    bubble_sort_strings(acids, size);
    printf("<------------------------------>\n");
    printf("Here are all the Codon's acid, in order\n");
    printf("\033[1;32m");
    for (int i = 0; i < count; i++) {
        printf("%s\n", acids[i]);
    }
    printf("\033[0;37m");
    return;
}
