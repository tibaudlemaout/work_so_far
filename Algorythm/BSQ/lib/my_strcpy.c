/*
** EPITECH PROJECT, 2022
** task01
** File description:
** my_strcpy
*/
#include "../bsq.h"

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++){
        dest[i] = src[i];
        my_putchar(dest[i]);
    }
    dest[i] = '\0';
    return (dest);
}
