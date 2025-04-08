/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file player_commands.c
 * @brief File containing a function to send to the gui for the team names
*/

#include "../../include/zappy_server.h"

/**
 * @brief function that sends to the gui the team names
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void teams_names(player_t *player, char **args, info_t *info)
{
    char str[128];
    int len = 0;

    (void)player;
    (void)args;
    for (; info->teams[len]; len++);
    sprintf(str, "tna %d", len);
    append_to_gui(info, str);
    for (int i = 0; info->teams[i]; i++) {
        sprintf(str, " %s", info->teams[i]);
        append_to_gui(info, str);
    }
    append_to_gui(info, "\n");
}
