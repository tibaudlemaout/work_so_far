/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file drop.c
 * @brief File containing functions for the set object AI command
*/

#include "../../include/zappy_server.h"

/**
 * @brief function that is first called for the set object AI command
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void start_drop(player_t *player, char **args, info_t *info)
{
    char str[128];
    ressource_t ressource = get_ressource(args[1]);

    if (ressource == ERROR) {
        append_to_string(player->w_buffer, "ko\n");
        player->time_start = ERROR_FIRST_COMMAND;
        return;
    }
    if (!has_x_ressource(player->inventory, ressource, 1)) {
        append_to_string(player->w_buffer, "ko\n");
        player->time_start = ERROR_FIRST_COMMAND;
        return;
    }
    set_time(player);
    sprintf(str, "pdr %d %d\n", player->id, ressource);
    append_to_gui(info, str);
}

/**
 * @brief function that is first called for the set object AI command
 * @param inv a pointer to the structure of the inventory of the given tile
 * @param ressource the ressource to drop
 * @param n the quantity of the said ressource
*/
void give_nressources(inventory_t *inv, ressource_t ressource, int n)
{
    if (ressource == FOOD)
        inv->food += n;
    if (ressource == LINEMATE)
        inv->linemate += n;
    if (ressource == DERAUMERE)
        inv->deraumere += n;
    if (ressource == SIBUR)
        inv->sibur += n;
    if (ressource == MENDIANE)
        inv->mendiane += n;
    if (ressource == PHIRAS)
        inv->phiras += n;
    if (ressource == THYSTAME)
        inv->thystame += n;
}

/**
 * @brief function for the set object AI command
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void end_drop(player_t *player, char **args, info_t *info)
{
    inventory_t *inv = &info->map.tile[player->position.y][player->position.x];
    ressource_t ressource = get_ressource(args[1]);

    if (ressource == ERROR) {
        append_to_string(player->w_buffer, "ko\n");
        return;
    }
    if (!has_x_ressource(player->inventory, ressource, 1)) {
        append_to_string(player->w_buffer, "ko\n");
        return;
    }
    take_nressources(&player->inventory, ressource, 1);
    give_nressources(inv, ressource, 1);
    give_nressources(&(info->global_inv), ressource, 1);
    print_inventory(info->global_inv);
    append_to_string(player->w_buffer, "ok\n");
    send_new_invs(*player, *inv, info);
}
