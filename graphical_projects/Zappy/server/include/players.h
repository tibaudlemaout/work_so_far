/*
** EPITECH PROJECT, 2024
** zappytest
** File description:
** players
*/

/**
 * @file players.h
 * @brief Header File containing functions and function pointers
 *  for AI parsing and commands
*/

#ifndef PLAYERS_H_
    #define PLAYERS_H_

    #include <stdio.h>

typedef void (*action_players_t)(char *, game_t *engine);

/**
 * @struct action_map_t
 * @brief structure for functions pointer
 */
typedef struct {
    /**
     * @brief string containing a command
     */
    char *command;

    /**
     * @brief function pointer
     */
    action_players_t func;
} action_map_t;

void player_get_actions(char *str, game_t *engine);

void action_go_forward(char *str, game_t *engine);
void action_turn_right(char *str, game_t *engine);
void action_turn_left(char *str, game_t *engine);

void action_look_around(char *str, game_t *engine);
void action_inventory(char *str, game_t *engine);
void action_broadcast_text(char *str, game_t *engine);

void action_unused_teams(char *str, game_t *engine);
void action_player_fork(char *str, game_t *engine);
void action_eject_players(char *str, game_t *engine);
void action_death(char *str, game_t *engine);

void action_take_object(char *str, game_t *engine);
void action_set_down(char *str, game_t *engine);
void action_incantation(char *str, game_t *engine);

void action_unknown(char *str, game_t *engine);

#endif /* !PLAYERS_H_ */
