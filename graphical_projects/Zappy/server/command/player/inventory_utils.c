/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/
/**
 * @file inventory_utils.c
 * @brief File containing different functions for the inventory AI command
*/

#include "../../include/zappy_server.h"

const char *RESSOURCES[] = {
    "food",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame",
    NULL
};

/**
 * @brief function that gets a wanted ressource in function of a string
 * @param arg the string containing the name of the ressource
 * @return the ressource itself
*/
int get_ressource(char *arg)
{
    size_t i = 0;

    if (!arg)
        return ERROR;
    for (; RESSOURCES[i]; i++) {
        if (strcmp(RESSOURCES[i], arg) == 0)
            break;
    }
    return (i);
}

/**
 * @brief function that returns the number of a given ressource in a
 *  given inventory
 * @param inv the given inventory of a target player
 * @param ressource the wanted ressource
 * @return the number of the said ressource in the inventory
*/
int get_nb_ressource(inventory_t inv, ressource_t ressource)
{
    if (ressource == FOOD)
        return inv.food;
    if (ressource == LINEMATE)
        return inv.linemate;
    if (ressource == DERAUMERE)
        return inv.deraumere;
    if (ressource == SIBUR)
        return inv.sibur;
    if (ressource == MENDIANE)
        return inv.mendiane;
    if (ressource == PHIRAS)
        return inv.phiras;
    if (ressource == THYSTAME)
        return inv.thystame;
    return (0);
}
