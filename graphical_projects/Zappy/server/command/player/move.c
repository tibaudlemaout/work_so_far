/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file move.c
 * @brief File containing different functions for the player movements
*/

#include "../../include/zappy_server.h"

/**
 * @brief function that moves the player in function of its direction
 * @param player a pointer to a structure corresponding to a player
 * @param direction a pointer to a structure containing every game info
*/
void move_direction(player_t *player, direction_t direction)
{
    if (direction == UP)
        player->position.y++;
    if (direction == DOWN)
        player->position.y--;
    if (direction == RIGHT)
        player->position.x++;
    if (direction == LEFT)
        player->position.x--;
}

/**
 * @brief function that adapts the player to the torus map
 * @param player a pointer to a structure corresponding to a player
 * @param info a pointer to a structure containing every game info
*/
void check_limits(player_t *player, info_t *info)
{
    if (player->position.x < 0)
        player->position.x = info->map.width - 1;
    if (player->position.x == info->map.width)
        player->position.x = 0;
    if (player->position.y < 0)
        player->position.y = info->map.height - 1;
    if (player->position.y == info->map.height)
        player->position.y = 0;
}

/**
 * @brief function that starts the forward AI command
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void forward(player_t *player, char **args, info_t *info)
{
    (void)args;
    move_direction(player, player->direction);
    check_limits(player, info);
    append_to_string(player->w_buffer, "ok\n");
}

/**
 * @brief function that starts the right AI command
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void right(player_t *player, char **args, info_t *info)
{
    bool change = false;

    (void)info;
    (void)args;
    if (player->direction == UP && !change) {
        player->direction = RIGHT;
        change = true;
    }
    if (player->direction == DOWN && !change) {
        player->direction = LEFT;
        change = true;
    }
    if (player->direction == RIGHT && !change) {
        player->direction = DOWN;
        change = true;
    }
    if (player->direction == LEFT && !change)
        player->direction = UP;
    append_to_string(player->w_buffer, "ok\n");
}

/**
 * @brief function that starts the left AI command
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void left(player_t *player, char **args, info_t *info)
{
    bool change = false;

    (void)info;
    (void)args;
    if (player->direction == DOWN && !change) {
        player->direction = RIGHT;
        change = true;
    }
    if (player->direction == RIGHT && !change) {
        player->direction = UP;
        change = true;
    }
    if (player->direction == LEFT && !change) {
        player->direction = DOWN;
        change = true;
    }
    if (player->direction == UP && !change)
        player->direction = LEFT;
    append_to_string(player->w_buffer, "ok\n");
}
