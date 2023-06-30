/*
** EPITECH PROJECT, 2023
** base_layout
** File description:
** requirement
*/
#include "include/fastatools.h"
#include "stdbool.h"

static int is_alphanum(char c)
{
    if ((c <= 122 && c >= 97) || (c <= 90 && c >= 65) ||
        (c <= '9' && c >= '0'))
        return (1);
    return (0);
}

char *my_strcapitalize_synthesis(char *str)
{
    if (str[0] >= 97 && str[0] <= 122)
        str[0] = str[0] - 32;
    for (int i = 1; str[i]; i++) {
        if (is_alphanum(str[i - 1]) == 0 && (str[i] >= 97 && str[i] <= 122))
            str[i] = str[i] - 32;
    }
    return (str);
}
