/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file no_preparation.c
 * @brief File containing a function for a non start of the program
*/

#include "../../include/zappy_server.h"

/**
 * @brief function for a non start of the program
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void start_no_check(player_t *player, char **args, info_t *info)
{
    (void)args;
    (void)info;
    set_time(player);
}
