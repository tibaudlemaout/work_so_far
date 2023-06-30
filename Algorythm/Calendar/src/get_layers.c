/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-calendar-tibaud.le-maout
** File description:
** get_layers
*/
#include "../include/calendar.h"

int get_tab_layers(char **tab)
{
    int layers = 0;

    if (tab == NULL)
        return (layers);
    for (int i = 1; tab[i]; i++)
        layers++;
    return (layers);
}
