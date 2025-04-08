/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file init_tools.c
 * @brief File containing important functions for program initialization
*/

#include "include/zappy_server.h"

/**
 * @brief Function to initiate any player's/map inventory
 * @param inv pointer to a structure containing a player's inventory
*/
void init_inventory(inventory_t *inv)
{
    inv->food = 10;
    inv->deraumere = 0;
    inv->linemate = 0;
    inv->mendiane = 0;
    inv->phiras = 0;
    inv->sibur = 0;
    inv->thystame = 0;
    return;
}

/**
 * @brief Function to initiate the map and every one of its tiles
 * @param data pointer to a structure containing every information
 *  about the game (to be initialized)
*/
void init_map(info_t *data)
{
    data->map.tile = malloc(sizeof(inventory_t *) * (data->map.width + 1));
    if (data->map.tile == NULL)
        show_error("map malloc failed\n");
    for (int i = 0; i != data->map.width; i++) {
        data->map.tile[i] = malloc(sizeof(inventory_t) *
        (data->map.height + 1));
        if (data->map.tile[i] == NULL)
            show_error("map tile malloc failed\n");
        for (int j = 0; j != data->map.height; j++) {
            init_inventory(&data->map.tile[i][j]);
            data->map.tile[i][j].food = 0;
        }
    }
    data->time_gen = clock();
    return;
}

/**
 * @brief Function to initiate the players in function of their numbers
 * @param nb_cli the number of clients connected, and of player to create
 * @param info pointer to a structure containing every information
 *  about the game (to be initialized)
*/
void init_players(int nb_cli, info_t *info)
{
    player_t tmp_player;
    char str[126] = "";

    create_player(&tmp_player, "GRAPHIC", info);
    tmp_player.position.x = -1;
    tmp_player.position.y = -1;
    append_player_node(&info->head_player, tmp_player);
    info->next_id++;
    for (int i = 0; info->teams[i]; i++) {
        for (int j = 0; j != nb_cli; info->next_id++) {
            create_player(&tmp_player, info->teams[i], info);
            append_player_node(&info->head_player, tmp_player);
            j++;
        }
    }
    return;
}
