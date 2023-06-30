/*
** EPITECH PROJECT, 2023
** check.c
** File description:
** check
*/

#include "../include/struct.h"
#include "../include/stumper.h"
#include "../include/lib.h"
#include <string.h>

int check_for_spaces(char *str)
{
    size_t nb = 0;

    for (int i = 0; i != strlen(str); i++) {
        if (str[i] == ' ')
            nb++;
    }
    if (nb == strlen(str))
        return (1);
    return (0);
}
