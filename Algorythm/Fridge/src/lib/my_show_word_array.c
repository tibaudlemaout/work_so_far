/*
** EPITECH PROJECT, 2022
** my_show_word_array.c
** File description:
** task03
*/

#include "duo.h"
#include <stdlib.h>

int my_show_word_array(char * const *tab)
{
    for (int i = 0 ; tab[i] != 0 ; i++) {
        my_putstr(tab[i]);
        my_putstr("\n");
    }
    return (0);
}
