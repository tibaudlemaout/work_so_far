/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-tibaud.le-maout
** File description:
** option_6_acid_list
*/
#include "../include/fastatools.h"

static char identify_acid_cont3(char *acid, char ret)
{
    if (strcmp(acid, "ACT") == 0 || strcmp(acid, "ACC") == 0 ||
        strcmp(acid, "ACA") == 0 || strcmp(acid, "ACG") == 0)
        ret = 'T';
    if (strcmp(acid, "GTT") == 0 || strcmp(acid, "GTC") == 0 ||
        strcmp(acid, "GTA") == 0 || strcmp(acid, "GTG") == 0)
        ret = 'V';
    if (strcmp(acid, "TGG") == 0)
        ret = 'W';
    if (strcmp(acid, "TAT") == 0 || strcmp(acid, "TAC") == 0)
        ret = 'Y';
    return (ret);
}

static char identify_acid_cont2(char *acid, char ret)
{
    if (strcmp(acid, "AAT") == 0 || strcmp(acid, "AAC") == 0)
        ret = 'N';
    if (strcmp(acid, "CCT") == 0 || strcmp(acid, "CCC") == 0 ||
        strcmp(acid, "CCA") == 0 || strcmp(acid, "CCG") == 0)
        ret = 'P';
    if (strcmp(acid, "CAA") == 0 || strcmp(acid, "CAG") == 0)
        ret = 'Q';
    if (strcmp(acid, "AGA") == 0 || strcmp(acid, "AGG") == 0 ||
        strcmp(acid, "CGT") == 0 || strcmp(acid, "CGC") == 0 ||
        strcmp(acid, "CGA") == 0 || strcmp(acid, "CGG") == 0)
        ret = 'R';
    if (strcmp(acid, "TCT") == 0 || strcmp(acid, "TCC") == 0 ||
        strcmp(acid, "TCA") == 0 || strcmp(acid, "TCG") == 0 ||
        strcmp(acid, "AGT") == 0 || strcmp(acid, "AGC") == 0)
        ret = 'S';
    ret = identify_acid_cont3(acid, ret);
    return (ret);
}

static char identify_acid_cont(char *acid, char ret)
{
    if (strcmp (acid, "GGT") == 0 || strcmp (acid, "GGC") == 0 ||
        strcmp (acid, "GGA") == 0 || strcmp (acid, "GGG") == 0)
        ret = 'G';
    if (strcmp (acid, "CAT") == 0 || strcmp (acid, "CAC") == 0)
        ret = 'H';
    if (strcmp(acid, "ATT") == 0 || strcmp(acid, "ATC") == 0 ||
        strcmp(acid, "ATA") == 0)
        ret = 'I';
    if (strcmp(acid, "AAA") == 0 || strcmp(acid, "AAG") == 0)
        ret = 'K';
    if (strcmp(acid, "TTA") == 0 || strcmp(acid, "TTG") == 0 ||
        strcmp(acid, "CTT") == 0 || strcmp(acid, "CTC") == 0 ||
        strcmp(acid, "CTA") == 0 || strcmp(acid, "CTG") == 0)
        ret = 'L';
    if (strcmp(acid, "ATG") == 0)
        ret = 'M';
    ret = identify_acid_cont2(acid, ret);
    return (ret);
}

char identify_acid(char a, char b, char c)
{
    char *acid = malloc(sizeof(char) * 4);
    char ret = 'X';
    acid[0] = a;
    acid[1] = b;
    acid[2] = c;

    if (strcmp (acid, "GCT") == 0 || strcmp (acid, "GCC") == 0 ||
        strcmp (acid, "GCA") == 0 || strcmp (acid, "GCG") == 0)
        ret = 'A';
    if (strcmp (acid, "TGT") == 0 || strcmp (acid, "TGC") == 0)
        ret = 'C';
    if (strcmp (acid, "GAT") == 0 || strcmp (acid, "GAC") == 0)
        ret = 'D';
    if (strcmp (acid, "GAA") == 0 || strcmp (acid, "GAG") == 0)
        ret = 'E';
    if (strcmp (acid, "TTT") == 0 || strcmp (acid, "TTC") == 0)
        ret = 'F';
    ret = identify_acid_cont(acid, ret);
    return (ret);
}
