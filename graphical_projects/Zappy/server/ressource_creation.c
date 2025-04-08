/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** map creation
*/

/**
 * @file ressource_creation.c
 * @brief File containing different function for ressource
 *  creation and generation
*/

#include "include/zappy_server.h"

const double res_amount[] = {0.5, 0.3, 0.15, 0.1, 0.1, 0.08, 0.05};

/**
 * @brief Function that puts elements on the map, at random
 *  (mendiane, phiras, thystame, sibur)
 * @param info pointer to a structure containing all informations
 *  about the game
 * @param ressource the corresponding ressource to be generated
 * @param x the x coordinate for the tile on which the ressources are generated
 * @param y the y coordinate for the tile on which the ressources are generated
*/
static void add_other_res_rand(info_t *info, ressource_t ressource,
    int x, int y)
{
    if (ressource == MENDIANE) {
        info->map.tile[y][x].mendiane++;
        info->global_inv.mendiane++;
        update_tile_inv(x, y, info->map.tile[y][x], info);
    }
    if (ressource == PHIRAS) {
        info->map.tile[y][x].phiras++;
        info->global_inv.phiras++;
        update_tile_inv(x, y, info->map.tile[y][x], info);
    }
    if (ressource == THYSTAME) {
        info->map.tile[y][x].thystame++;
        info->global_inv.thystame++;
        update_tile_inv(x, y, info->map.tile[y][x], info);
    }
    if (ressource == SIBUR) {
        info->map.tile[y][x].sibur++;
        info->global_inv.sibur++;
        update_tile_inv(x, y, info->map.tile[y][x], info);
    }
}

/**
 * @brief Function that puts elements on the map, at random
 *  (food, linemate, deraumere)
 * @param info pointer to a structure containing all informations
 *  about the game
 * @param ressource the corresponding ressource to be generated
*/
static void add_res_rand(info_t *info, ressource_t ressource)
{
    int x = rand() % info->map.width;
    int y = rand() % info->map.height;

    if (ressource == FOOD) {
        info->map.tile[y][x].food++;
        info->global_inv.food++;
        update_tile_inv(x, y, info->map.tile[y][x], info);
    }
    if (ressource == LINEMATE) {
        info->map.tile[y][x].linemate++;
        info->global_inv.linemate++;
        update_tile_inv(x, y, info->map.tile[y][x], info);
    }
    if (ressource == DERAUMERE) {
        info->map.tile[y][x].deraumere++;
        info->global_inv.deraumere++;
        update_tile_inv(x, y, info->map.tile[y][x], info);
    }
    add_other_res_rand(info, ressource, x, y);
}

/**
 * @brief Function that generates the ressources on the map (phiras,
 *  thystame, mendiane)
 * @param info pointer to a structure containing all informations about
 *  the game
*/
static void gen_other_res(info_t *info)
{
    int nb_phiras = info->map.width * info->map.height * res_amount[PHIRAS]
    - info->global_inv.phiras;
    int nb_thystame = info->map.width * info->map.height * res_amount[THYSTAME]
    - info->global_inv.thystame;
    int nb_mendiane = info->map.width * info->map.height * res_amount[MENDIANE]
    - info->global_inv.mendiane;

    for (; nb_mendiane > 0; nb_mendiane--)
        add_res_rand(info, MENDIANE);
    for (; nb_phiras > 0; nb_phiras--)
        add_res_rand(info, PHIRAS);
    for (; nb_thystame > 0; nb_thystame--)
        add_res_rand(info, THYSTAME);
}

/**
 * @brief Function that generates the ressources on the map (food, linemate,
 *  deraumere, sibur)
 * @param info pointer to a structure containing all informations about
 *  the game
*/
void gen_res(info_t *info)
{
    int nb_food = info->map.width * info->map.height * res_amount[FOOD]
    - info->global_inv.food;
    int nb_linemate = info->map.width * info->map.height * res_amount[LINEMATE]
    - info->global_inv.linemate;
    int nb_der = info->map.width * info->map.height * res_amount[DERAUMERE]
    - info->global_inv.deraumere;
    int nb_sibur = info->map.width * info->map.height * res_amount[SIBUR]
    - info->global_inv.sibur;

    for (; nb_food > 0; nb_food--)
        add_res_rand(info, FOOD);
    for (; nb_linemate > 0; nb_linemate--)
        add_res_rand(info, LINEMATE);
    for (; nb_der > 0; nb_der--)
        add_res_rand(info, DERAUMERE);
    for (; nb_sibur > 0; nb_sibur--)
        add_res_rand(info, SIBUR);
    gen_other_res(info);
}

/**
 * @brief Function that generates the ticks based on the frequency and
 *  applies them in the info structure
 * @param info pointer to a structure containing all informations
 *  about the game
*/
void gen_res_tick(info_t *info)
{
    double waiting = (clock() - info->time_gen) / CLOCKS_PER_SEC;

    if (waiting >= (GEN_TICK / info->freq)) {
        gen_res(info);
        info->time_gen = clock();
    }
}
