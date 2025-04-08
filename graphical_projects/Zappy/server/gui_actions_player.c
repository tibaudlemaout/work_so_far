/*
** EPITECH PROJECT, 2024
** ee
** File description:
** gui_actions_player
*/

/**
 * @file gui_actions_player.c
 * @brief Some prototype functions for the gui
*/

#include <stdio.h>
#include "include/gui_actions.h"

/**
 * @brief prototype for the player position function
 * @param str the string corresponding to the message
*/
void gui_player_position(char *str)
{
    int n = 0;
    int X = 0;
    int Y = 0;
    int O = 0;

    if (!gui_str_value_getter(str, &n)) {
        printf("suc\n");
        return;
    }
    printf("info pos for player #%i\n", n);
    printf("ppo #%i %i %i %i\n", n, X, Y, O);
}

/**
 * @brief prototype for the player level function
 * @param str the string corresponding to the message
*/
void gui_player_level(char *str)
{
    int n = 0;
    int L = 0;

    if (!gui_str_value_getter(str, &n)) {
        printf("suc\n");
        return;
    }
    printf("info level for player #%i\n", n);
    printf("plv #%i %i\n", n, L);
}

/**
 * @brief prototype for the inventory function
 * @param str the string corresponding to the message
*/
void gui_player_inventory(char *str)
{
    int n = 0;

    if (!gui_str_value_getter(str, &n)) {
        printf("suc\n");
        return;
    }
    printf("info inventory for player #%i\n", n);
    printf("pin #%i [inventaire]", n);
}
