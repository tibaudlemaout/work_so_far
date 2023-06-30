/*
** EPITECH PROJECT, 2022
** task01
** File description:
** my_strcpy
*/
#include "../include/minishell_1.h"

char *my_strcpy(char *dest, char const *src)
{
    int i;

    dest = malloc(sizeof(char *) * (my_strlen(src) + 1));
    for (i = 0; src[i] != '\0'; i++){
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
