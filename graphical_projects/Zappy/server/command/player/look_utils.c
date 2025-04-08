/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file look_utils.c
 * @brief File containing different functions for the look AI command
*/

#include "../../include/zappy_server.h"

/**
 * @brief function that starts the look AI command
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void start_look(player_t *player, char **args, info_t *info)
{
    char str[128];

    (void)args;
    set_time(player);
    return;
}

/**
 * @brief function that adds ressource to the return of look AI command
 * @param player a pointer to a structure corresponding to a player
 * @param inv the inventory of the tiles
 * @param total an integer for total ressources
*/
void add_other_res(player_t *player, inventory_t inv, int total)
{
    int mendiane = get_nb_ressource(inv, MENDIANE);
    int phiras = get_nb_ressource(inv, PHIRAS);
    int thystame = get_nb_ressource(inv, THYSTAME);

    for (int i = 0; i != mendiane; i++) {
        append_to_string(player->w_buffer, " mendiane");
        total++;
    }
    for (int i = 0; i != phiras; i++) {
        append_to_string(player->w_buffer, " phiras");
        total++;
    }
    for (int i = 0; i != thystame; i++) {
        append_to_string(player->w_buffer, " thystame");
        total++;
    }
    if (total == 0)
        append_to_string(player->w_buffer, " ");
}

/**
 * @brief function that adds ressource to the return of look AI command
 * @param player a pointer to a structure corresponding to a player
 * @param inv the inventory of the tiles
 * @param total an integer for total ressources
*/
void add_res(player_t *player, inventory_t inv, int total)
{
    int linemate = get_nb_ressource(inv, LINEMATE);
    int deraumere = get_nb_ressource(inv, DERAUMERE);
    int sibur = get_nb_ressource(inv, SIBUR);

    for (int i = 0; i != linemate; i++) {
        append_to_string(player->w_buffer, " linemate");
        total++;
    }
    for (int i = 0; i != deraumere; i++) {
        append_to_string(player->w_buffer, " deraumere");
        total++;
    }
    for (int i = 0; i != sibur; i++) {
        append_to_string(player->w_buffer, " sibur");
        total++;
    }
    add_other_res(player, inv, total);
}

/**
 * @brief function that adds players and food to the return of look AI command
 * @param player a pointer to a structure corresponding to a player
 * @param info a pointer to a structure containing every game info
 * @param x the x coordinate of the wanted tile
 * @param y the y coordinate of the wanted tile
*/
void append_each(player_t *player, info_t *info, int x, int y)
{
    position_t xy = {x, y};
    inventory_t inv = info->map.tile[xy.y][xy.x];
    int nb_players = get_nb_players(info, xy);
    int food = get_nb_ressource(inv, FOOD);
    int total = 0;

    for (int i = 0; i != nb_players; i++) {
        append_to_string(player->w_buffer, " player");
        total++;
    }
    for (int i = 0; i != food; i++) {
        append_to_string(player->w_buffer, " food");
        total++;
    }
    add_res(player, inv, total);
}

/**
 * @brief function that calculates the coordinates of a point
 *  outside the grid to make an infinite world
 * @param n a pointer to an integer
 * @param goal a pointer to the goal integer
 * @param lim an integer corresponding to the limit
*/
void fix_coord(int *n, int *goal, int lim)
{
    if (goal == NULL && *n == lim)
        *n = 0;
    else if (goal == NULL && *n < 0)
        *n = lim - 1;
    if (*n == lim) {
        *n = 0;
        *goal -= lim;
    } else if (*n < 0) {
        *n = lim - 1;
        *goal += lim;
    }
}
