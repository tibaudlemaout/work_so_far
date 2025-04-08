/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file inventory.c
 * @brief File containing different functions for the inventory AI command
*/

#include "../../include/zappy_server.h"

/**
 * @brief function that starts the inventory AI command
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void inventory(player_t *player, char **args, info_t *info)
{
    char inv[128];

    (void)info;
    (void)args;
    sprintf(inv, "[ food %d, linemate %d, deraumere %d, sibur %d, "
        "mendiane %d, phiras %d, thystame %d ]\n", player->inventory.food,
        player->inventory.linemate,
        player->inventory.deraumere,
        player->inventory.sibur,
        player->inventory.mendiane,
        player->inventory.phiras,
        player->inventory.thystame);
    append_to_string(player->w_buffer, inv);
}

/**
 * @brief function that displays an inventory
 * @param inventory the inventory to display
*/
void print_inventory(inventory_t inventory)
{
    printf("inv[food %d, linemate %d, deraumere %d, sibur %d, "
    "mendiane %d, phiras %d, thystame %d]\n",
        inventory.food,
        inventory.linemate,
        inventory.deraumere,
        inventory.sibur,
        inventory.mendiane,
        inventory.phiras,
        inventory.thystame);
}

/**
 * @brief function that returns the new inventory AI command
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void send_new_invs(player_t player, inventory_t inv, info_t *info)
{
    char str[128];

    sprintf(str, "pin %d %d %d %d %d %d %d %d %d %d\n", player.id,
        player.position.x, player.position.y,
        player.inventory.food, player.inventory.linemate,
        player.inventory.deraumere, player.inventory.sibur,
        player.inventory.mendiane,
        player.inventory.phiras,
        player.inventory.thystame);
    sprintf(str, "bct %d %d %d %d %d %d %d %d %d\n",
        player.position.x, player.position.y, inv.food, inv.linemate,
        inv.deraumere, inv.sibur, inv.mendiane, inv.phiras, inv.thystame);
    append_to_gui(info, str);
}
