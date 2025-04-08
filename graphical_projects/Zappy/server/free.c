/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** initialization of the server
*/

/**
 * @file free.c
 * @brief File containing functions to free structures and arrays
*/

#include "include/zappy_server.h"

/**
 * @brief function that frees a char *** storing separated arguments
 * @param largs a pointer to the array to be freed
*/
void free_array(char ***largs)
{
    char **args = *largs;

    for (size_t i = 0; args[i]; i++) {
        free(args[i]);
    }
    free(*largs);
    return;
}

/**
 * @brief function that frees the map in structure containing all
 *  informations for the game itself
 * @param data a pointer to a structure containing all informations
 *  about the game, in which is stored the map
*/
static void free_map(info_t *data)
{
    for (int i = 0; i != data->map.width; i++)
        free(data->map.tile[i]);
    free(data->map.tile);
    return;
}

/**
 * @brief function that frees the teams in structure containing all
 *  informations for the game itself
 * @param data a pointer to a structure containing all informations about
 *  the game, in which are stored the teams
*/
static void free_teams(info_t *data)
{
    for (int i = 0; data->teams[i]; i++)
        free(data->teams[i]);
    free(data->teams);
    return;
}

/**
 * @brief function that frees a structure containing all informations for
 *  the game itself and a structure for all the network
 * @param info a pointer to a structure containing all informations
 *  about the game
 * @param server a pointer to a structure containing all informations
 *  about the network
*/
void destroy_everything(info_t *info, zappy_server_t *server)
{
    free_map(info);
    free_teams(info);
    destroy_players(info->head_player);
    destroy_clients(server->head_client);
    return;
}
