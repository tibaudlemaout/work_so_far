/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** task03
*/

#include "duo.h"

int my_strlen(char const *str)
{
    int nb_char = 0;

    while (*str != '\0') {
        *str++;
        nb_char++;
    }
    return (nb_char);
}
