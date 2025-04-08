/*
** EPITECH PROJECT, 2024
** zappytest
** File description:
** player_interactions
*/

/**
 * @file player_interactions.c
 * @brief Functions prototypes for AI commands
*/

#include <stdio.h>
#include "include/zappy_server.h"

/**
 * @brief function prototype for the AI to get unused teams
 * @param str the string on which there are parameters
 * @param engine the old main game structure containing all informations
*/
void action_unused_teams(char *str, game_t *engine)
{
    printf("value\n");
}

/**
 * @brief function prototype for the AI to lay an egg
 * @param str the string on which there are parameters
 * @param engine the old main game structure containing all informations
*/
void action_player_fork(char *str, game_t *engine)
{
    printf("ok\n");
}

/**
 * @brief function prototype for the AI to eject players
 * @param str the string on which there are parameters
 * @param engine the old main game structure containing all informations
*/
void action_eject_players(char *str, game_t *engine)
{
    printf("ok/ko\n");
}

/**
 * @brief function prototype for the AI to die
 * @param str the string on which there are parameters
 * @param engine the old main game structure containing all informations
*/
void action_death(char *str, game_t *engine)
{
    printf("ok\n");
}
