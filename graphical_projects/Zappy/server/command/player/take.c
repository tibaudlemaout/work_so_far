/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file take.c
 * @brief File containing different functions for the take object AI command
*/

#include "../../include/zappy_server.h"

/**
 * @brief function that begins the take action AI command
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void start_take(player_t *player, char **args, info_t *info)
{
    char str[128];
    inventory_t *inv = &info->map.tile[player->position.y][player->position.x];
    ressource_t ressource = get_ressource(args[1]);

    if (ressource == ERROR) {
        append_to_string(player->w_buffer, "ko\n");
        player->time_start = ERROR_FIRST_COMMAND;
        return;
    }
    if (!has_x_ressource(*inv, ressource, 1)) {
        append_to_string(player->w_buffer, "ko\n");
        player->time_start = ERROR_FIRST_COMMAND;
        return;
    }
    set_time(player);
    sprintf(str, "pgt %d %d\n", player->id, ressource);
    append_to_gui(info, str);
}

/**
 * @brief function that returns if a ressource is able to be extracted
 *  from an inventory
 * @param ressource the wanted ressource
 * @param player a pointer to a structure corresponding to a player
 * @param info a pointer to a structure containing every game info
 * @param inv a pointer to a structure containing an inventory
 * @return yes if the resource can be taken, no otherwise
*/
bool can_take_end(ressource_t ressource, player_t *player,
    info_t *info, inventory_t *inv)
{
    char str[128];

    if (ressource == ERROR) {
        append_to_string(player->w_buffer, "ko\n");
        sprintf(str, "pgt %d %d\n", player->id, 0);
        append_to_gui(info, str);
        return (false);
    } else if (!has_x_ressource(*inv, ressource, 1)) {
        append_to_string(player->w_buffer, "ko\n");
        sprintf(str, "pgt %d %d\n", player->id, 0);
        append_to_gui(info, str);
        return (false);
    }
    return (true);
}

/**
 * @brief function that takes n ressource of any type from a tile inventory
 * @param inv a pointer to a structure correspondingto the inventory
 * @param ressource the given ressource
 * @param n the amount of ressource to extract
*/
void take_nressources(inventory_t *inv, ressource_t ressource, int n)
{
    if (ressource == FOOD)
        inv->food -= n;
    if (ressource == LINEMATE)
        inv->linemate -= n;
    if (ressource == DERAUMERE)
        inv->deraumere -= n;
    if (ressource == SIBUR)
        inv->sibur -= n;
    if (ressource == MENDIANE)
        inv->mendiane -= n;
    if (ressource == PHIRAS)
        inv->phiras -= n;
    if (ressource == THYSTAME)
        inv->thystame -= n;
}

/**
 * @brief function that ends the take object function
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void end_take(player_t *player, char **args, info_t *info)
{
    char str[128];
    inventory_t *inv = &info->map.tile[player->position.y][player->position.x];
    ressource_t ressource = get_ressource(args[1]);

    if (!can_take_end(ressource, player, info, inv))
        return;
    take_nressources(inv, ressource, 1);
    take_nressources(&info->global_inv, ressource, 1);
    give_nressources(&player->inventory, ressource, 1);
    append_to_string(player->w_buffer, "ok\n");
    sprintf(str, "pgt %d %d\n", player->id, 1);
    append_to_gui(info, str);
    send_new_invs(*player, *inv, info);
}
