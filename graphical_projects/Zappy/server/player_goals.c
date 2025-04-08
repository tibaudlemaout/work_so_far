/*
** EPITECH PROJECT, 2024
** zappytest
** File description:
** player_goals
*/

/**
 * @file player_goals.c
 * @brief Functions prototypes for AI commands
*/

#include <stdio.h>
#include "include/zappy_server.h"

/**
 * @brief function prototype for the AI to take an object
 * @param str the string on which there are parameters
 * @param engine the old main game structure containing all informations
*/
void action_take_object(char *str, game_t *engine)
{
    printf("ok/ko\n");
}

/**
 * @brief function prototype for the AI to set object down
 * @param str the string on which there are parameters
 * @param engine the old main game structure containing all informations
*/
void action_set_down(char *str, game_t *engine)
{
    printf("ok/ko\n");
}

/**
 * @brief function prototype for the AI to do incantation
 * @param str the string on which there are parameters
 * @param engine the old main game structure containing all informations
*/
void action_incantation(char *str, game_t *engine)
{
    int level = 5;

    printf("Elevationunderway\nCurrent level: %i\n/ko\n", level);
}
