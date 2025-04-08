/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file incantation_results.c
 * @brief File containing functions for the incantation AI command
*/

#include "../../include/zappy_server.h"

/**
 * @brief function that actualises a tile after incantation
 * @param coords coordinates of the tile
 * @param info a pointer to a structure containing every game info
*/
static void new_tile_content(position_t coords, info_t *info)
{
    char str[128];
    int x = coords.x;
    int y = coords.y;

    sprintf(str, "bct %d %d %d %d %d %d %d %d %d\n", coords.x, coords.y,
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
 * @brief function in case of success in the incantation
 * @param player a pointer to a structure corresponding to a player
 * @param info a pointer to a structure containing every game info
*/
static void incantation_success(player_t *player, info_t *info)
{
    char str[32];
    char str_gui[64] = "";
    linked_player_t *tmp = info->head_player;
    int lvl = player->level;

    while (tmp != NULL) {
        if (tmp->player.position.x == player->position.x &&
            tmp->player.position.y == player->position.y &&
            tmp->player.level == lvl &&
            tmp->player.state == ALIVE) {
            tmp->player.level++;
            sprintf(str_gui, "plv %d %d\n",
                tmp->player.id, tmp->player.level);
            sprintf(str, "Current level: %d\n", tmp->player.level);
            append_to_string(tmp->player.w_buffer, str);
            append_to_gui(info, str_gui);
        }
        memset(str_gui, 0, strlen(str_gui));
        tmp = tmp->next;
    }
}

/**
 * @brief function in case of a fail in the incantation
 * @param player a pointer to a structure corresponding to a player
 * @param info a pointer to a structure containing every game info
*/
static void incantation_fail(player_t *player, info_t *info)
{
    char str_gui[48];
    linked_player_t *tmp = info->head_player;
    int lvl = player->level;

    while (tmp != NULL) {
        if (tmp->player.position.x == player->position.x &&
            tmp->player.position.y == player->position.y &&
            tmp->player.level == lvl &&
            tmp->player.state == ALIVE) {
                sprintf(str_gui, "pie %d %d %d\n",
                    tmp->player.position.x, tmp->player.position.y, 0);
                append_to_string(tmp->player.w_buffer, "ko\n");
        }
        tmp = tmp->next;
    }
}

/**
 * @brief function that ends the incantation AI command
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void end_incantation(player_t *player, char **args, info_t *info)
{
    char str_gui[64];
    inventory_t *inv = &info->map.tile[player->position.y][player->position.x];

    (void)args;
    if (check_incantation(player, info)) {
        remove_incantation_res(player->level, inv, info);
        new_tile_content(player->position, info);
        incantation_success(player, info);
        sprintf(str_gui, "pie %d %d %d\n", player->position.x,
            player->position.y, 1);
    } else
        incantation_fail(player, info);
    append_to_gui(info, str_gui);
}
