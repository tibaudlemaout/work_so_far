/*
** EPITECH PROJECT, 2023
** utils
** File description:
** utils
*/

#include "duo.h"

int is_int(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 1;
    }
    return 0;
}

int is_int_modif(char *str)
{
    for (int i = 0; str[i] != '\n'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 1;
    }
    return 0;
}
