/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-tibaud.le-maout
** File description:
** option_3_rev
*/
#include "../include/fastatools.h"

char *rev_str(char *str)
{
    int i = 0;
    int j = strlen(str);
    char *tmp = NULL;

    tmp = malloc(sizeof(char) * (j));
    while (j != 0) {
        tmp[i] = str[j - 1];
        i++;
        j--;
    }
    tmp[i + 1] = '\0';
    str = strdup(tmp);
    free(tmp);
    return (str);
}
