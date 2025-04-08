/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** map creation
*/

/**
 * @file update_map.c
 * @brief File to be deleted
*/

#include "include/zappy_server.h"

/**
 * @brief Function that gives to the gui the inventory of the tiles
 * @param x the x coordinate of the tile
 * @param y the y coordinate of the tile
 * @param inv a structure cotaining the inventory
 * @param info a pointer to a structure containing every info
 *  about the game itself
*/
void update_tile_inv(int x, int y, inventory_t inv, info_t *info)
{
    char str[128];

    sprintf(str, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
        inv.food, inv.linemate, inv.deraumere, inv.sibur,
        inv.mendiane, inv.phiras, inv.thystame);
    append_to_gui(info, str);
    return;
}
