/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file freq_commands.c
 * @brief File containing functions to manage the frequency nd the timer
*/

#include "../../include/zappy_server.h"

/**
 * @brief function that sets the content of the frequency
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void freq_content(player_t *player, char **args, info_t *info)
{
    char str[128];

    (void)player;
    (void)args;
    sprintf(str, "sgt %d\n", info->freq);
    append_to_gui(info, str);
}

/**
 * @brief function that updates the frequency
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void freq_update(player_t *player, char **args, info_t *info)
{
    char str[128];

    (void)player;
    info->freq = atoi(args[1]);
    sprintf(str, "sst %d\n", info->freq);
    append_to_gui(info, str);
}
