/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file connect_nbr.c
 * @brief File containing functions for the connect_nbr AI command
*/

#include "../../include/zappy_server.h"

/**
 * @brief function that is first called for the connect_nbr AI command
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void unused_players(player_t *player, char **args, info_t *info)
{
    char value[6];

    (void)args;
    sprintf(value, "%d\n", get_nb_unused(info->head_player,
        player->team_name));
    append_to_string(player->w_buffer, value);
    return;
}
