/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file resource.c
 * @brief File containing multiple resources functions for AI commands
*/

#include "../../include/zappy_server.h"

const int linemate_tab2[] = {1, 1, 2, 1, 1, 1, 2};
const int deraumere_tab2[] = {0, 1, 0, 1, 2, 2, 2};
const int sibur_tab2[] = {0, 1, 1, 2, 1, 3, 2};
const int mendiane_tab2[] = {0, 0, 0, 0, 3, 0, 2};
const int phiras_tab2[] = {0, 0, 2, 1, 0, 1, 2};
const int thystame_tab2[] = {0, 0, 0, 0, 0, 0, 1};

/**
 * @brief function to know if an inventory have x of the same ressource
 * @param inventory the inventory
 * @param ressource the given ressource to count
 * @param x the number to check
 * @return yes if there is enough, no if not
*/
bool has_x_ressource(inventory_t inv, ressource_t ressource, int x)
{
    if (ressource == FOOD && inv.food < x)
        return (false);
    if (ressource == LINEMATE && inv.linemate < x)
        return (false);
    if (ressource == DERAUMERE && inv.deraumere < x)
        return (false);
    if (ressource == SIBUR && inv.sibur < x)
        return (false);
    if (ressource == MENDIANE && inv.mendiane < x)
        return (false);
    if (ressource == PHIRAS && inv.phiras < x)
        return (false);
    if (ressource == THYSTAME && inv.thystame < x)
        return (false);
    return (true);
}

/**
 * @brief function that removes the incantation ressources
 * @param pl_lvl the level of the player
 * @param inv a pointer to the inventory of the tile
 * @param info a pointer to a structure containing every game info
*/
void remove_incantation_res(int pl_lvl, inventory_t *inv, info_t *info)
{
    take_nressources(inv, LINEMATE, linemate_tab2[pl_lvl - 1]);
    take_nressources(inv, DERAUMERE, deraumere_tab2[pl_lvl - 1]);
    take_nressources(inv, SIBUR, sibur_tab2[pl_lvl - 1]);
    take_nressources(inv, MENDIANE, mendiane_tab2[pl_lvl - 1]);
    take_nressources(inv, PHIRAS, phiras_tab2[pl_lvl - 1]);
    take_nressources(inv, THYSTAME, thystame_tab2[pl_lvl - 1]);
    give_nressources(&info->global_inv, LINEMATE,
        linemate_tab2[pl_lvl - 1]);
    give_nressources(&info->global_inv, DERAUMERE,
        deraumere_tab2[pl_lvl - 1]);
    give_nressources(&info->global_inv, SIBUR, sibur_tab2[pl_lvl - 1]);
    give_nressources(&info->global_inv, MENDIANE,
        mendiane_tab2[pl_lvl - 1]);
    give_nressources(&info->global_inv, PHIRAS, phiras_tab2[pl_lvl - 1]);
    give_nressources(&info->global_inv, THYSTAME,
        thystame_tab2[pl_lvl - 1]);
}
