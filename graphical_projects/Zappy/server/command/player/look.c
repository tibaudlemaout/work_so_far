/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file look.c
 * @brief File containing different functions for the look AI command
*/

#include "../../include/zappy_server.h"

/**
 * @brief function to look up
 * @param player a pointer to a structure corresponding to a player
 * @param info a pointer to a structure containing every game info
*/
void look_up(player_t *player, info_t *info)
{
    look_coords_t coords = {1, player->position.x, player->position.x + 1,
    player->position.y + player->level + 1};

    append_to_string(player->w_buffer, "[");
    for (int i = player->position.y; i != coords.ly; i++) {
        fix_coord(&i, &coords.ly, info->map.height);
        fix_coord(&coords.k, NULL, info->map.width);
        coords.lx = coords.k + coords.j;
        for (int n = coords.k; n != coords.lx; n++) {
            fix_coord(&n, &coords.lx, info->map.width);
            append_each(player, info, n, i);
            add_coma_u(player, coords, i, n);
        }
        coords.j += 2;
        coords.k -= 1;
    }
    append_to_string(player->w_buffer, " ]\n");
}

/**
 * @brief function to look down
 * @param player a pointer to a structure corresponding to a player
 * @param info a pointer to a structure containing every game info
*/
void look_down(player_t *player, info_t *info)
{
    look_coords_t coords = {1, player->position.x, player->position.x + 1,
    player->position.y - player->level - 1};

    append_to_string(player->w_buffer, "[");
    for (int i = player->position.y; i != coords.ly; i--) {
        fix_coord(&i, &coords.ly, info->map.height);
        fix_coord(&coords.k, NULL, info->map.width);
        coords.lx = coords.k - coords.j;
        for (int n = coords.k; n != coords.lx; n--) {
            fix_coord(&n, &coords.lx, info->map.width);
            append_each(player, info, n, i);
            add_coma_d(player, coords, i, n);
        }
        coords.j += 2;
        coords.k += 1;
    }
    append_to_string(player->w_buffer, " ]\n");
}

/**
 * @brief function to look right
 * @param player a pointer to a structure corresponding to a player
 * @param info a pointer to a structure containing every game info
*/
void look_right(player_t *player, info_t *info)
{
    look_coords_t coords = {1, player->position.y,
    player->position.x + player->level + 1, player->position.y + 1};

    append_to_string(player->w_buffer, "[");
    for (int i = player->position.x; i != coords.lx; i++) {
        fix_coord(&i, &coords.lx, info->map.width);
        fix_coord(&coords.k, NULL, info->map.height);
        coords.ly = coords.k - coords.j;
        for (int n = coords.k; n != coords.ly; n--) {
            fix_coord(&n, &coords.ly, info->map.height);
            append_each(player, info, i, n);
            add_coma_r(player, coords, i, n);
        }
        coords.j += 2;
        coords.k += 1;
    }
    append_to_string(player->w_buffer, " ]\n");
}

/**
 * @brief function to look left
 * @param player a pointer to a structure corresponding to a player
 * @param info a pointer to a structure containing every game info
*/
void look_left(player_t *player, info_t *info)
{
    look_coords_t coords = {1, player->position.y,
    player->position.x - player->level - 1, player->position.y + 1};

    append_to_string(player->w_buffer, "[");
    for (int i = player->position.x; i != coords.lx; i--) {
        fix_coord(&i, &coords.lx, info->map.width);
        fix_coord(&coords.k, NULL, info->map.height);
        coords.ly = coords.k + coords.j;
        for (int n = coords.k; n != coords.ly; n++) {
            fix_coord(&n, &coords.ly, info->map.height);
            append_each(player, info, i, n);
            add_coma_l(player, coords, i, n);
        }
        coords.j += 2;
        coords.k -= 1;
    }
    append_to_string(player->w_buffer, " ]\n");
}

/**
 * @brief function that starts the look AI command
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void look(player_t *player, char **args, info_t *info)
{
    (void)args;
    if (player->direction == UP)
        look_up(player, info);
    if (player->direction == DOWN)
        look_down(player, info);
    if (player->direction == RIGHT)
        look_right(player, info);
    if (player->direction == LEFT)
        look_left(player, info);
}
