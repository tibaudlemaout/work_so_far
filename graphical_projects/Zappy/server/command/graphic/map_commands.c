/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file map_commands.c
 * @brief File containing functions to manage the map and its tiles
*/

#include "../../include/zappy_server.h"

/**
 * @brief function that sends to the gui the map size
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void map_size(player_t *player, char **args, info_t *info)
{
    char str[16];

    (void)args;
    (void)player;
    sprintf(str, "msz %d %d\n", info->map.width, info->map.height);
    append_to_gui(info, str);
}

/**
 * @brief function that sends to the gui the content of a tile
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void tile_content(player_t *player, char **args, info_t *info)
{
    char str[48];
    int x = atoi(args[1]);
    int y = atoi(args[2]);

    (void)player;
    sprintf(str, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
    info->map.tile[y][x].food,
    info->map.tile[y][x].linemate,
    info->map.tile[y][x].deraumere,
    info->map.tile[y][x].sibur,
    info->map.tile[y][x].mendiane,
    info->map.tile[y][x].phiras,
    info->map.tile[y][x].thystame);
    append_to_gui(info, str);
}

/**
 * @brief function that sends to the gui the content of the map (entierely)
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void map_content(player_t *player, char **args, info_t *info)
{
    char str[256];

    (void)args;
    (void)player;
    for (int i = 0; i != info->map.height; i++) {
        for (int j = 0; j != info->map.width; j++) {
            sprintf(str, "bct %d %d %d %d %d %d %d %d %d\n", j, i,
            info->map.tile[i][j].food,
            info->map.tile[i][j].linemate,
            info->map.tile[i][j].deraumere,
            info->map.tile[i][j].sibur,
            info->map.tile[i][j].mendiane,
            info->map.tile[i][j].phiras,
            info->map.tile[i][j].thystame);
            append_to_gui(info, str);
            memset(str, 0, strlen(str));
        }
    }
}
