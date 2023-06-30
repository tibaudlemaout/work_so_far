/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-dante-tibaud.le-maout
** File description:
** lib
*/
#include "include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return 0;
}

int my_strlen(char *str)
{
    int cmp = 0;

    for (cmp; str[cmp] != '\0'; cmp++);
    return (cmp);
}

char *my_strcpy(char *str)
{
    char *new;
    int i = 0;

    new = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (i; str[i]; i++)
        new[i] = str[i];
    new[i] = '\0';
    return (new);
}

int get_lines(char **tab)
{
    int cmp = 0;

    for (int i = 0; tab[i]; i++)
        cmp++;
    return (cmp);
}
