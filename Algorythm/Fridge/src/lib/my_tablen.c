/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_tablen
*/

#include "duo.h"

int my_tablen(char **tab)
{
    int len = 0;

    while (tab[len] != 0) {
        len++;
    }
    return (len);
}
