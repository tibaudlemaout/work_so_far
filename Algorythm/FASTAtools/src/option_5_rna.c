/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-tibaud.le-maout
** File description:
** option_5_rna
*/
#include "../include/fastatools.h"

static char *complement_link(char *rna, int q)
{
    if (rna[q] == 'a' || rna[q] == 'A') {
        rna[q] = 'T';
        return (rna);
    }
    if (rna[q] == 't' || rna[q] == 'T') {
        rna[q] = 'A';
        return (rna);
    }
    if (rna[q] == 'c' || rna[q] == 'C') {
        rna[q] = 'G';
        return (rna);
    }
    if (rna[q] == 'g' || rna[q] == 'G') {
        rna[q] = 'C';
        return (rna);
    }
    if (rna[q] == 'n')
        rna[q] = 'N';
    return (rna);
}

char *get_rna(char *rna, global_t *data)
{
    data->string = malloc(sizeof(char) * (strlen(rna) + 1));
    int i = 0;

    for (int q = 0; rna[q]; q++) {
        if (rna[q] == '\n')
            rna[q] = '\0';
        if (rna[0] != '>')
            rna = complement_link(rna, q);
        if (rna[q] == 'A' || rna[q] == 'T' || rna[q] == 'C' ||
            rna[q] == 'G' || rna[q] == 'N') {
            data->string[i] = rna[q];
            i++;
        }
    }
    data->string[i] = '\0';
    rna = strdup(data->string);
    return (rna);
}
