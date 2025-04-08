/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file death.c
 * @brief File containing functions for the death of a player
*/

#include "../include/zappy_server.h"

/**
 * @brief function that sets a new time for the game clock
 * @param player a pointer to a structure for a player
*/
void set_time(player_t *player)
{
    player->time_start = clock();
    return;
}

/**
 * @brief function used for the death of a player
 * @param player a pointer to a structure for a player
 * @param args an array containing every arguments
 * @param info a pointer to a structure containing every info about the game
*/
void player_death(player_t *player, char **args, info_t *info)
{
    char str[128];

    (void)args;
    player->state = DEAD;
    set_time(player);
    append_to_string(player->w_buffer, "dead\n");
    sprintf(str, "pdi %d\n", player->id);
    append_to_gui(info, str);
    return;
}
