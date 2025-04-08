/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file create_player.c
 * @brief File containing different functions for the player creation
*/

#include "../include/zappy_server.h"

/**
 * @brief function that gives random position to a position
 * @param info a pointer to a structure containing every info about the game
 * @param position a pointer to a position
*/
static void gen_rand_coords(info_t *info, position_t *position)
{
    position->x = rand() % info->map.width;
    position->y = rand() % info->map.height;
}

/**
 * @brief function that returns random directions
 * @return an integer with a random direction from 1 to 4
*/
static int gen_rand_direction(void)
{
    direction_t direction = UP;

    direction = rand() % 4;
    return (direction);
}

/**
 * @brief function that creates a player
 * @param player a pointer to a structure for one player
 * @param team_name a string containing the name of the team of the player
 * @param info a pointer to a structure containing every info about the game
*/
void create_player(player_t *player, char *team_name, info_t *info)
{
    player->id = info->next_id;
    player->direction = gen_rand_direction();
    player->time_to_eat = clock();
    player->time_start = READY_FIRST_COMMAND;
    player->level = 1;
    player->state = UNUSED;
    player->team_name = team_name;
    strcpy(player->w_buffer, "");
    for (int i = 0; i < MAX_COMMAND + 1; i++)
        player->command[i] = NULL;
    gen_rand_coords(info, &(player->position));
    init_inventory(&(player->inventory));
}

/**
 * @brief function that creates an egg
 * @param player a pointer to a structure for one player
 * @param team_name a string containing the name of the team of the player
 * @param info a pointer to a structure containing every info about the game
 * @param coord position of the new egg to be created
*/
void create_egg(player_t *player, char *team_name,
    info_t *info, position_t coord)
{
    player->id = info->next_id;
    player->direction = gen_rand_direction();
    player->time_to_eat = 10000;
    player->time_start = READY_FIRST_COMMAND;
    player->level = 1;
    player->state = EGG;
    player->team_name = team_name;
    player->position.x = coord.x;
    player->position.y = coord.y;
    strcpy(player->w_buffer, "");
    for (int i = 0; i < MAX_COMMAND; i++)
        player->command[i] = NULL;
    init_inventory(&(player->inventory));
}
