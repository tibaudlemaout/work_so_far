/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** task02
*/

#include "duo.h"

int my_putstr(char const *str)
{
    int i;

    while (*str != '\0') {
        my_putchar(*str);
        *str++;
    }
    return (0);
}
