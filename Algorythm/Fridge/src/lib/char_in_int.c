/*
** EPITECH PROJECT, 2023
** duo
** File description:
** char_in_int
*/

#include "duo.h"

int char_in_int(char *str)
{
    int nb = 0;
    int len = my_strlen(str);
    int div = 1;

    for (int loop = len; loop > 0; loop--) {
        nb = nb + (str[loop - 1] - 48) * div;
        div = div * 10;
    }
    return (nb);
}

int char_in_int_modif(char *str)
{
    int nb = 0;
    int len = my_strlen(str) - 1;
    int div = 1;

    for (int loop = len; loop > 0; loop--) {
        nb = nb + (str[loop - 1] - 48) * div;
        div = div * 10;
    }
    return (nb);
}
