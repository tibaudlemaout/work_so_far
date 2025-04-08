/*
** EPITECH PROJECT, 2024
** ee
** File description:
** gui_actions_map
*/

/**
 * @file gui_actions_map.c
 * @brief Some prototype functions for the gui
*/

#include <stdio.h>
#include "include/gui_actions.h"

/**
 * @brief prototype for the map_size function
 * @param str the string corresponding to the message
*/
void gui_map_size(char *str)
{
    int X = 0;
    int Y = 0;

    printf("msz %i %i\n", X, Y);
}

/**
 * @brief prototype for the content of a tile function
 * @param str the string corresponding to the message
*/
void gui_tile_content(char *str)
{
    int X = 0;
    int Y = 0;
    int q1 = 0;
    int q2 = 0;
    int q3 = 0;
    int q4 = 0;
    int q5 = 0;
    int q6 = 0;

    if (!gui_str_two_values_getter(str, &X, &Y)) {
        printf("suc\n");
        return;
    }
    printf("bct %i %i %i %i %i %i %i %i\n", X, Y, q1, q2, q3, q4, q5, q6);
}

/**
 * @brief prototype for the content of the map function
 * @param str the string corresponding to the message
*/
void gui_map_content(char *str)
{
    printf("contenu de la map\n");
}

/**
 * @brief prototype for the team names function
 * @param str the string corresponding to the message
*/
void gui_teams_names(char *str)
{
    int N = 0;

    printf("tna %i\n", N);
}
